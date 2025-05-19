/*
 * @Author: mtz nuaamzt@nuaa.edu.cn
 * @Date: 2025-05-19 22:40:29
 * @LastEditors: mtz nuaamzt@nuaa.edu.cn
 * @LastEditTime: 2025-05-19 23:59:32
 * @FilePath: /g4_shield/main.cc
 * @Description: 主函数
 */
#include "DetectorConstruction.hh"
#include "FTFP_BERT.hh"
#include "G4MTRunManager.hh"
#include "G4StepLimiterPhysics.hh"
#include "G4VModularPhysicsList.hh"
#include "iostream"
#include "ActionInitialization.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
int main(int argc, char **argv) {
  std::cout << "Hello World!" << std::endl;
  G4MTRunManager *runManager = new G4MTRunManager();
  runManager->SetUserInitialization(new DetectorConstruction());
  G4VModularPhysicsList *physicsList = new FTFP_BERT;
  physicsList->RegisterPhysics(new G4StepLimiterPhysics());
  runManager->SetUserInitialization(physicsList);
  runManager->SetUserInitialization(new ActionInitialization());


  // 通用UI
   // 粒子可视化
   G4UIExecutive *ui = nullptr;
   if (argc == 1) {
     ui = new G4UIExecutive(argc, argv);
   }
   G4VisExecutive *visManager = new G4VisExecutive(); //* initialize vis manager
   visManager->Initialize();
   G4UImanager *uiManager =
       G4UImanager::GetUIpointer(); // get ui manager from vis manager
   if (ui) {
     uiManager->ApplyCommand("/control/execute vis.mac");
     ui->SessionStart();
   } else {
     G4String command = "/control/execute ";
     G4String fileName = argv[1];
     uiManager->ApplyCommand(command + fileName);
   }

}