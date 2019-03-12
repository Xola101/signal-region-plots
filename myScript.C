#include "TFile.h"
#include "TDirectory.h"
#include "TKey.h"
#include "TH1D.h"
#include "TObjArray.h"
#include "TDirectory.h"
#include <string>
#include <sstream>
#include "TCanvas.h"
#include "TPad.h"
#include <map>
#include "TLegend.h"
#include "TLatex.h"
#include <iostream>
#include "TStyle.h"
//#include "/gpfs/atlas/kshaw/ICToPCode/TopPlot/TopPlot.h"
//#include "AtlasStyle.C"
//#include "AtlasUtils.C"


void SetUnderFlow(TH1D *histo);
void SetUpperFlow(TH1D *histo);
using namespace std;

void myScript() {
  cout << "Begin myScript.C" << endl;
//  //gROOT->SetStyle("Plain");
//  gStyle->SetOptStat(0);
//  gROOT->SetBatch(true);
  
  
  //Open the root ntuples
  string path_s = "/Users/cashcrusaders/Documents/signal_for_xola/ZdZdPlot/Output/Signals/";
  string path_b = "/Users/cashcrusaders/Documents/signal_for_xola/ZdZdPlot/Output/Bkgs/";
//
//
  TFile *f0,*f1,*f2,*f3,*f4,*f5,*f6;
    f0 = new TFile(string(path_b + "_TotalBkgs.nd_upto_muquality_L3.root").c_str());
    f1 = new TFile(string(path_s + "302080_mc16a_13TeV_20_125_histos.minal_QVeto_level_L3.root").c_str());
    f2 = new TFile(string(path_s + "302081_mc16a_13TeV_20_125_histos.minal_QVeto_level_L3.root").c_str());
    f3 = new TFile(string(path_s + "302079_mc16a_13TeV_20_125_histos.minal_QVeto_level_L3.root").c_str());

//  f4 = new TFile(string(path + "wjets4_L3.root").c_str());
//  f5 = new TFile(string(path + "wjets5_L3.root").c_str());
//  f6 = new TFile(string(path + "data_L3.root").c_str());




    TH1D * mll_4e_pass_1 = new TH1D("mll_4e_pass","h1 title" , 100, 0, 50);
    TH1D * mll_4e_pass_2 = new TH1D("mll_4e_pass","h1 title" , 100, 0, 50);
    TH1D * mll_4e_pass_3 = new TH1D("mll_4e_pass","h1 title" , 100, 0, 50);

    TH1D * mll_4e_fail_1 = new TH1D("mll_4e_fail","h1 title" , 100, 0, 50);
    TH1D * mll_4e_fail_2 = new TH1D("mll_4e_fail","h1 title" , 100, 0, 50);
    TH1D * mll_4e_fail_3 = new TH1D("mll_4e_fail","h1 title" , 100, 0, 50);


    TH1D * mll_2e2m_pass = new TH1D("mll_2e2m_pass","h1 title" , 100, 0, 50);
    TH1D * mll_4m_pass = new TH1D("mll_4m_pass","h1 title" , 100, 0, 50);
    TH1D * mll_2e2m_fail = new TH1D("mll_2e2m_fail","h1 title" , 100, 0,50);
    TH1D * mll_4m_fail = new TH1D("mll_4m_fail","h1 title" , 100, 0, 50);
    TH1D * bkgs = new TH1D("bkgs","h1 title" , 100, 0, 30);

    bkgs = (TH1D*)f0->Get("hist_mll_4m9_MediumSR_channel");
    mll_4e_pass_1 = (TH1D*)f1->Get("hist_mll_4m9_MediumSR_channel");
    mll_4e_fail_1 = (TH1D*)f1->Get("hist_mll_4e8_LooseSR_channel");

    mll_4e_pass_2 = (TH1D*)f2->Get("hist_mll_4m9_MediumSR_channel");
    mll_4e_fail_2 = (TH1D*)f2->Get("hist_mll_4e8_LooseSR_channel");

    mll_4e_pass_3 = (TH1D*)f3->Get("hist_mll_4m9_MediumSR_channel");
    mll_4e_fail_3 = (TH1D*)f3->Get("hist_mll_4e8_LooseSR_channel");
TH1D * mll_4e_nmi = (TH1D*)mll_4e_fail_1->Clone();
//mll_4e_fail_1->Add(mll_4e_pass_1,-1);


    TCanvas *c1 = new TCanvas("c1","c1");
    TPad* thePad = (TPad*)c1->cd();
    c1->SetRightMargin(0.18);
    gStyle->SetPalette(55);
//    c1->SetLogz();
//   c1->SetLogy();
    gStyle->SetPaintTextFormat("4.1f");
//    Signal_2e->SetMinimum(0);
//    Signal_2e->SetMaximum(110);
   // mll_4e_pass->Draw();
    c1->SetLogy();
    mll_4e_pass_1->Draw();
    mll_4e_pass_1->SetLineColor(57);
    mll_4e_pass_2->Draw("same");
    mll_4e_pass_2->SetLineColor(57);
    mll_4e_pass_3->Draw("same");
    mll_4e_pass_3->SetLineColor(57);

    mll_4e_fail_1->Draw("same");
    mll_4e_fail_1->SetLineColor(1);
    mll_4e_fail_2->Draw("same");
    mll_4e_fail_2->SetLineColor(1);
    mll_4e_fail_3->Draw("same");
    mll_4e_fail_3->SetLineColor(1);


    bkgs->Draw("same");
    bkgs->SetLineColor(74);
    bkgs->SetLineColor(74);
}
