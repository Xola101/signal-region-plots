//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Feb 26 12:16:33 2019 by ROOT version 6.14/04
// from TTree myTree/myTree
// found on file: background_upto_muquality.root
//////////////////////////////////////////////////////////

#ifndef ZdZdPlot_h
#define ZdZdPlot_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>

// Header file for the classes stored in the TTree if any.
#include "TLorentzVector.h"
using namespace std;

class ZdZdPlot {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t channelArray[21];
   UInt_t          mc_channel_number;
   Int_t           EventNumber;
   TLorentzVector  *lep12;
   TLorentzVector  *lep34;
   TLorentzVector  *lep32;
   TLorentzVector  *lep14;
   TLorentzVector  *lep1234;
   TLorentzVector  *lep1;
   TLorentzVector  *lep2;
   TLorentzVector  *lep3;
   TLorentzVector  *lep4;
   Int_t           IdLep1;
   Int_t           IdLep2;
   Int_t           IdLep3;
   Int_t           IdLep4;
   Float_t         d0SigLep1;
   Float_t         d0SigLep2;
   Float_t         d0SigLep3;
   Float_t         d0SigLep4;
   Int_t           elIDLep1;
   Int_t           elIDLep2;
   Int_t           elIDLep3;
   Int_t           elIDLep4;
   Int_t           muID4Lep;
   Double_t        EvtWeight;
   Int_t           llll_pdgIdSum;
   ULong64_t       eventNumber;
   Int_t           RunNumber;
   Int_t           l_isIsolFixedCutLoose;
   Int_t           MC_channel_number;
   Double_t        max_el_d0Sig;
   Double_t        max_mu_d0Sig;
   Double_t        Events_all;
   Bool_t          Q_Veto;
   Bool_t          Electron_ID;
   Bool_t          LowMassVeto;
   Bool_t          HWinHM;
   Bool_t          ZVeto;
   Bool_t          LooseSR_HM;
   Bool_t          MediumSR;
   Bool_t          ZVR1HM;
   Bool_t          ZVR2HM;
   Double_t        min_SF_dR;
   Double_t        min_OF_dR;

   // List of branches
   TBranch        *b_lep12;   //!
   TBranch        *b_lep34;   //!
   TBranch        *b_lep32;   //!
   TBranch        *b_lep14;   //!
   TBranch        *b_lep1234;   //!
   TBranch        *b_lep1;   //!
   TBranch        *b_lep2;   //!
   TBranch        *b_lep3;   //!
   TBranch        *b_lep4;   //!
   TBranch        *b_IdLep1;   //!
   TBranch        *b_IdLep2;   //!
   TBranch        *b_IdLep3;   //!
   TBranch        *b_IdLep4;   //!
   TBranch        *b_d0SigLep1;   //!
   TBranch        *b_d0SigLep2;   //!
   TBranch        *b_d0SigLep3;   //!
   TBranch        *b_d0SigLep4;   //!
   TBranch        *b_elIDLep1;   //!
   TBranch        *b_elIDLep2;   //!
   TBranch        *b_elIDLep3;   //!
   TBranch        *b_elIDLep4;   //!
   TBranch        *b_muID4Lep;   //!
   TBranch        *b_EvtWeight;   //!
   TBranch        *b_llll_pdgIdSum;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_l_isIsolFixedCutLoose;   //!
   TBranch        *b_MC_channel_number;   //!
   TBranch        *b_max_el_d0Sig;   //!
   TBranch        *b_max_mu_d0Sig;   //!
   TBranch        *b_Events_all;   //!
   TBranch        *b_Q_Veto;   //!
   TBranch        *b_Electron_ID;   //!
   TBranch        *b_LowMassVeto;   //!
   TBranch        *b_HWinHM;   //!
   TBranch        *b_ZVeto;   //!
   TBranch        *b_LooseSR_HM;   //!
   TBranch        *b_MediumSR;   //!
   TBranch        *b_ZVR1HM;   //!
   TBranch        *b_ZVR2HM;   //!
   TBranch        *b_min_SF_dR;   //!
   TBranch        *b_min_OF_dR;   //!

   ZdZdPlot(TTree *tree=0);
   virtual ~ZdZdPlot();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TTree* tree, string rootFileName);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef ZdZdPlot_cxx
ZdZdPlot::ZdZdPlot(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("user.ychiu.361601.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WZlvll_mll4.e4475_e5984_s3126_r10724_r10726_p3652.17064385.NTUP4L._000002.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("background_upto_muquality.root");
      }
      f->GetObject("myTree",tree);

   }
   Init(tree);
}

ZdZdPlot::~ZdZdPlot()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ZdZdPlot::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ZdZdPlot::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void ZdZdPlot::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   lep12 = 0;
   lep34 = 0;
   lep32 = 0;
   lep14 = 0;
   lep1234 = 0;
   lep1 = 0;
   lep2 = 0;
   lep3 = 0;
   lep4 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("lep12", &lep12, &b_lep12);
   fChain->SetBranchAddress("lep34", &lep34, &b_lep34);
   fChain->SetBranchAddress("lep32", &lep32, &b_lep32);
   fChain->SetBranchAddress("lep14", &lep14, &b_lep14);
   fChain->SetBranchAddress("lep1234", &lep1234, &b_lep1234);
   fChain->SetBranchAddress("lep1", &lep1, &b_lep1);
   fChain->SetBranchAddress("lep2", &lep2, &b_lep2);
   fChain->SetBranchAddress("lep3", &lep3, &b_lep3);
   fChain->SetBranchAddress("lep4", &lep4, &b_lep4);
   fChain->SetBranchAddress("IdLep1", &IdLep1, &b_IdLep1);
   fChain->SetBranchAddress("IdLep2", &IdLep2, &b_IdLep2);
   fChain->SetBranchAddress("IdLep3", &IdLep3, &b_IdLep3);
   fChain->SetBranchAddress("IdLep4", &IdLep4, &b_IdLep4);
   fChain->SetBranchAddress("d0SigLep1", &d0SigLep1, &b_d0SigLep1);
   fChain->SetBranchAddress("d0SigLep2", &d0SigLep2, &b_d0SigLep2);
   fChain->SetBranchAddress("d0SigLep3", &d0SigLep3, &b_d0SigLep3);
   fChain->SetBranchAddress("d0SigLep4", &d0SigLep4, &b_d0SigLep4);
   fChain->SetBranchAddress("elIDLep1", &elIDLep1, &b_elIDLep1);
   fChain->SetBranchAddress("elIDLep2", &elIDLep2, &b_elIDLep2);
   fChain->SetBranchAddress("elIDLep3", &elIDLep3, &b_elIDLep3);
   fChain->SetBranchAddress("elIDLep4", &elIDLep4, &b_elIDLep4);
   fChain->SetBranchAddress("muID4Lep", &muID4Lep, &b_muID4Lep);
   fChain->SetBranchAddress("EvtWeight", &EvtWeight, &b_EvtWeight);
   fChain->SetBranchAddress("llll_pdgIdSum", &llll_pdgIdSum, &b_llll_pdgIdSum);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("l_isIsolFixedCutLoose", &l_isIsolFixedCutLoose, &b_l_isIsolFixedCutLoose);
   fChain->SetBranchAddress("MC_channel_number", &MC_channel_number, &b_MC_channel_number);
   fChain->SetBranchAddress("max_el_d0Sig", &max_el_d0Sig, &b_max_el_d0Sig);
   fChain->SetBranchAddress("max_mu_d0Sig", &max_mu_d0Sig, &b_max_mu_d0Sig);
   fChain->SetBranchAddress("Events_all", &Events_all, &b_Events_all);
   fChain->SetBranchAddress("Q_Veto", &Q_Veto, &b_Q_Veto);
   fChain->SetBranchAddress("Electron_ID", &Electron_ID, &b_Electron_ID);
   fChain->SetBranchAddress("LowMassVeto", &LowMassVeto, &b_LowMassVeto);
   fChain->SetBranchAddress("HWinHM", &HWinHM, &b_HWinHM);
   fChain->SetBranchAddress("ZVeto", &ZVeto, &b_ZVeto);
   fChain->SetBranchAddress("LooseSR_HM", &LooseSR_HM, &b_LooseSR_HM);
   fChain->SetBranchAddress("MediumSR", &MediumSR, &b_MediumSR);
   fChain->SetBranchAddress("ZVR1HM", &ZVR1HM, &b_ZVR1HM);
   fChain->SetBranchAddress("ZVR2HM", &ZVR2HM, &b_ZVR2HM);
   fChain->SetBranchAddress("min_SF_dR", &min_SF_dR, &b_min_SF_dR);
   fChain->SetBranchAddress("min_OF_dR", &min_OF_dR, &b_min_OF_dR);
   Notify();
}

Bool_t ZdZdPlot::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void ZdZdPlot::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ZdZdPlot::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef ZdZdPlot_cxx
