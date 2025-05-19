#include "DetectorConstruction.hh"
#include <CLHEP/Units/SystemOfUnits.h>

DetectorConstruction::DetectorConstruction() {}
DetectorConstruction::~DetectorConstruction() {



}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    G4NistManager* nist = G4NistManager::Instance();


  // 世界10m*10m*10m的空气
  G4double world_halfX = 10*m; // 预留安全距离
  G4Box* solidWorld = new G4Box("World", world_halfX,  world_halfX,  world_halfX);
  G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, nist->FindOrBuildMaterial("G4_AIR"), "World");
  G4VPhysicalVolume* physWorld = new G4PVPlacement(nullptr, G4ThreeVector(), logicWorld, "World", nullptr, false, 0);

  // 屏蔽层（y,z不变，保持这两个方向上全屏蔽。只改变x）
  G4Box* solidShield = new G4Box("Shield", 1*m, world_halfX , world_halfX );
  G4LogicalVolume* logicShield = new G4LogicalVolume(solidShield, nist->FindOrBuildMaterial("G4_Pb"), "Shield");
  new G4PVPlacement(nullptr, G4ThreeVector(3*m, 0, 0), logicShield, "Shield", logicWorld, false, 0);

  // 探测器（10*10*10cm）
  G4Box* solidDetector = new G4Box("Detector", 1*m,1*m,1*m);
  G4LogicalVolume* logicDetector = new G4LogicalVolume(solidDetector, nist->FindOrBuildMaterial("G4_Si"), "Detector");
  new G4PVPlacement(nullptr, G4ThreeVector(5*m, 0, 0), logicDetector, "Detector", logicWorld, false, 0);
  detector = logicDetector;
  return physWorld;
}
