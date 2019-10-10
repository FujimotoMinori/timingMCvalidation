#define MySelector_cxx
// The class definition in MySelector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("MySelector.C")
// root> T->Process("MySelector.C","some options")
// root> T->Process("MySelector.C+")
//


#include "MySelector.h"
#include <TH2.h>
#include <TStyle.h>

void MySelector::Begin(TTree * /*tree*/)
{
    // The Begin() function is called at the start of the query.
    // When running with PROOF Begin() is only called on the client.
    // The tree argument is deprecated (on PROOF 0 is passed).

    TString option = GetOption();
}

void MySelector::SlaveBegin(TTree * /*tree*/)
{
    // The SlaveBegin() function is called after the Begin() function.
    // When running with PROOF SlaveBegin() is called on each slave server.
    // The tree argument is deprecated (on PROOF 0 is passed).

    TString option = GetOption();
    outputfile_ = "output18.root";

    //TH1F
    h_LB= new TH1F("LB", "; LB; ", 100, 0.0, 1500.0);
    hist_trk_num = new TH1F("hist_trk_num",";track number ;", 200,  0.0, 1000.0); 
    hist_trktrue_num = new TH1F("hist_trktrue_num",";truetrack number ;", 200,  0.0, 1000.0); 
    hist_truth_num = new TH1F("hist_truth_num",";truth number ;", 200,  0.0, 1000.0); 
    hist_trk_pt  = new TH1F("hist_trk_pt",";track pt ;",  50,  0.0, 5.0); //200
    hist_true_pt  = new TH1F("hist_true_pt",";truetrack pt ;",  50,  0.0, 5.0); 
    hist_truepass_pt  = new TH1F("hist_truepass_pt",";truepass pt ;",  50,  0.0, 5.0); 
    hist_trk_eta = new TH1F("hist_trk_eta",";track eta;",  56, -2.8, 2.8); 
    hist_true_eta = new TH1F("hist_true_eta",";true eta;",  56, -2.8, 2.8); 
    hist_truepass_eta  = new TH1F("hist_truepass_eta",";truepass eta ;",  56, -2.8, 2.8); 
    hist_trk_phi = new TH1F("hist_trk_phi",";track phi;",  64,  -TMath::Pi(), TMath::Pi()); 
    hist_true_phi = new TH1F("hist_true_phi",";true phi;",  64,  -TMath::Pi(), TMath::Pi()); 
    hist_truepass_phi = new TH1F("hist_truepass_phi",";truepass phi;",  64,  -TMath::Pi(), TMath::Pi()); 
    hist_true_numVtx = new TH1F("hist_true_numVtx",";true numVtx;",  50,  -0.5, 49.5); 
    hist_truepass_numVtx = new TH1F("hist_truepass_numVtx",";truepass numVtx;",  50,  -0.5, 49.5); 
    hist_true_avePU = new TH1F("hist_true_avePU",";true avePU;",  50,  0.5, 100.); 
    hist_truepass_avePU = new TH1F("hist_truepass_avePU",";truepass avePU;",  50,  0.0, 100.); 
    hist_trk_qoverp = new TH1F("hist_trk_qoverp", ";track q/P;", 200,  -2e-3,  2e-3); 
    hist_trk_d0     = new TH1F("hist_trk_d0",     ";track d0;", 100,   -0.2,   0.2); 
    hist_trk_z0     = new TH1F("hist_trk_z0",     ";track z0;", 100, -200.0, 200.0); 
    hist_trk_deltaZ = new TH1F("hist_trk_deltaZ", ";track deltaZ;", 100, -5.0, 5.0);
    h_trackD0Err      = new TH1F("trackD0Err",     ";track d0err;", 100,   -0.2,   0.2); 
    h_trackZ0Err      = new TH1F("trackZ0Err",     ";track z0err;", 100, -20.0, 20.0); 
    h_trackTheta      = new TH1F("trackTheta",";track theta;",  16, 0, TMath::Pi()/2); 
    h_trackCharge     = new TH1F("trackCharge",";track charge;",  60, 0.,120.); 
    h_trackMindR      = new TH1F("trackMindR",";track MindR;",  100, 0.,200.); 
    h_trackClass      = new TH1F("trackClass",";track MindR;",  10, -0.5,10.); 
    h_trackPassCut      = new TH1F("trackPassCut",";track PassCut;",  100, 0.,200.); 
    hist_numVtx                      = new TH1F("hist_numVtx",      "",  50,-0.5,  49.5);

    /* Resolution */
    hist_trk_dpt   = new TH1F("hist_trk_dpt",  "; dpt;", 100, -5.0, 5.0); 
    hist_trk_dphi  = new TH1F("hist_trk_dphi", "; dphi;", 100, -5.0, 5.0); 
    hist_trk_deta  = new TH1F("hist_trk_deta", "; deta;", 100, -5.0, 5.0); 
    hist_trk_dd0   = new TH1F("hist_trk_dd0",  "; dd0;", 100, -5.0, 5.0); 
    hist_trk_dz0   = new TH1F("hist_trk_dz0",  "; dz0;", 100, -5.0, 5.0); 
    /*efficiency*/
    hist_trk_dr   = new TH1F("hist_trk_dr",  "; dr;", 500, 0.0, 0.5); 
    hist_trkeff_pt   = new TH1F("hist_trkeff_pt",  "; pt;tracking efficiency ", 50, 0.0, 5.0); 
    hist_trkeff_eta  = new TH1F("hist_trkeff_eta", "; eta;tracking efficiency ", 56, -2.8, 2.8); 
    hist_trkeff_phi  = new TH1F("hist_trkeff_phi", "; phi;tracking efficiency ", 64,-TMath::Pi(), TMath::Pi()); 
    hist_trkeff_numVtx  = new TH1F("hist_trkeff_numVtx", "; numVtx;tracking efficiency ", 50,-0.5, 49.5); 
    hist_trkeff_avePU  = new TH1F("hist_trkeff_avePU", "; avePU;tracking efficiency ", 50,0.0, 100.); 

    hist_IBL_MapHitEtaeff         = new TH1F("hist_IBL_MapHitEtaeff",    ";eta;hit efficiency(IBl)", 56, -2.8, 2.8);
    hist_BLY_MapHitEtaeff         = new TH1F("hist_BLY_MapHitEtaeff",    ";eta;hit efficiency(blayer)", 56, -2.8, 2.8);
    hist_LY1_MapHitEtaeff         = new TH1F("hist_LY1_MapHitEtaeff",    ";eta;hit efficiency(L1)", 56, -2.8, 2.8);
    hist_LY2_MapHitEtaeff         = new TH1F("hist_LY2_MapHitEtaeff",    ";eta;hit efficiency(L2)", 56, -2.8, 2.8);
    hist_IBL_MapHitEta         = new TH1F("hist_IBL_MapHitEta",    ";eta(IBL);", 56, -2.8, 2.8);
    hist_BLY_MapHitEta         = new TH1F("hist_BLY_MapHitEta",    ";eta(blayer);", 56, -2.8, 2.8);
    hist_LY1_MapHitEta         = new TH1F("hist_LY1_MapHitEta",    ";eta(L1);",  56, -2.8, 2.8);
    hist_LY2_MapHitEta         = new TH1F("hist_LY2_MapHitEta",    ";eta(L2);",  56, -2.8, 2.8);
    hist_IBL_MapEta         = new TH1F("hist_IBL_MapEta",    ";eta(IBL);", 56, -2.8, 2.8);
    hist_BLY_MapEta         = new TH1F("hist_BLY_MapEta",    ";eta(blayer);", 56, -2.8, 2.8);
    hist_LY1_MapEta         = new TH1F("hist_LY1_MapEta",    ";eta(L1);",  56, -2.8, 2.8);
    hist_LY2_MapEta         = new TH1F("hist_LY2_MapEta",    ";eta(L2);",  56, -2.8, 2.8);

    hist_IBL_MapHitPteff         = new TH1F("hist_IBL_MapHitPteff",    ";Pt;hit efficiency(IBl)", 50, 0.0, 5.0);
    hist_BLY_MapHitPteff         = new TH1F("hist_BLY_MapHitPteff",    ";Pt;hit efficiency(blayer)", 50, 0.0, 5.0);
    hist_LY1_MapHitPteff         = new TH1F("hist_LY1_MapHitPteff",    ";Pt;hit efficiency(L1)", 50, 0.0, 5.0);
    hist_LY2_MapHitPteff         = new TH1F("hist_LY2_MapHitPteff",    ";Pt;hit efficiency(L2)", 50, 0.0, 5.0);
    hist_IBL_MapHitPt         = new TH1F("hist_IBL_MapHitPt",    ";Pt(IBL);", 50, 0.0, 5.0);
    hist_BLY_MapHitPt         = new TH1F("hist_BLY_MapHitPt",    ";Pt(blayer);", 50, 0.0, 5.0);
    hist_LY1_MapHitPt         = new TH1F("hist_LY1_MapHitPt",    ";Pt(L1);", 50, 0.0, 5.0);
    hist_LY2_MapHitPt         = new TH1F("hist_LY2_MapHitPt",    ";Pt(L2);", 50, 0.0, 5.0);
    hist_IBL_MapPt         = new TH1F("hist_IBL_MapPt",    ";Pt(IBL);", 50, 0.0, 5.0);
    hist_BLY_MapPt         = new TH1F("hist_BLY_MapPt",    ";Pt(blayer);", 50, 0.0, 5.0);
    hist_LY1_MapPt         = new TH1F("hist_LY1_MapPt",    ";Pt(L1);", 50, 0.0, 5.0);
    hist_LY2_MapPt         = new TH1F("hist_LY2_MapPt",    ";Pt(L2);", 50, 0.0, 5.0);

    hist_IBL_MapHitnumVtxeff         = new TH1F("hist_IBL_MapHitnumVtxeff",    ";numVtx;hit efficiency(IBl)", 50, -0.5, 49.5);
    hist_BLY_MapHitnumVtxeff         = new TH1F("hist_BLY_MapHitnumVtxeff",    ";numVtx;hit efficiency(blayer)", 50, -0.5, 49.5);
    hist_LY1_MapHitnumVtxeff         = new TH1F("hist_LY1_MapHitnumVtxeff",    ";numVtx;hit efficiency(L1)", 50, -0.5, 49.5);
    hist_LY2_MapHitnumVtxeff         = new TH1F("hist_LY2_MapHitnumVtxeff",    ";numVtx;hit efficiency(L2)", 50, -0.5, 49.5);
    hist_IBL_MapHitnumVtx            = new TH1F("hist_IBL_MapHitnumVtx",    ";numVtx(IBL);", 50, -0.5, 49.5);
    hist_BLY_MapHitnumVtx            = new TH1F("hist_BLY_MapHitnumVtx",    ";numVtx(blayer);", 50, -0.5, 49.5);
    hist_LY1_MapHitnumVtx            = new TH1F("hist_LY1_MapHitnumVtx",    ";numVtx(L1);", 50, -0.5, 49.5);
    hist_LY2_MapHitnumVtx            = new TH1F("hist_LY2_MapHitnumVtx",    ";numVtx(L2);", 50, -0.5, 49.5);
    hist_IBL_MapnumVtx            = new TH1F("hist_IBL_MapnumVtx",    ";numVtx(IBL);", 50, -0.5, 49.5);
    hist_BLY_MapnumVtx            = new TH1F("hist_BLY_MapnumVtx",    ";numVtx(blayer);", 50, -0.5, 49.5);
    hist_LY1_MapnumVtx            = new TH1F("hist_LY1_MapnumVtx",    ";numVtx(L1);", 50, -0.5, 49.5);
    hist_LY2_MapnumVtx            = new TH1F("hist_LY2_MapnumVtx",    ";numVtx(L2);", 50, -0.5, 49.5);

    hist_IBL_MapHitavePUeff         = new TH1F("hist_IBL_MapHitavePUeff",    ";averagePU;hit efficiency(IBl)", 50, 0.0, 100.);
    hist_BLY_MapHitavePUeff         = new TH1F("hist_BLY_MapHitavePUeff",    ";averagePU;hit efficiency(blayer)", 50, 0.0, 100.);
    hist_LY1_MapHitavePUeff         = new TH1F("hist_LY1_MapHitavePUeff",    ";averagePU;hit efficiency(L1)", 50, 0.0, 100.);
    hist_LY2_MapHitavePUeff         = new TH1F("hist_LY2_MapHitavePUeff",    ";averagePU;hit efficiency(L2)", 50, 0.0, 100.);
    hist_IBL_MapHitavePU            = new TH1F("hist_IBL_MapHitavePU"   ,    ";averagePU(IBL);", 50, 0.0, 100.);
    hist_BLY_MapHitavePU            = new TH1F("hist_BLY_MapHitavePU"   ,    ";averagePU(blayer);", 50, 0.0, 100.);
    hist_LY1_MapHitavePU            = new TH1F("hist_LY1_MapHitavePU"   ,    ";averagePU(L1);", 50, 0.0, 100.);
    hist_LY2_MapHitavePU            = new TH1F("hist_LY2_MapHitavePU"   ,    ";averagePU(L2);", 50, 0.0, 100.);
    hist_IBL_MapavePU            = new TH1F("hist_IBL_MapavePU"         ,    ";averagePU(IBL);", 50, 0.0, 100.);
    hist_BLY_MapavePU            = new TH1F("hist_BLY_MapavePU"         ,    ";averagePU(blayer);", 50, 0.0, 100.);
    hist_LY1_MapavePU            = new TH1F("hist_LY1_MapavePU"         ,    ";averagePU(L1);", 50, 0.0, 100.);
    hist_LY2_MapavePU            = new TH1F("hist_LY2_MapavePU"         ,    ";averagePU(L2);", 50, 0.0, 100.);
    /* track*/
    hist_trk_nPixHits = new TH1F("hist_trk_nPixHits", ";track nPixHits;", 16, -0.5, 15.5); 
    hist_trk_nGangedPix        = new TH1F("hist_trk_nGangedPix",        ";track nGangedPixel;",   8, -0.5,  7.5); 
    hist_trk_nPixLay           = new TH1F("hist_trk_nPixLay",           ";track nPixLayer;",  10, -0.5,  9.5); 
    hist_trk_nPixSharedHits    = new TH1F("hist_trk_nPixSharedHits",    ";track nPixSharedHits;",   8, -0.5,  7.5); 
    hist_trk_nPixSplitHits     = new TH1F("hist_trk_nPixSplitHits",     ";track nPixlSplitHits;",   8, -0.5,  7.5); 
    hist_trk_nPixOutliers      = new TH1F("hist_trk_nPixOutliers",      ";track nPixOutliers;",   8, -0.5,  7.5); 
    hist_trk_nPixHoles         = new TH1F("hist_trk_nPixHoles",         ";track nPixHoles;",   8, -0.5,  7.5); 
    hist_trk_nPixelDeadSensors = new TH1F("hist_trk_nPixelDeadSensors", ";track nPixDeadSenesors;",   8, -0.5,  7.5); 
    hist_trk_nOutliers         = new TH1F("hist_trk_nOutliers",         ";track nOutliers;",  20, -0.5, 19.5);
    hist_trk_stdDevChi2OS      = new TH1F("hist_trk_stdDevChi2OS",      ";track stdDevChi2OS;", 100,  0.0, 500.0);
    h_trackChiSqPerDof      = new TH1F("trackChiSqPerDof",      ";track ChiSqPerDof;", 100,  0.0, 500.0);
    h_trackNIBLUsedHits      = new TH1F("trackNIBLUsedHits",      ";track NIBLUsedHits;", 100,  0.0, 500.0);
    h_trackNBLUsedHits      = new TH1F("trackNBLUsedHits",      ";track NBLUsedHits;", 100,  0.0, 500.0);
    h_trackNSplitIBLHits      = new TH1F("trackNSplitIBLHits",      ";track NSplitIBLHits;", 100,  0.0, 500.0);
    h_trackNSplitBLHits      = new TH1F("trackNSplitBLHits",      ";track NSplitBLHits;", 100,  0.0, 500.0);
    h_trackNSharedIBLHits      = new TH1F("trackNSharedIBLHits",      ";track NSharedIBLHits;", 100,  0.0, 500.0);
    h_trackNSharedBLHits      = new TH1F("trackNSharedBLHits",      ";track NSharedBLHits;", 100,  0.0, 500.0);
    h_trackNIBLHits      = new TH1F("trackNIBLHits",      ";track NIBLHits;", 100,  0.0, 500.0);
    h_trackNBLHits      = new TH1F("trackNBLHits",      ";track NBLHits;", 100,  0.0, 500.0);
    h_trackNL1Hits      = new TH1F("trackNL1Hits",      ";track NL1Hits;", 100,  0.0, 500.0);
    h_trackNL2Hits      = new TH1F("trackNL2Hits",      ";track NL2Hits;", 100,  0.0, 500.0);
    h_trackNIBLExpectedHits      = new TH1F("trackNIBLExpectedHits",      ";track NIBLExpectedHits;", 100,  0.0, 500.0);
    h_trackNBLExpectedHits      = new TH1F("trackNBLExpectedHits",      ";track NBLExpectedHits;", 100,  0.0, 500.0);

    /* cluster */
    hist_BLY_IsEdge            = new TH1F("hist_BLY_IsEdge",            ";IsEdge(blayer);    ",   2, -0.5,   1.5); 
    hist_BLY_IsOverflow        = new TH1F("hist_BLY_IsOverflow",        ";IsOverflow(blayer);",   2, -0.5,   1.5); 
    hist_BLY_IsSplit           = new TH1F("hist_BLY_IsSplit",           ";IsSplit(blayer);   ",   2, -0.5,   1.5); 
    hist_BLY_L1A               = new TH1F("hist_BLY_L1A",               ";L1A(blayer);       ",   6, -2.5,   3.5);
    hist_BLY_ToT               = new TH1F("hist_BLY_ToT",               ";ToT(blayer);       ", 100, -0.5, 199.5); 
    hist_BLY_Charge            = new TH1F("hist_BLY_Charge",            ";Charge(blayer);    ",  60,  0.0, 120.0); 
    //hist_BLY_dEdx              = new TH1F("hist_BLY_dEdx",              "",  50,  0.0,  10.0); 
    //hist_BLY_dEdxVsP           = new TH2F("hist_BLY_dEdxVsP",           "", 500,  0.0,5000.0, 200, 0.0, 20.0); 
    hist_BLY_HitSize           = new TH1F("hist_BLY_HitSize",           ";HitSize(blayer);          ",  20,  0.0,  20.0); 
    hist_BLY_HitSizePhi        = new TH1F("hist_BLY_HitSizePhi",        ";HitSizePhi(blayer);       ",  10,  0.0,  20.0); 
    hist_BLY_HitSizeZ          = new TH1F("hist_BLY_HitSizeZ",          ";HitSizeZ(blayer);         ",   8,  0.0,   8.0); 
    hist_BLY_unbiasedResidualX = new TH1F("hist_BLY_unbiasedResidualX", ";unbisedResidualX(blayer); ", 100, -0.3,   0.3);
    hist_BLY_unbiasedResidualY = new TH1F("hist_BLY_unbiasedResidualY", ";unbisedResidualY(blayer); ", 100, -0.5,   0.5);
    hist_BLY_Isolation10x2     = new TH1F("hist_BLY_Isolation10x2",     ";Isolation10x2(blayer);    ",  20,  0.0,  20.0);
    hist_BLY_Isolation20x4     = new TH1F("hist_BLY_Isolation20x4",     ";Isolation20x4(blayer);    ",  20,  0.0,  20.0);
    hist_BLY_numTotalClustersPerModule = new TH1F("hist_BLY_numTotalClustersPerModule", ";numTotalClustersPerModule(blayer); ", 50.0,0.0, 50.0);
    hist_BLY_numTotalPixelsPerModule   = new TH1F("hist_BLY_numTotalPixelsPerModule",   ";numTotalPixelPerModule(blayer);    ", 50.0,0.0,100.0);
    //hist_BLY_LorentzAngle      = new TH2F("hist_BLY_LorentzAngle", "", 50,  0.0, 1.0, 10, 0.0, 20.0);

    hist_LY1_IsEdge            = new TH1F("hist_LY1_IsEdge",     ";IsEdge(L1);    ",   2, -0.5, 1.5); 
    hist_LY1_IsOverflow        = new TH1F("hist_LY1_IsOverflow", ";IsOverflow(L1);",   2, -0.5, 1.5); 
    hist_LY1_IsSplit           = new TH1F("hist_LY1_IsSplit",    ";IsSplit(L1);   ",   2, -0.5, 1.5); 
    hist_LY1_L1A               = new TH1F("hist_LY1_L1A",        ";L1A(L1);       ",   6, -2.5, 3.5);
    hist_LY1_ToT               = new TH1F("hist_LY1_ToT",        ";ToT(L1);       ", 100, -0.5, 199.5); 
    hist_LY1_Charge            = new TH1F("hist_LY1_Charge",     ";Charge(L1);    ",  60,  0.0, 120.0); 
    //hist_LY1_dEdx              = new TH1F("hist_LY1_dEdx",       "",  50,  0.0, 10.0); 
    //hist_LY1_dEdxVsP           = new TH2F("hist_LY1_dEdxVsP",    "", 500,  0.0, 5000.0, 200, 0.0, 20.0); 
    hist_LY1_HitSize           = new TH1F("hist_LY1_HitSize",    ";HitSize(L1);          ",  20,  0.0, 20.0); 
    hist_LY1_HitSizePhi        = new TH1F("hist_LY1_HitSizePhi", ";HitSizePhi(L1);       ",  10,  0.0, 20.0); 
    hist_LY1_HitSizeZ          = new TH1F("hist_LY1_HitSizeZ",   ";HitSizeZ(L1);         ",   8,  0.0,  8.0); 
    hist_LY1_unbiasedResidualX = new TH1F("hist_LY1_unbiasedResidualX", ";unbisedResidualX(L1); ", 100, -0.3, 0.3);
    hist_LY1_unbiasedResidualY = new TH1F("hist_LY1_unbiasedResidualY", ";unbisedResidualY(L1); ", 100, -0.5, 0.5);
    hist_LY1_Isolation10x2     = new TH1F("hist_LY1_Isolation10x2",     ";Isolation10x2(L1);    ", 20,   0.0, 20.0);
    hist_LY1_Isolation20x4     = new TH1F("hist_LY1_Isolation20x4",     ";Isolation20x4(L1);    ", 20,   0.0, 20.0);
    hist_LY1_numTotalClustersPerModule = new TH1F("hist_LY1_numTotalClustersPerModule", ";numTotalClustersPerModule(L1); ", 50, 0.0,  50.0);
    hist_LY1_numTotalPixelsPerModule   = new TH1F("hist_LY1_numTotalPixelsPerModule",   ";numTotalPixelPerModule(L1);    ", 50, 0.0, 100.0);
    //hist_LY1_LorentzAngle      = new TH2F("hist_LY1_LorentzAngle", "",  50,  0.0, 1.0, 10, 0.0, 20.0);

    hist_LY2_IsEdge            = new TH1F("hist_LY2_IsEdge",            ";IsEdge(L2);    ",   2, -0.5,   1.5); 
    hist_LY2_IsOverflow        = new TH1F("hist_LY2_IsOverflow",        ";IsOverflow(L2);",   2, -0.5,   1.5); 
    hist_LY2_IsSplit           = new TH1F("hist_LY2_IsSplit",           ";IsSplit(L2);   ",   2, -0.5,   1.5); 
    hist_LY2_L1A               = new TH1F("hist_LY2_L1A",               ";L1A(L2);       ",   6, -2.5,   3.5);
    hist_LY2_ToT               = new TH1F("hist_LY2_ToT",               ";ToT(L2);       ", 100, -0.5, 199.5); 
    hist_LY2_Charge            = new TH1F("hist_LY2_Charge",            ";Charge(L2);    ",  60,  0.0, 120.0); 
    //hist_LY2_dEdx              = new TH1F("hist_LY2_dEdx",              "",  50,  0.0,  10.0); 
    //hist_LY2_dEdxVsP           = new TH2F("hist_LY2_dEdxVsP",           "", 500,  0.0,5000.0, 200, 0.0, 20.0); 
    hist_LY2_HitSize           = new TH1F("hist_LY2_HitSize",           ";HitSize(L2);          ",  20,  0.0,  20.0); 
    hist_LY2_HitSizePhi        = new TH1F("hist_LY2_HitSizePhi",        ";HitSizePhi(L2);       ",  10,  0.0,  20.0); 
    hist_LY2_HitSizeZ          = new TH1F("hist_LY2_HitSizeZ",          ";HitSizeZ(L2);         ",   8,  0.0,   8.0); 
    hist_LY2_unbiasedResidualX = new TH1F("hist_LY2_unbiasedResidualX", ";unbisedResidualX(L2); ", 100, -0.3,   0.3);
    hist_LY2_unbiasedResidualY = new TH1F("hist_LY2_unbiasedResidualY", ";unbisedResidualY(L2); ", 100, -0.5,   0.5);
    hist_LY2_Isolation10x2     = new TH1F("hist_LY2_Isolation10x2",     ";Isolation10x2(L2);    ",  20,  0.0,  20.0);
    hist_LY2_Isolation20x4     = new TH1F("hist_LY2_Isolation20x4",     ";Isolation20x4(L2);    ",  20,  0.0,  20.0);
    hist_LY2_numTotalClustersPerModule = new TH1F("hist_LY2_numTotalClustersPerModule", ";numTotalClustersPerModule(L2); ", 50, 0.0,  50.0);
    hist_LY2_numTotalPixelsPerModule   = new TH1F("hist_LY2_numTotalPixelsPerModule",   ";numTotalPixelPerModule(L2);    ", 50, 0.0, 100.0);
    //hist_LY2_LorentzAngle      = new TH2F("hist_LY2_LorentzAngle", "",  50,  0.0, 1.0, 10, 0.0, 20.0);

    ListTH1F.push_back(h_LB);
    ListTH1F.push_back(hist_trk_num); 
    ListTH1F.push_back(hist_trktrue_num); 
    ListTH1F.push_back(hist_truth_num); 
    ListTH1F.push_back(hist_trk_pt);  
    ListTH1F.push_back(hist_true_pt);  
    ListTH1F.push_back(hist_truepass_pt);  
    ListTH1F.push_back(hist_trk_eta); 
    ListTH1F.push_back(hist_true_eta);  
    ListTH1F.push_back(hist_truepass_eta);  
    ListTH1F.push_back(hist_trk_phi); 
    ListTH1F.push_back(hist_true_phi);  
    ListTH1F.push_back(hist_truepass_phi);  
    ListTH1F.push_back(hist_true_numVtx);  
    ListTH1F.push_back(hist_truepass_numVtx);  
    ListTH1F.push_back(hist_true_avePU);  
    ListTH1F.push_back(hist_truepass_avePU);  
    ListTH1F.push_back(hist_trk_qoverp);  
    ListTH1F.push_back(hist_trk_d0);      
    ListTH1F.push_back(hist_trk_z0);      
    ListTH1F.push_back(hist_trk_deltaZ); 
    ListTH1F.push_back(h_trackD0Err); 
    ListTH1F.push_back(h_trackZ0Err); 
    ListTH1F.push_back(h_trackTheta); 
    ListTH1F.push_back(h_trackCharge); 
    ListTH1F.push_back(h_trackMindR); 
    ListTH1F.push_back(h_trackClass); 
    ListTH1F.push_back(h_trackPassCut); 
    ListTH1F.push_back(hist_trk_dpt); 
    ListTH1F.push_back(hist_trk_dphi); 
    ListTH1F.push_back(hist_trk_deta); 
    ListTH1F.push_back(hist_trk_dd0); 
    ListTH1F.push_back(hist_trk_dz0); 
    ListTH1F.push_back(hist_trk_dr); 
    ListTH1F.push_back(hist_trkeff_pt); 
    ListTH1F.push_back(hist_trkeff_phi); 
    ListTH1F.push_back(hist_trkeff_eta); 
    ListTH1F.push_back(hist_trkeff_numVtx); 
    ListTH1F.push_back(hist_trkeff_avePU); 
    ListTH1F.push_back(hist_trk_nPixHits); 
    ListTH1F.push_back(hist_trk_nGangedPix        ); 
    ListTH1F.push_back(hist_trk_nPixLay           ); 
    ListTH1F.push_back(hist_trk_nPixSharedHits    ); 
    ListTH1F.push_back(hist_trk_nPixSplitHits     ); 
    ListTH1F.push_back(hist_trk_nPixOutliers      ); 
    ListTH1F.push_back(hist_trk_nPixHoles         ); 
    ListTH1F.push_back(hist_trk_nPixelDeadSensors ); 
    ListTH1F.push_back(hist_trk_nOutliers         );
    ListTH1F.push_back(hist_trk_stdDevChi2OS      );
    ListTH1F.push_back(h_trackChiSqPerDof); 
    ListTH1F.push_back(h_trackNIBLUsedHits); 
    ListTH1F.push_back(h_trackNBLUsedHits); 
    ListTH1F.push_back(h_trackNSplitIBLHits); 
    ListTH1F.push_back(h_trackNSplitBLHits); 
    ListTH1F.push_back(h_trackNSharedIBLHits); 
    ListTH1F.push_back(h_trackNSharedBLHits); 
    ListTH1F.push_back(h_trackNIBLHits); 
    ListTH1F.push_back(h_trackNBLHits); 
    ListTH1F.push_back(h_trackNL1Hits); 
    ListTH1F.push_back(h_trackNL2Hits); 
    ListTH1F.push_back(h_trackNIBLExpectedHits); 
    ListTH1F.push_back(h_trackNBLExpectedHits); 
    ListTH1F.push_back(hist_IBL_MapHitEtaeff            ); 
    ListTH1F.push_back(hist_IBL_MapHitEta            ); 
    ListTH1F.push_back(hist_IBL_MapEta            ); 
    ListTH1F.push_back(hist_IBL_MapHitPteff            ); 
    ListTH1F.push_back(hist_IBL_MapHitPt            ); 
    ListTH1F.push_back(hist_IBL_MapPt            ); 
    ListTH1F.push_back(hist_numVtx             ); 
    ListTH1F.push_back(hist_IBL_MapHitnumVtxeff);
    ListTH1F.push_back(hist_BLY_MapHitnumVtxeff);
    ListTH1F.push_back(hist_LY1_MapHitnumVtxeff);
    ListTH1F.push_back(hist_LY2_MapHitnumVtxeff);
    ListTH1F.push_back(hist_IBL_MapHitnumVtx   );
    ListTH1F.push_back(hist_BLY_MapHitnumVtx   );
    ListTH1F.push_back(hist_LY1_MapHitnumVtx   );
    ListTH1F.push_back(hist_LY2_MapHitnumVtx   );
    ListTH1F.push_back(hist_IBL_MapnumVtx   );
    ListTH1F.push_back(hist_BLY_MapnumVtx   );
    ListTH1F.push_back(hist_LY1_MapnumVtx   );
    ListTH1F.push_back(hist_LY2_MapnumVtx   );
    ListTH1F.push_back(hist_IBL_MapHitavePUeff);
    ListTH1F.push_back(hist_BLY_MapHitavePUeff);
    ListTH1F.push_back(hist_LY1_MapHitavePUeff);
    ListTH1F.push_back(hist_LY2_MapHitavePUeff);
    ListTH1F.push_back(hist_IBL_MapHitavePU   );
    ListTH1F.push_back(hist_BLY_MapHitavePU   );
    ListTH1F.push_back(hist_LY1_MapHitavePU   );
    ListTH1F.push_back(hist_LY2_MapHitavePU   );
    ListTH1F.push_back(hist_IBL_MapavePU   );
    ListTH1F.push_back(hist_BLY_MapavePU   );
    ListTH1F.push_back(hist_LY1_MapavePU   );
    ListTH1F.push_back(hist_LY2_MapavePU   );
    //ListTH1F.push_back(hist_trk_truthMatchProb    );
    ListTH1F.push_back(hist_BLY_IsEdge            ); 
    ListTH1F.push_back(hist_BLY_IsOverflow        ); 
    ListTH1F.push_back(hist_BLY_IsSplit           ); 
    ListTH1F.push_back(hist_BLY_L1A               );
    ListTH1F.push_back(hist_BLY_ToT               ); 
    ListTH1F.push_back(hist_BLY_Charge            ); 
    ListTH1F.push_back(hist_BLY_MapHitEtaeff           ); 
    ListTH1F.push_back(hist_BLY_MapHitEta            ); 
    ListTH1F.push_back(hist_BLY_MapEta            ); 
    ListTH1F.push_back(hist_BLY_MapHitPteff           ); 
    ListTH1F.push_back(hist_BLY_MapHitPt            ); 
    ListTH1F.push_back(hist_BLY_MapPt            ); 
    //ListTH1F.push_back(hist_BLY_dEdx              ); 
    ListTH1F.push_back(hist_BLY_HitSize           ); 
    ListTH1F.push_back(hist_BLY_HitSizePhi        ); 
    ListTH1F.push_back(hist_BLY_HitSizeZ          ); 
    ListTH1F.push_back(hist_BLY_unbiasedResidualX );
    ListTH1F.push_back(hist_BLY_unbiasedResidualY );
    ListTH1F.push_back(hist_BLY_Isolation10x2     );
    ListTH1F.push_back(hist_BLY_Isolation20x4     );
    ListTH1F.push_back(hist_BLY_numTotalClustersPerModule );
    ListTH1F.push_back(hist_BLY_numTotalPixelsPerModule   );
    ListTH1F.push_back(hist_LY1_IsEdge            ); 
    ListTH1F.push_back(hist_LY1_IsOverflow        ); 
    ListTH1F.push_back(hist_LY1_IsSplit           ); 
    ListTH1F.push_back(hist_LY1_L1A               );
    ListTH1F.push_back(hist_LY1_ToT               ); 
    ListTH1F.push_back(hist_LY1_Charge            ); 
    ListTH1F.push_back(hist_LY1_MapHitEtaeff            ); 
    ListTH1F.push_back(hist_LY1_MapHitEta            ); 
    ListTH1F.push_back(hist_LY1_MapEta            ); 
    ListTH1F.push_back(hist_LY1_MapHitPteff            ); 
    ListTH1F.push_back(hist_LY1_MapHitPt            ); 
    ListTH1F.push_back(hist_LY1_MapPt            ); 
    //ListTH1F.push_back(hist_LY1_dEdx              ); 
    ListTH1F.push_back(hist_LY1_HitSize           ); 
    ListTH1F.push_back(hist_LY1_HitSizePhi        ); 
    ListTH1F.push_back(hist_LY1_HitSizeZ          ); 
    ListTH1F.push_back(hist_LY1_unbiasedResidualX );
    ListTH1F.push_back(hist_LY1_unbiasedResidualY );
    ListTH1F.push_back(hist_LY1_Isolation10x2     );
    ListTH1F.push_back(hist_LY1_Isolation20x4     );
    ListTH1F.push_back(hist_LY1_numTotalClustersPerModule );
    ListTH1F.push_back(hist_LY1_numTotalPixelsPerModule   );
    ListTH1F.push_back(hist_LY2_IsEdge            ); 
    ListTH1F.push_back(hist_LY2_IsOverflow        ); 
    ListTH1F.push_back(hist_LY2_IsSplit           ); 
    ListTH1F.push_back(hist_LY2_L1A               );
    ListTH1F.push_back(hist_LY2_ToT               ); 
    ListTH1F.push_back(hist_LY2_Charge            ); 
    ListTH1F.push_back(hist_LY2_MapHitEtaeff            ); 
    ListTH1F.push_back(hist_LY2_MapEta            ); 
    ListTH1F.push_back(hist_LY2_MapHitPteff            ); 
    ListTH1F.push_back(hist_LY2_MapPt            ); 
    //ListTH1F.push_back(hist_LY2_dEdx              ); 
    ListTH1F.push_back(hist_LY2_HitSize           ); 
    ListTH1F.push_back(hist_LY2_HitSizePhi        ); 
    ListTH1F.push_back(hist_LY2_HitSizeZ          ); 
    ListTH1F.push_back(hist_LY2_unbiasedResidualX );
    ListTH1F.push_back(hist_LY2_unbiasedResidualY );
    ListTH1F.push_back(hist_LY2_Isolation10x2     );
    ListTH1F.push_back(hist_LY2_Isolation20x4     );
    ListTH1F.push_back(hist_LY2_numTotalClustersPerModule );
    ListTH1F.push_back(hist_LY2_numTotalPixelsPerModule   );

    //TH2F

    //for output
    cout << "outputfile_:" << outputfile_ << endl;
    outputFile = new TFile(outputfile_.c_str(), "RECREATE");

}

Bool_t MySelector::Process(Long64_t entry)
{
    // The Process() function is called for each entry in the tree (or possibly
    // keyed object in the case of PROOF) to be processed. The entry argument
    // specifies which entry in the currently loaded tree is to be processed.
    // When processing keyed objects with PROOF, the object is already loaded
    // and is available via the fObject pointer.
    //
    // This function should contain the \"body\" of the analysis. It can contain
    // simple or elaborate selection criteria, run algorithms on the data
    // of the event and typically fill histograms.
    //
    // The processing can be stopped by calling Abort().
    //
    // Use fStatus to set the return value of TTree::Process().
    //
    // The return value is currently not used.

    fReader.SetEntry(entry);
    h_LB->Fill(*lumiBlock);

    //float histWeight = 1.0;
    //histWeight=pileupWeight*mcWeight;

    int ntracks = (int)(trackPt).GetSize();
    hist_trk_num->Fill(ntracks); 
    int ntrackstrue = (int)(truePt).GetSize();
    hist_trktrue_num->Fill(ntrackstrue); 
    int ntruth = (int)(truthPt).GetSize();
    hist_truth_num->Fill(ntruth); 

    for (int i=0; i<ntracks; i++) { //track loop

        hist_trk_pt->Fill(trackPt[i]);   
        hist_trk_eta->Fill(trackEta[i]);  
        hist_trk_phi->Fill(trackPhi[i]);   
        hist_numVtx->Fill(*numVtx);   
        hist_trk_qoverp->Fill(trackqOverP[i]); 
        hist_trk_d0->Fill(trackD0[i]);     
        hist_trk_z0->Fill(trackZ0[i]);     
        h_trackD0Err->Fill(trackD0Err[i]);      
        h_trackZ0Err->Fill(trackD0Err[i]);      
        h_trackTheta->Fill(trackTheta[i]);      
        h_trackCharge->Fill(trackCharge[i]);      
        h_trackMindR->Fill(trackMindR[i]);      
        h_trackClass->Fill(trackClass[i]);      
        h_trackPassCut->Fill(trackPassCut[i]);      
        hist_trk_deltaZ->Fill(trackDeltaZSinTheta[i]); 
        hist_trk_nPixHits->Fill(trackNPixelHits[i]); 
        hist_trk_nGangedPix->Fill(nPixelGanged[i]);        
        hist_trk_nPixLay->Fill(trackNPixelLayers[i]);           
        hist_trk_nPixSharedHits->Fill(nPixelShared[i]);    
        hist_trk_nPixSplitHits->Fill(nPixelSplit[i]);     
        hist_trk_nPixOutliers->Fill(trackNPixelOutliers[i]);      
        hist_trk_nPixHoles->Fill(trackNPixelHoles[i]);         
        hist_trk_nPixelDeadSensors->Fill(nPixelDeadSensors[i]); 
        hist_trk_nOutliers->Fill(trackOutliers[i]);         
        hist_trk_stdDevChi2OS->Fill(trackStdDevChi2OS[i]);      
        h_trackChiSqPerDof->Fill(trackChiSqPerDof[i]);      
        h_trackNIBLUsedHits->Fill(trackNIBLUsedHits[i]);      
        h_trackNBLUsedHits->Fill(trackNBLUsedHits[i]);      
        h_trackNSplitIBLHits->Fill(trackNSplitIBLHits[i]);      
        h_trackNSplitBLHits->Fill(trackNSplitBLHits[i]);      
        h_trackNSharedIBLHits->Fill(trackNSharedIBLHits[i]);
        h_trackNSharedBLHits->Fill(trackNSharedBLHits[i]);      
        h_trackNIBLHits->Fill(trackNIBLHits[i]);      
        h_trackNBLHits->Fill(trackNBLHits[i]);      
        h_trackNL1Hits->Fill(trackNL1Hits[i]);      
        h_trackNL2Hits->Fill(trackNL2Hits[i]);      
        h_trackNIBLExpectedHits->Fill(trackNIBLExpectedHits[i]);      
        h_trackNBLExpectedHits->Fill(trackNBLExpectedHits[i]);      
        /*resolution*/
        hist_trk_dpt->Fill(trackPt[i]-truePt[i]/truePt[i]);
        hist_trk_dphi->Fill(trackPhi[i]-truePhi[i]/truePhi[i]);
        hist_trk_deta->Fill(trackEta[i]-trueEta[i]/trueEta[i]);
        hist_trk_dd0->Fill(trackD0[i]-trued0[i]/trued0[i]);
        hist_trk_dz0->Fill(trackZ0[i]-truez0[i]/truez0[i]);

        //loose track selection
        bool loose = false;
        if (trackPt[i] > 0.4 && TMath::Abs((trackEta)[i])<=2.5  
                && (trackNPixelHits[i]+trackNSCTHits[i])>=7 
                && (nPixelShared[i]+trackNSCTSharedHits[i])<=1 
                && trackNPixelHoles[i]<=1 
                && (trackNPixelHoles[i]+trackNSCTHoles[i])<=2 ) { loose=true; }

        //tightprimary track selection
        bool tightprimary = false;
        if ((( TMath::Abs((trackEta)[i])<=1.65 && (trackNPixelHits[i]+trackNSCTHits[i])>=9) 
                    || (TMath::Abs((trackEta)[i]) >1.65 && (trackNPixelHits[i]+trackNSCTHits[i])>=11) )
                && (trackNIBLHits[i] + trackNBLHits[i]) > 0 
                &&  trackNPixelHoles[i] < 1 ) { tightprimary = true; }

        if (!loose) { continue; }
        //if (!tightprimary) { continue; }

        //==================
        // Efficiency check
        //==================
        if ((trackPt)[i]>2.0 && TMath::Abs((trackEta)[i])<=1.8 /*&& TMath::Abs((trackDeltaZSinTheta)[i])<3.0 */&& (nPixelDeadSensors)[i]==0) {
            // IBL hit efficiency
            if ((trackNBLHits)[i]>0 && (trackNL1Hits)[i]>0 && (trackNL2Hits)[i]>0) {
                hist_IBL_MapEta    -> Fill((trackEta)[i]/*,histWeight*/);
                hist_IBL_MapPt     -> Fill((trackPt)[i]/*,histWeight*/);
                hist_IBL_MapnumVtx -> Fill(*numVtx/*,histWeight*/);
                hist_IBL_MapavePU -> Fill(*averagePU/*,histWeight*/);
                if ((trackNIBLHits)[i]>0) {
                    hist_IBL_MapHitEta -> Fill((trackEta)[i]/*,histWeight*/);
                    hist_IBL_MapHitPt -> Fill((trackPt)[i]/*,histWeight*/);
                    hist_IBL_MapHitnumVtx -> Fill(*numVtx/*,histWeight*/);
                    hist_IBL_MapHitavePU -> Fill(*averagePU/*,histWeight*/);
                }
            }

            // B-layer hit efficiency
            if ((trackNIBLHits)[i]>0 && (trackNL1Hits)[i]>0 && (trackNL2Hits)[i]>0) {
                hist_BLY_MapEta      -> Fill((trackEta)[i]/*,histWeight*/);
                hist_BLY_MapPt      -> Fill((trackPt)[i]/*,histWeight*/);
                hist_BLY_MapnumVtx      -> Fill((*numVtx)[i]/*,histWeight*/);
                hist_BLY_MapavePU -> Fill(*averagePU/*,histWeight*/);
                if ((trackNBLHits)[i]>0) {
                    hist_BLY_MapHitEta -> Fill((trackEta)[i]/*,histWeight*/);
                    hist_BLY_MapHitPt -> Fill((trackPt)[i]/*,histWeight*/);
                    hist_BLY_MapHitnumVtx -> Fill(*numVtx/*,histWeight*/);
                    hist_BLY_MapHitavePU -> Fill(*averagePU/*,histWeight*/);
                }
            }

            // L1 hit efficiency
            if ((trackNIBLHits)[i]>0 && (trackNBLHits)[i]>0 && (trackNL2Hits)[i]>0) {
                hist_LY1_MapEta      -> Fill((trackEta)[i]/*,histWeight*/);
                hist_LY1_MapPt      -> Fill((trackPt)[i]/*,histWeight*/);
                hist_LY1_MapnumVtx      -> Fill(*numVtx/*,histWeight*/);
                hist_LY1_MapavePU -> Fill(*averagePU/*,histWeight*/);
                if ((trackNL1Hits)[i]>0) {
                    hist_LY1_MapHitEta -> Fill((trackEta)[i]/*,histWeight*/);
                    hist_LY1_MapHitPt -> Fill((trackPt)[i]/*,histWeight*/);
                    hist_LY1_MapHitnumVtx -> Fill(*numVtx/*,histWeight*/);
                    hist_LY1_MapHitavePU -> Fill(*averagePU/*,histWeight*/);
                }
            }

            // L2 hit efficiency
            if ((trackNIBLHits)[i]>0 && (trackNBLHits)[i]>0 && (trackNL1Hits)[i]>0) {
                hist_LY2_MapEta      -> Fill((trackEta)[i]/*,histWeight*/);
                hist_LY2_MapPt      -> Fill((trackPt)[i]/*,histWeight*/);
                hist_LY2_MapnumVtx      -> Fill(*numVtx/*,histWeight*/);
                hist_LY2_MapavePU -> Fill(*averagePU/*,histWeight*/);
                if ((trackNL2Hits)[i]>0) {
                    hist_LY2_MapHitEta -> Fill((trackEta)[i]/*,histWeight*/);
                    hist_LY2_MapHitPt -> Fill((trackPt)[i]/*,histWeight*/);
                    hist_LY2_MapHitnumVtx -> Fill(*numVtx/*,histWeight*/);
                    hist_LY2_MapHitavePU -> Fill(*averagePU/*,histWeight*/);
                }
            }

        }



        int nhits = (int)(hitLayer[i]).size();
        for (int j=0; j<nhits; j++) {
            if ((hitIsEndCap)[i][j]==0 && (hitLayer)[i][j]==1) { //blayer
                hist_BLY_IsEdge->Fill(hitIsEdge[i][j]);             
                hist_BLY_IsOverflow->Fill(hitIsOverflow[i][j]);         
                hist_BLY_IsSplit->Fill(hitIsSplit[i][j]);            
                hist_BLY_L1A->Fill(hitLVL1A[i][j]);               
                hist_BLY_ToT->Fill(hitToT[i][j]);                
                hist_BLY_Charge->Fill(hitCharge[i][j]/1000.0);             
                //hist_BLY_dEdx->Fill();               
                hist_BLY_HitSize->Fill(hitNPixel[i][j]);            
                hist_BLY_HitSizePhi->Fill(hitNPixelX[i][j]);         
                hist_BLY_HitSizeZ->Fill(hitNPixelY[i][j]);           
                hist_BLY_unbiasedResidualX->Fill(unbiasedResidualX[i][j]); 
                hist_BLY_unbiasedResidualY->Fill(unbiasedResidualY[i][j]); 
                hist_BLY_Isolation10x2->Fill(hitIsolation10x2[i][j]);     
                hist_BLY_Isolation20x4->Fill(hitIsolation20x4[i][j]);     
                hist_BLY_numTotalClustersPerModule->Fill(numTotalClustersPerModule[i][j]);
                hist_BLY_numTotalPixelsPerModule->Fill(numTotalPixelsPerModule[i][j]); 
            }
            else if ((hitIsEndCap)[i][j]==0 && (hitLayer)[i][j]==2) { //layer1
                hist_LY1_IsEdge->Fill(hitIsEdge[i][j]);             
                hist_LY1_IsOverflow->Fill(hitIsOverflow[i][j]);         

                hist_LY1_IsSplit->Fill(hitIsSplit[i][j]);            
                hist_LY1_L1A->Fill(hitLVL1A[i][j]);               
                hist_LY1_ToT->Fill(hitToT[i][j]);                
                hist_LY1_Charge->Fill(hitCharge[i][j]/1000.0);             
                //hist_LY1_dEdx->Fill();               
                hist_LY1_HitSize->Fill(hitNPixel[i][j]);            
                hist_LY1_HitSizePhi->Fill(hitNPixelX[i][j]);         
                hist_LY1_HitSizeZ->Fill(hitNPixelY[i][j]);           
                hist_LY1_unbiasedResidualX->Fill(unbiasedResidualX[i][j]); 
                hist_LY1_unbiasedResidualY->Fill(unbiasedResidualY[i][j]); 
                hist_LY1_Isolation10x2->Fill(hitIsolation10x2[i][j]);     
                hist_LY1_Isolation20x4->Fill(hitIsolation20x4[i][j]);     
                hist_LY1_numTotalClustersPerModule->Fill(numTotalClustersPerModule[i][j]);
                hist_LY1_numTotalPixelsPerModule->Fill(numTotalPixelsPerModule[i][j]); 
            }
            else if ((hitIsEndCap)[i][j]==0 && (hitLayer)[i][j]==3) { //layer2
                hist_LY2_IsEdge->Fill(hitIsEdge[i][j]);             
                hist_LY2_IsOverflow->Fill(hitIsOverflow[i][j]);         
                hist_LY2_IsSplit->Fill(hitIsSplit[i][j]);            
                hist_LY2_L1A->Fill(hitLVL1A[i][j]);               
                hist_LY2_ToT->Fill(hitToT[i][j]);                
                hist_LY2_Charge->Fill(hitCharge[i][j]/1000.0);             
                //hist_LY2_dEdx->Fill();               
                hist_LY2_HitSize->Fill(hitNPixel[i][j]);            
                hist_LY2_HitSizePhi->Fill(hitNPixelX[i][j]);         
                hist_LY2_HitSizeZ->Fill(hitNPixelY[i][j]);           
                hist_LY2_unbiasedResidualX->Fill(unbiasedResidualX[i][j]); 
                hist_LY2_unbiasedResidualY->Fill(unbiasedResidualY[i][j]); 
                hist_LY2_Isolation10x2->Fill(hitIsolation10x2[i][j]);     
                hist_LY2_Isolation20x4->Fill(hitIsolation20x4[i][j]);     
                hist_LY2_numTotalClustersPerModule->Fill(numTotalClustersPerModule[i][j]);
                hist_LY1_numTotalPixelsPerModule->Fill(numTotalPixelsPerModule[i][j]); 
            }
        }

    } //end of track loop

    for (int j=0; j<ntrackstrue; j++) { //true loop
        if (truePt[j] > 2.0) hist_true_eta->Fill(trueEta[j]);
        if (trueEta[j] < 2.5) hist_true_Pt->Fill(truePt[j]);

        if (truePt[j] <= 2.0 || TMath::Abs(trueEta[j]) > 2.5) continue;
        hist_true_phi->Fill(truePhi[j]);
        hist_true_numVtx->Fill(*numVtx);
        hist_true_avePU->Fill(*averagePU);

        // Loose track selection
        bool loose = false;
        for (int i=0; i<ntracks; i++) { //track loop
            if (trackPt[i] > 2.0 && TMath::Abs((trackEta)[i])<=2.5  
                    && (trackNPixelHits[i]+trackNSCTHits[i])>=7 
                    && (nPixelShared[i]+trackNSCTSharedHits[i])<=1 
                    && trackNPixelHoles[i]<=1 
                    && (trackNPixelHoles[i]+trackNSCTHoles[i])<=2 ) { loose=true; }
            if (!loose) { continue; }

            double dPhi = 0.;
            double dEta = 0.;
            double dR = 0.;
            dPhi = trackPhi[i]-truePhi[j];
            dEta = trackEta[i]-trueEta[j];
            dR = TMath::Sqrt(dPhi*dPhi+dEta*dEta);
            hist_trk_dr->Fill(dR);
            if (dR <= 0.02 && truthmatchprob[i] > 0.95) {
                hist_truepass_pt->Fill(truePt[j]);
                hist_truepass_eta->Fill(trueEta[j]);
                hist_truepass_phi->Fill(truePhi[j]);
                hist_truepass_numVtx->Fill(*numVtx);
                hist_truepass_avePU->Fill(*averagePU);
            }
        } //end of track loop
    } //end of true loop

    hist_trkeff_pt->Divide(hist_truepass_pt,hist_true_pt,1,1);
    hist_trkeff_eta->Divide(hist_truepass_eta,hist_true_eta,1,1);
    hist_trkeff_phi->Divide(hist_truepass_phi,hist_true_phi,1,1);
    hist_trkeff_numVtx->Divide(hist_truepass_numVtx,hist_true_numVtx,1,1);
    hist_trkeff_avePU->Divide(hist_truepass_avePU,hist_true_avePU,1,1);

    hist_IBL_MapHitEtaeff->Divide(hist_IBL_MapHitEta,hist_IBL_MapEta,1,1);
    hist_BLY_MapHitEtaeff->Divide(hist_BLY_MapHitEta,hist_BLY_MapEta,1,1);
    hist_LY1_MapHitEtaeff->Divide(hist_LY1_MapHitEta,hist_LY1_MapEta,1,1);
    hist_LY2_MapHitEtaeff->Divide(hist_LY2_MapHitEta,hist_LY2_MapEta,1,1);
    hist_IBL_MapHitPteff->Divide(hist_IBL_MapHitPt,hist_IBL_MapPt,1,1);
    hist_BLY_MapHitPteff->Divide(hist_BLY_MapHitPt,hist_BLY_MapPt,1,1);
    hist_LY1_MapHitPteff->Divide(hist_LY1_MapHitPt,hist_LY1_MapPt,1,1);
    hist_LY2_MapHitPteff->Divide(hist_LY2_MapHitPt,hist_LY2_MapPt,1,1);
    hist_IBL_MapHitnumVtxeff->Divide(hist_IBL_MapHitnumVtx,hist_IBL_MapHitnumVtx,1,1);
    hist_BLY_MapHitnumVtxeff->Divide(hist_BLY_MapHitnumVtx,hist_BLY_MapHitnumVtx,1,1);
    hist_LY1_MapHitnumVtxeff->Divide(hist_LY1_MapHitnumVtx,hist_LY1_MapHitnumVtx,1,1);
    hist_LY2_MapHitnumVtxeff->Divide(hist_LY2_MapHitnumVtx,hist_LY2_MapHitnumVtx,1,1);
    hist_IBL_MapHitavePU->Divide(hist_IBL_MapHitavePU,hist_IBL_MapHitavePU,1,1);
    hist_BLY_MapHitavePU->Divide(hist_BLY_MapHitavePU,hist_BLY_MapHitavePU,1,1);
    hist_LY1_MapHitavePU->Divide(hist_LY1_MapHitavePU,hist_LY1_MapHitavePU,1,1);
    hist_LY2_MapHitavePU->Divide(hist_LY2_MapHitavePU,hist_LY2_MapHitavePU,1,1);

    return kTRUE;
}

void MySelector::SlaveTerminate()
{
    // The SlaveTerminate() function is called after all entries or objects
    // have been processed. When running with PROOF SlaveTerminate() is called
    // on each slave server.

}

void MySelector::Terminate()
{
    // The Terminate() function is the last function to be called during
    // a query. It always runs on the client, it can be used to present
    // the results graphically or save the results to file.
    for ( TH1F* th1f : ListTH1F) th1f->Write();
    for ( TH2F* th2f : ListTH2F) th2f->Write();
    outputFile->Close();

}
