// -*- C++ -*-
//
// Package:    test/test1
// Class:      test1
// 
/**\class test1 test1.cc test/test1/plugins/test1.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Pallabi Das
//         Created:  Fri, 01 Apr 2016 05:51:53 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/METReco/interface/CaloMETCollection.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "TLorentzVector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <TH1F.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <TFile.h>

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

//class test1 : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
class test1 : public edm::EDAnalyzer {
   public:
      explicit test1(const edm::ParameterSet&);
      ~test1();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;
	TFile *file;
	TH1F *h1, *h2, *h3, *h4, *h5, *h6, *h7, *h8, *h9, *h10, *h11, *h12, *h13, *h14, *h15, *h16, *h17, *h18, *h19, *h20;
	TH1F *h21, *h22, *h23, *h24, *h25, *h26, *h27, *h28, *h29, *h30, *h31, *h32, *h33, *h34, *h35, *h36, *h37, *h38, *h39, *h40;
	TH1F *h41, *h42, *h43, *h44, *h45, *h46, *h47, *h48, *h49, *h50, *h51, *h52, *h53, *h54, *h55, *h56, *h57, *h58, *h59, *h60;
	TH1F *h61;
	TH2F *k1, *k2, *k3, *k4, *k5, *k6, *k7, *k8;
	TH1F *m1, *m2, *m3, *m4, *m5, *m6, *m7, *m8, *m9, *m10, *m11, *m12, *m13, *m14, *m15, *m16, *m17, *m18, *m19, *m20;
	TH1F *m21, *m22, *m23, *m24, *m25, *m26, *m27, *m28, *m29, *m30, *m31, *m32, *m33, *m34, *m35, *m36, *m37, *m38, *m39, *m40;
      // ----------member data ---------------------------
	edm::EDGetTokenT<pat::METCollection> metToken;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
test1::test1(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
        metToken = consumes<pat::METCollection>(iConfig.getParameter<edm::InputTag>("mets"));
 //       usesResource("TFileService");

}


test1::~test1()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
test1::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	using namespace edm;
	using namespace std;
        Handle<pat::METCollection> mets;
        iEvent.getByToken(metToken, mets);
        const pat::MET &met = mets->front();
//        printf("MET: pt %5.1f, phi %+4.2f, sumEt (%.1f). genMET %.1f. MET with JES up/down: %.1f/%.1f\n", met.pt(), met.phi(), met.sumEt(), met.genMET()->pt(), met.shiftedPt(pat::MET::JetEnUp), met.shiftedPt(pat::MET::JetEnDown));
	h1->Fill(met.pt()); h2->Fill(met.phi()); h3->Fill(met.sumEt());
	h4->Fill(met.genMET()->pt()); 
	h5->Fill(met.shiftedPt(pat::MET::JetResUp));
	h6->Fill(met.shiftedPt(pat::MET::JetResDown));
	h7->Fill(met.shiftedPt(pat::MET::JetEnUp));
	h8->Fill(met.shiftedPt(pat::MET::JetEnDown)); 	
	h9->Fill(met.shiftedPt(pat::MET::MuonEnUp));
	h10->Fill(met.shiftedPt(pat::MET::MuonEnDown));
	h11->Fill(met.shiftedPt(pat::MET::ElectronEnUp));
	h12->Fill(met.shiftedPt(pat::MET::ElectronEnDown));
	h13->Fill(met.shiftedPt(pat::MET::TauEnUp));
	h14->Fill(met.shiftedPt(pat::MET::TauEnDown));
	h15->Fill(met.shiftedPt(pat::MET::UnclusteredEnUp));
	h16->Fill(met.shiftedPt(pat::MET::UnclusteredEnDown));
	h17->Fill(met.shiftedPt(pat::MET::PhotonEnUp));
	h18->Fill(met.shiftedPt(pat::MET::PhotonEnDown));
	h19->Fill(met.shiftedPt(pat::MET::NoShift));
	h20->Fill(met.shiftedPt(pat::MET::METUncertaintySize));
	h21->Fill(met.shiftedPt(pat::MET::JetResUpSmear));
	h22->Fill(met.shiftedPt(pat::MET::JetResDownSmear));
	h23->Fill(met.shiftedPt(pat::MET::METFullUncertaintySize));
	h24->Fill(met.shiftedPhi(pat::MET::JetResUp));
	h25->Fill(met.shiftedPhi(pat::MET::JetResDown));
	h26->Fill(met.shiftedPhi(pat::MET::JetEnUp));
	h27->Fill(met.shiftedPhi(pat::MET::JetEnDown)); 	
	h28->Fill(met.shiftedPhi(pat::MET::MuonEnUp));
	h29->Fill(met.shiftedPhi(pat::MET::MuonEnDown));
	h30->Fill(met.shiftedPhi(pat::MET::ElectronEnUp));
	h31->Fill(met.shiftedPhi(pat::MET::ElectronEnDown));
	h32->Fill(met.shiftedPhi(pat::MET::TauEnUp));
	h33->Fill(met.shiftedPhi(pat::MET::TauEnDown));
	h34->Fill(met.shiftedPhi(pat::MET::UnclusteredEnUp));
	h35->Fill(met.shiftedPhi(pat::MET::UnclusteredEnDown));
	h36->Fill(met.shiftedPhi(pat::MET::PhotonEnUp));
	h37->Fill(met.shiftedPhi(pat::MET::PhotonEnDown));
	h38->Fill(met.shiftedPhi(pat::MET::NoShift));
	h39->Fill(met.shiftedPhi(pat::MET::METUncertaintySize));
	h40->Fill(met.shiftedPhi(pat::MET::JetResUpSmear));
	h41->Fill(met.shiftedPhi(pat::MET::JetResDownSmear));
	h42->Fill(met.shiftedPhi(pat::MET::METFullUncertaintySize));
	h43->Fill(met.shiftedSumEt(pat::MET::JetResUp));
	h44->Fill(met.shiftedSumEt(pat::MET::JetResDown));
	h45->Fill(met.shiftedSumEt(pat::MET::JetEnUp));
	h46->Fill(met.shiftedSumEt(pat::MET::JetEnDown)); 	
	h47->Fill(met.shiftedSumEt(pat::MET::MuonEnUp));
	h48->Fill(met.shiftedSumEt(pat::MET::MuonEnDown));
	h49->Fill(met.shiftedSumEt(pat::MET::ElectronEnUp));
	h50->Fill(met.shiftedSumEt(pat::MET::ElectronEnDown));
	h51->Fill(met.shiftedSumEt(pat::MET::TauEnUp));
	h52->Fill(met.shiftedSumEt(pat::MET::TauEnDown));
	h53->Fill(met.shiftedSumEt(pat::MET::UnclusteredEnUp));
	h54->Fill(met.shiftedSumEt(pat::MET::UnclusteredEnDown));
	h55->Fill(met.shiftedSumEt(pat::MET::PhotonEnUp));
	h56->Fill(met.shiftedSumEt(pat::MET::PhotonEnDown));
	h57->Fill(met.shiftedSumEt(pat::MET::NoShift));
	h58->Fill(met.shiftedSumEt(pat::MET::METUncertaintySize));
	h59->Fill(met.shiftedSumEt(pat::MET::JetResUpSmear));
	h60->Fill(met.shiftedSumEt(pat::MET::JetResDownSmear));
	h61->Fill(met.shiftedSumEt(pat::MET::METFullUncertaintySize));
	k1->Fill(met.shiftedPt(pat::MET::JetResUp)-met.shiftedPt(pat::MET::JetResDown),met.pt());
	k2->Fill(met.shiftedPt(pat::MET::JetEnUp)-met.shiftedPt(pat::MET::JetEnDown),met.pt());
	k3->Fill(met.shiftedPt(pat::MET::MuonEnUp)-met.shiftedPt(pat::MET::MuonEnDown),met.pt());
	k4->Fill(met.shiftedPt(pat::MET::ElectronEnUp)-met.shiftedPt(pat::MET::ElectronEnDown),met.pt());
	k5->Fill(met.shiftedPt(pat::MET::TauEnUp)-met.shiftedPt(pat::MET::TauEnDown),met.pt());
	k6->Fill(met.shiftedPt(pat::MET::UnclusteredEnUp)-met.shiftedPt(pat::MET::UnclusteredEnDown),met.pt());
	k7->Fill(met.shiftedPt(pat::MET::PhotonEnUp)-met.shiftedPt(pat::MET::PhotonEnDown),met.pt());
	k8->Fill(met.shiftedPt(pat::MET::JetResUpSmear)-met.shiftedPt(pat::MET::JetResDownSmear),met.pt());
	m1->Fill(met.shiftedPt(pat::MET::JetResUp)-met.shiftedPt(pat::MET::JetResDown));
	m2->Fill(met.shiftedPt(pat::MET::JetEnUp)-met.shiftedPt(pat::MET::JetEnDown));
	m3->Fill(met.shiftedPt(pat::MET::MuonEnUp)-met.shiftedPt(pat::MET::MuonEnDown));
	m4->Fill(met.shiftedPt(pat::MET::ElectronEnUp)-met.shiftedPt(pat::MET::ElectronEnDown));
	m5->Fill(met.shiftedPt(pat::MET::TauEnUp)-met.shiftedPt(pat::MET::TauEnDown));
	m6->Fill(met.shiftedPt(pat::MET::UnclusteredEnUp)-met.shiftedPt(pat::MET::UnclusteredEnDown));
	m7->Fill(met.shiftedPt(pat::MET::PhotonEnUp)-met.shiftedPt(pat::MET::PhotonEnDown));
	m8->Fill(met.shiftedPt(pat::MET::JetResUpSmear)-met.shiftedPt(pat::MET::JetResDownSmear));
	m9->Fill((met.shiftedPt(pat::MET::JetResUp)-met.pt())/met.pt());
	m10->Fill((met.shiftedPt(pat::MET::JetEnUp)-met.pt())/met.pt());
	m11->Fill((met.shiftedPt(pat::MET::MuonEnUp)-met.pt())/met.pt());
	m12->Fill((met.shiftedPt(pat::MET::ElectronEnUp)-met.pt())/met.pt());
	m13->Fill((met.shiftedPt(pat::MET::TauEnUp)-met.pt())/met.pt());
	m14->Fill((met.shiftedPt(pat::MET::UnclusteredEnUp)-met.pt())/met.pt());
	m15->Fill((met.shiftedPt(pat::MET::PhotonEnUp)-met.pt())/met.pt());
	m16->Fill((met.shiftedPt(pat::MET::JetResUpSmear)-met.pt())/met.pt());
	m17->Fill((met.shiftedPt(pat::MET::JetResDown)-met.pt())/met.pt());
	m18->Fill((met.shiftedPt(pat::MET::JetEnDown)-met.pt())/met.pt());
	m19->Fill((met.shiftedPt(pat::MET::MuonEnDown)-met.pt())/met.pt());
	m20->Fill((met.shiftedPt(pat::MET::ElectronEnDown)-met.pt())/met.pt());
	m21->Fill((met.shiftedPt(pat::MET::TauEnDown)-met.pt())/met.pt());
	m22->Fill((met.shiftedPt(pat::MET::UnclusteredEnDown)-met.pt())/met.pt());
	m23->Fill((met.shiftedPt(pat::MET::PhotonEnDown)-met.pt())/met.pt());
	m24->Fill((met.shiftedPt(pat::MET::JetResDownSmear)-met.pt())/met.pt());
	m25->Fill(met.shiftedPt(pat::MET::JetResUp)-met.pt());
	m26->Fill(met.shiftedPt(pat::MET::JetEnUp)-met.pt());
	m27->Fill(met.shiftedPt(pat::MET::MuonEnUp)-met.pt());
	m28->Fill(met.shiftedPt(pat::MET::ElectronEnUp)-met.pt());
	m29->Fill(met.shiftedPt(pat::MET::TauEnUp)-met.pt());
	m30->Fill(met.shiftedPt(pat::MET::UnclusteredEnUp)-met.pt());
	m31->Fill(met.shiftedPt(pat::MET::PhotonEnUp)-met.pt());
	m32->Fill(met.shiftedPt(pat::MET::JetResUpSmear)-met.pt());
	m33->Fill(met.shiftedPt(pat::MET::JetResDown)-met.pt());
	m34->Fill(met.shiftedPt(pat::MET::JetEnDown)-met.pt());
	m35->Fill(met.shiftedPt(pat::MET::MuonEnDown)-met.pt());
	m36->Fill(met.shiftedPt(pat::MET::ElectronEnDown)-met.pt());
	m37->Fill(met.shiftedPt(pat::MET::TauEnDown)-met.pt());
	m38->Fill(met.shiftedPt(pat::MET::UnclusteredEnDown)-met.pt());
	m39->Fill(met.shiftedPt(pat::MET::PhotonEnDown)-met.pt());
	m40->Fill(met.shiftedPt(pat::MET::JetResDownSmear)-met.pt());

#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
test1::beginJob()
{
	h1 = new TH1F("MET_pt", "MET pt", 100, 0.0, 300.0);
	h2 = new TH1F("MET_phi", "MET phi", 100, -M_PI, M_PI);
	h3 = new TH1F("MET_sumEt", "MET sumEt", 100, 0.0, 3000.0);
	h4 = new TH1F("genMET_pt", "genMET pt", 100, 0.0, 100.0);
	h5 = new TH1F("shiftedPt_JetResUp", "shifted Pt JetResUp", 100, 0.0, 300.0);
	h6 = new TH1F("shiftedPt_JetResDown", "shifted Pt JetResDown", 100, 0.0, 300.0);
	h7 = new TH1F("shiftedPt_JetEnUp", "shifted pt JetEnUp", 100, 0.0, 300.0);
	h8 = new TH1F("shiftedPt_JetEnDown", "shifted pt JetEnDown", 100, 0.0, 300.0);
	h9 = new TH1F("shiftedPt_MuonEnUp", "shifted Pt MuonEnUp", 100, 0.0, 300.0);
	h10 = new TH1F("shiftedPt_MuonEnDown", "shifted Pt MuonEnDown", 100, 0.0, 300.0);
	h11 = new TH1F("shiftedPt_ElectronEnUp", "shifted Pt ElectronEnUp", 100, 0.0, 300.0);
	h12 = new TH1F("shiftedPt_ElectronEnDown", "shifted Pt ElectronEnDown", 100, 0.0, 300.0);
	h13 = new TH1F("shiftedPt_TauEnUp", "shifted Pt TauEnUp", 100, 0.0, 300.0);
	h14 = new TH1F("shiftedPt_TauEnDown", "shifted Pt TauEnDown", 100, 0.0, 300.0);
	h15 = new TH1F("shiftedPt_UnclusteredEnUp", "shifted Pt UnclusteredEnUp", 100, 0.0, 300.0);
	h16 = new TH1F("shiftedPt_UnclusteredEnDown", "shifted Pt UnclusteredEn Down", 100, 0.0, 300.0);
	h17 = new TH1F("shiftedPt_PhotonEnUp", "shifted Pt PhotonEnUp", 100, 0.0, 300.0);
	h18 = new TH1F("shiftedPt_PhotonEnDown", "shifted Pt PhotonEnDown", 100, 0.0, 300.0);
	h19 = new TH1F("shiftedPt_NoShift", "shifted Pt NoShift", 100, 0.0, 300.0);
	h20 = new TH1F("shiftedPt_METUncertaintySize", "shifted Pt METUncertaintySize", 100, 0.0, 300.0);
	h21 = new TH1F("shiftedPt_JetResUpSmear", "shifted Pt JetResUpSmear", 100, 0.0, 300.0);
	h22 = new TH1F("shiftedPt_JetResDownSmear", "shifted Pt JetResDownSmear", 100, 0.0, 300.0);
	h23 = new TH1F("shiftedPt_METFullUncertaintySize", "shifted Pt METFullUncertaintySize", 100, 0.0, 300.0);
	h24 = new TH1F("shiftedPhi_JetResUp", "shifted Phi JetResUp", 100, -M_PI, M_PI);
	h25 = new TH1F("shiftedPhi_JetResDown", "shifted Phi JetResDown", 100, -M_PI, M_PI);
	h26 = new TH1F("shiftedPhi_JetEnUp", "shifted Phi JetEnUp", 100, -M_PI, M_PI);
	h27 = new TH1F("shiftedPhi_JetEnDown", "shifted Phi JetEnDown", 100, -M_PI, M_PI);
	h28 = new TH1F("shiftedPhi_MuonEnUp", "shifted Phi MuonEnUp", 100, -M_PI, M_PI);
	h29 = new TH1F("shiftedPhi_MuonEnDown", "shifted Phi MuonEnDown", 100, -M_PI, M_PI);
	h30 = new TH1F("shiftedPhi_ElectronEnUp", "shifted Phi ElectronEnUp", 100, -M_PI, M_PI);
	h31 = new TH1F("shiftedPhi_ElectronEnDown", "shifted Phi ElectronEnDown", 100, -M_PI, M_PI);
	h32 = new TH1F("shiftedPhi_TauEnUp", "shifted Phi TauEnUp", 100, -M_PI, M_PI);
	h33 = new TH1F("shiftedPhi_TauEnDown", "shifted Phi TauEnDown", 100, -M_PI, M_PI);
	h34 = new TH1F("shiftedPhi_UnclusteredEnUp", "shifted Phi UnclusteredEnUp", 100, -M_PI, M_PI);
	h35 = new TH1F("shiftedPhi_UnclusteredEnDown", "shifted Phi UnclusteredEn Down", 100, -M_PI, M_PI);
	h36 = new TH1F("shiftedPhi_PhotonEnUp", "shifted Phi PhotonEnUp", 100, -M_PI, M_PI);
	h37 = new TH1F("shiftedPhi_PhotonEnDown", "shifted Phi PhotonEnDown", 100, -M_PI, M_PI);
	h38 = new TH1F("shiftedPhi_NoShift", "shifted Phi NoShift", 100, -M_PI, M_PI);
	h39 = new TH1F("shiftedPhi_METUncertaintySize", "shifted Phi METUncertaintySize", 100, -M_PI, M_PI);
	h40 = new TH1F("shiftedPhi_JetResUpSmear", "shifted Phi JetResUpSmear", 100, -M_PI, M_PI);
	h41 = new TH1F("shiftedPhi_JetResDownSmear", "shifted Phi JetResDownSmear", 100, -M_PI, M_PI);
	h42 = new TH1F("shiftedPhi_METFullUncertaintySize", "shifted Phi METFullUncertaintySize", 100, -M_PI, M_PI);
	h43 = new TH1F("shiftedSumEt_JetResUp", "shifted SumEt JetResUp", 100, 0.0, 3000.0);
	h44 = new TH1F("shiftedSumEt_JetResDown", "shifted SumEt JetResDown", 100, 0.0, 3000.0);
	h45 = new TH1F("shiftedSumEt_JetEnUp", "shifted SumEt JetEnUp", 100, 0.0, 3000.0);
	h46 = new TH1F("shiftedSumEt_JetEnDown", "shifted SumEt JetEnDown", 100, 0.0, 3000.0);
	h47 = new TH1F("shiftedSumEt_MuonEnUp", "shifted SumEt MuonEnUp", 100, 0.0, 3000.0);
	h48 = new TH1F("shiftedSumEt_MuonEnDown", "shifted SumEt MuonEnDown", 100, 0.0, 3000.0);
	h49 = new TH1F("shiftedSumEt_ElectronEnUp", "shifted SumEt ElectronEnUp", 100, 0.0, 3000.0);
	h50 = new TH1F("shiftedSumEt_ElectronEnDown", "shifted SumEt ElectronEnDown", 100, 0.0, 3000.0);
	h51 = new TH1F("shiftedSumEt_TauEnUp", "shifted SumEt TauEnUp", 100, 0.0, 3000.0);
	h52 = new TH1F("shiftedSumEt_TauEnDown", "shifted SumEt TauEnDown", 100, 0.0, 3000.0);
	h53 = new TH1F("shiftedSumEt_UnclusteredEnUp", "shifted SumEt UnclusteredEnUp", 100, 0.0, 3000.0);
	h54 = new TH1F("shiftedSumEt_UnclusteredEnDown", "shifted SumEt UnclusteredEn Down", 100, 0.0, 3000.0);
	h55 = new TH1F("shiftedSumEt_PhotonEnUp", "shifted SumEt PhotonEnUp", 100, 0.0, 3000.0);
	h56 = new TH1F("shiftedSumEt_PhotonEnDown", "shifted SumEt PhotonEnDown", 100, 0.0, 3000.0);
	h57 = new TH1F("shiftedSumEt_NoShift", "shifted SumEt NoShift", 100, 0.0, 3000.0);
	h58 = new TH1F("shiftedSumEt_METUncertaintySize", "shifted SumEt METUncertaintySize", 100, 0.0, 3000.0);
	h59 = new TH1F("shiftedSumEt_JetResUpSmear", "shifted SumEt JetResUpSmear", 100, 0.0, 3000.0);
	h60 = new TH1F("shiftedSumEt_JetResDownSmear", "shifted SumEt JetResDownSmear", 100, 0.0, 3000.0);
	h61 = new TH1F("shiftedSumEt_METFullUncertaintySize", "shifted SumEt METFullUncertaintySize", 100, 0.0, 3000.0);
	k1 = new TH2F("DeltaMETvsMET_JetRes","#DeltaMET vs MET for Uncertainty shift: JetRes",100,-20.0,20.0,100,0.0,300.0);
	k2 = new TH2F("DeltaMETvsMET_JetEn","#DeltaMET vs MET for Uncertainty shift: JetEn",100,-5.0,5.0,100,0.0,300.0);
	k3 = new TH2F("DeltaMETvsMET_MuonEn","#DeltaMET vs MET for Uncertainty shift: MuonEn",100,-5.0,5.0,100,0.0,300.0);
	k4 = new TH2F("DeltaMETvsMET_ElectronEn","#DeltaMET vs MET for Uncertainty shift: ElectronEn",100,-5.0,5.0,100,0.0,300.0);
	k5 = new TH2F("DeltaMETvsMET_TauEn","#DeltaMET vs MET for Uncertainty shift: TauEn",100,-10.0,10.0,100,0.0,300.0);
	k6 = new TH2F("DeltaMETvsMET_UnclusteredEn","#DeltaMET vs MET for Uncertainty shift: UnclusteredEn",100,-20.0,20.0,100,0.0,300.0);
	k7 = new TH2F("DeltaMETvsMET_PhotonEn","#DeltaMET vs MET for Uncertainty shift: PhotonEn",100,-5.0,5.0,100,0.0,300.0);
	k8 = new TH2F("DeltaMETvsMET_JetResSmear","#DeltaMET vs MET for Uncertainty shift: JetResSmear",100,-10.0,10.0,100,0.0,300.0);
	m1 = new TH1F("DeltaMET_JetRes", "#DeltaMET for Uncertainty shift: JetRes", 100, -20.0, 20.0);
	m2 = new TH1F("DeltaMET_JetEn", "#DeltaMET for Uncertainty shift: JetEn", 100, -5.0, 5.0);
	m3 = new TH1F("DeltaMET_MuonEn", "#DeltaMET for Uncertainty shift: MuonEn", 100, -5.0, 5.0);
	m4 = new TH1F("DeltaMET_ElectronEn", "#DeltaMET for Uncertainty shift: ElectronEn", 100, -5.0, 5.0);
	m5 = new TH1F("DeltaMET_TauEn", "#DeltaMET for Uncertainty shift: TauEn", 100, -10.0, 10.0);
	m6 = new TH1F("DeltaMET_UnclusteredEn", "#DeltaMET for Uncertainty shift: UnclusteredEn", 100, -20.0, 20.0);
	m7 = new TH1F("DeltaMET_PhotonEn", "#DeltaMET for Uncertainty shift: PhotonEn", 100, -5.0, 5.0);
	m8 = new TH1F("DeltaMET_JetResSmear", "#DeltaMET for Uncertainty shift: JetResSmear", 100, -10.0, 10.0);
	m9 = new TH1F("FracDeltaMET_JetResUp", "#DeltaMET/MET for Uncertainty shift: JetResUp", 100, -20.0, 20.0);
	m10 = new TH1F("FracDeltaMET_JetEnUp", "#DeltaMET/MET for Uncertainty shift: JetEnUp", 100, -5.0, 5.0);
	m11 = new TH1F("FracDeltaMET_MuonEnUp", "#DeltaMET/MET for Uncertainty shift: MuonEnUp", 100, -5.0, 5.0);
	m12 = new TH1F("FracDeltaMET_ElectronEnUp", "#DeltaMET/MET for Uncertainty shift: ElectronEnUp", 100, -5.0, 5.0);
	m13 = new TH1F("FracDeltaMET_TauEnUp", "#DeltaMET/MET for Uncertainty shift: TauEnUp", 100, -10.0, 10.0);
	m14 = new TH1F("FracDeltaMET_UnclusteredEnUp", "#DeltaMET/MET for Uncertainty shift: UnclusteredEnUp", 100, -20.0, 20.0);
	m15 = new TH1F("FracDeltaMET_PhotonEnUp", "#DeltaMET/MET for Uncertainty shift: PhotonEnUp", 100, -5.0, 5.0);
	m16 = new TH1F("FracDeltaMET_JetResUpSmear", "#DeltaMET/MET for Uncertainty shift: JetResUpSmear", 100, -10.0, 10.0);
	m17 = new TH1F("FracDeltaMET_JetResDown", "#DeltaMET/MET for Uncertainty shift: JetResDown", 100, -20.0, 20.0);
	m18 = new TH1F("FracDeltaMET_JetEnDown", "#DeltaMET/MET for Uncertainty shift: JetEnDown", 100, -5.0, 5.0);
	m19 = new TH1F("FracDeltaMET_MuonEnDown", "#DeltaMET/MET for Uncertainty shift: MuonEnDown", 100, -5.0, 5.0);
	m20 = new TH1F("FracDeltaMET_ElectronEnDown", "#DeltaMET/MET for Uncertainty shift: ElectronEnDown", 100, -5.0, 5.0);
	m21 = new TH1F("FracDeltaMET_TauEnDown", "#DeltaMET/MET for Uncertainty shift: TauEnDown", 100, -10.0, 10.0);
	m22 = new TH1F("FracDeltaMET_UnclusteredEnDown", "#DeltaMET/MET for Uncertainty shift: UnclusteredEnDown", 100, -20.0, 20.0);
	m23 = new TH1F("FracDeltaMET_PhotonEnDown", "#DeltaMET/MET for Uncertainty shift: PhotonEnDown", 100, -5.0, 5.0);
	m24 = new TH1F("FracDeltaMET_JetResDownSmear", "#DeltaMET/MET for Uncertainty shift: JetResDownSmear", 100, -10.0, 10.0);
	m25 = new TH1F("DeltaMET_JetResUp", "#DeltaMET for Uncertainty shift: JetResUp", 100, -20.0, 20.0);
	m26 = new TH1F("DeltaMET_JetEnUp", "#DeltaMET for Uncertainty shift: JetEnUp", 100, -5.0, 5.0);
	m27 = new TH1F("DeltaMET_MuonEnUp", "#DeltaMET for Uncertainty shift: MuonEnUp", 100, -5.0, 5.0);
	m28 = new TH1F("DeltaMET_ElectronEnUp", "#DeltaMET for Uncertainty shift: ElectronEnUp", 100, -5.0, 5.0);
	m29 = new TH1F("DeltaMET_TauEnUp", "#DeltaMET for Uncertainty shift: TauEnUp", 100, -10.0, 10.0);
	m30 = new TH1F("DeltaMET_UnclusteredEnUp", "#DeltaMET for Uncertainty shift: UnclusteredEnUp", 100, -20.0, 20.0);
	m31 = new TH1F("DeltaMET_PhotonEnUp", "#DeltaMET for Uncertainty shift: PhotonEnUp", 100, -5.0, 5.0);
	m32 = new TH1F("DeltaMET_JetResUpSmear", "#DeltaMET for Uncertainty shift: JetResUpSmear", 100, -10.0, 10.0);
	m33 = new TH1F("DeltaMET_JetResDown", "#DeltaMET for Uncertainty shift: JetResDown", 100, -20.0, 20.0);
	m34 = new TH1F("DeltaMET_JetEnDown", "#DeltaMET for Uncertainty shift: JetEnDown", 100, -5.0, 5.0);
	m35 = new TH1F("DeltaMET_MuonEnDown", "#DeltaMET for Uncertainty shift: MuonEnDown", 100, -5.0, 5.0);
	m36 = new TH1F("DeltaMET_ElectronEnDown", "#DeltaMET for Uncertainty shift: ElectronEnDown", 100, -5.0, 5.0);
	m37 = new TH1F("DeltaMET_TauEnDown", "#DeltaMET for Uncertainty shift: TauEnDown", 100, -10.0, 10.0);
	m38 = new TH1F("DeltaMET_UnclusteredEnDown", "#DeltaMET for Uncertainty shift: UnclusteredEnDown", 100, -20.0, 20.0);
	m39 = new TH1F("DeltaMET_PhotonEnDown", "#DeltaMET for Uncertainty shift: PhotonEnDown", 100, -5.0, 5.0);
	m40 = new TH1F("DeltaMET_JetResDownSmear", "#DeltaMET for Uncertainty shift: JetResDownSmear", 100, -10.0, 10.0);
}

// ------------ method called once each job just after ending the event loop  ------------
void 
test1::endJob() 
{
	TFile* file = TFile::Open("histo.root","RECREATE");
	h1->Write(); h2->Write(); h3->Write(); h4->Write(); h5->Write(); h6->Write(); h7->Write(); h8->Write(); h9->Write(); h10->Write();
	h11->Write(); h12->Write(); h13->Write(); h14->Write(); h15->Write(); h16->Write(); h17->Write(); h18->Write(); h19->Write();
	h20->Write(); h21->Write(); h22->Write(); h23->Write(); h24->Write(); h25->Write(); h26->Write(); h27->Write(); h28->Write();
	h29->Write(); h30->Write(); h31->Write(); h32->Write(); h33->Write(); h34->Write(); h35->Write(); h36->Write(); h37->Write();
	h38->Write(); h39->Write(); h40->Write(); h41->Write(); h42->Write(); h43->Write(); h44->Write(); h45->Write(); h46->Write();
	h47->Write(); h48->Write(); h49->Write(); h50->Write(); h51->Write(); h52->Write(); h53->Write(); h54->Write(); h55->Write();
	h56->Write(); h57->Write(); h58->Write(); h59->Write(); h60->Write(); h61->Write();
	k1->Write(); k2->Write(); k3->Write(); k4->Write(); k5->Write(); k6->Write(); k7->Write(); k8->Write();
	m1->Write(); m2->Write(); m3->Write(); m4->Write(); m5->Write(); m6->Write(); m7->Write(); m8->Write(); m9->Write(); m10->Write();
	m11->Write(); m12->Write(); m13->Write(); m14->Write(); m15->Write(); m16->Write(); m17->Write(); m18->Write();
	m19->Write(); m20->Write(); m21->Write(); m22->Write(); m23->Write(); m24->Write(); m25->Write(); m26->Write(); 
	m27->Write(); m28->Write(); m29->Write(); m30->Write(); m31->Write(); m32->Write(); m33->Write(); m34->Write(); 
	m35->Write(); m36->Write(); m37->Write(); m38->Write(); m39->Write(); m40->Write();
	file->Close();
	delete h1; delete h2; delete h3; delete h4; delete h5; delete h6; delete h7; delete h8; delete h9; delete h10;
	delete h11; delete h12; delete h13; delete h14; delete h15; delete h16; delete h17; delete h18; delete h19; delete h20;
	delete h21; delete h22; delete h23; delete h24; delete h25; delete h26; delete h27; delete h28; delete h29; delete h30;
	delete h31; delete h32; delete h33; delete h34; delete h35; delete h36; delete h37; delete h38; delete h39; delete h40;
	delete h41; delete h42; delete h43; delete h44; delete h45; delete h46; delete h47; delete h48; delete h49; delete h50;
	delete h51; delete h52; delete h53; delete h54; delete h55; delete h56; delete h57; delete h58; delete h59; delete h60;
	delete h61;
	delete k1; delete k2; delete k3; delete k4; delete k5; delete k6; delete k7; delete k8;
	delete m1; delete m2; delete m3; delete m4; delete m5; delete m6; delete m7; delete m8; delete m9; delete m10;
	delete m11; delete m12; delete m13; delete m14; delete m15; delete m16; delete m17; delete m18; delete m19; delete m20;
	delete m21; delete m22; delete m23; delete m24; delete m25; delete m26; delete m27; delete m28; delete m29; delete m30;
	delete m31; delete m32; delete m33; delete m34; delete m35; delete m36; delete m37; delete m38; delete m39; delete m40;
	delete file;
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
test1::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(test1);
