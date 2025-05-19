/*
 * @Author: mtz nuaamzt@nuaa.edu.cn
 * @Date: 2025-05-19 23:39:10
 * @LastEditors: mtz nuaamzt@nuaa.edu.cn
 * @LastEditTime: 2025-05-19 23:55:45
 * @FilePath: /g4_shield/include/EventAction.hh
 * @Description: 事件类
 */

#include <G4Types.hh>
#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "RunAction.hh"



class EventAction : public G4UserEventAction
{
  public:
    EventAction(RunAction* runAction);
    virtual ~EventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);
    void AddEdep(G4double energy){fEnergy+=energy;}


    

  private:
    RunAction* fRunAction;
    G4double fEnergy;
   
    
};



#endif

    
