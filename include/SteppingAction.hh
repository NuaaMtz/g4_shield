/*
 * @Author: mtz nuaamzt@nuaa.edu.cn
 * @Date: 2025-05-19 23:41:39
 * @LastEditors: mtz nuaamzt@nuaa.edu.cn
 * @LastEditTime: 2025-05-19 23:51:27
 * @FilePath: /g4_shield/include/SteppingAction.hh
 * @Description: 步类
 */



#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"
#include "EventAction.hh"
#include "G4LogicalVolume.hh"
#include "DetectorConstruction.hh"

class SteppingAction : public G4UserSteppingAction
{
  public:
    SteppingAction(EventAction* eventAction);
    virtual ~SteppingAction();
    virtual void UserSteppingAction(const G4Step*);

  private:
    EventAction*  fEventAction;
    G4LogicalVolume* fDetector;
    
};



#endif
