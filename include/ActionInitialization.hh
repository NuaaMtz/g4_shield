/*
 * @Author: mtz nuaamzt@nuaa.edu.cn
 * @Date: 2025-05-19 23:06:38
 * @LastEditors: mtz nuaamzt@nuaa.edu.cn
 * @LastEditTime: 2025-05-20 00:36:25
 * @FilePath: /g4_shield/include/ActionInitialization.hh
 * @Description: 行为管理类
 */

 #ifndef B1ActionInitialization_h
 #define B1ActionInitialization_h 1
 
 #include "G4VUserActionInitialization.hh"
 #include "PrimaryGeneratorAction.hh"
 #include "RunAction.hh"
 #include "EventAction.hh"
    #include "SteppingAction.hh"
 
 class ActionInitialization : public G4VUserActionInitialization
 {
   public:
     ActionInitialization();
     virtual ~ActionInitialization();
 
     virtual void BuildForMaster() const;
     virtual void Build() const;
 };
 #endif