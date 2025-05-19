#include"ActionInitialization.hh"
#include "RunAction.hh"
ActionInitialization::ActionInitialization(){

}
ActionInitialization::~ActionInitialization(){

}
void ActionInitialization::BuildForMaster()const{
    SetUserAction(new RunAction);

}
void ActionInitialization::Build()const{
    // GPS粒子源
    SetUserAction(new PrimaryGeneratorAction);
    // 运行
    RunAction *runAction = new RunAction;
    SetUserAction(runAction);

    // 事件
    EventAction *eventAction = new EventAction(runAction);
    SetUserAction(eventAction);
    // 步
    SetUserAction(new SteppingAction(eventAction));
    




}