#include "eventtree.h"

#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TLorentzVector.h"

class ZmumuAnalysis : public eventtree {
  public:

    ZmumuAnalysis() {};
    ZmumuAnalysis(TTree *ntuple) : eventtree(ntuple) {};
    virtual ~ZmumuAnalysis() {};

    virtual void initialize(TString rout);
    virtual void execute();
    virtual void finalize();

  private:

    TH1F* hist_muValue;
    TH1F* hist_lumiBlk;
    TH1F* hist_numVtx;
    TH1F* hist_numJet;
    TH1F* hist_numJetjvt;
    TH1F* hist_muon_pt1;
    TH1F* hist_muon_eta1;
    TH1F* hist_muon_pt2;
    TH1F* hist_muon_eta2;
    TH1F* hist_dimuon_mass;
    TH1F* hist_dimuon_pt;
    TH1F* hist_dimuon_eta;

    TH1F* hist_trk_num;
    TH1F* hist_trk_pt;
    TH1F* hist_trk_eta;
    TH1F* hist_trk_phi;

    TH1F* hist_trk_qoverp;
    TH1F* hist_trk_d0;
    TH1F* hist_trk_z0;
    TH1F* hist_trk_deltaZ;

    TH2F* hist_trk_etaVSphi;

    TH1F* hist_truth_pt;
    TH1F* hist_truth_eta;
    TH1F* hist_truth_phi;
    TH1F* hist_truth_d0;
    TH1F* hist_truth_z0;

    /* Resolution */
    TH1F* hist_trk_dpt;
    TH1F* hist_trk_dphi;
    TH1F* hist_trk_deta;
    TH1F* hist_trk_dd0;
    TH1F* hist_trk_dz0;

  /* track properties */
    TH1F* hist_trk_nPixHits;
    TH1F* hist_trk_nSCTHits;
    TH1F* hist_trk_nSiHits;

    TH1F* hist_trk_nGangedPix;
    TH1F* hist_trk_nPixLay;
    TH1F* hist_trk_nPixSharedHits;
    TH1F* hist_trk_nPixSplitHits;
    TH1F* hist_trk_nPixOutliers;
    TH1F* hist_trk_nPixHoles;
    TH1F* hist_trk_nPixelDeadSensors;
    TH1F* hist_trk_nSCTSharedHits;
    TH1F* hist_trk_nSCTOutliers;
    TH1F* hist_trk_nSCTHoles;
    TH1F* hist_trk_nSCTDeadSensors;
    TH1F* hist_trk_nTRTHits;
    TH1F* hist_trk_nTRTOutliers;
    TH1F* hist_trk_nTRTHoles;
    TH1F* hist_trk_nTRTHTHits;
    TH1F* hist_trk_chiSqPerDof;
    TH1F* hist_trk_nOutliers;
    TH1F* hist_trk_stdDevChi2OS;
    TH1F* hist_trk_truthMatchProb;

    // Cluster study
    TH1F* hist_IBL_IsEdge;
    TH1F* hist_IBL_IsOverflow;
    TH1F* hist_IBL_IsSplit;
    TH1F* hist_IBL_L1A;
    TH1F* hist_IBL_ToT;
    TH1F* hist_IBL_Charge;
    TH1F* hist_IBL_dEdx;
    TH2F* hist_IBL_dEdxVsP;
    TH1F* hist_IBL_HitSize;
    TH1F* hist_IBL_HitSizePhi;
    TH1F* hist_IBL_HitSizeZ;
    TH1F* hist_IBL_unbiasedResidualX;
    TH1F* hist_IBL_unbiasedResidualY;
    TH1F* hist_IBL_Isolation10x2;
    TH1F* hist_IBL_Isolation20x4;
    TH1F* hist_IBL_numTotalClustersPerModule;
    TH1F* hist_IBL_numTotalPixelsPerModule;
    TH2F* hist_IBL_LorentzAngle;
    TH2F* hist_IBL_Map;
    TH2F* hist_IBL_MapHit;
    TH1F* hist_IBL_MapEta;
    TH1F* hist_IBL_MapHitEta;

    TH1F* hist_BLY_IsEdge;
    TH1F* hist_BLY_IsOverflow;
    TH1F* hist_BLY_IsSplit;
    TH1F* hist_BLY_L1A;
    TH1F* hist_BLY_ToT;
    TH1F* hist_BLY_Charge;
    TH1F* hist_BLY_dEdx;
    TH2F* hist_BLY_dEdxVsP;
    TH1F* hist_BLY_HitSize;
    TH1F* hist_BLY_HitSizePhi;
    TH1F* hist_BLY_HitSizeZ;
    TH1F* hist_BLY_unbiasedResidualX;
    TH1F* hist_BLY_unbiasedResidualY;
    TH1F* hist_BLY_Isolation10x2;
    TH1F* hist_BLY_Isolation20x4;
    TH1F* hist_BLY_numTotalClustersPerModule;
    TH1F* hist_BLY_numTotalPixelsPerModule;
    TH2F* hist_BLY_LorentzAngle;
    TH2F* hist_BLY_Map;
    TH2F* hist_BLY_MapHit;
    TH1F* hist_BLY_MapEta;
    TH1F* hist_BLY_MapHitEta;

    TH1F* hist_LY1_IsEdge;
    TH1F* hist_LY1_IsOverflow;
    TH1F* hist_LY1_IsSplit;
    TH1F* hist_LY1_L1A;
    TH1F* hist_LY1_ToT;
    TH1F* hist_LY1_Charge;
    TH1F* hist_LY1_dEdx;
    TH2F* hist_LY1_dEdxVsP;
    TH1F* hist_LY1_HitSize;
    TH1F* hist_LY1_HitSizePhi;
    TH1F* hist_LY1_HitSizeZ;
    TH1F* hist_LY1_unbiasedResidualX;
    TH1F* hist_LY1_unbiasedResidualY;
    TH1F* hist_LY1_Isolation10x2;
    TH1F* hist_LY1_Isolation20x4;
    TH1F* hist_LY1_numTotalClustersPerModule;
    TH1F* hist_LY1_numTotalPixelsPerModule;
    TH2F* hist_LY1_LorentzAngle;
    TH2F* hist_LY1_Map;
    TH2F* hist_LY1_MapHit;
    TH1F* hist_LY1_MapEta;
    TH1F* hist_LY1_MapHitEta;

    TH1F* hist_LY2_IsEdge;
    TH1F* hist_LY2_IsOverflow;
    TH1F* hist_LY2_IsSplit;
    TH1F* hist_LY2_L1A;
    TH1F* hist_LY2_ToT;
    TH1F* hist_LY2_Charge;
    TH1F* hist_LY2_dEdx;
    TH2F* hist_LY2_dEdxVsP;
    TH1F* hist_LY2_HitSize;
    TH1F* hist_LY2_HitSizePhi;
    TH1F* hist_LY2_HitSizeZ;
    TH1F* hist_LY2_unbiasedResidualX;
    TH1F* hist_LY2_unbiasedResidualY;
    TH1F* hist_LY2_Isolation10x2;
    TH1F* hist_LY2_Isolation20x4;
    TH1F* hist_LY2_numTotalClustersPerModule;
    TH1F* hist_LY2_numTotalPixelsPerModule;
    TH2F* hist_LY2_LorentzAngle;
    TH2F* hist_LY2_Map;
    TH2F* hist_LY2_MapHit;
    TH1F* hist_LY2_MapEta;
    TH1F* hist_LY2_MapHitEta;

    TH1F* hist_END_IsEdge;
    TH1F* hist_END_IsOverflow;
    TH1F* hist_END_IsSplit;
    TH1F* hist_END_L1A;
    TH1F* hist_END_ToT;
    TH1F* hist_END_Charge;
    TH1F* hist_END_dEdx;
    TH2F* hist_END_dEdxVsP;
    TH1F* hist_END_HitSize;
    TH1F* hist_END_HitSizePhi;
    TH1F* hist_END_HitSizeZ;
    TH1F* hist_END_unbiasedResidualX;
    TH1F* hist_END_unbiasedResidualY;
    TH1F* hist_END_Isolation10x2;
    TH1F* hist_END_Isolation20x4;
    TH1F* hist_END_numTotalClustersPerModule;
    TH1F* hist_END_numTotalPixelsPerModule;
    TH2F* hist_END_LorentzAngle;
    TH2F* hist_ED1_Map;
    TH2F* hist_ED1_MapHit;
    TH1F* hist_ED1_MapEta;
    TH1F* hist_ED1_MapHitEta;
    TH2F* hist_ED2_3Map;
    TH2F* hist_ED2_3MapHit;
    TH1F* hist_ED2_3MapEta;
    TH1F* hist_ED2_3MapHitEta;

    TH1F* hist_ALL_dEdx;
    TH2F* hist_ALL_dEdxVsP;

    TFile * m_rootFile;

};

