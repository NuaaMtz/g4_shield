/*
 * @Author: mtz nuaamzt@nuaa.edu.cn
 * @Date: 2025-05-19 23:18:38
 * @LastEditors: mtz nuaamzt@nuaa.edu.cn
 * @LastEditTime: 2025-05-19 23:57:07
 * @FilePath: /g4_shield/include/RunAction.hh
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


#ifndef RunAction_h
#define RunAction_h 1
#include <G4Types.hh>
#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"
#include "globals.hh"
#include "iostream"



class RunAction : public G4UserRunAction
{
  public:
    RunAction();
    virtual ~RunAction();

    // virtual G4Run* GenerateRun();
    virtual void BeginOfRunAction(const G4Run*);
    virtual void   EndOfRunAction(const G4Run*);

    void AddEnergy(G4double energy){fEdep+=energy;}



  private:
  G4Accumulable<G4double> fEdep;// 累积沉积能量

   
};

#endif