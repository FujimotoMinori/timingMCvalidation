//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Aug 30 00:54:00 2019 by ROOT version 6.14/04
// from TTree eventtree/Zmumu ntuple
// found on file: mc2018.361107.PowhegPythia8EvtGen_AZNLOCTEQ6L1_Zmumu.timing2015.EVENT_NT._0001.pool.root
//////////////////////////////////////////////////////////

#ifndef MySelector_h
#define MySelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class MySelector : public TSelector {
private:
   std::string outputfile_;
public :
   TFile *outputFile = 0;
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<UInt_t> runNumber = {fReader, "runNumber"};
   TTreeReaderValue<ULong64_t> eventNumber = {fReader, "eventNumber"};
   TTreeReaderValue<Double_t> pileupWeight = {fReader, "pileupWeight"};
   TTreeReaderValue<Double_t> mcWeight = {fReader, "mcWeight"};
   TTreeReaderValue<Int_t> lumiBlock = {fReader, "lumiBlock"};
   TTreeReaderValue<Float_t> averagePU = {fReader, "averagePU"};
   TTreeReaderValue<Float_t> eventPU = {fReader, "eventPU"};
   TTreeReaderValue<Int_t> mcFlag = {fReader, "mcFlag"};
   TTreeReaderValue<Int_t> numVtx = {fReader, "numVtx"};
   TTreeReaderValue<Float_t> pVtxX = {fReader, "pVtxX"};
   TTreeReaderValue<Float_t> pVtxY = {fReader, "pVtxY"};
   TTreeReaderValue<Float_t> pVtxZ = {fReader, "pVtxZ"};
   TTreeReaderValue<Float_t> pVtxXErr = {fReader, "pVtxXErr"};
   TTreeReaderValue<Float_t> pVtxYErr = {fReader, "pVtxYErr"};
   TTreeReaderValue<Float_t> pVtxZErr = {fReader, "pVtxZErr"};
   TTreeReaderValue<Float_t> truthPVtxX = {fReader, "truthPVtxX"};
   TTreeReaderValue<Float_t> truthPVtxY = {fReader, "truthPVtxY"};
   TTreeReaderValue<Float_t> truthPVtxZ = {fReader, "truthPVtxZ"};
   TTreeReaderArray<float> trackPt = {fReader, "trackPt"};
   TTreeReaderArray<float> trackPhi = {fReader, "trackPhi"};
   TTreeReaderArray<float> trackEta = {fReader, "trackEta"};
   TTreeReaderArray<float> trackTheta = {fReader, "trackTheta"};
   TTreeReaderArray<float> trackCharge = {fReader, "trackCharge"};
   TTreeReaderArray<float> trackqOverP = {fReader, "trackqOverP"};
   TTreeReaderArray<float> trackD0 = {fReader, "trackD0"};
   TTreeReaderArray<float> trackZ0 = {fReader, "trackZ0"};
   TTreeReaderArray<float> trackD0Err = {fReader, "trackD0Err"};
   TTreeReaderArray<float> trackZ0Err = {fReader, "trackZ0Err"};
   TTreeReaderArray<float> trackqOverPErr = {fReader, "trackqOverPErr"};
   TTreeReaderArray<float> trackDeltaZSinTheta = {fReader, "trackDeltaZSinTheta"};
   TTreeReaderArray<float> trackMindR = {fReader, "trackMindR"};
   TTreeReaderArray<int> trackClass = {fReader, "trackClass"};
   TTreeReaderArray<int> trackPassCut = {fReader, "trackPassCut"};
   TTreeReaderArray<int> trackOutliers = {fReader, "trackOutliers"};
   TTreeReaderArray<float> trackChiSqPerDof = {fReader, "trackChiSqPerDof"};
   TTreeReaderArray<float> trackStdDevChi2OS = {fReader, "trackStdDevChi2OS"};
   TTreeReaderArray<int> trackNPixelHits = {fReader, "trackNPixelHits"};
   TTreeReaderArray<int> trackNPixelHoles = {fReader, "trackNPixelHoles"};
   TTreeReaderArray<int> trackNPixelLayers = {fReader, "trackNPixelLayers"};
   TTreeReaderArray<int> trackNPixelOutliers = {fReader, "trackNPixelOutliers"};
   TTreeReaderArray<int> nPixelGanged = {fReader, "nPixelGanged"};
   TTreeReaderArray<int> nPixelShared = {fReader, "nPixelShared"};
   TTreeReaderArray<int> nPixelSplit = {fReader, "nPixelSplit"};
   TTreeReaderArray<int> nPixelDeadSensors = {fReader, "nPixelDeadSensors"};
   TTreeReaderArray<int> trackNIBLUsedHits = {fReader, "trackNIBLUsedHits"};
   TTreeReaderArray<int> trackNBLUsedHits = {fReader, "trackNBLUsedHits"};
   TTreeReaderArray<int> trackNSCTHits = {fReader, "trackNSCTHits"};
   TTreeReaderArray<int> trackNSCTHoles = {fReader, "trackNSCTHoles"};
   TTreeReaderArray<int> nSCTOutliers = {fReader, "nSCTOutliers"};
   TTreeReaderArray<int> nSCTDeadSensors = {fReader, "nSCTDeadSensors"};
   TTreeReaderArray<int> trackNTRTHits = {fReader, "trackNTRTHits"};
   TTreeReaderArray<int> nTRTOutliers = {fReader, "nTRTOutliers"};
   TTreeReaderArray<int> nTRTHoles = {fReader, "nTRTHoles"};
   TTreeReaderArray<int> nTRTHTHits = {fReader, "nTRTHTHits"};
   TTreeReaderArray<int> trackNSplitIBLHits = {fReader, "trackNSplitIBLHits"};
   TTreeReaderArray<int> trackNSplitBLHits = {fReader, "trackNSplitBLHits"};
   TTreeReaderArray<int> trackNSharedIBLHits = {fReader, "trackNSharedIBLHits"};
   TTreeReaderArray<int> trackNSharedBLHits = {fReader, "trackNSharedBLHits"};
   TTreeReaderArray<int> trackNIBLHits = {fReader, "trackNIBLHits"};
   TTreeReaderArray<int> trackNBLHits = {fReader, "trackNBLHits"};
   TTreeReaderArray<int> trackNL1Hits = {fReader, "trackNL1Hits"};
   TTreeReaderArray<int> trackNL2Hits = {fReader, "trackNL2Hits"};
   TTreeReaderArray<int> trackNECHits = {fReader, "trackNECHits"};
   TTreeReaderArray<int> trackNIBLExpectedHits = {fReader, "trackNIBLExpectedHits"};
   TTreeReaderArray<int> trackNBLExpectedHits = {fReader, "trackNBLExpectedHits"};
   TTreeReaderArray<int> trackNSCTSharedHits = {fReader, "trackNSCTSharedHits"};
   TTreeReaderArray<float> trackTruncateddEdx = {fReader, "trackTruncateddEdx"};
   TTreeReaderArray<int> trackNTruncateddEdx = {fReader, "trackNTruncateddEdx"};
   TTreeReaderArray<float> extrapolatedIBLX = {fReader, "extrapolatedIBLX"};
   TTreeReaderArray<float> extrapolatedIBLY = {fReader, "extrapolatedIBLY"};
   TTreeReaderArray<float> extrapolatedIBLZ = {fReader, "extrapolatedIBLZ"};
   TTreeReaderArray<float> extrapolatedBLX = {fReader, "extrapolatedBLX"};
   TTreeReaderArray<float> extrapolatedBLY = {fReader, "extrapolatedBLY"};
   TTreeReaderArray<float> extrapolatedBLZ = {fReader, "extrapolatedBLZ"};
   TTreeReaderArray<float> extrapolatedL1X = {fReader, "extrapolatedL1X"};
   TTreeReaderArray<float> extrapolatedL1Y = {fReader, "extrapolatedL1Y"};
   TTreeReaderArray<float> extrapolatedL1Z = {fReader, "extrapolatedL1Z"};
   TTreeReaderArray<float> extrapolatedL2X = {fReader, "extrapolatedL2X"};
   TTreeReaderArray<float> extrapolatedL2Y = {fReader, "extrapolatedL2Y"};
   TTreeReaderArray<float> extrapolatedL2Z = {fReader, "extrapolatedL2Z"};
   TTreeReaderArray<float> truePt = {fReader, "truePt"};
   TTreeReaderArray<float> truePhi = {fReader, "truePhi"};
   TTreeReaderArray<float> trueEta = {fReader, "trueEta"};
   TTreeReaderArray<float> trueE = {fReader, "trueE"};
   TTreeReaderArray<float> trued0 = {fReader, "trued0"};
   TTreeReaderArray<float> truez0 = {fReader, "truez0"};
   TTreeReaderArray<float> truephi0 = {fReader, "truephi0"};
   TTreeReaderArray<float> truetheta = {fReader, "truetheta"};
   TTreeReaderArray<float> trueqoverp = {fReader, "trueqoverp"};
   TTreeReaderArray<int> truepdgid = {fReader, "truepdgid"};
   TTreeReaderArray<int> truebarcode = {fReader, "truebarcode"};
   TTreeReaderArray<float> truthmatchprob = {fReader, "truthmatchprob"};
   TTreeReaderArray<float> trueMindR = {fReader, "trueMindR"};
   TTreeReaderArray<float> genVtxR = {fReader, "genVtxR"};
   TTreeReaderArray<float> genVtxZ = {fReader, "genVtxZ"};
   TTreeReaderArray<int> parentFlavour = {fReader, "parentFlavour"};
   TTreeReaderArray<vector<int>> hitIsEndCap = {fReader, "hitIsEndCap"};
   TTreeReaderArray<vector<int>> hitIsHole = {fReader, "hitIsHole"};
   TTreeReaderArray<vector<int>> hitIsOutlier = {fReader, "hitIsOutlier"};
   TTreeReaderArray<vector<int>> hitLayer = {fReader, "hitLayer"};
   TTreeReaderArray<vector<int>> hitEtaModule = {fReader, "hitEtaModule"};
   TTreeReaderArray<vector<int>> hitPhiModule = {fReader, "hitPhiModule"};
   TTreeReaderArray<vector<float>> hitCharge = {fReader, "hitCharge"};
   TTreeReaderArray<vector<int>> hitToT = {fReader, "hitToT"};
   TTreeReaderArray<vector<int>> hitLVL1A = {fReader, "hitLVL1A"};
   TTreeReaderArray<vector<int>> hitNPixel = {fReader, "hitNPixel"};
   TTreeReaderArray<vector<int>> hitNPixelX = {fReader, "hitNPixelX"};
   TTreeReaderArray<vector<int>> hitNPixelY = {fReader, "hitNPixelY"};
   TTreeReaderArray<vector<int>> hitBSerr = {fReader, "hitBSerr"};
   TTreeReaderArray<vector<int>> hitDCSstate = {fReader, "hitDCSstate"};
   TTreeReaderArray<vector<float>> hitVBias = {fReader, "hitVBias"};
   TTreeReaderArray<vector<float>> hitTemp = {fReader, "hitTemp"};
   TTreeReaderArray<vector<float>> hitLorentzShift = {fReader, "hitLorentzShift"};
   TTreeReaderArray<vector<int>> hitIsSplit = {fReader, "hitIsSplit"};
   TTreeReaderArray<vector<bool>> hitIsEdge = {fReader, "hitIsEdge"};
   TTreeReaderArray<vector<bool>> hitIsOverflow = {fReader, "hitIsOverflow"};
   TTreeReaderArray<vector<int>> hitIsolation10x2 = {fReader, "hitIsolation10x2"};
   TTreeReaderArray<vector<int>> hitIsolation20x4 = {fReader, "hitIsolation20x4"};
   TTreeReaderArray<vector<float>> hitGlobalX = {fReader, "hitGlobalX"};
   TTreeReaderArray<vector<float>> hitGlobalY = {fReader, "hitGlobalY"};
   TTreeReaderArray<vector<float>> hitGlobalZ = {fReader, "hitGlobalZ"};
   TTreeReaderArray<vector<float>> hitLocalX = {fReader, "hitLocalX"};
   TTreeReaderArray<vector<float>> hitLocalY = {fReader, "hitLocalY"};
   TTreeReaderArray<vector<float>> trkLocalX = {fReader, "trkLocalX"};
   TTreeReaderArray<vector<float>> trkLocalY = {fReader, "trkLocalY"};
   TTreeReaderArray<vector<float>> unbiasedResidualX = {fReader, "unbiasedResidualX"};
   TTreeReaderArray<vector<float>> unbiasedResidualY = {fReader, "unbiasedResidualY"};
   TTreeReaderArray<vector<float>> unbiasedPullX = {fReader, "unbiasedPullX"};
   TTreeReaderArray<vector<float>> unbiasedPullY = {fReader, "unbiasedPullY"};
   TTreeReaderArray<vector<float>> trkPhiOnSurface = {fReader, "trkPhiOnSurface"};
   TTreeReaderArray<vector<float>> trkThetaOnSurface = {fReader, "trkThetaOnSurface"};
   TTreeReaderArray<vector<int>> numTotalClustersPerModule = {fReader, "numTotalClustersPerModule"};
   TTreeReaderArray<vector<int>> numTotalPixelsPerModule = {fReader, "numTotalPixelsPerModule"};
   TTreeReaderArray<vector<vector<int> >> RdoToT = {fReader, "RdoToT"};
   TTreeReaderArray<vector<vector<float> >> RdoCharge = {fReader, "RdoCharge"};
   TTreeReaderArray<vector<vector<int> >> RdoPhi = {fReader, "RdoPhi"};
   TTreeReaderArray<vector<vector<int> >> RdoEta = {fReader, "RdoEta"};
   TTreeReaderArray<vector<vector<int> >> hitTruthPdgId = {fReader, "hitTruthPdgId"};
   TTreeReaderArray<vector<vector<int> >> siHitPdgId = {fReader, "siHitPdgId"};
   TTreeReaderArray<vector<vector<int> >> siHitBarcode = {fReader, "siHitBarcode"};
   TTreeReaderArray<vector<vector<float> >> siHitStartPosX = {fReader, "siHitStartPosX"};
   TTreeReaderArray<vector<vector<float> >> siHitStartPosY = {fReader, "siHitStartPosY"};
   TTreeReaderArray<vector<vector<float> >> siHitEndPosX = {fReader, "siHitEndPosX"};
   TTreeReaderArray<vector<vector<float> >> siHitEndPosY = {fReader, "siHitEndPosY"};
   TTreeReaderArray<vector<vector<float> >> siHitEnergyDeposit = {fReader, "siHitEnergyDeposit"};
   TTreeReaderArray<float> truthEta = {fReader, "truthEta"};
   TTreeReaderArray<float> truthPhi = {fReader, "truthPhi"};
   TTreeReaderArray<float> truthPt = {fReader, "truthPt"};
   TTreeReaderArray<float> truthE = {fReader, "truthE"};
   TTreeReaderArray<float> truthCharge = {fReader, "truthCharge"};
   TTreeReaderArray<int> truthPdgId = {fReader, "truthPdgId"};
   TTreeReaderArray<int> truthBarcode = {fReader, "truthBarcode"};
   TTreeReaderArray<int> truthStatus = {fReader, "truthStatus"};
   TTreeReaderArray<float> muonEta = {fReader, "muonEta"};
   TTreeReaderArray<float> muonPhi = {fReader, "muonPhi"};
   TTreeReaderArray<float> muonPt = {fReader, "muonPt"};
   TTreeReaderArray<float> muonE = {fReader, "muonE"};
   TTreeReaderArray<float> jetEta = {fReader, "jetEta"};
   TTreeReaderArray<float> jetPhi = {fReader, "jetPhi"};
   TTreeReaderArray<float> jetPt = {fReader, "jetPt"};
   TTreeReaderArray<float> jetE = {fReader, "jetE"};
   TTreeReaderArray<int> jetPassJVT = {fReader, "jetPassJVT"};
   TTreeReaderArray<float> tauEta = {fReader, "tauEta"};
   TTreeReaderArray<float> tauPhi = {fReader, "tauPhi"};
   TTreeReaderArray<float> tauPt = {fReader, "tauPt"};
   TTreeReaderArray<float> tauM = {fReader, "tauM"};
   TTreeReaderArray<float> tauCharge = {fReader, "tauCharge"};
   TTreeReaderArray<int> tauNumTracksCharged = {fReader, "tauNumTracksCharged"};
   TTreeReaderArray<int> tauNumTracksIsolation = {fReader, "tauNumTracksIsolation"};
   TTreeReaderArray<int> tauNumAllTracks = {fReader, "tauNumAllTracks"};
   TTreeReaderArray<int> tauTrackFilterProngs = {fReader, "tauTrackFilterProngs"};
   TTreeReaderArray<int> tauTrackFilterQuality = {fReader, "tauTrackFilterQuality"};
   TTreeReaderArray<int> tauNumClusters = {fReader, "tauNumClusters"};
   TTreeReaderArray<int> tauNumPi0s = {fReader, "tauNumPi0s"};
   TTreeReaderArray<int> tauNumCells = {fReader, "tauNumCells"};
   TTreeReaderArray<int> tauIsTauFlags = {fReader, "tauIsTauFlags"};
   TTreeReaderArray<float> tauBDTJetScore = {fReader, "tauBDTJetScore"};
   TTreeReaderArray<float> tauBDTEleScore = {fReader, "tauBDTEleScore"};
   TTreeReaderArray<float> tauEleMatchLikelihoodScore = {fReader, "tauEleMatchLikelihoodScore"};
   TTreeReaderArray<float> tauBDTJetScoreSigTrans = {fReader, "tauBDTJetScoreSigTrans"};
   TTreeReaderArray<float> tauRNNJetScore = {fReader, "tauRNNJetScore"};
   TTreeReaderArray<float> tauRNNJetScoreSigTrans = {fReader, "tauRNNJetScoreSigTrans"};
   TTreeReaderArray<float> tauIpZ0SinThetaSigLeadTrk = {fReader, "tauIpZ0SinThetaSigLeadTrk"};
   TTreeReaderArray<float> tauEtOverPtLeadTrk = {fReader, "tauEtOverPtLeadTrk"};
   TTreeReaderArray<float> tauLeadTrkPt = {fReader, "tauLeadTrkPt"};
   TTreeReaderArray<float> tauIpSigLeadTrk = {fReader, "tauIpSigLeadTrk"};
   TTreeReaderArray<float> tauMassTrkSys = {fReader, "tauMassTrkSys"};
   TTreeReaderArray<float> tauTrkWidth2 = {fReader, "tauTrkWidth2"};
   TTreeReaderArray<float> tauTrFlightPathSig = {fReader, "tauTrFlightPathSig"};
   TTreeReaderArray<float> tauEMRadius = {fReader, "tauEMRadius"};
   TTreeReaderArray<float> tauHadRadius = {fReader, "tauHadRadius"};
   TTreeReaderArray<float> tauEtEMAtEMScale = {fReader, "tauEtEMAtEMScale"};
   TTreeReaderArray<float> tauEtHadAtEMScale = {fReader, "tauEtHadAtEMScale"};
   TTreeReaderArray<float> tauIsolFrac = {fReader, "tauIsolFrac"};
   TTreeReaderArray<float> tauCentFrac = {fReader, "tauCentFrac"};
   TTreeReaderArray<float> tauStripWidth2 = {fReader, "tauStripWidth2"};
   TTreeReaderArray<int> tauNumStrip = {fReader, "tauNumStrip"};
   TTreeReaderArray<float> tauTrkAvgDist = {fReader, "tauTrkAvgDist"};
   TTreeReaderArray<float> tauDRmax = {fReader, "tauDRmax"};
   TTreeReaderValue<Float_t> metCaloPx = {fReader, "metCaloPx"};
   TTreeReaderValue<Float_t> metCaloPy = {fReader, "metCaloPy"};
   TTreeReaderValue<Float_t> metCaloET = {fReader, "metCaloET"};
   TTreeReaderValue<Float_t> metCaloSumET = {fReader, "metCaloSumET"};
   TTreeReaderValue<Float_t> metTrackPx = {fReader, "metTrackPx"};
   TTreeReaderValue<Float_t> metTrackPy = {fReader, "metTrackPy"};
   TTreeReaderValue<Float_t> metTrackET = {fReader, "metTrackET"};
   TTreeReaderValue<Float_t> metTrackSumET = {fReader, "metTrackSumET"};
   TTreeReaderValue<Float_t> metLocHadPx = {fReader, "metLocHadPx"};
   TTreeReaderValue<Float_t> metLocHadPy = {fReader, "metLocHadPy"};
   TTreeReaderValue<Float_t> metLocHadET = {fReader, "metLocHadET"};
   TTreeReaderValue<Float_t> metLocHadSumET = {fReader, "metLocHadSumET"};
   TTreeReaderValue<Float_t> metCoreLCTopoPx = {fReader, "metCoreLCTopoPx"};
   TTreeReaderValue<Float_t> metCoreLCTopoPy = {fReader, "metCoreLCTopoPy"};
   TTreeReaderValue<Float_t> metCoreLCTopoET = {fReader, "metCoreLCTopoET"};
   TTreeReaderValue<Float_t> metCoreLCTopoSumET = {fReader, "metCoreLCTopoSumET"};
   TTreeReaderValue<Float_t> metRefLCTopoPx = {fReader, "metRefLCTopoPx"};
   TTreeReaderValue<Float_t> metRefLCTopoPy = {fReader, "metRefLCTopoPy"};
   TTreeReaderValue<Float_t> metRefLCTopoET = {fReader, "metRefLCTopoET"};
   TTreeReaderValue<Float_t> metRefLCTopoSumET = {fReader, "metRefLCTopoSumET"};
   TTreeReaderValue<Float_t> metTruthPx = {fReader, "metTruthPx"};
   TTreeReaderValue<Float_t> metTruthPy = {fReader, "metTruthPy"};
   TTreeReaderValue<Float_t> metTruthET = {fReader, "metTruthET"};
   TTreeReaderValue<Float_t> metTruthSumET = {fReader, "metTruthSumET"};


   MySelector(TTree * /*tree*/ =0) { }
   virtual ~MySelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   //Histograms
   std::vector<TH2F*> ListTH2F;
   std::vector<TH1F*> ListTH1F;

   //TH1F
   TH1F* h_LB;
   TH1F* hist_trk_num; 
   TH1F* hist_trktrue_num; 
   TH1F* hist_truth_num; 
   TH1F* hist_trk_pt;  
   TH1F* hist_true_pt;  
   TH1F* hist_truepass_pt;  
   TH1F* hist_trkpass_pt;  
   TH1F* hist_trk_phi; 
   TH1F* hist_true_phi;  
   TH1F* hist_truepass_phi;  
   TH1F* hist_hitpass_phi;  
   TH1F* hist_trk_eta; 
   TH1F* hist_true_eta;  
   TH1F* hist_truepass_eta;  
   //TH1F* hist_true_numVtx;  
   //TH1F* hist_truepass_numVtx;  
   TH1F* hist_true_avePU;  
   TH1F* hist_truepass_avePU;  
   TH1F* hist_hitpass_eta;  
   TH1F* hist_trk_qoverp;  
   TH1F* hist_trk_d0;      
   TH1F* hist_trk_z0;      
   TH1F* hist_trk_deltaZ;  
   TH1F* h_trackD0Err;
   TH1F* h_trackZ0Err;
   TH1F* h_trackTheta;
   TH1F* h_trackCharge;
   TH1F* h_trackMindR;
   TH1F* h_trackClass;
   TH1F* h_trackPassCut;
   TH1F* hist_numVtx;             

   TH1F* hist_trk_dpt;
   TH1F* hist_trk_dphi; 
   TH1F* hist_trk_deta; 
   TH1F* hist_trk_dd0; 
   TH1F* hist_trk_dz0; 

   TH1F* hist_trk_dr; 
   TH1F* hist_trkeff_pt;
   TH1F* hist_trkeff_phi; 
   TH1F* hist_trkeff_eta; 
   //TH1F* hist_trkeff_numVtx; 
   TH1F* hist_trkeff_avePU; 

   TH1F* hist_trk_nPixHits; 
   TH1F* hist_trk_nGangedPix; 
   TH1F* hist_trk_nPixLay; 
   TH1F* hist_trk_nPixSharedHits; 
   TH1F* hist_trk_nPixSplitHits; 
   TH1F* hist_trk_nPixOutliers; 
   TH1F* hist_trk_nPixHoles; 
   TH1F* hist_trk_nPixelDeadSensors; 
   TH1F* hist_trk_nOutliers;
   TH1F* hist_trk_stdDevChi2OS;
   TH1F* h_trackChiSqPerDof;      

   TH1F* h_trackNIBLUsedHits;     
   TH1F* h_trackNBLUsedHits;      
   TH1F* h_trackNSplitIBLHits;    
   TH1F* h_trackNSplitBLHits;     
   TH1F* h_trackNSharedIBLHits;   
   TH1F* h_trackNSharedBLHits;    
   TH1F* h_trackNIBLHits;        
   TH1F* h_trackNBLHits;         
   TH1F* h_trackNL1Hits;         
   TH1F* h_trackNL2Hits;         
   TH1F* h_trackNIBLExpectedHits;
   TH1F* h_trackNBLExpectedHits; 
   TH1F* hist_IBL_MapHitEtaeff; 
   TH1F* hist_IBL_MapHitEta; 
   TH1F* hist_IBL_MapEta; 
   TH1F* hist_IBL_MapHitPteff; 
   TH1F* hist_IBL_MapHitPt; 
   TH1F* hist_IBL_MapPt; 
   //TH1F* hist_IBL_MapHitnumVtxeff;
   //TH1F* hist_BLY_MapHitnumVtxeff;
   //TH1F* hist_LY1_MapHitnumVtxeff;
   //TH1F* hist_LY2_MapHitnumVtxeff;
   //TH1F* hist_IBL_MapHitnumVtx;   
   //TH1F* hist_BLY_MapHitnumVtx;   
   //TH1F* hist_LY1_MapHitnumVtx;   
   //TH1F* hist_LY2_MapHitnumVtx;   
   //TH1F* hist_IBL_MapnumVtx;   
   //TH1F* hist_BLY_MapnumVtx;   
   //TH1F* hist_LY1_MapnumVtx;   
   //TH1F* hist_LY2_MapnumVtx;   
   TH1F* hist_IBL_MapHitavePUeff;
   TH1F* hist_BLY_MapHitavePUeff;
   TH1F* hist_LY1_MapHitavePUeff;
   TH1F* hist_LY2_MapHitavePUeff;
   TH1F* hist_IBL_MapHitavePU;   
   TH1F* hist_BLY_MapHitavePU;   
   TH1F* hist_LY1_MapHitavePU;   
   TH1F* hist_LY2_MapHitavePU;   
   TH1F* hist_IBL_MapavePU;   
   TH1F* hist_BLY_MapavePU;   
   TH1F* hist_LY1_MapavePU;   
   TH1F* hist_LY2_MapavePU;   

   //TH1F* hist_trk_truthMatchProb  ;
   TH1F* hist_BLY_IsEdge; 
   TH1F* hist_BLY_IsOverflow; 
   TH1F* hist_BLY_IsSplit; 
   TH1F* hist_BLY_L1A;
   TH1F* hist_BLY_ToT; 
   TH1F* hist_BLY_Charge; 
   TH1F* hist_BLY_MapHitEta; 
   TH1F* hist_BLY_MapEta; 
   TH1F* hist_BLY_MapHitEtaeff; 
   TH1F* hist_BLY_MapHitPt; 
   TH1F* hist_BLY_MapPt; 
   TH1F* hist_BLY_MapHitPteff; 
   //TH1F* hist_BLY_dEdx            ; 
   TH1F* hist_BLY_HitSize           ; 
   TH1F* hist_BLY_HitSizePhi        ; 
   TH1F* hist_BLY_HitSizeZ          ; 
   TH1F* hist_BLY_unbiasedResidualX ;
   TH1F* hist_BLY_unbiasedResidualY ;
   TH1F* hist_BLY_Isolation10x2     ;
   TH1F* hist_BLY_Isolation20x4     ;
   TH1F* hist_BLY_numTotalClustersPerModule ;
   TH1F* hist_BLY_numTotalPixelsPerModule   ;
   TH1F* hist_LY1_IsEdge            ; 
   TH1F* hist_LY1_IsOverflow        ; 
   TH1F* hist_LY1_IsSplit           ; 
   TH1F* hist_LY1_L1A               ;
   TH1F* hist_LY1_ToT               ; 
   TH1F* hist_LY1_Charge            ; 
   TH1F* hist_LY1_MapHitEta; 
   TH1F* hist_LY1_MapEta; 
   TH1F* hist_LY1_MapHitEtaeff; 
   TH1F* hist_LY1_MapHitPt; 
   TH1F* hist_LY1_MapPt; 
   TH1F* hist_LY1_MapHitPteff; 
   //TH1F* hist_LY1_dEdx            ; 
   TH1F* hist_LY1_HitSize           ;
   TH1F* hist_LY1_HitSizePhi        ;
   TH1F* hist_LY1_HitSizeZ          ;
   TH1F* hist_LY1_unbiasedResidualX ;
   TH1F* hist_LY1_unbiasedResidualY ;
   TH1F* hist_LY1_Isolation10x2     ;
   TH1F* hist_LY1_Isolation20x4     ;
   TH1F* hist_LY1_numTotalClustersPerModule ;
   TH1F* hist_LY1_numTotalPixelsPerModule   ;
   TH1F* hist_LY2_IsEdge            ; 
   TH1F* hist_LY2_IsOverflow        ; 
   TH1F* hist_LY2_IsSplit           ; 
   TH1F* hist_LY2_L1A               ;
   TH1F* hist_LY2_ToT               ; 
   TH1F* hist_LY2_Charge            ; 
   TH1F* hist_LY2_MapHitEta; 
   TH1F* hist_LY2_MapEta; 
   TH1F* hist_LY2_MapHitEtaeff; 
   TH1F* hist_LY2_MapHitPt; 
   TH1F* hist_LY2_MapPt; 
   TH1F* hist_LY2_MapHitPteff; 
   //TH1F* hist_LY2_dEdx            ; 
   TH1F* hist_LY2_HitSize           ; 
   TH1F* hist_LY2_HitSizePhi        ; 
   TH1F* hist_LY2_HitSizeZ          ; 
   TH1F* hist_LY2_unbiasedResidualX ;
   TH1F* hist_LY2_unbiasedResidualY ;
   TH1F* hist_LY2_Isolation10x2     ;
   TH1F* hist_LY2_Isolation20x4     ;
   TH1F* hist_LY2_numTotalClustersPerModule ;
   TH1F* hist_LY2_numTotalPixelsPerModule   ;

   //TH2F

   ClassDef(MySelector,0);

};

#endif

#ifdef MySelector_cxx
void MySelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t MySelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef MySelector_cxx
