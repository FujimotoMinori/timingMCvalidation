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
    h_LB= new TH1F("LB", "; LB; Events", 100, 0.0, 1500.0);
    hist_trk_num = new TH1F("hist_trk_num","", 200,  0.0, 1000.0); 
    hist_trk_pt  = new TH1F("hist_trk_pt","",  200,  0.0, 50.0); 
    hist_trk_eta = new TH1F("hist_trk_eta","",  56, -2.8, 2.8); 
    hist_trk_phi = new TH1F("hist_trk_phi","",  64,  -TMath::Pi(), TMath::Pi()); 
    hist_trk_qoverp = new TH1F("hist_trk_qoverp", "", 200,  -2e-3,  2e-3); 
    hist_trk_d0     = new TH1F("hist_trk_d0",     "", 100,   -0.2,   0.2); 
    hist_trk_z0     = new TH1F("hist_trk_z0",     "", 100, -200.0, 200.0); 
    hist_trk_deltaZ = new TH1F("hist_trk_deltaZ", "", 100, -5.0, 5.0);
    /* Resolution */
    hist_trk_dpt   = new TH1F("hist_trk_dpt",  "", 100, -5.0, 5.0); 
    hist_trk_dphi  = new TH1F("hist_trk_dphi", "", 100, -5.0, 5.0); 
    hist_trk_deta  = new TH1F("hist_trk_deta", "", 100, -5.0, 5.0); 
    hist_trk_dd0   = new TH1F("hist_trk_dd0",  "", 100, -5.0, 5.0); 
    hist_trk_dz0   = new TH1F("hist_trk_dz0",  "", 100, -5.0, 5.0); 
    /* track*/
    hist_trk_nPixHits = new TH1F("hist_trk_nPixHits", "", 16, -0.5, 15.5); 
    hist_trk_nGangedPix        = new TH1F("hist_trk_nGangedPix",        "",   8, -0.5,  7.5); 
    hist_trk_nPixLay           = new TH1F("hist_trk_nPixLay",           "",  10, -0.5,  9.5); 
    hist_trk_nPixSharedHits    = new TH1F("hist_trk_nPixSharedHits",    "",   8, -0.5,  7.5); 
    hist_trk_nPixSplitHits     = new TH1F("hist_trk_nPixSplitHits",     "",   8, -0.5,  7.5); 
    hist_trk_nPixOutliers      = new TH1F("hist_trk_nPixOutliers",      "",   8, -0.5,  7.5); 
    hist_trk_nPixHoles         = new TH1F("hist_trk_nPixHoles",         "",   8, -0.5,  7.5); 
    hist_trk_nPixelDeadSensors = new TH1F("hist_trk_nPixelDeadSensors", "",   8, -0.5,  7.5); 
    hist_trk_nOutliers         = new TH1F("hist_trk_nOutliers",         "",  20, -0.5, 19.5);
    hist_trk_stdDevChi2OS      = new TH1F("hist_trk_stdDevChi2OS",      "", 100,  0.0, 500.0);
    //hist_trk_truthMatchProb    = new TH1F("hist_trk_truthMatchProb",    "", 100,  0.0,  1.0);
    /* cluster */
    hist_BLY_IsEdge            = new TH1F("hist_BLY_IsEdge",            "",   2, -0.5,   1.5); 
    hist_BLY_IsOverflow        = new TH1F("hist_BLY_IsOverflow",        "",   2, -0.5,   1.5); 
    hist_BLY_IsSplit           = new TH1F("hist_BLY_IsSplit",           "",   2, -0.5,   1.5); 
    hist_BLY_L1A               = new TH1F("hist_BLY_L1A",               "",   6, -2.5,   3.5);
    hist_BLY_ToT               = new TH1F("hist_BLY_ToT",               "", 100, -0.5, 199.5); 
    hist_BLY_Charge            = new TH1F("hist_BLY_Charge",            "",  60,  0.0, 120.0); 
    //hist_BLY_dEdx              = new TH1F("hist_BLY_dEdx",              "",  50,  0.0,  10.0); 
    //hist_BLY_dEdxVsP           = new TH2F("hist_BLY_dEdxVsP",           "", 500,  0.0,5000.0, 200, 0.0, 20.0); 
    hist_BLY_HitSize           = new TH1F("hist_BLY_HitSize",           "",  20,  0.0,  20.0); 
    hist_BLY_HitSizePhi        = new TH1F("hist_BLY_HitSizePhi",        "",  10,  0.0,  20.0); 
    hist_BLY_HitSizeZ          = new TH1F("hist_BLY_HitSizeZ",          "",   8,  0.0,   8.0); 
    hist_BLY_unbiasedResidualX = new TH1F("hist_BLY_unbiasedResidualX", "", 100, -0.3,   0.3);
    hist_BLY_unbiasedResidualY = new TH1F("hist_BLY_unbiasedResidualY", "", 100, -0.5,   0.5);
    hist_BLY_Isolation10x2     = new TH1F("hist_BLY_Isolation10x2",     "",  20,  0.0,  20.0);
    hist_BLY_Isolation20x4     = new TH1F("hist_BLY_Isolation20x4",     "",  20,  0.0,  20.0);
    hist_BLY_numTotalClustersPerModule = new TH1F("hist_BLY_numTotalClustersPerModule", "", 50.0,0.0, 50.0);
    hist_BLY_numTotalPixelsPerModule   = new TH1F("hist_BLY_numTotalPixelsPerModule",   "", 50.0,0.0,100.0);
    //hist_BLY_LorentzAngle      = new TH2F("hist_BLY_LorentzAngle", "", 50,  0.0, 1.0, 10, 0.0, 20.0);
    //hist_BLY_Map               = new TH2F("hist_BLY_Map",          "", 30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
    //hist_BLY_MapHit            = new TH2F("hist_BLY_MapHit",       "", 30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
    //hist_BLY_MapEta            = new TH1F("hist_BLY_MapEta",       "", 30, -3.0, 3.0);
    //hist_BLY_MapHitEta         = new TH1F("hist_BLY_MapHitEta",    "", 30, -3.0, 3.0);

    hist_LY1_IsEdge            = new TH1F("hist_LY1_IsEdge",     "",   2, -0.5, 1.5); 
    hist_LY1_IsOverflow        = new TH1F("hist_LY1_IsOverflow", "",   2, -0.5, 1.5); 
    hist_LY1_IsSplit           = new TH1F("hist_LY1_IsSplit",    "",   2, -0.5, 1.5); 
    hist_LY1_L1A               = new TH1F("hist_LY1_L1A",        "",   6, -2.5, 3.5);
    hist_LY1_ToT               = new TH1F("hist_LY1_ToT",        "", 100, -0.5, 199.5); 
    hist_LY1_Charge            = new TH1F("hist_LY1_Charge",     "",  60,  0.0, 120.0); 
    //hist_LY1_dEdx              = new TH1F("hist_LY1_dEdx",       "",  50,  0.0, 10.0); 
    //hist_LY1_dEdxVsP           = new TH2F("hist_LY1_dEdxVsP",    "", 500,  0.0, 5000.0, 200, 0.0, 20.0); 
    hist_LY1_HitSize           = new TH1F("hist_LY1_HitSize",    "",  20,  0.0, 20.0); 
    hist_LY1_HitSizePhi        = new TH1F("hist_LY1_HitSizePhi", "",  10,  0.0, 20.0); 
    hist_LY1_HitSizeZ          = new TH1F("hist_LY1_HitSizeZ",   "",   8,  0.0,  8.0); 
    hist_LY1_unbiasedResidualX = new TH1F("hist_LY1_unbiasedResidualX", "", 100, -0.3, 0.3);
    hist_LY1_unbiasedResidualY = new TH1F("hist_LY1_unbiasedResidualY", "", 100, -0.5, 0.5);
    hist_LY1_Isolation10x2     = new TH1F("hist_LY1_Isolation10x2",     "", 20,   0.0, 20.0);
    hist_LY1_Isolation20x4     = new TH1F("hist_LY1_Isolation20x4",     "", 20,   0.0, 20.0);
    hist_LY1_numTotalClustersPerModule = new TH1F("hist_LY1_numTotalClustersPerModule", "", 50, 0.0,  50.0);
    hist_LY1_numTotalPixelsPerModule   = new TH1F("hist_LY1_numTotalPixelsPerModule",   "", 50, 0.0, 100.0);
    //hist_LY1_LorentzAngle      = new TH2F("hist_LY1_LorentzAngle", "",  50,  0.0, 1.0, 10, 0.0, 20.0);
    //hist_LY1_Map               = new TH2F("hist_LY1_Map",          "",  30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
    //hist_LY1_MapHit            = new TH2F("hist_LY1_MapHit",       "",  30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
    //hist_LY1_MapEta            = new TH1F("hist_LY1_MapEta",       "",  30, -3.0, 3.0);
    //hist_LY1_MapHitEta         = new TH1F("hist_LY1_MapHitEta",    "",  30, -3.0, 3.0);

    hist_LY2_IsEdge            = new TH1F("hist_LY2_IsEdge",            "",   2, -0.5,   1.5); 
    hist_LY2_IsOverflow        = new TH1F("hist_LY2_IsOverflow",        "",   2, -0.5,   1.5); 
    hist_LY2_IsSplit           = new TH1F("hist_LY2_IsSplit",           "",   2, -0.5,   1.5); 
    hist_LY2_L1A               = new TH1F("hist_LY2_L1A",               "",   6, -2.5,   3.5);
    hist_LY2_ToT               = new TH1F("hist_LY2_ToT",               "", 100, -0.5, 199.5); 
    hist_LY2_Charge            = new TH1F("hist_LY2_Charge",            "",  60,  0.0, 120.0); 
    //hist_LY2_dEdx              = new TH1F("hist_LY2_dEdx",              "",  50,  0.0,  10.0); 
    //hist_LY2_dEdxVsP           = new TH2F("hist_LY2_dEdxVsP",           "", 500,  0.0,5000.0, 200, 0.0, 20.0); 
    hist_LY2_HitSize           = new TH1F("hist_LY2_HitSize",           "",  20,  0.0,  20.0); 
    hist_LY2_HitSizePhi        = new TH1F("hist_LY2_HitSizePhi",        "",  10,  0.0,  20.0); 
    hist_LY2_HitSizeZ          = new TH1F("hist_LY2_HitSizeZ",          "",   8,  0.0,   8.0); 
    hist_LY2_unbiasedResidualX = new TH1F("hist_LY2_unbiasedResidualX", "", 100, -0.3,   0.3);
    hist_LY2_unbiasedResidualY = new TH1F("hist_LY2_unbiasedResidualY", "", 100, -0.5,   0.5);
    hist_LY2_Isolation10x2     = new TH1F("hist_LY2_Isolation10x2",     "",  20,  0.0,  20.0);
    hist_LY2_Isolation20x4     = new TH1F("hist_LY2_Isolation20x4",     "",  20,  0.0,  20.0);
    hist_LY2_numTotalClustersPerModule = new TH1F("hist_LY2_numTotalClustersPerModule", "", 50, 0.0,  50.0);
    hist_LY2_numTotalPixelsPerModule   = new TH1F("hist_LY2_numTotalPixelsPerModule",   "", 50, 0.0, 100.0);
    //hist_LY2_LorentzAngle      = new TH2F("hist_LY2_LorentzAngle", "",  50,  0.0, 1.0, 10, 0.0, 20.0);
    //hist_LY2_Map               = new TH2F("hist_LY2_Map",          "",  30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
    //hist_LY2_MapHit            = new TH2F("hist_LY2_MapHit",       "",  30, -3.0, 3.0, 30, -TMath::Pi(), TMath::Pi());
    //hist_LY2_MapEta            = new TH1F("hist_LY2_MapEta",       "",  30, -3.0, 3.0);
    //hist_LY2_MapHitEta         = new TH1F("hist_LY2_MapHitEta",    "",  30, -3.0, 3.0);
    ListTH1F.push_back(h_LB);
    ListTH1F.push_back(hist_trk_num); 
    ListTH1F.push_back(hist_trk_pt);  
    ListTH1F.push_back(hist_trk_eta); 
    ListTH1F.push_back(hist_trk_phi); 
    ListTH1F.push_back(hist_trk_qoverp);  
    ListTH1F.push_back(hist_trk_d0);      
    ListTH1F.push_back(hist_trk_z0);      
    ListTH1F.push_back(hist_trk_deltaZ); 
    ListTH1F.push_back(hist_trk_dpt); 
    ListTH1F.push_back(hist_trk_dph); 
    ListTH1F.push_back(hist_trk_det); 
    ListTH1F.push_back(hist_trk_dd0); 
    ListTH1F.push_back(hist_trk_dz0); 
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
    //ListTH1F.push_back(hist_trk_truthMatchProb    );
    ListTH1F.push_back(hist_BLY_IsEdge            ); 
    ListTH1F.push_back(hist_BLY_IsOverflow        ); 
    ListTH1F.push_back(hist_BLY_IsSplit           ); 
    ListTH1F.push_back(hist_BLY_L1A               );
    ListTH1F.push_back(hist_BLY_ToT               ); 
    ListTH1F.push_back(hist_BLY_Charge            ); 
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
    //histWeight*=pileupWeight*mcWeight;

    int ntracks = (int)(trackPt).GetSize();
    hist_trk_num->Fill(ntracks); 
    for (int i=0; i<ntracks; i++) { //track loop
        hist_trk_pt->Fill(trackPt[i]);   
        hist_trk_eta->Fill(trackEta[i]);  
        hist_trk_phi->Fill(trackPhi[i]);   
        hist_trk_qoverp->Fill(trackqOverP[i]); 
        hist_trk_d0->Fill(trackD0[i]);     
        hist_trk_z0->Fill(trackZ0[i]);     
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
        /*resolution*/
        hist_trk_dpt->Fill(trackPt[i]-truePt[i]/truePt[i]);
        hist_trk_dph->Fill(trackPhi[i]-truePhi[i]/truePhi[i]);
        hist_trk_det->Fill(trackEta[i]-trueEta[i]/trueEta[i]);
        hist_trk_dd0->Fill(trackD0[i]-trueD0[i]/trueD0[i]);
        hist_trk_dz0->Fill(trackZ0[i]-trueZ0[i]/trueZ0[i]);

        for (int j=0; j<(int)(hitLayer)[i].GetSize(); j++) {
            if ((*hitIsEndCap)[i][j]==0 && (*hitLayer)[i][j]==1) { //blayer
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
                hist_BLY_numTotalPixelsPerModule->Fill(numTotalPixelClustersPerModule[i][j]); 
            }
            else if ((*hitIsEndCap)[i][j]==0 && (*hitLayer)[i][j]==2) { //layer1
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
                hist_LY1_numTotalPixelsPerModule->Fill(numTotalPixelClustersPerModule[i][j]); 
            }
            else if ((*hitIsEndCap)[i][j]==0 && (*hitLayer)[i][j]==3) { //layer2
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
                hist_LY1_numTotalPixelsPerModule->Fill(numTotalPixelClustersPerModule[i][j]); 
            }
        }

    } //end of track loop
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
