#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "ZmumuAnalysis.h"
//#include "Helix.h"

#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TLorentzVector.h"
#include <math.h>

using namespace std;

//class Point3D;
//class Helix;

void ZmumuAnalysis::initialize(TString rout) {
  m_rootFile = new TFile(rout,"recreate");

  hist_muValue     = new TH1F("hist_muValue",     "",  50, 0.0, 100.0);
  hist_lumiBlk     = new TH1F("hist_lumiBlk",     "", 100, 0.0,1500.0);
  hist_numVtx      = new TH1F("hist_numVtx",      "",  50,-0.5,  49.5);
  hist_numJet      = new TH1F("hist_numJet",      "",  20,-0.5,  19.5);
  hist_numJetjvt   = new TH1F("hist_numJetjvt",   "",  20,-0.5,  19.5);
  hist_muon_pt1    = new TH1F("hist_muon_pt1",    "",  60, 0.0, 120.0);
  hist_muon_eta1   = new TH1F("hist_muon_eta1",   "",  50,-2.5,   2.5);
  hist_muon_pt2    = new TH1F("hist_muon_pt2",    "",  60, 0.0, 120.0);
  hist_muon_eta2   = new TH1F("hist_muon_eta2",   "",  50,-2.5,   2.5);
  hist_dimuon_mass = new TH1F("hist_dimuon_mass", "", 100, 0.0, 200.0);
  hist_dimuon_pt   = new TH1F("hist_dimuon_pt",   "", 100, 0.0, 200.0);
  hist_dimuon_eta  = new TH1F("hist_dimuon_eta",  "",  50,-5.0,   5.0);

  hist_trk_num = new TH1F("hist_trk_num","", 200,  0.0, 1000.0); 
  hist_trk_pt  = new TH1F("hist_trk_pt","",  200,  0.0, 50.0); 
  hist_trk_eta = new TH1F("hist_trk_eta","",  56, -2.8, 2.8); 
  hist_trk_phi = new TH1F("hist_trk_phi","",  64,  -TMath::Pi(), TMath::Pi()); 

  hist_trk_qoverp = new TH1F("hist_trk_qoverp", "", 200,  -2e-3,  2e-3); 
  hist_trk_d0     = new TH1F("hist_trk_d0",     "", 100,   -0.2,   0.2); 
  hist_trk_z0     = new TH1F("hist_trk_z0",     "", 100, -200.0, 200.0); 
  hist_trk_deltaZ = new TH1F("hist_trk_deltaZ", "", 100, -5.0, 5.0);

  hist_trk_etaVSphi = new TH2F("hist_trk_etaVSphi", "", 60, -3.0, 3.0, 64, -TMath::Pi(), TMath::Pi()); 

  hist_truth_pt  = new TH1F("hist_truth_pt",  "", 200,    0.0,   50.0); 
  hist_truth_eta = new TH1F("hist_truth_eta", "",  60,   -3.0,    3.0); 
  hist_truth_phi = new TH1F("hist_truth_phi", "",  64,   -3.2,    3.2); 
  hist_truth_d0  = new TH1F("hist_truth_d0",  "", 100,   -0.1,    0.1); 
  hist_truth_z0  = new TH1F("hist_truth_z0",  "", 100, -200.0,  200.0); 

  /* Resolution */
  hist_trk_dpt   = new TH1F("hist_trk_dpt",  "", 100, -5.0, 5.0); 
  hist_trk_dphi  = new TH1F("hist_trk_dphi", "", 100, -5.0, 5.0); 
  hist_trk_deta  = new TH1F("hist_trk_deta", "", 100, -5.0, 5.0); 
  hist_trk_dd0   = new TH1F("hist_trk_dd0",  "", 100, -5.0, 5.0); 
  hist_trk_dz0   = new TH1F("hist_trk_dz0",  "", 100, -5.0, 5.0); 

  /* track properties */
  hist_trk_nPixHits = new TH1F("hist_trk_nPixHits", "", 16, -0.5, 15.5); 
  hist_trk_nSCTHits = new TH1F("hist_trk_nSCTHits", "", 25, -0.5, 24.5); 
  hist_trk_nSiHits  = new TH1F("hist_trk_nSiHits",  "", 30, -0.5, 29.5);

  hist_trk_nGangedPix        = new TH1F("hist_trk_nGangedPix",        "",   8, -0.5,  7.5); 
  hist_trk_nPixLay           = new TH1F("hist_trk_nPixLay",           "",  10, -0.5,  9.5); 
  hist_trk_nPixSharedHits    = new TH1F("hist_trk_nPixSharedHits",    "",   8, -0.5,  7.5); 
  hist_trk_nPixSplitHits     = new TH1F("hist_trk_nPixSplitHits",     "",   8, -0.5,  7.5); 
  hist_trk_nPixOutliers      = new TH1F("hist_trk_nPixOutliers",      "",   8, -0.5,  7.5); 
  hist_trk_nPixHoles         = new TH1F("hist_trk_nPixHoles",         "",   8, -0.5,  7.5); 
  hist_trk_nPixelDeadSensors = new TH1F("hist_trk_nPixelDeadSensors", "",   8, -0.5,  7.5); 
  hist_trk_nSCTSharedHits    = new TH1F("hist_trk_nSCTSharedHits",    "",  11, -0.5, 10.5); 
  hist_trk_nSCTOutliers      = new TH1F("hist_trk_nSCTOutliers",      "",   8, -0.5,  7.5); 
  hist_trk_nSCTHoles         = new TH1F("hist_trk_nSCTHoles",         "",   8, -0.5,  7.5); 
  hist_trk_nSCTDeadSensors   = new TH1F("hist_trk_nSCTDeadSensors",   "",   5, -0.5,  4.5);
  hist_trk_nTRTHits          = new TH1F("hist_trk_nTRTHits",          "",  61, -0.5, 60.5); 
  hist_trk_nTRTOutliers      = new TH1F("hist_trk_nTRTOutliers",      "",  11, -0.5, 10.5); 
  hist_trk_nTRTHoles         = new TH1F("hist_trk_nTRTHoles",         "",  11, -0.5, 10.5); 
  hist_trk_nTRTHTHits        = new TH1F("hist_trk_nTRTHTHits",        "",  31, -0.5, 30.5); 
  hist_trk_chiSqPerDof       = new TH1F("hist_trk_chiSqPerDof",       "", 120,  0.0, 12.0);
  hist_trk_nOutliers         = new TH1F("hist_trk_nOutliers",         "",  20, -0.5, 19.5);
  hist_trk_stdDevChi2OS      = new TH1F("hist_trk_stdDevChi2OS",      "", 100,  0.0, 500.0);
  hist_trk_truthMatchProb    = new TH1F("hist_trk_truthMatchProb",    "", 100,  0.0,  1.0);

  // Cluster study
  hist_IBL_IsEdge            = new TH1F("hist_IBL_IsEdge",            "",   2, -0.5,   1.5); 
  hist_IBL_IsOverflow        = new TH1F("hist_IBL_IsOverflow",        "",   2, -0.5,   1.5); 
  hist_IBL_IsSplit           = new TH1F("hist_IBL_IsSplit",           "",   2, -0.5,   1.5); 
  hist_IBL_L1A               = new TH1F("hist_IBL_L1A",               "",   6, -2.5,   3.5);
  hist_IBL_ToT               = new TH1F("hist_IBL_ToT",               "",  60, -0.5,  59.5); 
  hist_IBL_Charge            = new TH1F("hist_IBL_Charge",            "",  50,  0.0, 100.0); 
  hist_IBL_dEdx              = new TH1F("hist_IBL_dEdx",              "",  50,  0.0,  10.0); 
  hist_IBL_dEdxVsP           = new TH2F("hist_IBL_dEdxVsP",           "", 500,  0.0,5000.0, 200, 0.0, 20.0); 
  hist_IBL_HitSize           = new TH1F("hist_IBL_HitSize",           "",  20,  0.0,  20.0); 
  hist_IBL_HitSizePhi        = new TH1F("hist_IBL_HitSizePhi",        "",  10,  0.0,  20.0); 
  hist_IBL_HitSizeZ          = new TH1F("hist_IBL_HitSizeZ",          "",   8,  0.0,   8.0); 
  hist_IBL_unbiasedResidualX = new TH1F("hist_IBL_unbiasedResidualX", "", 100, -0.3,   0.3);
  hist_IBL_unbiasedResidualY = new TH1F("hist_IBL_unbiasedResidualY", "", 100, -0.5,   0.5);
  hist_IBL_Isolation10x2     = new TH1F("hist_IBL_Isolation10x2",     "",  20,  0.0,  20.0);
  hist_IBL_Isolation20x4     = new TH1F("hist_IBL_Isolation20x4",     "",  20,  0.0,  20.0);
  hist_IBL_numTotalClustersPerModule = new TH1F("hist_IBL_numTotalClustersPerModule", "", 50,0.0, 50.0);
  hist_IBL_numTotalPixelsPerModule   = new TH1F("hist_IBL_numTotalPixelsPerModule",   "", 50,0.0,100.0);
  hist_IBL_LorentzAngle      = new TH2F("hist_IBL_LorentzAngle", "", 50,  0.0, 1.0, 10, 0.0, 20.0);
  hist_IBL_Map               = new TH2F("hist_IBL_Map",          "", 30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
  hist_IBL_MapHit            = new TH2F("hist_IBL_MapHit",       "", 30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
  hist_IBL_MapEta            = new TH1F("hist_IBL_MapEta",       "", 30, -3.0, 3.0);
  hist_IBL_MapHitEta         = new TH1F("hist_IBL_MapHitEta",    "", 30, -3.0, 3.0);

  hist_BLY_IsEdge            = new TH1F("hist_BLY_IsEdge",            "",   2, -0.5,   1.5); 
  hist_BLY_IsOverflow        = new TH1F("hist_BLY_IsOverflow",        "",   2, -0.5,   1.5); 
  hist_BLY_IsSplit           = new TH1F("hist_BLY_IsSplit",           "",   2, -0.5,   1.5); 
  hist_BLY_L1A               = new TH1F("hist_BLY_L1A",               "",   6, -2.5,   3.5);
  hist_BLY_ToT               = new TH1F("hist_BLY_ToT",               "", 100, -0.5, 199.5); 
  hist_BLY_Charge            = new TH1F("hist_BLY_Charge",            "",  60,  0.0, 120.0); 
  hist_BLY_dEdx              = new TH1F("hist_BLY_dEdx",              "",  50,  0.0,  10.0); 
  hist_BLY_dEdxVsP           = new TH2F("hist_BLY_dEdxVsP",           "", 500,  0.0,5000.0, 200, 0.0, 20.0); 
  hist_BLY_HitSize           = new TH1F("hist_BLY_HitSize",           "",  20,  0.0,  20.0); 
  hist_BLY_HitSizePhi        = new TH1F("hist_BLY_HitSizePhi",        "",  10,  0.0,  20.0); 
  hist_BLY_HitSizeZ          = new TH1F("hist_BLY_HitSizeZ",          "",   8,  0.0,   8.0); 
  hist_BLY_unbiasedResidualX = new TH1F("hist_BLY_unbiasedResidualX", "", 100, -0.3,   0.3);
  hist_BLY_unbiasedResidualY = new TH1F("hist_BLY_unbiasedResidualY", "", 100, -0.5,   0.5);
  hist_BLY_Isolation10x2     = new TH1F("hist_BLY_Isolation10x2",     "",  20,  0.0,  20.0);
  hist_BLY_Isolation20x4     = new TH1F("hist_BLY_Isolation20x4",     "",  20,  0.0,  20.0);
  hist_BLY_numTotalClustersPerModule = new TH1F("hist_BLY_numTotalClustersPerModule", "", 50.0,0.0, 50.0);
  hist_BLY_numTotalPixelsPerModule   = new TH1F("hist_BLY_numTotalPixelsPerModule",   "", 50.0,0.0,100.0);
  hist_BLY_LorentzAngle      = new TH2F("hist_BLY_LorentzAngle", "", 50,  0.0, 1.0, 10, 0.0, 20.0);
  hist_BLY_Map               = new TH2F("hist_BLY_Map",          "", 30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
  hist_BLY_MapHit            = new TH2F("hist_BLY_MapHit",       "", 30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
  hist_BLY_MapEta            = new TH1F("hist_BLY_MapEta",       "", 30, -3.0, 3.0);
  hist_BLY_MapHitEta         = new TH1F("hist_BLY_MapHitEta",    "", 30, -3.0, 3.0);

  hist_LY1_IsEdge            = new TH1F("hist_LY1_IsEdge",     "",   2, -0.5, 1.5); 
  hist_LY1_IsOverflow        = new TH1F("hist_LY1_IsOverflow", "",   2, -0.5, 1.5); 
  hist_LY1_IsSplit           = new TH1F("hist_LY1_IsSplit",    "",   2, -0.5, 1.5); 
  hist_LY1_L1A               = new TH1F("hist_LY1_L1A",        "",   6, -2.5, 3.5);
  hist_LY1_ToT               = new TH1F("hist_LY1_ToT",        "", 100, -0.5, 199.5); 
  hist_LY1_Charge            = new TH1F("hist_LY1_Charge",     "",  60,  0.0, 120.0); 
  hist_LY1_dEdx              = new TH1F("hist_LY1_dEdx",       "",  50,  0.0, 10.0); 
  hist_LY1_dEdxVsP           = new TH2F("hist_LY1_dEdxVsP",    "", 500,  0.0, 5000.0, 200, 0.0, 20.0); 
  hist_LY1_HitSize           = new TH1F("hist_LY1_HitSize",    "",  20,  0.0, 20.0); 
  hist_LY1_HitSizePhi        = new TH1F("hist_LY1_HitSizePhi", "",  10,  0.0, 20.0); 
  hist_LY1_HitSizeZ          = new TH1F("hist_LY1_HitSizeZ",   "",   8,  0.0,  8.0); 
  hist_LY1_unbiasedResidualX = new TH1F("hist_LY1_unbiasedResidualX", "", 100, -0.3, 0.3);
  hist_LY1_unbiasedResidualY = new TH1F("hist_LY1_unbiasedResidualY", "", 100, -0.5, 0.5);
  hist_LY1_Isolation10x2     = new TH1F("hist_LY1_Isolation10x2",     "", 20,   0.0, 20.0);
  hist_LY1_Isolation20x4     = new TH1F("hist_LY1_Isolation20x4",     "", 20,   0.0, 20.0);
  hist_LY1_numTotalClustersPerModule = new TH1F("hist_LY1_numTotalClustersPerModule", "", 50, 0.0,  50.0);
  hist_LY1_numTotalPixelsPerModule   = new TH1F("hist_LY1_numTotalPixelsPerModule",   "", 50, 0.0, 100.0);
  hist_LY1_LorentzAngle      = new TH2F("hist_LY1_LorentzAngle", "",  50,  0.0, 1.0, 10, 0.0, 20.0);
  hist_LY1_Map               = new TH2F("hist_LY1_Map",          "",  30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
  hist_LY1_MapHit            = new TH2F("hist_LY1_MapHit",       "",  30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
  hist_LY1_MapEta            = new TH1F("hist_LY1_MapEta",       "",  30, -3.0, 3.0);
  hist_LY1_MapHitEta         = new TH1F("hist_LY1_MapHitEta",    "",  30, -3.0, 3.0);

  hist_LY2_IsEdge            = new TH1F("hist_LY2_IsEdge",            "",   2, -0.5,   1.5); 
  hist_LY2_IsOverflow        = new TH1F("hist_LY2_IsOverflow",        "",   2, -0.5,   1.5); 
  hist_LY2_IsSplit           = new TH1F("hist_LY2_IsSplit",           "",   2, -0.5,   1.5); 
  hist_LY2_L1A               = new TH1F("hist_LY2_L1A",               "",   6, -2.5,   3.5);
  hist_LY2_ToT               = new TH1F("hist_LY2_ToT",               "", 100, -0.5, 199.5); 
  hist_LY2_Charge            = new TH1F("hist_LY2_Charge",            "",  60,  0.0, 120.0); 
  hist_LY2_dEdx              = new TH1F("hist_LY2_dEdx",              "",  50,  0.0,  10.0); 
  hist_LY2_dEdxVsP           = new TH2F("hist_LY2_dEdxVsP",           "", 500,  0.0,5000.0, 200, 0.0, 20.0); 
  hist_LY2_HitSize           = new TH1F("hist_LY2_HitSize",           "",  20,  0.0,  20.0); 
  hist_LY2_HitSizePhi        = new TH1F("hist_LY2_HitSizePhi",        "",  10,  0.0,  20.0); 
  hist_LY2_HitSizeZ          = new TH1F("hist_LY2_HitSizeZ",          "",   8,  0.0,   8.0); 
  hist_LY2_unbiasedResidualX = new TH1F("hist_LY2_unbiasedResidualX", "", 100, -0.3,   0.3);
  hist_LY2_unbiasedResidualY = new TH1F("hist_LY2_unbiasedResidualY", "", 100, -0.5,   0.5);
  hist_LY2_Isolation10x2     = new TH1F("hist_LY2_Isolation10x2",     "",  20,  0.0,  20.0);
  hist_LY2_Isolation20x4     = new TH1F("hist_LY2_Isolation20x4",     "",  20,  0.0,  20.0);
  hist_LY2_numTotalClustersPerModule = new TH1F("hist_LY2_numTotalClustersPerModule", "", 50, 0.0,  50.0);
  hist_LY2_numTotalPixelsPerModule   = new TH1F("hist_LY2_numTotalPixelsPerModule",   "", 50, 0.0, 100.0);
  hist_LY2_LorentzAngle      = new TH2F("hist_LY2_LorentzAngle", "",  50,  0.0, 1.0, 10, 0.0, 20.0);
  hist_LY2_Map               = new TH2F("hist_LY2_Map",          "",  30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
  hist_LY2_MapHit            = new TH2F("hist_LY2_MapHit",       "",  30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
  hist_LY2_MapEta            = new TH1F("hist_LY2_MapEta",       "",  30, -3.0, 3.0);
  hist_LY2_MapHitEta         = new TH1F("hist_LY2_MapHitEta",    "",  30, -3.0, 3.0);

  hist_END_IsEdge            = new TH1F("hist_END_IsEdge",            "",   2, -0.5,   1.5); 
  hist_END_IsOverflow        = new TH1F("hist_END_IsOverflow",        "",   2, -0.5,   1.5); 
  hist_END_IsSplit           = new TH1F("hist_END_IsSplit",           "",   2, -0.5,   1.5); 
  hist_END_L1A               = new TH1F("hist_END_L1A",               "",   6, -2.5,   3.5);
  hist_END_ToT               = new TH1F("hist_END_ToT",               "", 100, -0.5, 199.5); 
  hist_END_Charge            = new TH1F("hist_END_Charge",            "",  60,  0.0, 120.0); 
  hist_END_dEdx              = new TH1F("hist_END_dEdx",              "",  50,  0.0,  10.0); 
  hist_END_dEdxVsP           = new TH2F("hist_END_dEdxVsP",           "", 500,  0.0,5000.0, 200, 0.0, 20.0); 
  hist_END_HitSize           = new TH1F("hist_END_HitSize",           "",  20,  0.0,  20.0); 
  hist_END_HitSizePhi        = new TH1F("hist_END_HitSizePhi",        "",  10,  0.0,  20.0); 
  hist_END_HitSizeZ          = new TH1F("hist_END_HitSizeZ",          "",   8,  0.0,   8.0); 
  hist_END_unbiasedResidualX = new TH1F("hist_END_unbiasedResidualX", "", 100, -0.3,   0.3);
  hist_END_unbiasedResidualY = new TH1F("hist_END_unbiasedResidualY", "", 100, -0.5,   0.5);
  hist_END_Isolation10x2     = new TH1F("hist_END_Isolation10x2",     "",  20,  0.0,  20.0);
  hist_END_Isolation20x4     = new TH1F("hist_END_Isolation20x4",     "",  20,  0.0,  20.0);
  hist_END_numTotalClustersPerModule = new TH1F("hist_END_numTotalClustersPerModule", "", 50, 0.0,  50.0);
  hist_END_numTotalPixelsPerModule   = new TH1F("hist_END_numTotalPixelsPerModule",   "", 50, 0.0, 100.0);
  hist_END_LorentzAngle      = new TH2F("hist_END_LorentzAngle", "",  50,  0.0, 1.0, 10, 0.0, 20.0);
  hist_ED1_Map               = new TH2F("hist_ED1_Map",          "",  30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
  hist_ED1_MapHit            = new TH2F("hist_ED1_MapHit",       "",  30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
  hist_ED1_MapEta            = new TH1F("hist_ED1_MapEta",       "",  30, -3.0, 3.0);
  hist_ED1_MapHitEta         = new TH1F("hist_ED1_MapHitEta",    "",  30, -3.0, 3.0);
  hist_ED2_3Map              = new TH2F("hist_ED2_3Map",         "",  30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
  hist_ED2_3MapHit           = new TH2F("hist_ED2_3MapHit",      "",  30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
  hist_ED2_3MapEta           = new TH1F("hist_ED2_3MapEta",      "",  30, -3.0, 3.0);
  hist_ED2_3MapHitEta        = new TH1F("hist_ED2_3MapHitEta",   "",  30, -3.0, 3.0);

  hist_ALL_dEdx              = new TH1F("hist_ALL_dEdx",              "",  50,  0.0,  10.0); 
  hist_ALL_dEdxVsP           = new TH2F("hist_ALL_dEdxVsP",           "", 500,  0.0,5000.0, 200, 0.0, 20.0); 
}

void ZmumuAnalysis::execute() {

  Long64_t nentries = fChain->GetEntriesFast();

  cout << "Total Number of Evetns = " << nentries << endl;

  Int_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = fChain->LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;

    if (jentry%1000==0) { cout << jentry << " events processed..." << endl; }

    //================
    // Fill histogram
    //================
    float histWeight = 1.0;
    if (mcFlag) { histWeight*=pileupWeight*mcWeight; }

    hist_muValue -> Fill(averagePU,histWeight);

    hist_lumiBlk     -> Fill(1.0*lumiBlock,histWeight);
    hist_numVtx      -> Fill(1.0*numVtx,histWeight);

    TLorentzVector muon1,muon2,Zboson;
    muon1.SetPtEtaPhiE((*muonPt)[0],(*muonEta)[0],(*muonPhi)[0],(*muonE)[0]);
    muon2.SetPtEtaPhiE((*muonPt)[1],(*muonEta)[1],(*muonPhi)[1],(*muonE)[1]);
    Zboson = muon1 + muon2;

    hist_muon_pt1    -> Fill(muon1.Pt(),histWeight);
    hist_muon_eta1   -> Fill(muon1.Eta(),histWeight);
    hist_muon_pt2    -> Fill(muon2.Pt(),histWeight);
    hist_muon_eta2   -> Fill(muon2.Eta(),histWeight);
    hist_dimuon_mass -> Fill(Zboson.M(),histWeight);
    hist_dimuon_pt   -> Fill(Zboson.Pt(),histWeight);
    hist_dimuon_eta  -> Fill(Zboson.Eta(),histWeight);

    int numJets = (int)(*jetPt).size();
    int numJetJVT = 0;
    for (int i=0; i<numJets; i++) {
      if (TMath::Abs((*jetEta)[i])<2.4) {
        if ((*jetPt)[i]<60.0) {
          if ((*jetPassJVT)[i]==1) { numJetJVT++; }
        }
        else {
          numJetJVT++;
        }
      }
      else if (TMath::Abs((*jetEta)[i])>2.5) {
        if ((*jetPt)[i]<50.0) {
          if ((*jetPassJVT)[i]==1) { numJetJVT++; }
        }
        else {
          numJetJVT++;
        }
      }
      else {
        if ((*jetPt)[i]>60.0) {
          numJetJVT++;
        }
      }
    }
    hist_numJet    -> Fill(1.0*numJets,histWeight);
    hist_numJetjvt -> Fill(1.0*numJetJVT,histWeight);


    int numTracks = (int)(*trackPt).size();
    hist_trk_num -> Fill(1.0*numTracks,histWeight);
    for (int i=0; i<numTracks; i++) {

//      if (mcFlag && TMath::Abs((*truepdgid)[i])==0) { continue; }  // select particle ID

//      if ((*trackClass)[i]!=0) { continue; }   // other track
//      if ((*trackClass)[i]!=1) { continue; }   // muon track
//      if ((*trackClass)[i]!=2) { continue; }   // jet track

      // Loose track selection
      bool trackSel = false;
      if ((TMath::Abs((*trackEta)[i])<=1.65 && (*trackNSCTHits)[i]>=6) || (TMath::Abs((*trackEta)[i])>1.65 && (*trackNSCTHits)[i]>=8)) { trackSel=true; }
      if (!trackSel) { continue; }

      //==================
      // Efficiency check
      //==================
      if ((*trackPt)[i]>2.0 && TMath::Abs((*trackDeltaZSinTheta)[i])<3.0 && (*nPixelDeadSensors)[i]==0) {
        // IBL hit efficiency
        if ((*trackNBLHits)[i]>0 && (*trackNL1Hits)[i]>0 && (*trackNL2Hits)[i]>0) {
          hist_IBL_Map         -> Fill((*trackEta)[i],(*trackPhi)[i],histWeight);
          hist_IBL_MapEta      -> Fill((*trackEta)[i],histWeight);
          if ((*trackNIBLHits)[i]>0) {
            hist_IBL_MapHit    -> Fill((*trackEta)[i],(*trackPhi)[i],histWeight);
            hist_IBL_MapHitEta -> Fill((*trackEta)[i],histWeight);
          }
        }

        // B-layer hit efficiency
        if ((*trackNIBLHits)[i]>0 && (*trackNL1Hits)[i]>0 && (*trackNL2Hits)[i]>0) {
          hist_BLY_Map         -> Fill((*trackEta)[i],(*trackPhi)[i],histWeight);
          hist_BLY_MapEta      -> Fill((*trackEta)[i],histWeight);
          if ((*trackNBLHits)[i]>0) {
            hist_BLY_MapHit    -> Fill((*trackEta)[i],(*trackPhi)[i],histWeight);
            hist_BLY_MapHitEta -> Fill((*trackEta)[i],histWeight);
          }
        }

        // L1 hit efficiency
        if ((*trackNIBLHits)[i]>0 && (*trackNBLHits)[i]>0 && (*trackNL2Hits)[i]>0) {
          hist_LY1_Map         -> Fill((*trackEta)[i],(*trackPhi)[i],histWeight);
          hist_LY1_MapEta      -> Fill((*trackEta)[i],histWeight);
          if ((*trackNL1Hits)[i]>0) {
            hist_LY1_MapHit    -> Fill((*trackEta)[i],(*trackPhi)[i],histWeight);
            hist_LY1_MapHitEta -> Fill((*trackEta)[i],histWeight);
          }
        }

        // L2 hit efficiency
        if ((*trackNIBLHits)[i]>0 && (*trackNBLHits)[i]>0 && (*trackNL1Hits)[i]>0) {
          hist_LY2_Map         -> Fill((*trackEta)[i],(*trackPhi)[i],histWeight);
          hist_LY2_MapEta      -> Fill((*trackEta)[i],histWeight);
          if ((*trackNL2Hits)[i]>0) {
            hist_LY2_MapHit    -> Fill((*trackEta)[i],(*trackPhi)[i],histWeight);
            hist_LY2_MapHitEta -> Fill((*trackEta)[i],histWeight);
          }
        }

        // Endcap hit efficiency
        if ((*trackNIBLHits)[i]>0) {
          if ((*trackNL1Hits)[i]>0) { // Disk-1
            hist_ED1_Map         -> Fill((*trackEta)[i],(*trackPhi)[i],histWeight);
            hist_ED1_MapEta      -> Fill((*trackEta)[i],histWeight);
            if ((*trackNECHits)[i]>0) {
              hist_ED1_MapHit    -> Fill((*trackEta)[i],(*trackPhi)[i],histWeight);
              hist_ED1_MapHitEta -> Fill((*trackEta)[i],histWeight);
            }
          }
        }
      }

      //===============================
      // Lorentz angle and dE/dx study
      //===============================

      // Track quality
      if ((*trackNPixelHits)[i]<4)     { continue; }
      if ((*trackNPixelHoles)[i]>0)    { continue; }
      if ((*nPixelDeadSensors)[i]>0)   { continue; }
      if ((*trackNPixelOutliers)[i]>0) { continue; }
      if ((*nPixelShared)[i]>0)        { continue; }
      if ((*nPixelSplit)[i]>0)         { continue; } 
      if ((*nPixelGanged)[i]>0)        { continue; }

      // Pixel hit multiplicity
      bool pixelHit = false;
      if      ((*trackNIBLHits)[i]>0 && (*trackNBLHits)[i]>0 && (*trackNL1Hits)[i]>0 && (*trackNL2Hits)[i]>0) { pixelHit=true; }
      else if ((*trackNIBLHits)[i]>0 && (*trackNECHits)[i]>1) { pixelHit=true; }
      if (!pixelHit) { continue; }

      // Cluster should not contain edge pixels
      int isEdge = 0;
      for (int j=0; j<(int)(*hitLayer)[i].size(); j++) { isEdge+=(*hitIsEdge)[i][j]; }
      if (isEdge>0) { continue; }

      // Cluster should not contain overflow pixels
      int isOverflow = 0;
      for (int j=0; j<(int)(*hitLayer)[i].size(); j++) { isOverflow+=(*hitIsOverflow)[i][j]; }
      if (isOverflow>0) { continue; }

      // Cluster should not contain split state
      int isSplit = 0;
      for (int j=0; j<(int)(*hitLayer)[i].size(); j++) { isSplit+=(*hitIsSplit)[i][j]; }
      if (isSplit>0) { continue; }

      // Strong isolation
      int iso20x4 = 0;
      for (int j=0; j<(int)(*hitLayer)[i].size(); j++) { iso20x4+=(*hitIsolation20x4)[i][j]; }
      if (iso20x4>0) { continue; }

      // Cut on angle alpha
      bool isAlphaCut = false;
      for (int j=0; j<(int)(*hitLayer)[i].size(); j++) {
        float alpha = TMath::ATan(TMath::Sqrt(TMath::Power(TMath::Tan((*trkThetaOnSurface)[i][j]),2)+TMath::Power(TMath::Tan((*trkPhiOnSurface)[i][j]),2)));
        if (TMath::Cos(alpha)<0.16) { isAlphaCut=true; break; }
      }
      if (isAlphaCut) { continue; }

      // Exclude 3D sensor since no Lorentz angle, different thickness (230um) than IBL
      bool exclude3D = false;
      for (int j=0; j<(int)(*hitLayer)[i].size(); j++) {
        if ((*hitIsEndCap)[i][j]==0 && (*hitLayer)[i][j]==0) {  // IBL
          if ((*hitEtaModule)[i][j]>5)  { exclude3D=true; break; }
          if ((*hitEtaModule)[i][j]<-6) { exclude3D=true; break; }
        }
      }
      if (exclude3D) { continue; }

      // Exclude small hit ToT<10 for pixel (not IBL)
      bool excludeSmallToT = false;
      for (int j=0; j<(int)(*hitLayer)[i].size(); j++) {
        if ((*hitIsEndCap)[i][j]==0 && (*hitLayer)[i][j]>0) {  // Barrel NOT IBL
          if ((*hitToT)[i][j]<10) { excludeSmallToT=true; break; }
        }
      }
      if (excludeSmallToT) { continue; }


      hist_trk_pt  -> Fill((*trackPt)[i],histWeight);
      hist_trk_eta -> Fill((*trackEta)[i],histWeight);
      hist_trk_phi -> Fill((*trackPhi)[i],histWeight);

      hist_trk_qoverp -> Fill((*trackqOverP)[i],histWeight);
      hist_trk_d0     -> Fill((*trackD0)[i],histWeight);
      hist_trk_z0     -> Fill((*trackZ0)[i],histWeight);
      hist_trk_deltaZ -> Fill((*trackDeltaZSinTheta)[i],histWeight);

      hist_trk_etaVSphi -> Fill((*trackEta)[i],(*trackPhi)[i],histWeight);

      if (mcFlag && (*truepdgid)[i]!=0) {
        hist_truth_pt  -> Fill((*truePt)[i],histWeight);
        hist_truth_eta -> Fill((*trueEta)[i],histWeight);
        hist_truth_phi -> Fill((*truePhi)[i],histWeight);
        hist_truth_d0  -> Fill((*trued0)[i],histWeight);
        hist_truth_z0  -> Fill((*truez0)[i],histWeight);

        /* Resolution */
        hist_trk_dpt   -> Fill(1.0*((*trackPt)[i]-(*truePt)[i])/(*truePt)[i],histWeight);
        hist_trk_dphi  -> Fill(((*trackPhi)[i]-(*truePhi)[i])/(*truePhi)[i],histWeight);
        hist_trk_deta  -> Fill(((*trackEta)[i]-(*trueEta)[i])/(*trueEta)[i],histWeight);
        hist_trk_dd0   -> Fill(((*trackD0)[i]-(*trued0)[i])/(*trued0)[i],histWeight);
        hist_trk_dz0   -> Fill(((*trackZ0)[i]-(*truez0)[i])/(*truez0)[i],histWeight);
        hist_trk_truthMatchProb -> Fill((*truthmatchprob)[i],histWeight);
      }

      /* track properties */
      hist_trk_nPixHits -> Fill(1.0*(*trackNPixelHits)[i],histWeight);
      hist_trk_nSCTHits -> Fill(1.0*(*trackNSCTHits)[i],histWeight);
      hist_trk_nSiHits  -> Fill(1.0*((*trackNPixelHits)[i]+(*trackNSCTHits)[i]),histWeight);

      hist_trk_nGangedPix        -> Fill(1.0*(*nPixelGanged)[i],histWeight);
      hist_trk_nPixLay           -> Fill(1.0*(*trackNPixelLayers)[i],histWeight);
      hist_trk_nPixSharedHits    -> Fill(1.0*(*nPixelShared)[i],histWeight);
      hist_trk_nPixSplitHits     -> Fill(1.0*(*nPixelSplit)[i],histWeight);
      hist_trk_nPixOutliers      -> Fill(1.0*(*trackNPixelOutliers)[i],histWeight);
      hist_trk_nPixHoles         -> Fill(1.0*(*trackNPixelHoles)[i],histWeight);
      hist_trk_nPixelDeadSensors -> Fill(1.0*(*nPixelDeadSensors)[i],histWeight);
      hist_trk_nSCTSharedHits    -> Fill(1.0*(*trackNSCTSharedHits)[i],histWeight);
      hist_trk_nSCTOutliers      -> Fill(1.0*(*nSCTOutliers)[i],histWeight);
      hist_trk_nSCTHoles         -> Fill(1.0*(*trackNSCTHoles)[i],histWeight);
      hist_trk_nSCTDeadSensors   -> Fill(1.0*(*nSCTDeadSensors)[i],histWeight);
      hist_trk_nTRTHits          -> Fill(1.0*(*trackNTRTHits)[i],histWeight);
      hist_trk_nTRTOutliers      -> Fill(1.0*(*nTRTOutliers)[i],histWeight);
      hist_trk_nTRTHoles         -> Fill(1.0*(*nTRTHoles)[i],histWeight);
      hist_trk_nTRTHTHits        -> Fill(1.0*(*nTRTHTHits)[i],histWeight);
      hist_trk_chiSqPerDof       -> Fill((*trackChiSqPerDof)[i],histWeight);
      hist_trk_nOutliers         -> Fill(1.0*(*trackOutliers)[i],histWeight);
      hist_trk_stdDevChi2OS      -> Fill((*trackStdDevChi2OS)[i],histWeight);

      float energyPair   = 3.62e-6;   // Electron-hole pair creation energy  e-h/[MeV]
      float siDensity    = 2.329;     // Silicon density [g/cm^3]
      float thicknessIBL = 0.0200;    // thickness for IBL [cm]
      float thicknessPIX = 0.0250;    // thickness for PIXEL [cm]

      // Cluster study
      float sumdE = 0.0;
      float sumdx = 0.0;
      for (int j=0; j<(int)(*hitLayer)[i].size(); j++) {
        float alpha = TMath::ATan(TMath::Sqrt(TMath::Power(TMath::Tan((*trkThetaOnSurface)[i][j]),2)+TMath::Power(TMath::Tan((*trkPhiOnSurface)[i][j]),2)));  // incidence angle 3D

        if ((*hitIsEndCap)[i][j]==0 && (*hitLayer)[i][j]==0) {  // IBL
          hist_IBL_IsEdge            -> Fill(1.0*(*hitIsEdge)[i][j],histWeight);
          hist_IBL_IsOverflow        -> Fill(1.0*(*hitIsOverflow)[i][j],histWeight);
          hist_IBL_IsSplit           -> Fill(1.0*(*hitIsSplit)[i][j],histWeight);
          hist_IBL_L1A               -> Fill(1.0*(*hitLVL1A)[i][j],histWeight);
          hist_IBL_ToT               -> Fill(1.0*(*hitToT)[i][j],histWeight);
          hist_IBL_Charge            -> Fill((*hitCharge)[i][j]/1000.0,histWeight);
          hist_IBL_dEdx              -> Fill((*hitCharge)[i][j]*energyPair/thicknessIBL/siDensity*TMath::Cos(alpha),histWeight);
          hist_IBL_dEdxVsP           -> Fill(1.0/TMath::Abs((*trackqOverP)[i]),(*hitCharge)[i][j]*energyPair/thicknessIBL/siDensity*TMath::Cos(alpha),histWeight);
          hist_IBL_HitSize           -> Fill(1.0*(*hitNPixel)[i][j],histWeight);
          hist_IBL_HitSizePhi        -> Fill(1.0*(*hitNPixelX)[i][j],histWeight);
          hist_IBL_HitSizeZ          -> Fill(1.0*(*hitNPixelY)[i][j],histWeight);
          hist_IBL_unbiasedResidualX -> Fill((*unbiasedResidualX)[i][j],histWeight);
          hist_IBL_unbiasedResidualY -> Fill((*unbiasedResidualY)[i][j],histWeight);
          hist_IBL_Isolation10x2     -> Fill(1.0*(*hitIsolation10x2)[i][j],histWeight);
          hist_IBL_Isolation20x4     -> Fill(1.0*(*hitIsolation20x4)[i][j],histWeight);
          hist_IBL_numTotalClustersPerModule -> Fill(1.0*(*numTotalClustersPerModule)[i][j],histWeight);
          hist_IBL_numTotalPixelsPerModule   -> Fill(1.0*(*numTotalPixelsPerModule)[i][j],histWeight);
          hist_IBL_LorentzAngle      -> Fill((*trkPhiOnSurface)[i][j],1.0*(*hitNPixelX)[i][j],histWeight);
          sumdE += (*hitCharge)[i][j]*energyPair/siDensity;
          sumdx += thicknessIBL/TMath::Cos(alpha);
        }
        else if ((*hitIsEndCap)[i][j]==0 && (*hitLayer)[i][j]==1) {  // b-layer
          hist_BLY_IsEdge            -> Fill(1.0*(*hitIsEdge)[i][j],histWeight);
          hist_BLY_IsOverflow        -> Fill(1.0*(*hitIsOverflow)[i][j],histWeight);
          hist_BLY_IsSplit           -> Fill(1.0*(*hitIsSplit)[i][j],histWeight);
          hist_BLY_L1A               -> Fill(1.0*(*hitLVL1A)[i][j],histWeight);
          hist_BLY_ToT               -> Fill(1.0*(*hitToT)[i][j],histWeight);
          hist_BLY_Charge            -> Fill((*hitCharge)[i][j]/1000.0,histWeight);
          hist_BLY_dEdx              -> Fill((*hitCharge)[i][j]*energyPair/thicknessPIX/siDensity*TMath::Cos(alpha),histWeight);
          hist_BLY_dEdxVsP           -> Fill(1.0/TMath::Abs((*trackqOverP)[i]),(*hitCharge)[i][j]*energyPair/thicknessIBL/siDensity*TMath::Cos(alpha),histWeight);
          hist_BLY_HitSize           -> Fill(1.0*(*hitNPixel)[i][j],histWeight);
          hist_BLY_HitSizePhi        -> Fill(1.0*(*hitNPixelX)[i][j],histWeight);
          hist_BLY_HitSizeZ          -> Fill(1.0*(*hitNPixelY)[i][j],histWeight);
          hist_BLY_unbiasedResidualX -> Fill((*unbiasedResidualX)[i][j],histWeight);
          hist_BLY_unbiasedResidualY -> Fill((*unbiasedResidualY)[i][j],histWeight);
          hist_BLY_Isolation10x2     -> Fill(1.0*(*hitIsolation10x2)[i][j],histWeight);
          hist_BLY_Isolation20x4     -> Fill(1.0*(*hitIsolation20x4)[i][j],histWeight);
          hist_BLY_numTotalClustersPerModule -> Fill(1.0*(*numTotalClustersPerModule)[i][j],histWeight);
          hist_BLY_numTotalPixelsPerModule   -> Fill(1.0*(*numTotalPixelsPerModule)[i][j],histWeight);
          hist_BLY_LorentzAngle      -> Fill((*trkPhiOnSurface)[i][j],1.0*(*hitNPixelX)[i][j],histWeight);
          sumdE += (*hitCharge)[i][j]*energyPair/siDensity;
          sumdx += thicknessPIX/TMath::Cos(alpha);
        }
        else if ((*hitIsEndCap)[i][j]==0 && (*hitLayer)[i][j]==2) {  // Layer-1
          hist_LY1_IsEdge            -> Fill(1.0*(*hitIsEdge)[i][j],histWeight);
          hist_LY1_IsOverflow        -> Fill(1.0*(*hitIsOverflow)[i][j],histWeight);
          hist_LY1_IsSplit           -> Fill(1.0*(*hitIsSplit)[i][j],histWeight);
          hist_LY1_L1A               -> Fill(1.0*(*hitLVL1A)[i][j],histWeight);
          hist_LY1_ToT               -> Fill(1.0*(*hitToT)[i][j],histWeight);
          hist_LY1_Charge            -> Fill((*hitCharge)[i][j]/1000.0,histWeight);
          hist_LY1_dEdx              -> Fill((*hitCharge)[i][j]*energyPair/thicknessPIX/siDensity*TMath::Cos(alpha),histWeight);
          hist_LY1_dEdxVsP           -> Fill(1.0/TMath::Abs((*trackqOverP)[i]),(*hitCharge)[i][j]*energyPair/thicknessIBL/siDensity*TMath::Cos(alpha),histWeight);
          hist_LY1_HitSize           -> Fill(1.0*(*hitNPixel)[i][j],histWeight);
          hist_LY1_HitSizePhi        -> Fill(1.0*(*hitNPixelX)[i][j],histWeight);
          hist_LY1_HitSizeZ          -> Fill(1.0*(*hitNPixelY)[i][j],histWeight);
          hist_LY1_unbiasedResidualX -> Fill((*unbiasedResidualX)[i][j],histWeight);
          hist_LY1_unbiasedResidualY -> Fill((*unbiasedResidualY)[i][j],histWeight);
          hist_LY1_Isolation10x2     -> Fill(1.0*(*hitIsolation10x2)[i][j],histWeight);
          hist_LY1_Isolation20x4     -> Fill(1.0*(*hitIsolation20x4)[i][j],histWeight);
          hist_LY1_numTotalClustersPerModule -> Fill(1.0*(*numTotalClustersPerModule)[i][j],histWeight);
          hist_LY1_numTotalPixelsPerModule   -> Fill(1.0*(*numTotalPixelsPerModule)[i][j],histWeight);
          hist_LY1_LorentzAngle      -> Fill((*trkPhiOnSurface)[i][j],1.0*(*hitNPixelX)[i][j],histWeight);
          sumdE += (*hitCharge)[i][j]*energyPair/siDensity;
          sumdx += thicknessPIX/TMath::Cos(alpha);
        }
        else if ((*hitIsEndCap)[i][j]==0 && (*hitLayer)[i][j]==3) {  // Layer-2
          hist_LY2_IsEdge            -> Fill(1.0*(*hitIsEdge)[i][j],histWeight);
          hist_LY2_IsOverflow        -> Fill(1.0*(*hitIsOverflow)[i][j],histWeight);
          hist_LY2_IsSplit           -> Fill(1.0*(*hitIsSplit)[i][j],histWeight);
          hist_LY2_L1A               -> Fill(1.0*(*hitLVL1A)[i][j],histWeight);
          hist_LY2_ToT               -> Fill(1.0*(*hitToT)[i][j],histWeight);
          hist_LY2_Charge            -> Fill((*hitCharge)[i][j]/1000.0,histWeight);
          hist_LY2_dEdx              -> Fill((*hitCharge)[i][j]*energyPair/thicknessPIX/siDensity*TMath::Cos(alpha),histWeight);
          hist_LY2_dEdxVsP           -> Fill(1.0/TMath::Abs((*trackqOverP)[i]),(*hitCharge)[i][j]*energyPair/thicknessIBL/siDensity*TMath::Cos(alpha),histWeight);
          hist_LY2_HitSize           -> Fill(1.0*(*hitNPixel)[i][j],histWeight);
          hist_LY2_HitSizePhi        -> Fill(1.0*(*hitNPixelX)[i][j],histWeight);
          hist_LY2_HitSizeZ          -> Fill(1.0*(*hitNPixelY)[i][j],histWeight);
          hist_LY2_unbiasedResidualX -> Fill((*unbiasedResidualX)[i][j],histWeight);
          hist_LY2_unbiasedResidualY -> Fill((*unbiasedResidualY)[i][j],histWeight);
          hist_LY2_Isolation10x2     -> Fill(1.0*(*hitIsolation10x2)[i][j],histWeight);
          hist_LY2_Isolation20x4     -> Fill(1.0*(*hitIsolation20x4)[i][j],histWeight);
          hist_LY2_numTotalClustersPerModule -> Fill(1.0*(*numTotalClustersPerModule)[i][j],histWeight);
          hist_LY2_numTotalPixelsPerModule   -> Fill(1.0*(*numTotalPixelsPerModule)[i][j],histWeight);
          hist_LY2_LorentzAngle      -> Fill((*trkPhiOnSurface)[i][j],1.0*(*hitNPixelX)[i][j],histWeight);
          sumdE += (*hitCharge)[i][j]*energyPair/siDensity;
          sumdx += thicknessPIX/TMath::Cos(alpha);
        }
        else if (TMath::Abs((*hitIsEndCap)[i][j])==2) {  // Endcap
          hist_END_IsEdge            -> Fill(1.0*(*hitIsEdge)[i][j],histWeight);
          hist_END_IsOverflow        -> Fill(1.0*(*hitIsOverflow)[i][j],histWeight);
          hist_END_IsSplit           -> Fill(1.0*(*hitIsSplit)[i][j],histWeight);
          hist_END_L1A               -> Fill(1.0*(*hitLVL1A)[i][j],histWeight);
          hist_END_ToT               -> Fill(1.0*(*hitToT)[i][j],histWeight);
          hist_END_Charge            -> Fill((*hitCharge)[i][j]/1000.0,histWeight);
          hist_END_dEdx              -> Fill((*hitCharge)[i][j]*energyPair/thicknessPIX/siDensity*TMath::Cos(alpha),histWeight);
          hist_END_dEdxVsP           -> Fill(1.0/TMath::Abs((*trackqOverP)[i]),(*hitCharge)[i][j]*energyPair/thicknessIBL/siDensity*TMath::Cos(alpha),histWeight);
          hist_END_HitSize           -> Fill(1.0*(*hitNPixel)[i][j],histWeight);
          hist_END_HitSizePhi        -> Fill(1.0*(*hitNPixelX)[i][j],histWeight);
          hist_END_HitSizeZ          -> Fill(1.0*(*hitNPixelY)[i][j],histWeight);
          hist_END_unbiasedResidualX -> Fill((*unbiasedResidualX)[i][j],histWeight);
          hist_END_unbiasedResidualY -> Fill((*unbiasedResidualY)[i][j],histWeight);
          hist_END_Isolation10x2     -> Fill(1.0*(*hitIsolation10x2)[i][j],histWeight);
          hist_END_Isolation20x4     -> Fill(1.0*(*hitIsolation20x4)[i][j],histWeight);
          hist_END_numTotalClustersPerModule -> Fill(1.0*(*numTotalClustersPerModule)[i][j],histWeight);
          hist_END_numTotalPixelsPerModule   -> Fill(1.0*(*numTotalPixelsPerModule)[i][j],histWeight);
          hist_END_LorentzAngle      -> Fill((*trkPhiOnSurface)[i][j],1.0*(*hitNPixelX)[i][j],histWeight);
        }
      }
      hist_ALL_dEdx    -> Fill(sumdE/sumdx,histWeight);
      hist_ALL_dEdxVsP -> Fill(1.0/TMath::Abs((*trackqOverP)[i]),sumdE/sumdx,histWeight);


    }
  }
}

void ZmumuAnalysis::finalize() {
  m_rootFile->Write();
  m_rootFile->Close();
}


