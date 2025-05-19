/*
 * @Author: mtz nuaamzt@nuaa.edu.cn
 * @Date: 2025-05-18 01:35:59
 * @LastEditors: mtz nuaamzt@nuaa.edu.cn
 * @LastEditTime: 2025-05-20 00:14:28
 * @FilePath: /g4_proton/src/RunAction.cc
 * @Description: 运行类，负责统计事件数和产额
 */

#include "RunAction.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
// #include "B1Run.hh"
#include "g4root_defs.hh" // 添加头文件

#include "G4AccumulableManager.hh"
#include "G4LogicalVolume.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "g4root.hh"
#include <G4Types.hh>
#include <G4ios.hh>

RunAction::RunAction() : G4UserRunAction(), fEdep(0) {
  // 初始化需要累加的数据
  G4AccumulableManager *accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->RegisterAccumulable(fEdep);
  // 定义保存的文件的结构
  auto analysisManager = G4AnalysisManager::Instance();
  G4cout << "Using " << analysisManager->GetType() << G4endl;
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true);
  analysisManager->CreateNtuple("tree", "能量tree");
  analysisManager->CreateNtupleDColumn("Energy");
  analysisManager->FinishNtuple();
}

RunAction::~RunAction() { delete G4Root::G4AnalysisManager::Instance(); }

void RunAction::BeginOfRunAction(const G4Run *run) {
  // 创建和打开root文件
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
  G4AccumulableManager *accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->Reset();
  // 打开root文件
  auto analysisManager = G4Root::G4AnalysisManager::Instance();
  G4int runNum = run->GetRunID();
  std::stringstream strRunID;
  strRunID << runNum;
  analysisManager->OpenFile("../rt/output_target" + strRunID.str() +
                            ".root"); // 每个beam都有自己的编号
}

void RunAction::EndOfRunAction(const G4Run *run) {
  // 没有run的事件不保存
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0)
    return;
  // 将所有线程（或所有事件）中累积的变量进行合并，得到整个run的总和（多线程时尤其重要）
  G4AccumulableManager *accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->Merge();
  G4int Edep = fEdep.GetValue();
  G4cout << " 总沉积能： " << Edep << G4endl;

  // 填充数据
  auto analysisManager = G4Root::G4AnalysisManager::Instance();

  if (!G4Threading::IsMasterThread()) {
    analysisManager->FillNtupleDColumn(0, Edep);
    analysisManager->AddNtupleRow();
  }
  // 主线程只负责合并和写文件

  analysisManager->Write();
  analysisManager->CloseFile();
}
