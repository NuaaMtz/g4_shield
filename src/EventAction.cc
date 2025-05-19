/*
 * @Author: mtz nuaamzt@nuaa.edu.cn
 * @Date: 2025-05-19 23:39:05
 * @LastEditors: mtz nuaamzt@nuaa.edu.cn
 * @LastEditTime: 2025-05-19 23:57:49
 * @FilePath: /g4_shield/src/EventAction.cc
 * @Description: 事件类
 */



#include "EventAction.hh"
#include "RunAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

EventAction::EventAction(RunAction *runAction)
    : G4UserEventAction(), fRunAction(runAction),fEnergy(0) {}

EventAction::~EventAction() {}

void EventAction::BeginOfEventAction(const G4Event *) { 
  fEnergy=0;

 }

void EventAction::EndOfEventAction(const G4Event *) {
  fRunAction->AddEnergy(fEnergy);

}
