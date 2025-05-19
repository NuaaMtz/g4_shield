/*
 * @Author: mtz nuaamzt@nuaa.edu.cn
 * @Date: 2025-05-19 23:15:54
 * @LastEditors: mtz nuaamzt@nuaa.edu.cn
 * @LastEditTime: 2025-05-19 23:16:13
 * @FilePath: /g4_shield/include/PrimaryGeneratorAction.hh
 * @Description: GPS粒子源
 */
#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4ParticleGun.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"

#include "G4GeneralParticleSource.hh"
#include "G4GenericMessenger.hh"
class PrimaryGeneratorMessenger;
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
  PrimaryGeneratorAction();
  virtual ~PrimaryGeneratorAction();
  virtual void GeneratePrimaries(G4Event *);

  G4GeneralParticleSource *GetGPS() const { return fParticleGun; }

  G4int n_particle;
  double energy;

private:
  G4GeneralParticleSource *fParticleGun; // G4 particle gun
};

#endif