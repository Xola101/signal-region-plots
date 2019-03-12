#define ZdZdPlot_cxx
#include "ZdZdPlot.h"

#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <map>

#include <TH1.h>
#include <TH1D.h>
#include <TH2.h>
#include <TH2D.h>
#include "TProfile.h"


using namespace std;

void ZdZdPlot::Loop(TTree* tree, string rootFileName) {
//   In a ROOT session, you can do:
//      root> .L ZdZdPlot.C
//      root> ZdZdPlot t
//      root> t.GetEntry(12); // Fill t data members with entry number12
//      root> t.Show();       // Show values of entry12
//      root> t.Show(16);     // Read and show values of entry16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

//cout << "hello" << endl;
//    TH1D *hist_m4l_4e_channel = new TH1D("hist_m4l_4e_channel","hist_m4l_4e_channel" ,140,160,180);
//    stringstream hist_nr[2];
    if (fChain == 0) return;

    int channelArray[22];
    map<double, double> eventsAll;
    map<double, string> outputMidName;


    channelArray[0] = 341488;
    channelArray[1] = 341947;
    channelArray[2] = 341964;
    channelArray[3] = 344973;
    channelArray[4] = 344974;
    channelArray[5] = 345060;
    channelArray[6] = 345066;
    channelArray[7] = 345708;
    channelArray[8] = 345709;
    channelArray[9] = 361601;
    channelArray[10] = 364243;
    channelArray[11] = 364245;
    channelArray[12] = 364247;
    channelArray[13] = 364248;
    channelArray[14] = 364250;
    channelArray[15] = 364251;
    channelArray[16] = 364252;
    channelArray[17] = 364364;
    channelArray[18] = 410472;
    channelArray[19] = 302079;
    channelArray[20] = 302080;
    channelArray[21] = 302081;


    outputMidName[channelArray[0]] = "VBFH125_ZZ4lep";
    outputMidName[channelArray[1]] = "ZH125_ZZ4l";
    outputMidName[channelArray[2]] = "WH125_ZZ4l";
    outputMidName[channelArray[3]] = "bbH125_yb2_ZZ4lep_noTau";
    outputMidName[channelArray[4]] = "bbH125_ybyt_ZZ4lep_noTau";
    outputMidName[channelArray[5]] = "ggH125_ZZ4l";
    outputMidName[channelArray[6]] = "ggZH125_ZZ4lepZinc";
    outputMidName[channelArray[7]] = "ggllllNoHiggs_0M4l130";
    outputMidName[channelArray[8]] = "ggllllNoHiggs_130M4l";
    outputMidName[channelArray[9]] = "WZlvll_mll4";
    outputMidName[channelArray[10]] = "WWZ_4l2v_EW6";
    outputMidName[channelArray[11]] = "WZZ_5l1v_EW6";
    outputMidName[channelArray[12]] = "ZZZ_6l0v_EW6";
    outputMidName[channelArray[13]] = "ZZZ_4l2v_EW6";
    outputMidName[channelArray[14]] = "llll";
    outputMidName[channelArray[15]] = "llll_m4l100_300_filt100_150";
    outputMidName[channelArray[16]] = "llll_m4l300";
    outputMidName[channelArray[17]] = "lllljj_EW6_noHiggs";
    outputMidName[channelArray[18]] = "ttbar_hdamp258p75_dil";
    outputMidName[channelArray[19]] = "302079_mc16a_13TeV_20_125";
    outputMidName[channelArray[20]] = "302080_mc16a_13TeV_20_125";
    outputMidName[channelArray[21]] = "302081_mc16a_13TeV_20_125";


    eventsAll[channelArray[0]] =40000;
    TObjArray *MyHistArray = new TObjArray();
//    for (int i = 0; i <18; i++) {
//
//        string Arrayname;
//        string mc_num = to_string(channelArray[i]);
//        Arrayname = "MyHistArray" + mc_num;
//        MyHistArray->SetName(Arrayname.c_str());
//        cout << MyHistArray->GetName() << endl;

//    MyHistArray
//    cout << Arrayname << endl;



    TH1D *hist_MC_channel_number = new TH1D("hist_MC_channel_number","hist_MC_channel_number",1000000,1,1000000);
    MyHistArray->AddLast(hist_MC_channel_number);


//    TH1D *hCutflow_4e = new TH1D("cutflow_4e_channel", "cutflow_4e_channel",10,1,11);
//    hCutflow_4e->GetXaxis()->SetBinLabel(1, "all events");
//    hCutflow_4e->GetXaxis()->SetBinLabel(2, "Isolation");
//    hCutflow_4e->GetXaxis()->SetBinLabel(3, "Electron ID");
//    hCutflow_4e->GetXaxis()->SetBinLabel(4, "Impact Parameter");
//    hCutflow_4e->GetXaxis()->SetBinLabel(5, "QVeto");
//    hCutflow_4e->GetXaxis()->SetBinLabel(6, "Low Mass Veto");
//    hCutflow_4e->GetXaxis()->SetBinLabel(7, "Higgs Window");
//    hCutflow_4e->GetXaxis()->SetBinLabel(8, "ZVeto");
//    hCutflow_4e->GetXaxis()->SetBinLabel(9, "Loose_SR");
//    hCutflow_4e->GetXaxis()->SetBinLabel(10, "Medium_SR");
//
//    MyHistArray->AddLast(hCutflow_4e);
//
//    TH1D *hCutflow_2e2m = new TH1D("cutflow_2e2m_channel", "cutflow_2e2m_channel",10,1,11);
//    hCutflow_2e2m->GetXaxis()->SetBinLabel(1, "all events");
//    hCutflow_2e2m->GetXaxis()->SetBinLabel(2, "Isolation");
//    hCutflow_2e2m->GetXaxis()->SetBinLabel(3, "Electron ID");
//    hCutflow_2e2m->GetXaxis()->SetBinLabel(4, "Impact Parameter");
//    hCutflow_2e2m->GetXaxis()->SetBinLabel(5, "QVeto");
//    hCutflow_2e2m->GetXaxis()->SetBinLabel(6, "Low Mass Veto");
//    hCutflow_2e2m->GetXaxis()->SetBinLabel(7, "Higgs Window");
//    hCutflow_2e2m->GetXaxis()->SetBinLabel(8, "ZVeto");
//    hCutflow_2e2m->GetXaxis()->SetBinLabel(9, "Loose_SR");
//    hCutflow_2e2m->GetXaxis()->SetBinLabel(10, "Medium_SR");
//
//    MyHistArray->AddLast(hCutflow_2e2m);
//
//    TH1D *hCutflow_4m = new TH1D("cutflow_4m_channel", "cutflow_4m_channel",10,1,11);
//    hCutflow_4m->GetXaxis()->SetBinLabel(1, "all events");
//    hCutflow_4m->GetXaxis()->SetBinLabel(2, "Isolation");
//    hCutflow_4m->GetXaxis()->SetBinLabel(3, "Electron ID");
//    hCutflow_4m->GetXaxis()->SetBinLabel(4, "Impact Parameter");
//    hCutflow_4m->GetXaxis()->SetBinLabel(5, "QVeto");
//    hCutflow_4m->GetXaxis()->SetBinLabel(6, "Low Mass Veto");
//    hCutflow_4m->GetXaxis()->SetBinLabel(7, "Higgs Window");
//    hCutflow_4m->GetXaxis()->SetBinLabel(8, "ZVeto");
//    hCutflow_4m->GetXaxis()->SetBinLabel(9, "Loose_SR");
//    hCutflow_4m->GetXaxis()->SetBinLabel(10, "Medium_SR");
//
//    MyHistArray->AddLast(hCutflow_4m);

        TH1D *hist_m4l_4e1_isol_channel = new TH1D("hist_m4l_4e1_isol_channel","hist_m4l_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4e1_isol_channel);
        TH1D *hist_m4l_4e2_elID_channel = new TH1D("hist_m4l_4e2_elID_channel","hist_m4l_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4e2_elID_channel);
        TH1D *hist_m4l_4e3_imp_channel = new TH1D("hist_m4l_4e3_imp_channel","hist_m4l_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4e3_imp_channel);
        TH1D *hist_m4l_4e4_QVeto_channel = new TH1D("hist_m4l_4e4_QVeto_channel","hist_m4l_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4e4_QVeto_channel);
        TH1D *hist_m4l_4e5_lowMassVeto_channel = new TH1D("hist_m4l_4e5_lowMassVeto_channel","hist_m4l_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4e5_lowMassVeto_channel);
        TH1D *hist_m4l_4e7_HWinHM__channel = new TH1D("hist_m4l_4e7_HWinHM__channel","hist_m4l_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4e7_HWinHM__channel);
        TH1D *hist_m4l_4e6_ZVeto_channel = new TH1D("hist_m4l_4e6_ZVeto_channel","hist_m4l_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4e6_ZVeto_channel);
        TH1D *hist_m4l_4e8_LooseSR_channel = new TH1D("hist_m4l_4e8_LooseSR_channel","hist_m4l_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4e8_LooseSR_channel);
        TH1D *hist_m4l_4e9_MediumSR_channel = new TH1D("hist_m4l_4e9_MediumSR_channel","hist_m4l_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4e9_MediumSR_channel);
        TH1D *hist_m4l_4e0_all_channel = new TH1D("hist_m4l_4e0_all_channel","hist_m4l_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4e0_all_channel);

        TH1D *hist_m12_4e1_isol_channel = new TH1D("hist_m12_4e1_isol_channel","hist_m12_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4e1_isol_channel);
        TH1D *hist_m12_4e2_elID_channel = new TH1D("hist_m12_4e2_elID_channel","hist_m12_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4e2_elID_channel);
        TH1D *hist_m12_4e3_imp_channel = new TH1D("hist_m12_4e3_imp_channel","hist_m12_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4e3_imp_channel);
        TH1D *hist_m12_4e4_QVeto_channel = new TH1D("hist_m12_4e4_QVeto_channel","hist_m12_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4e4_QVeto_channel);
        TH1D *hist_m12_4e5_lowMassVeto_channel = new TH1D("hist_m12_4e5_lowMassVeto_channel","hist_m12_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4e5_lowMassVeto_channel);
        TH1D *hist_m12_4e7_HWinHM__channel = new TH1D("hist_m12_4e7_HWinHM__channel","hist_m12_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4e7_HWinHM__channel);
        TH1D *hist_m12_4e6_ZVeto_channel = new TH1D("hist_m12_4e6_ZVeto_channel","hist_m12_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4e6_ZVeto_channel);
        TH1D *hist_m12_4e8_LooseSR_channel = new TH1D("hist_m12_4e8_LooseSR_channel","hist_m12_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4e8_LooseSR_channel);
        TH1D *hist_m12_4e9_MediumSR_channel = new TH1D("hist_m12_4e9_MediumSR_channel","hist_m12_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4e9_MediumSR_channel);
        TH1D *hist_m12_4e0_all_channel = new TH1D("hist_m12_4e0_all_channel","hist_m12_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4e0_all_channel);

        TH1D *hist_m34_4e1_isol_channel = new TH1D("hist_m34_4e1_isol_channel","hist_m34_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4e1_isol_channel);
        TH1D *hist_m34_4e2_elID_channel = new TH1D("hist_m34_4e2_elID_channel","hist_m34_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4e2_elID_channel);
        TH1D *hist_m34_4e3_imp_channel = new TH1D("hist_m34_4e3_imp_channel","hist_m34_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4e3_imp_channel);
        TH1D *hist_m34_4e4_QVeto_channel = new TH1D("hist_m34_4e4_QVeto_channel","hist_m34_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4e4_QVeto_channel);
        TH1D *hist_m34_4e5_lowMassVeto_channel = new TH1D("hist_m34_4e5_lowMassVeto_channel","hist_m34_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4e5_lowMassVeto_channel);
        TH1D *hist_m34_4e7_HWinHM__channel = new TH1D("hist_m34_4e7_HWinHM__channel","hist_m34_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4e7_HWinHM__channel);
        TH1D *hist_m34_4e6_ZVeto_channel = new TH1D("hist_m34_4e6_ZVeto_channel","hist_m34_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4e6_ZVeto_channel);
        TH1D *hist_m34_4e8_LooseSR_channel = new TH1D("hist_m34_4e8_LooseSR_channel","hist_m34_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4e8_LooseSR_channel);
        TH1D *hist_m34_4e9_MediumSR_channel = new TH1D("hist_m34_4e9_MediumSR_channel","hist_m34_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4e9_MediumSR_channel);
        TH1D *hist_m34_4e0_all_channel = new TH1D("hist_m34_4e0_all_channel","hist_m34_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4e0_all_channel);

        TH1D *hist_m32_4e1_isol_channel = new TH1D("hist_m32_4e1_isol_channel","hist_m32_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4e1_isol_channel);
        TH1D *hist_m32_4e2_elID_channel = new TH1D("hist_m32_4e2_elID_channel","hist_m32_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4e2_elID_channel);
        TH1D *hist_m32_4e3_imp_channel = new TH1D("hist_m32_4e3_imp_channel","hist_m32_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4e3_imp_channel);
        TH1D *hist_m32_4e4_QVeto_channel = new TH1D("hist_m32_4e4_QVeto_channel","hist_m32_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4e4_QVeto_channel);
        TH1D *hist_m32_4e5_lowMassVeto_channel = new TH1D("hist_m32_4e5_lowMassVeto_channel","hist_m32_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4e5_lowMassVeto_channel);
        TH1D *hist_m32_4e7_HWinHM__channel = new TH1D("hist_m32_4e7_HWinHM__channel","hist_m32_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4e7_HWinHM__channel);
        TH1D *hist_m32_4e6_ZVeto_channel = new TH1D("hist_m32_4e6_ZVeto_channel","hist_m32_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4e6_ZVeto_channel);
        TH1D *hist_m32_4e8_LooseSR_channel = new TH1D("hist_m32_4e8_LooseSR_channel","hist_m32_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4e8_LooseSR_channel);
        TH1D *hist_m32_4e9_MediumSR_channel = new TH1D("hist_m32_4e9_MediumSR_channel","hist_m32_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4e9_MediumSR_channel);
        TH1D *hist_m32_4e0_all_channel = new TH1D("hist_m32_4e0_all_channel","hist_m32_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4e0_all_channel);

        TH1D *hist_m14_4e1_isol_channel = new TH1D("hist_m14_4e1_isol_channel","hist_m14_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4e1_isol_channel);
        TH1D *hist_m14_4e2_elID_channel = new TH1D("hist_m14_4e2_elID_channel","hist_m14_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4e2_elID_channel);
        TH1D *hist_m14_4e3_imp_channel = new TH1D("hist_m14_4e3_imp_channel","hist_m14_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4e3_imp_channel);
        TH1D *hist_m14_4e4_QVeto_channel = new TH1D("hist_m14_4e4_QVeto_channel","hist_m14_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4e4_QVeto_channel);
        TH1D *hist_m14_4e5_lowMassVeto_channel = new TH1D("hist_m14_4e5_lowMassVeto_channel","hist_m14_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4e5_lowMassVeto_channel);
        TH1D *hist_m14_4e7_HWinHM__channel = new TH1D("hist_m14_4e7_HWinHM__channel","hist_m14_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4e7_HWinHM__channel);
        TH1D *hist_m14_4e6_ZVeto_channel = new TH1D("hist_m14_4e6_ZVeto_channel","hist_m14_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4e6_ZVeto_channel);
        TH1D *hist_m14_4e8_LooseSR_channel = new TH1D("hist_m14_4e8_LooseSR_channel","hist_m14_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4e8_LooseSR_channel);
        TH1D *hist_m14_4e9_MediumSR_channel = new TH1D("hist_m14_4e9_MediumSR_channel","hist_m14_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4e9_MediumSR_channel);
        TH1D *hist_m14_4e0_all_channel = new TH1D("hist_m14_4e0_all_channel","hist_m14_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4e0_all_channel);

        TH1D *hist_mll_4e1_isol_channel = new TH1D("hist_mll_4e1_isol_channel","hist_mll_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4e1_isol_channel);
        TH1D *hist_mll_4e2_elID_channel = new TH1D("hist_mll_4e2_elID_channel","hist_mll_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4e2_elID_channel);
        TH1D *hist_mll_4e3_imp_channel = new TH1D("hist_mll_4e3_imp_channel","hist_mll_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4e3_imp_channel);
        TH1D *hist_mll_4e4_QVeto_channel = new TH1D("hist_mll_4e4_QVeto_channel","hist_mll_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4e4_QVeto_channel);
        TH1D *hist_mll_4e5_lowMassVeto_channel = new TH1D("hist_mll_4e5_lowMassVeto_channel","hist_mll_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4e5_lowMassVeto_channel);
        TH1D *hist_mll_4e7_HWinHM__channel = new TH1D("hist_mll_4e7_HWinHM__channel","hist_mll_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4e7_HWinHM__channel);
        TH1D *hist_mll_4e6_ZVeto_channel = new TH1D("hist_mll_4e6_ZVeto_channel","hist_mll_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4e6_ZVeto_channel);
        TH1D *hist_mll_4e8_LooseSR_channel = new TH1D("hist_mll_4e8_LooseSR_channel","hist_mll_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4e8_LooseSR_channel);
        TH1D *hist_mll_4e9_MediumSR_channel = new TH1D("hist_mll_4e9_MediumSR_channel","hist_mll_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4e9_MediumSR_channel);
        TH1D *hist_mll_4e0_all_channel = new TH1D("hist_mll_4e0_all_channel","hist_mll_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4e0_all_channel);

        TH1D *hist_mll_atl_4e1_isol_channel = new TH1D("hist_mll_atl_4e1_isol_channel","hist_mll_atl_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4e1_isol_channel);
        TH1D *hist_mll_atl_4e2_elID_channel = new TH1D("hist_mll_atl_4e2_elID_channel","hist_mll_atl_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4e2_elID_channel);
        TH1D *hist_mll_atl_4e3_imp_channel = new TH1D("hist_mll_atl_4e3_imp_channel","hist_mll_atl_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4e3_imp_channel);
        TH1D *hist_mll_atl_4e4_QVeto_channel = new TH1D("hist_mll_atl_4e4_QVeto_channel","hist_mll_atl_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4e4_QVeto_channel);
        TH1D *hist_mll_atl_4e5_lowMassVeto_channel = new TH1D("hist_mll_atl_4e5_lowMassVeto_channel","hist_mll_atl_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4e5_lowMassVeto_channel);
        TH1D *hist_mll_atl_4e7_HWinHM__channel = new TH1D("hist_mll_atl_4e7_HWinHM__channel","hist_mll_atl_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4e7_HWinHM__channel);
        TH1D *hist_mll_atl_4e6_ZVeto_channel = new TH1D("hist_mll_atl_4e6_ZVeto_channel","hist_mll_atl_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4e6_ZVeto_channel);
        TH1D *hist_mll_atl_4e8_LooseSR_channel = new TH1D("hist_mll_atl_4e8_LooseSR_channel","hist_mll_atl_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4e8_LooseSR_channel);
        TH1D *hist_mll_atl_4e9_MediumSR_channel = new TH1D("hist_mll_atl_4e9_MediumSR_channel","hist_mll_atl_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4e9_MediumSR_channel);
        TH1D *hist_mll_atl_4e0_all_channel = new TH1D("hist_mll_atl_4e0_all_channel","hist_mll_atl_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4e0_all_channel);

        TH1D *hist_Pt1_4e1_isol_channel = new TH1D("hist_Pt1_4e1_isol_channel","hist_Pt1_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4e1_isol_channel);
        TH1D *hist_Pt1_4e2_elID_channel = new TH1D("hist_Pt1_4e2_elID_channel","hist_Pt1_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4e2_elID_channel);
        TH1D *hist_Pt1_4e3_imp_channel = new TH1D("hist_Pt1_4e3_imp_channel","hist_Pt1_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4e3_imp_channel);
        TH1D *hist_Pt1_4e4_QVeto_channel = new TH1D("hist_Pt1_4e4_QVeto_channel","hist_Pt1_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4e4_QVeto_channel);
        TH1D *hist_Pt1_4e5_lowMassVeto_channel = new TH1D("hist_Pt1_4e5_lowMassVeto_channel","hist_Pt1_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4e5_lowMassVeto_channel);
        TH1D *hist_Pt1_4e7_HWinHM__channel = new TH1D("hist_Pt1_4e7_HWinHM__channel","hist_Pt1_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4e7_HWinHM__channel);
        TH1D *hist_Pt1_4e6_ZVeto_channel = new TH1D("hist_Pt1_4e6_ZVeto_channel","hist_Pt1_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4e6_ZVeto_channel);
        TH1D *hist_Pt1_4e8_LooseSR_channel = new TH1D("hist_Pt1_4e8_LooseSR_channel","hist_Pt1_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4e8_LooseSR_channel);
        TH1D *hist_Pt1_4e9_MediumSR_channel = new TH1D("hist_Pt1_4e9_MediumSR_channel","hist_Pt1_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4e9_MediumSR_channel);
        TH1D *hist_Pt1_4e0_all_channel = new TH1D("hist_Pt1_4e0_all_channel","hist_Pt1_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4e0_all_channel);

        TH1D *hist_Pt2_4e1_isol_channel = new TH1D("hist_Pt2_4e1_isol_channel","hist_Pt2_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4e1_isol_channel);
        TH1D *hist_Pt2_4e2_elID_channel = new TH1D("hist_Pt2_4e2_elID_channel","hist_Pt2_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4e2_elID_channel);
        TH1D *hist_Pt2_4e3_imp_channel = new TH1D("hist_Pt2_4e3_imp_channel","hist_Pt2_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4e3_imp_channel);
        TH1D *hist_Pt2_4e4_QVeto_channel = new TH1D("hist_Pt2_4e4_QVeto_channel","hist_Pt2_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4e4_QVeto_channel);
        TH1D *hist_Pt2_4e5_lowMassVeto_channel = new TH1D("hist_Pt2_4e5_lowMassVeto_channel","hist_Pt2_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4e5_lowMassVeto_channel);
        TH1D *hist_Pt2_4e7_HWinHM__channel = new TH1D("hist_Pt2_4e7_HWinHM__channel","hist_Pt2_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4e7_HWinHM__channel);
        TH1D *hist_Pt2_4e6_ZVeto_channel = new TH1D("hist_Pt2_4e6_ZVeto_channel","hist_Pt2_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4e6_ZVeto_channel);
        TH1D *hist_Pt2_4e8_LooseSR_channel = new TH1D("hist_Pt2_4e8_LooseSR_channel","hist_Pt2_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4e8_LooseSR_channel);
        TH1D *hist_Pt2_4e9_MediumSR_channel = new TH1D("hist_Pt2_4e9_MediumSR_channel","hist_Pt2_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4e9_MediumSR_channel);
        TH1D *hist_Pt2_4e0_all_channel = new TH1D("hist_Pt2_4e0_all_channel","hist_Pt2_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4e0_all_channel);

        TH1D *hist_Pt3_4e1_isol_channel = new TH1D("hist_Pt3_4e1_isol_channel","hist_Pt3_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4e1_isol_channel);
        TH1D *hist_Pt3_4e2_elID_channel = new TH1D("hist_Pt3_4e2_elID_channel","hist_Pt3_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4e2_elID_channel);
        TH1D *hist_Pt3_4e3_imp_channel = new TH1D("hist_Pt3_4e3_imp_channel","hist_Pt3_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4e3_imp_channel);
        TH1D *hist_Pt3_4e4_QVeto_channel = new TH1D("hist_Pt3_4e4_QVeto_channel","hist_Pt3_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4e4_QVeto_channel);
        TH1D *hist_Pt3_4e5_lowMassVeto_channel = new TH1D("hist_Pt3_4e5_lowMassVeto_channel","hist_Pt3_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4e5_lowMassVeto_channel);
        TH1D *hist_Pt3_4e7_HWinHM__channel = new TH1D("hist_Pt3_4e7_HWinHM__channel","hist_Pt3_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4e7_HWinHM__channel);
        TH1D *hist_Pt3_4e6_ZVeto_channel = new TH1D("hist_Pt3_4e6_ZVeto_channel","hist_Pt3_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4e6_ZVeto_channel);
        TH1D *hist_Pt3_4e8_LooseSR_channel = new TH1D("hist_Pt3_4e8_LooseSR_channel","hist_Pt3_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4e8_LooseSR_channel);
        TH1D *hist_Pt3_4e9_MediumSR_channel = new TH1D("hist_Pt3_4e9_MediumSR_channel","hist_Pt3_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4e9_MediumSR_channel);
        TH1D *hist_Pt3_4e0_all_channel = new TH1D("hist_Pt3_4e0_all_channel","hist_Pt3_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4e0_all_channel);

        TH1D *hist_Pt4_4e1_isol_channel = new TH1D("hist_Pt4_4e1_isol_channel","hist_Pt4_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4e1_isol_channel);
        TH1D *hist_Pt4_4e2_elID_channel = new TH1D("hist_Pt4_4e2_elID_channel","hist_Pt4_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4e2_elID_channel);
        TH1D *hist_Pt4_4e3_imp_channel = new TH1D("hist_Pt4_4e3_imp_channel","hist_Pt4_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4e3_imp_channel);
        TH1D *hist_Pt4_4e4_QVeto_channel = new TH1D("hist_Pt4_4e4_QVeto_channel","hist_Pt4_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4e4_QVeto_channel);
        TH1D *hist_Pt4_4e5_lowMassVeto_channel = new TH1D("hist_Pt4_4e5_lowMassVeto_channel","hist_Pt4_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4e5_lowMassVeto_channel);
        TH1D *hist_Pt4_4e7_HWinHM__channel = new TH1D("hist_Pt4_4e7_HWinHM__channel","hist_Pt4_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4e7_HWinHM__channel);
        TH1D *hist_Pt4_4e6_ZVeto_channel = new TH1D("hist_Pt4_4e6_ZVeto_channel","hist_Pt4_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4e6_ZVeto_channel);
        TH1D *hist_Pt4_4e8_LooseSR_channel = new TH1D("hist_Pt4_4e8_LooseSR_channel","hist_Pt4_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4e8_LooseSR_channel);
        TH1D *hist_Pt4_4e9_MediumSR_channel = new TH1D("hist_Pt4_4e9_MediumSR_channel","hist_Pt4_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4e9_MediumSR_channel);
        TH1D *hist_Pt4_4e0_all_channel = new TH1D("hist_Pt4_4e0_all_channel","hist_Pt4_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4e0_all_channel);

        TH1D *hist_Eta1_4e1_isol_channel = new TH1D("hist_Eta1_4e1_isol_channel","hist_Eta1_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4e1_isol_channel);
        TH1D *hist_Eta1_4e2_elID_channel = new TH1D("hist_Eta1_4e2_elID_channel","hist_Eta1_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4e2_elID_channel);
        TH1D *hist_Eta1_4e3_imp_channel = new TH1D("hist_Eta1_4e3_imp_channel","hist_Eta1_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4e3_imp_channel);
        TH1D *hist_Eta1_4e4_QVeto_channel = new TH1D("hist_Eta1_4e4_QVeto_channel","hist_Eta1_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4e4_QVeto_channel);
        TH1D *hist_Eta1_4e5_lowMassVeto_channel = new TH1D("hist_Eta1_4e5_lowMassVeto_channel","hist_Eta1_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4e5_lowMassVeto_channel);
        TH1D *hist_Eta1_4e7_HWinHM__channel = new TH1D("hist_Eta1_4e7_HWinHM__channel","hist_Eta1_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4e7_HWinHM__channel);
        TH1D *hist_Eta1_4e6_ZVeto_channel = new TH1D("hist_Eta1_4e6_ZVeto_channel","hist_Eta1_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4e6_ZVeto_channel);
        TH1D *hist_Eta1_4e8_LooseSR_channel = new TH1D("hist_Eta1_4e8_LooseSR_channel","hist_Eta1_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4e8_LooseSR_channel);
        TH1D *hist_Eta1_4e9_MediumSR_channel = new TH1D("hist_Eta1_4e9_MediumSR_channel","hist_Eta1_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4e9_MediumSR_channel);
        TH1D *hist_Eta1_4e0_all_channel = new TH1D("hist_Eta1_4e0_all_channel","hist_Eta1_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4e0_all_channel);

        TH1D *hist_Eta2_4e1_isol_channel = new TH1D("hist_Eta2_4e1_isol_channel","hist_Eta2_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4e1_isol_channel);
        TH1D *hist_Eta2_4e2_elID_channel = new TH1D("hist_Eta2_4e2_elID_channel","hist_Eta2_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4e2_elID_channel);
        TH1D *hist_Eta2_4e3_imp_channel = new TH1D("hist_Eta2_4e3_imp_channel","hist_Eta2_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4e3_imp_channel);
        TH1D *hist_Eta2_4e4_QVeto_channel = new TH1D("hist_Eta2_4e4_QVeto_channel","hist_Eta2_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4e4_QVeto_channel);
        TH1D *hist_Eta2_4e5_lowMassVeto_channel = new TH1D("hist_Eta2_4e5_lowMassVeto_channel","hist_Eta2_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4e5_lowMassVeto_channel);
        TH1D *hist_Eta2_4e7_HWinHM__channel = new TH1D("hist_Eta2_4e7_HWinHM__channel","hist_Eta2_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4e7_HWinHM__channel);
        TH1D *hist_Eta2_4e6_ZVeto_channel = new TH1D("hist_Eta2_4e6_ZVeto_channel","hist_Eta2_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4e6_ZVeto_channel);
        TH1D *hist_Eta2_4e8_LooseSR_channel = new TH1D("hist_Eta2_4e8_LooseSR_channel","hist_Eta2_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4e8_LooseSR_channel);
        TH1D *hist_Eta2_4e9_MediumSR_channel = new TH1D("hist_Eta2_4e9_MediumSR_channel","hist_Eta2_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4e9_MediumSR_channel);
        TH1D *hist_Eta2_4e0_all_channel = new TH1D("hist_Eta2_4e0_all_channel","hist_Eta2_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4e0_all_channel);

        TH1D *hist_Eta3_4e1_isol_channel = new TH1D("hist_Eta3_4e1_isol_channel","hist_Eta3_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4e1_isol_channel);
        TH1D *hist_Eta3_4e2_elID_channel = new TH1D("hist_Eta3_4e2_elID_channel","hist_Eta3_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4e2_elID_channel);
        TH1D *hist_Eta3_4e3_imp_channel = new TH1D("hist_Eta3_4e3_imp_channel","hist_Eta3_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4e3_imp_channel);
        TH1D *hist_Eta3_4e4_QVeto_channel = new TH1D("hist_Eta3_4e4_QVeto_channel","hist_Eta3_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4e4_QVeto_channel);
        TH1D *hist_Eta3_4e5_lowMassVeto_channel = new TH1D("hist_Eta3_4e5_lowMassVeto_channel","hist_Eta3_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4e5_lowMassVeto_channel);
        TH1D *hist_Eta3_4e7_HWinHM__channel = new TH1D("hist_Eta3_4e7_HWinHM__channel","hist_Eta3_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4e7_HWinHM__channel);
        TH1D *hist_Eta3_4e6_ZVeto_channel = new TH1D("hist_Eta3_4e6_ZVeto_channel","hist_Eta3_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4e6_ZVeto_channel);
        TH1D *hist_Eta3_4e8_LooseSR_channel = new TH1D("hist_Eta3_4e8_LooseSR_channel","hist_Eta3_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4e8_LooseSR_channel);
        TH1D *hist_Eta3_4e9_MediumSR_channel = new TH1D("hist_Eta3_4e9_MediumSR_channel","hist_Eta3_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4e9_MediumSR_channel);
        TH1D *hist_Eta3_4e0_all_channel = new TH1D("hist_Eta3_4e0_all_channel","hist_Eta3_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4e0_all_channel);

        TH1D *hist_Eta4_4e1_isol_channel = new TH1D("hist_Eta4_4e1_isol_channel","hist_Eta4_4e1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4e1_isol_channel);
        TH1D *hist_Eta4_4e2_elID_channel = new TH1D("hist_Eta4_4e2_elID_channel","hist_Eta4_4e2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4e2_elID_channel);
        TH1D *hist_Eta4_4e3_imp_channel = new TH1D("hist_Eta4_4e3_imp_channel","hist_Eta4_4e3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4e3_imp_channel);
        TH1D *hist_Eta4_4e4_QVeto_channel = new TH1D("hist_Eta4_4e4_QVeto_channel","hist_Eta4_4e4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4e4_QVeto_channel);
        TH1D *hist_Eta4_4e5_lowMassVeto_channel = new TH1D("hist_Eta4_4e5_lowMassVeto_channel","hist_Eta4_4e5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4e5_lowMassVeto_channel);
        TH1D *hist_Eta4_4e7_HWinHM__channel = new TH1D("hist_Eta4_4e7_HWinHM__channel","hist_Eta4_4e7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4e7_HWinHM__channel);
        TH1D *hist_Eta4_4e6_ZVeto_channel = new TH1D("hist_Eta4_4e6_ZVeto_channel","hist_Eta4_4e6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4e6_ZVeto_channel);
        TH1D *hist_Eta4_4e8_LooseSR_channel = new TH1D("hist_Eta4_4e8_LooseSR_channel","hist_Eta4_4e8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4e8_LooseSR_channel);
        TH1D *hist_Eta4_4e9_MediumSR_channel = new TH1D("hist_Eta4_4e9_MediumSR_channel","hist_Eta4_4e9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4e9_MediumSR_channel);
        TH1D *hist_Eta4_4e0_all_channel = new TH1D("hist_Eta4_4e0_all_channel","hist_Eta4_4e0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4e0_all_channel);

        TH1D *hist_Phi1_4e1_isol_channel = new TH1D("hist_Phi1_4e1_isol_channel","hist_Phi1_4e1_isol_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi1_4e1_isol_channel);
        TH1D *hist_Phi1_4e2_elID_channel = new TH1D("hist_Phi1_4e2_elID_channel","hist_Phi1_4e2_elID_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi1_4e2_elID_channel);
        TH1D *hist_Phi1_4e3_imp_channel = new TH1D("hist_Phi1_4e3_imp_channel","hist_Phi1_4e3_imp_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi1_4e3_imp_channel);
        TH1D *hist_Phi1_4e4_QVeto_channel = new TH1D("hist_Phi1_4e4_QVeto_channel","hist_Phi1_4e4_QVeto_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi1_4e4_QVeto_channel);
        TH1D *hist_Phi1_4e5_lowMassVeto_channel = new TH1D("hist_Phi1_4e5_lowMassVeto_channel","hist_Phi1_4e5_lowMassVeto_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi1_4e5_lowMassVeto_channel);
        TH1D *hist_Phi1_4e7_HWinHM__channel = new TH1D("hist_Phi1_4e7_HWinHM__channel","hist_Phi1_4e7_HWinHM__channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi1_4e7_HWinHM__channel);
        TH1D *hist_Phi1_4e6_ZVeto_channel = new TH1D("hist_Phi1_4e6_ZVeto_channel","hist_Phi1_4e6_ZVeto_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi1_4e6_ZVeto_channel);
        TH1D *hist_Phi1_4e8_LooseSR_channel = new TH1D("hist_Phi1_4e8_LooseSR_channel","hist_Phi1_4e8_LooseSR_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi1_4e8_LooseSR_channel);
        TH1D *hist_Phi1_4e9_MediumSR_channel = new TH1D("hist_Phi1_4e9_MediumSR_channel","hist_Phi1_4e9_MediumSR_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi1_4e9_MediumSR_channel);
        TH1D *hist_Phi1_4e0_all_channel = new TH1D("hist_Phi1_4e0_all_channel","hist_Phi1_4e0_all_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi1_4e0_all_channel);

        TH1D *hist_Phi2_4e1_isol_channel = new TH1D("hist_Phi2_4e1_isol_channel","hist_Phi2_4e1_isol_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi2_4e1_isol_channel);
        TH1D *hist_Phi2_4e2_elID_channel = new TH1D("hist_Phi2_4e2_elID_channel","hist_Phi2_4e2_elID_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi2_4e2_elID_channel);
        TH1D *hist_Phi2_4e3_imp_channel = new TH1D("hist_Phi2_4e3_imp_channel","hist_Phi2_4e3_imp_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi2_4e3_imp_channel);
        TH1D *hist_Phi2_4e4_QVeto_channel = new TH1D("hist_Phi2_4e4_QVeto_channel","hist_Phi2_4e4_QVeto_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi2_4e4_QVeto_channel);
        TH1D *hist_Phi2_4e5_lowMassVeto_channel = new TH1D("hist_Phi2_4e5_lowMassVeto_channel","hist_Phi2_4e5_lowMassVeto_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi2_4e5_lowMassVeto_channel);
        TH1D *hist_Phi2_4e7_HWinHM__channel = new TH1D("hist_Phi2_4e7_HWinHM__channel","hist_Phi2_4e7_HWinHM__channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi2_4e7_HWinHM__channel);
        TH1D *hist_Phi2_4e6_ZVeto_channel = new TH1D("hist_Phi2_4e6_ZVeto_channel","hist_Phi2_4e6_ZVeto_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi2_4e6_ZVeto_channel);
        TH1D *hist_Phi2_4e8_LooseSR_channel = new TH1D("hist_Phi2_4e8_LooseSR_channel","hist_Phi2_4e8_LooseSR_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi2_4e8_LooseSR_channel);
        TH1D *hist_Phi2_4e9_MediumSR_channel = new TH1D("hist_Phi2_4e9_MediumSR_channel","hist_Phi2_4e9_MediumSR_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi2_4e9_MediumSR_channel);
        TH1D *hist_Phi2_4e0_all_channel = new TH1D("hist_Phi2_4e0_all_channel","hist_Phi2_4e0_all_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi2_4e0_all_channel);

        TH1D *hist_Phi3_4e1_isol_channel = new TH1D("hist_Phi3_4e1_isol_channel","hist_Phi3_4e1_isol_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi3_4e1_isol_channel);
        TH1D *hist_Phi3_4e2_elID_channel = new TH1D("hist_Phi3_4e2_elID_channel","hist_Phi3_4e2_elID_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi3_4e2_elID_channel);
        TH1D *hist_Phi3_4e3_imp_channel = new TH1D("hist_Phi3_4e3_imp_channel","hist_Phi3_4e3_imp_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi3_4e3_imp_channel);
        TH1D *hist_Phi3_4e4_QVeto_channel = new TH1D("hist_Phi3_4e4_QVeto_channel","hist_Phi3_4e4_QVeto_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi3_4e4_QVeto_channel);
        TH1D *hist_Phi3_4e5_lowMassVeto_channel = new TH1D("hist_Phi3_4e5_lowMassVeto_channel","hist_Phi3_4e5_lowMassVeto_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi3_4e5_lowMassVeto_channel);
        TH1D *hist_Phi3_4e7_HWinHM__channel = new TH1D("hist_Phi3_4e7_HWinHM__channel","hist_Phi3_4e7_HWinHM__channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi3_4e7_HWinHM__channel);
        TH1D *hist_Phi3_4e6_ZVeto_channel = new TH1D("hist_Phi3_4e6_ZVeto_channel","hist_Phi3_4e6_ZVeto_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi3_4e6_ZVeto_channel);
        TH1D *hist_Phi3_4e8_LooseSR_channel = new TH1D("hist_Phi3_4e8_LooseSR_channel","hist_Phi3_4e8_LooseSR_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi3_4e8_LooseSR_channel);
        TH1D *hist_Phi3_4e9_MediumSR_channel = new TH1D("hist_Phi3_4e9_MediumSR_channel","hist_Phi3_4e9_MediumSR_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi3_4e9_MediumSR_channel);
        TH1D *hist_Phi3_4e0_all_channel = new TH1D("hist_Phi3_4e0_all_channel","hist_Phi3_4e0_all_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi3_4e0_all_channel);

        TH1D *hist_Phi4_4e1_isol_channel = new TH1D("hist_Phi4_4e1_isol_channel","hist_Phi4_4e1_isol_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi4_4e1_isol_channel);
        TH1D *hist_Phi4_4e2_elID_channel = new TH1D("hist_Phi4_4e2_elID_channel","hist_Phi4_4e2_elID_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi4_4e2_elID_channel);
        TH1D *hist_Phi4_4e3_imp_channel = new TH1D("hist_Phi4_4e3_imp_channel","hist_Phi4_4e3_imp_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi4_4e3_imp_channel);
        TH1D *hist_Phi4_4e4_QVeto_channel = new TH1D("hist_Phi4_4e4_QVeto_channel","hist_Phi4_4e4_QVeto_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi4_4e4_QVeto_channel);
        TH1D *hist_Phi4_4e5_lowMassVeto_channel = new TH1D("hist_Phi4_4e5_lowMassVeto_channel","hist_Phi4_4e5_lowMassVeto_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi4_4e5_lowMassVeto_channel);
        TH1D *hist_Phi4_4e7_HWinHM__channel = new TH1D("hist_Phi4_4e7_HWinHM__channel","hist_Phi4_4e7_HWinHM__channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi4_4e7_HWinHM__channel);
        TH1D *hist_Phi4_4e6_ZVeto_channel = new TH1D("hist_Phi4_4e6_ZVeto_channel","hist_Phi4_4e6_ZVeto_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi4_4e6_ZVeto_channel);
        TH1D *hist_Phi4_4e8_LooseSR_channel = new TH1D("hist_Phi4_4e8_LooseSR_channel","hist_Phi4_4e8_LooseSR_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi4_4e8_LooseSR_channel);
        TH1D *hist_Phi4_4e9_MediumSR_channel = new TH1D("hist_Phi4_4e9_MediumSR_channel","hist_Phi4_4e9_MediumSR_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi4_4e9_MediumSR_channel);
        TH1D *hist_Phi4_4e0_all_channel = new TH1D("hist_Phi4_4e0_all_channel","hist_Phi4_4e0_all_channel",160,-4.28,4.28);
        MyHistArray->AddLast(hist_Phi4_4e0_all_channel);


        TH1D *hist_m4l_2e2m1_isol_channel = new TH1D("hist_m4l_2e2m1_isol_channel","hist_m4l_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_2e2m1_isol_channel);
        TH1D *hist_m4l_2e2m2_elID_channel = new TH1D("hist_m4l_2e2m2_elID_channel","hist_m4l_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_2e2m2_elID_channel);
        TH1D *hist_m4l_2e2m3_imp_channel = new TH1D("hist_m4l_2e2m3_imp_channel","hist_m4l_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_2e2m3_imp_channel);
        TH1D *hist_m4l_2e2m4_QVeto_channel = new TH1D("hist_m4l_2e2m4_QVeto_channel","hist_m4l_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_2e2m4_QVeto_channel);
        TH1D *hist_m4l_2e2m5_lowMassVeto_channel = new TH1D("hist_m4l_2e2m5_lowMassVeto_channel","hist_m4l_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_2e2m5_lowMassVeto_channel);
        TH1D *hist_m4l_2e2m7_HWinHM__channel = new TH1D("hist_m4l_2e2m7_HWinHM__channel","hist_m4l_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_2e2m7_HWinHM__channel);
        TH1D *hist_m4l_2e2m6_ZVeto_channel = new TH1D("hist_m4l_2e2m6_ZVeto_channel","hist_m4l_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_2e2m6_ZVeto_channel);
        TH1D *hist_m4l_2e2m8_LooseSR_channel = new TH1D("hist_m4l_2e2m8_LooseSR_channel","hist_m4l_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_2e2m8_LooseSR_channel);
        TH1D *hist_m4l_2e2m9_MediumSR_channel = new TH1D("hist_m4l_2e2m9_MediumSR_channel","hist_m4l_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_2e2m9_MediumSR_channel);
        TH1D *hist_m4l_2e2m0_all_channel = new TH1D("hist_m4l_2e2m0_all_channel","hist_m4l_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_2e2m0_all_channel);

        TH1D *hist_m12_2e2m1_isol_channel = new TH1D("hist_m12_2e2m1_isol_channel","hist_m12_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_2e2m1_isol_channel);
        TH1D *hist_m12_2e2m2_elID_channel = new TH1D("hist_m12_2e2m2_elID_channel","hist_m12_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_2e2m2_elID_channel);
        TH1D *hist_m12_2e2m3_imp_channel = new TH1D("hist_m12_2e2m3_imp_channel","hist_m12_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_2e2m3_imp_channel);
        TH1D *hist_m12_2e2m4_QVeto_channel = new TH1D("hist_m12_2e2m4_QVeto_channel","hist_m12_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_2e2m4_QVeto_channel);
        TH1D *hist_m12_2e2m5_lowMassVeto_channel = new TH1D("hist_m12_2e2m5_lowMassVeto_channel","hist_m12_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_2e2m5_lowMassVeto_channel);
        TH1D *hist_m12_2e2m7_HWinHM__channel = new TH1D("hist_m12_2e2m7_HWinHM__channel","hist_m12_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m12_2e2m7_HWinHM__channel);
        TH1D *hist_m12_2e2m6_ZVeto_channel = new TH1D("hist_m12_2e2m6_ZVeto_channel","hist_m12_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_2e2m6_ZVeto_channel);
        TH1D *hist_m12_2e2m8_LooseSR_channel = new TH1D("hist_m12_2e2m8_LooseSR_channel","hist_m12_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_2e2m8_LooseSR_channel);
        TH1D *hist_m12_2e2m9_MediumSR_channel = new TH1D("hist_m12_2e2m9_MediumSR_channel","hist_m12_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_2e2m9_MediumSR_channel);
        TH1D *hist_m12_2e2m0_all_channel = new TH1D("hist_m12_2e2m0_all_channel","hist_m12_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_2e2m0_all_channel);

        TH1D *hist_m34_2e2m1_isol_channel = new TH1D("hist_m34_2e2m1_isol_channel","hist_m34_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_2e2m1_isol_channel);
        TH1D *hist_m34_2e2m2_elID_channel = new TH1D("hist_m34_2e2m2_elID_channel","hist_m34_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_2e2m2_elID_channel);
        TH1D *hist_m34_2e2m3_imp_channel = new TH1D("hist_m34_2e2m3_imp_channel","hist_m34_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_2e2m3_imp_channel);
        TH1D *hist_m34_2e2m4_QVeto_channel = new TH1D("hist_m34_2e2m4_QVeto_channel","hist_m34_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_2e2m4_QVeto_channel);
        TH1D *hist_m34_2e2m5_lowMassVeto_channel = new TH1D("hist_m34_2e2m5_lowMassVeto_channel","hist_m34_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_2e2m5_lowMassVeto_channel);
        TH1D *hist_m34_2e2m7_HWinHM__channel = new TH1D("hist_m34_2e2m7_HWinHM__channel","hist_m34_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m34_2e2m7_HWinHM__channel);
        TH1D *hist_m34_2e2m6_ZVeto_channel = new TH1D("hist_m34_2e2m6_ZVeto_channel","hist_m34_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_2e2m6_ZVeto_channel);
        TH1D *hist_m34_2e2m8_LooseSR_channel = new TH1D("hist_m34_2e2m8_LooseSR_channel","hist_m34_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_2e2m8_LooseSR_channel);
        TH1D *hist_m34_2e2m9_MediumSR_channel = new TH1D("hist_m34_2e2m9_MediumSR_channel","hist_m34_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_2e2m9_MediumSR_channel);
        TH1D *hist_m34_2e2m0_all_channel = new TH1D("hist_m34_2e2m0_all_channel","hist_m34_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_2e2m0_all_channel);

        TH1D *hist_m32_2e2m1_isol_channel = new TH1D("hist_m32_2e2m1_isol_channel","hist_m32_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_2e2m1_isol_channel);
        TH1D *hist_m32_2e2m2_elID_channel = new TH1D("hist_m32_2e2m2_elID_channel","hist_m32_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_2e2m2_elID_channel);
        TH1D *hist_m32_2e2m3_imp_channel = new TH1D("hist_m32_2e2m3_imp_channel","hist_m32_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_2e2m3_imp_channel);
        TH1D *hist_m32_2e2m4_QVeto_channel = new TH1D("hist_m32_2e2m4_QVeto_channel","hist_m32_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_2e2m4_QVeto_channel);
        TH1D *hist_m32_2e2m5_lowMassVeto_channel = new TH1D("hist_m32_2e2m5_lowMassVeto_channel","hist_m32_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_2e2m5_lowMassVeto_channel);
        TH1D *hist_m32_2e2m7_HWinHM__channel = new TH1D("hist_m32_2e2m7_HWinHM__channel","hist_m32_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m32_2e2m7_HWinHM__channel);
        TH1D *hist_m32_2e2m6_ZVeto_channel = new TH1D("hist_m32_2e2m6_ZVeto_channel","hist_m32_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_2e2m6_ZVeto_channel);
        TH1D *hist_m32_2e2m8_LooseSR_channel = new TH1D("hist_m32_2e2m8_LooseSR_channel","hist_m32_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_2e2m8_LooseSR_channel);
        TH1D *hist_m32_2e2m9_MediumSR_channel = new TH1D("hist_m32_2e2m9_MediumSR_channel","hist_m32_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_2e2m9_MediumSR_channel);
        TH1D *hist_m32_2e2m0_all_channel = new TH1D("hist_m32_2e2m0_all_channel","hist_m32_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_2e2m0_all_channel);

        TH1D *hist_m14_2e2m1_isol_channel = new TH1D("hist_m14_2e2m1_isol_channel","hist_m14_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_2e2m1_isol_channel);
        TH1D *hist_m14_2e2m2_elID_channel = new TH1D("hist_m14_2e2m2_elID_channel","hist_m14_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_2e2m2_elID_channel);
        TH1D *hist_m14_2e2m3_imp_channel = new TH1D("hist_m14_2e2m3_imp_channel","hist_m14_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_2e2m3_imp_channel);
        TH1D *hist_m14_2e2m4_QVeto_channel = new TH1D("hist_m14_2e2m4_QVeto_channel","hist_m14_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_2e2m4_QVeto_channel);
        TH1D *hist_m14_2e2m5_lowMassVeto_channel = new TH1D("hist_m14_2e2m5_lowMassVeto_channel","hist_m14_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_2e2m5_lowMassVeto_channel);
        TH1D *hist_m14_2e2m7_HWinHM__channel = new TH1D("hist_m14_2e2m7_HWinHM__channel","hist_m14_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m14_2e2m7_HWinHM__channel);
        TH1D *hist_m14_2e2m6_ZVeto_channel = new TH1D("hist_m14_2e2m6_ZVeto_channel","hist_m14_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_2e2m6_ZVeto_channel);
        TH1D *hist_m14_2e2m8_LooseSR_channel = new TH1D("hist_m14_2e2m8_LooseSR_channel","hist_m14_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_2e2m8_LooseSR_channel);
        TH1D *hist_m14_2e2m9_MediumSR_channel = new TH1D("hist_m14_2e2m9_MediumSR_channel","hist_m14_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_2e2m9_MediumSR_channel);
        TH1D *hist_m14_2e2m0_all_channel = new TH1D("hist_m14_2e2m0_all_channel","hist_m14_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_2e2m0_all_channel);

        TH1D *hist_mll_2e2m1_isol_channel = new TH1D("hist_mll_2e2m1_isol_channel","hist_mll_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_2e2m1_isol_channel);
        TH1D *hist_mll_2e2m2_elID_channel = new TH1D("hist_mll_2e2m2_elID_channel","hist_mll_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_2e2m2_elID_channel);
        TH1D *hist_mll_2e2m3_imp_channel = new TH1D("hist_mll_2e2m3_imp_channel","hist_mll_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_2e2m3_imp_channel);
        TH1D *hist_mll_2e2m4_QVeto_channel = new TH1D("hist_mll_2e2m4_QVeto_channel","hist_mll_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_2e2m4_QVeto_channel);
        TH1D *hist_mll_2e2m5_lowMassVeto_channel = new TH1D("hist_mll_2e2m5_lowMassVeto_channel","hist_mll_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_2e2m5_lowMassVeto_channel);
        TH1D *hist_mll_2e2m7_HWinHM__channel = new TH1D("hist_mll_2e2m7_HWinHM__channel","hist_mll_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_mll_2e2m7_HWinHM__channel);
        TH1D *hist_mll_2e2m6_ZVeto_channel = new TH1D("hist_mll_2e2m6_ZVeto_channel","hist_mll_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_2e2m6_ZVeto_channel);
        TH1D *hist_mll_2e2m8_LooseSR_channel = new TH1D("hist_mll_2e2m8_LooseSR_channel","hist_mll_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_2e2m8_LooseSR_channel);
        TH1D *hist_mll_2e2m9_MediumSR_channel = new TH1D("hist_mll_2e2m9_MediumSR_channel","hist_mll_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_2e2m9_MediumSR_channel);
        TH1D *hist_mll_2e2m0_all_channel = new TH1D("hist_mll_2e2m0_all_channel","hist_mll_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_2e2m0_all_channel);

        TH1D *hist_mll_atl_2e2m1_isol_channel = new TH1D("hist_mll_atl_2e2m1_isol_channel","hist_mll_atl_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_2e2m1_isol_channel);
        TH1D *hist_mll_atl_2e2m2_elID_channel = new TH1D("hist_mll_atl_2e2m2_elID_channel","hist_mll_atl_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_2e2m2_elID_channel);
        TH1D *hist_mll_atl_2e2m3_imp_channel = new TH1D("hist_mll_atl_2e2m3_imp_channel","hist_mll_atl_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_2e2m3_imp_channel);
        TH1D *hist_mll_atl_2e2m4_QVeto_channel = new TH1D("hist_mll_atl_2e2m4_QVeto_channel","hist_mll_atl_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_2e2m4_QVeto_channel);
        TH1D *hist_mll_atl_2e2m5_lowMassVeto_channel = new TH1D("hist_mll_atl_2e2m5_lowMassVeto_channel","hist_mll_atl_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_2e2m5_lowMassVeto_channel);
        TH1D *hist_mll_atl_2e2m7_HWinHM__channel = new TH1D("hist_mll_atl_2e2m7_HWinHM__channel","hist_mll_atl_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_2e2m7_HWinHM__channel);
        TH1D *hist_mll_atl_2e2m6_ZVeto_channel = new TH1D("hist_mll_atl_2e2m6_ZVeto_channel","hist_mll_atl_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_2e2m6_ZVeto_channel);
        TH1D *hist_mll_atl_2e2m8_LooseSR_channel = new TH1D("hist_mll_atl_2e2m8_LooseSR_channel","hist_mll_atl_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_2e2m8_LooseSR_channel);
        TH1D *hist_mll_atl_2e2m9_MediumSR_channel = new TH1D("hist_mll_atl_2e2m9_MediumSR_channel","hist_mll_atl_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_2e2m9_MediumSR_channel);
        TH1D *hist_mll_atl_2e2m0_all_channel = new TH1D("hist_mll_atl_2e2m0_all_channel","hist_mll_atl_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_2e2m0_all_channel);

        TH1D *hist_Pt1_2e2m1_isol_channel = new TH1D("hist_Pt1_2e2m1_isol_channel","hist_Pt1_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_2e2m1_isol_channel);
        TH1D *hist_Pt1_2e2m2_elID_channel = new TH1D("hist_Pt1_2e2m2_elID_channel","hist_Pt1_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_2e2m2_elID_channel);
        TH1D *hist_Pt1_2e2m3_imp_channel = new TH1D("hist_Pt1_2e2m3_imp_channel","hist_Pt1_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_2e2m3_imp_channel);
        TH1D *hist_Pt1_2e2m4_QVeto_channel = new TH1D("hist_Pt1_2e2m4_QVeto_channel","hist_Pt1_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_2e2m4_QVeto_channel);
        TH1D *hist_Pt1_2e2m5_lowMassVeto_channel = new TH1D("hist_Pt1_2e2m5_lowMassVeto_channel","hist_Pt1_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_2e2m5_lowMassVeto_channel);
        TH1D *hist_Pt1_2e2m7_HWinHM__channel = new TH1D("hist_Pt1_2e2m7_HWinHM__channel","hist_Pt1_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_2e2m7_HWinHM__channel);
        TH1D *hist_Pt1_2e2m6_ZVeto_channel = new TH1D("hist_Pt1_2e2m6_ZVeto_channel","hist_Pt1_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_2e2m6_ZVeto_channel);
        TH1D *hist_Pt1_2e2m8_LooseSR_channel = new TH1D("hist_Pt1_2e2m8_LooseSR_channel","hist_Pt1_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_2e2m8_LooseSR_channel);
        TH1D *hist_Pt1_2e2m9_MediumSR_channel = new TH1D("hist_Pt1_2e2m9_MediumSR_channel","hist_Pt1_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_2e2m9_MediumSR_channel);
        TH1D *hist_Pt1_2e2m0_all_channel = new TH1D("hist_Pt1_2e2m0_all_channel","hist_Pt1_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_2e2m0_all_channel);

        TH1D *hist_Pt2_2e2m1_isol_channel = new TH1D("hist_Pt2_2e2m1_isol_channel","hist_Pt2_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_2e2m1_isol_channel);
        TH1D *hist_Pt2_2e2m2_elID_channel = new TH1D("hist_Pt2_2e2m2_elID_channel","hist_Pt2_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_2e2m2_elID_channel);
        TH1D *hist_Pt2_2e2m3_imp_channel = new TH1D("hist_Pt2_2e2m3_imp_channel","hist_Pt2_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_2e2m3_imp_channel);
        TH1D *hist_Pt2_2e2m4_QVeto_channel = new TH1D("hist_Pt2_2e2m4_QVeto_channel","hist_Pt2_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_2e2m4_QVeto_channel);
        TH1D *hist_Pt2_2e2m5_lowMassVeto_channel = new TH1D("hist_Pt2_2e2m5_lowMassVeto_channel","hist_Pt2_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_2e2m5_lowMassVeto_channel);
        TH1D *hist_Pt2_2e2m7_HWinHM__channel = new TH1D("hist_Pt2_2e2m7_HWinHM__channel","hist_Pt2_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_2e2m7_HWinHM__channel);
        TH1D *hist_Pt2_2e2m6_ZVeto_channel = new TH1D("hist_Pt2_2e2m6_ZVeto_channel","hist_Pt2_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_2e2m6_ZVeto_channel);
        TH1D *hist_Pt2_2e2m8_LooseSR_channel = new TH1D("hist_Pt2_2e2m8_LooseSR_channel","hist_Pt2_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_2e2m8_LooseSR_channel);
        TH1D *hist_Pt2_2e2m9_MediumSR_channel = new TH1D("hist_Pt2_2e2m9_MediumSR_channel","hist_Pt2_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_2e2m9_MediumSR_channel);
        TH1D *hist_Pt2_2e2m0_all_channel = new TH1D("hist_Pt2_2e2m0_all_channel","hist_Pt2_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_2e2m0_all_channel);

        TH1D *hist_Pt3_2e2m1_isol_channel = new TH1D("hist_Pt3_2e2m1_isol_channel","hist_Pt3_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_2e2m1_isol_channel);
        TH1D *hist_Pt3_2e2m2_elID_channel = new TH1D("hist_Pt3_2e2m2_elID_channel","hist_Pt3_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_2e2m2_elID_channel);
        TH1D *hist_Pt3_2e2m3_imp_channel = new TH1D("hist_Pt3_2e2m3_imp_channel","hist_Pt3_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_2e2m3_imp_channel);
        TH1D *hist_Pt3_2e2m4_QVeto_channel = new TH1D("hist_Pt3_2e2m4_QVeto_channel","hist_Pt3_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_2e2m4_QVeto_channel);
        TH1D *hist_Pt3_2e2m5_lowMassVeto_channel = new TH1D("hist_Pt3_2e2m5_lowMassVeto_channel","hist_Pt3_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_2e2m5_lowMassVeto_channel);
        TH1D *hist_Pt3_2e2m7_HWinHM__channel = new TH1D("hist_Pt3_2e2m7_HWinHM__channel","hist_Pt3_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_2e2m7_HWinHM__channel);
        TH1D *hist_Pt3_2e2m6_ZVeto_channel = new TH1D("hist_Pt3_2e2m6_ZVeto_channel","hist_Pt3_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_2e2m6_ZVeto_channel);
        TH1D *hist_Pt3_2e2m8_LooseSR_channel = new TH1D("hist_Pt3_2e2m8_LooseSR_channel","hist_Pt3_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_2e2m8_LooseSR_channel);
        TH1D *hist_Pt3_2e2m9_MediumSR_channel = new TH1D("hist_Pt3_2e2m9_MediumSR_channel","hist_Pt3_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_2e2m9_MediumSR_channel);
        TH1D *hist_Pt3_2e2m0_all_channel = new TH1D("hist_Pt3_2e2m0_all_channel","hist_Pt3_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_2e2m0_all_channel);

        TH1D *hist_Pt4_2e2m1_isol_channel = new TH1D("hist_Pt4_2e2m1_isol_channel","hist_Pt4_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_2e2m1_isol_channel);
        TH1D *hist_Pt4_2e2m2_elID_channel = new TH1D("hist_Pt4_2e2m2_elID_channel","hist_Pt4_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_2e2m2_elID_channel);
        TH1D *hist_Pt4_2e2m3_imp_channel = new TH1D("hist_Pt4_2e2m3_imp_channel","hist_Pt4_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_2e2m3_imp_channel);
        TH1D *hist_Pt4_2e2m4_QVeto_channel = new TH1D("hist_Pt4_2e2m4_QVeto_channel","hist_Pt4_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_2e2m4_QVeto_channel);
        TH1D *hist_Pt4_2e2m5_lowMassVeto_channel = new TH1D("hist_Pt4_2e2m5_lowMassVeto_channel","hist_Pt4_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_2e2m5_lowMassVeto_channel);
        TH1D *hist_Pt4_2e2m7_HWinHM__channel = new TH1D("hist_Pt4_2e2m7_HWinHM__channel","hist_Pt4_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_2e2m7_HWinHM__channel);
        TH1D *hist_Pt4_2e2m6_ZVeto_channel = new TH1D("hist_Pt4_2e2m6_ZVeto_channel","hist_Pt4_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_2e2m6_ZVeto_channel);
        TH1D *hist_Pt4_2e2m8_LooseSR_channel = new TH1D("hist_Pt4_2e2m8_LooseSR_channel","hist_Pt4_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_2e2m8_LooseSR_channel);
        TH1D *hist_Pt4_2e2m9_MediumSR_channel = new TH1D("hist_Pt4_2e2m9_MediumSR_channel","hist_Pt4_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_2e2m9_MediumSR_channel);
        TH1D *hist_Pt4_2e2m0_all_channel = new TH1D("hist_Pt4_2e2m0_all_channel","hist_Pt4_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_2e2m0_all_channel);

        TH1D *hist_Eta1_2e2m1_isol_channel = new TH1D("hist_Eta1_2e2m1_isol_channel","hist_Eta1_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_2e2m1_isol_channel);
        TH1D *hist_Eta1_2e2m2_elID_channel = new TH1D("hist_Eta1_2e2m2_elID_channel","hist_Eta1_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_2e2m2_elID_channel);
        TH1D *hist_Eta1_2e2m3_imp_channel = new TH1D("hist_Eta1_2e2m3_imp_channel","hist_Eta1_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_2e2m3_imp_channel);
        TH1D *hist_Eta1_2e2m4_QVeto_channel = new TH1D("hist_Eta1_2e2m4_QVeto_channel","hist_Eta1_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_2e2m4_QVeto_channel);
        TH1D *hist_Eta1_2e2m5_lowMassVeto_channel = new TH1D("hist_Eta1_2e2m5_lowMassVeto_channel","hist_Eta1_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_2e2m5_lowMassVeto_channel);
        TH1D *hist_Eta1_2e2m7_HWinHM__channel = new TH1D("hist_Eta1_2e2m7_HWinHM__channel","hist_Eta1_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_2e2m7_HWinHM__channel);
        TH1D *hist_Eta1_2e2m6_ZVeto_channel = new TH1D("hist_Eta1_2e2m6_ZVeto_channel","hist_Eta1_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_2e2m6_ZVeto_channel);
        TH1D *hist_Eta1_2e2m8_LooseSR_channel = new TH1D("hist_Eta1_2e2m8_LooseSR_channel","hist_Eta1_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_2e2m8_LooseSR_channel);
        TH1D *hist_Eta1_2e2m9_MediumSR_channel = new TH1D("hist_Eta1_2e2m9_MediumSR_channel","hist_Eta1_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_2e2m9_MediumSR_channel);
        TH1D *hist_Eta1_2e2m0_all_channel = new TH1D("hist_Eta1_2e2m0_all_channel","hist_Eta1_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_2e2m0_all_channel);

        TH1D *hist_Eta2_2e2m1_isol_channel = new TH1D("hist_Eta2_2e2m1_isol_channel","hist_Eta2_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_2e2m1_isol_channel);
        TH1D *hist_Eta2_2e2m2_elID_channel = new TH1D("hist_Eta2_2e2m2_elID_channel","hist_Eta2_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_2e2m2_elID_channel);
        TH1D *hist_Eta2_2e2m3_imp_channel = new TH1D("hist_Eta2_2e2m3_imp_channel","hist_Eta2_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_2e2m3_imp_channel);
        TH1D *hist_Eta2_2e2m4_QVeto_channel = new TH1D("hist_Eta2_2e2m4_QVeto_channel","hist_Eta2_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_2e2m4_QVeto_channel);
        TH1D *hist_Eta2_2e2m5_lowMassVeto_channel = new TH1D("hist_Eta2_2e2m5_lowMassVeto_channel","hist_Eta2_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_2e2m5_lowMassVeto_channel);
        TH1D *hist_Eta2_2e2m7_HWinHM__channel = new TH1D("hist_Eta2_2e2m7_HWinHM__channel","hist_Eta2_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_2e2m7_HWinHM__channel);
        TH1D *hist_Eta2_2e2m6_ZVeto_channel = new TH1D("hist_Eta2_2e2m6_ZVeto_channel","hist_Eta2_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_2e2m6_ZVeto_channel);
        TH1D *hist_Eta2_2e2m8_LooseSR_channel = new TH1D("hist_Eta2_2e2m8_LooseSR_channel","hist_Eta2_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_2e2m8_LooseSR_channel);
        TH1D *hist_Eta2_2e2m9_MediumSR_channel = new TH1D("hist_Eta2_2e2m9_MediumSR_channel","hist_Eta2_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_2e2m9_MediumSR_channel);
        TH1D *hist_Eta2_2e2m0_all_channel = new TH1D("hist_Eta2_2e2m0_all_channel","hist_Eta2_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_2e2m0_all_channel);

        TH1D *hist_Eta3_2e2m1_isol_channel = new TH1D("hist_Eta3_2e2m1_isol_channel","hist_Eta3_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_2e2m1_isol_channel);
        TH1D *hist_Eta3_2e2m2_elID_channel = new TH1D("hist_Eta3_2e2m2_elID_channel","hist_Eta3_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_2e2m2_elID_channel);
        TH1D *hist_Eta3_2e2m3_imp_channel = new TH1D("hist_Eta3_2e2m3_imp_channel","hist_Eta3_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_2e2m3_imp_channel);
        TH1D *hist_Eta3_2e2m4_QVeto_channel = new TH1D("hist_Eta3_2e2m4_QVeto_channel","hist_Eta3_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_2e2m4_QVeto_channel);
        TH1D *hist_Eta3_2e2m5_lowMassVeto_channel = new TH1D("hist_Eta3_2e2m5_lowMassVeto_channel","hist_Eta3_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_2e2m5_lowMassVeto_channel);
        TH1D *hist_Eta3_2e2m7_HWinHM__channel = new TH1D("hist_Eta3_2e2m7_HWinHM__channel","hist_Eta3_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_2e2m7_HWinHM__channel);
        TH1D *hist_Eta3_2e2m6_ZVeto_channel = new TH1D("hist_Eta3_2e2m6_ZVeto_channel","hist_Eta3_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_2e2m6_ZVeto_channel);
        TH1D *hist_Eta3_2e2m8_LooseSR_channel = new TH1D("hist_Eta3_2e2m8_LooseSR_channel","hist_Eta3_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_2e2m8_LooseSR_channel);
        TH1D *hist_Eta3_2e2m9_MediumSR_channel = new TH1D("hist_Eta3_2e2m9_MediumSR_channel","hist_Eta3_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_2e2m9_MediumSR_channel);
        TH1D *hist_Eta3_2e2m0_all_channel = new TH1D("hist_Eta3_2e2m0_all_channel","hist_Eta3_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_2e2m0_all_channel);

        TH1D *hist_Eta4_2e2m1_isol_channel = new TH1D("hist_Eta4_2e2m1_isol_channel","hist_Eta4_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_2e2m1_isol_channel);
        TH1D *hist_Eta4_2e2m2_elID_channel = new TH1D("hist_Eta4_2e2m2_elID_channel","hist_Eta4_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_2e2m2_elID_channel);
        TH1D *hist_Eta4_2e2m3_imp_channel = new TH1D("hist_Eta4_2e2m3_imp_channel","hist_Eta4_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_2e2m3_imp_channel);
        TH1D *hist_Eta4_2e2m4_QVeto_channel = new TH1D("hist_Eta4_2e2m4_QVeto_channel","hist_Eta4_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_2e2m4_QVeto_channel);
        TH1D *hist_Eta4_2e2m5_lowMassVeto_channel = new TH1D("hist_Eta4_2e2m5_lowMassVeto_channel","hist_Eta4_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_2e2m5_lowMassVeto_channel);
        TH1D *hist_Eta4_2e2m7_HWinHM__channel = new TH1D("hist_Eta4_2e2m7_HWinHM__channel","hist_Eta4_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_2e2m7_HWinHM__channel);
        TH1D *hist_Eta4_2e2m6_ZVeto_channel = new TH1D("hist_Eta4_2e2m6_ZVeto_channel","hist_Eta4_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_2e2m6_ZVeto_channel);
        TH1D *hist_Eta4_2e2m8_LooseSR_channel = new TH1D("hist_Eta4_2e2m8_LooseSR_channel","hist_Eta4_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_2e2m8_LooseSR_channel);
        TH1D *hist_Eta4_2e2m9_MediumSR_channel = new TH1D("hist_Eta4_2e2m9_MediumSR_channel","hist_Eta4_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_2e2m9_MediumSR_channel);
        TH1D *hist_Eta4_2e2m0_all_channel = new TH1D("hist_Eta4_2e2m0_all_channel","hist_Eta4_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_2e2m0_all_channel);

        TH1D *hist_Phi1_2e2m1_isol_channel = new TH1D("hist_Phi1_2e2m1_isol_channel","hist_Phi1_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_2e2m1_isol_channel);
        TH1D *hist_Phi1_2e2m2_elID_channel = new TH1D("hist_Phi1_2e2m2_elID_channel","hist_Phi1_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_2e2m2_elID_channel);
        TH1D *hist_Phi1_2e2m3_imp_channel = new TH1D("hist_Phi1_2e2m3_imp_channel","hist_Phi1_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_2e2m3_imp_channel);
        TH1D *hist_Phi1_2e2m4_QVeto_channel = new TH1D("hist_Phi1_2e2m4_QVeto_channel","hist_Phi1_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_2e2m4_QVeto_channel);
        TH1D *hist_Phi1_2e2m5_lowMassVeto_channel = new TH1D("hist_Phi1_2e2m5_lowMassVeto_channel","hist_Phi1_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_2e2m5_lowMassVeto_channel);
        TH1D *hist_Phi1_2e2m7_HWinHM__channel = new TH1D("hist_Phi1_2e2m7_HWinHM__channel","hist_Phi1_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_2e2m7_HWinHM__channel);
        TH1D *hist_Phi1_2e2m6_ZVeto_channel = new TH1D("hist_Phi1_2e2m6_ZVeto_channel","hist_Phi1_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_2e2m6_ZVeto_channel);
        TH1D *hist_Phi1_2e2m8_LooseSR_channel = new TH1D("hist_Phi1_2e2m8_LooseSR_channel","hist_Phi1_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_2e2m8_LooseSR_channel);
        TH1D *hist_Phi1_2e2m9_MediumSR_channel = new TH1D("hist_Phi1_2e2m9_MediumSR_channel","hist_Phi1_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_2e2m9_MediumSR_channel);
        TH1D *hist_Phi1_2e2m0_all_channel = new TH1D("hist_Phi1_2e2m0_all_channel","hist_Phi1_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_2e2m0_all_channel);

        TH1D *hist_Phi2_2e2m1_isol_channel = new TH1D("hist_Phi2_2e2m1_isol_channel","hist_Phi2_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_2e2m1_isol_channel);
        TH1D *hist_Phi2_2e2m2_elID_channel = new TH1D("hist_Phi2_2e2m2_elID_channel","hist_Phi2_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_2e2m2_elID_channel);
        TH1D *hist_Phi2_2e2m3_imp_channel = new TH1D("hist_Phi2_2e2m3_imp_channel","hist_Phi2_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_2e2m3_imp_channel);
        TH1D *hist_Phi2_2e2m4_QVeto_channel = new TH1D("hist_Phi2_2e2m4_QVeto_channel","hist_Phi2_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_2e2m4_QVeto_channel);
        TH1D *hist_Phi2_2e2m5_lowMassVeto_channel = new TH1D("hist_Phi2_2e2m5_lowMassVeto_channel","hist_Phi2_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_2e2m5_lowMassVeto_channel);
        TH1D *hist_Phi2_2e2m7_HWinHM__channel = new TH1D("hist_Phi2_2e2m7_HWinHM__channel","hist_Phi2_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_2e2m7_HWinHM__channel);
        TH1D *hist_Phi2_2e2m6_ZVeto_channel = new TH1D("hist_Phi2_2e2m6_ZVeto_channel","hist_Phi2_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_2e2m6_ZVeto_channel);
        TH1D *hist_Phi2_2e2m8_LooseSR_channel = new TH1D("hist_Phi2_2e2m8_LooseSR_channel","hist_Phi2_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_2e2m8_LooseSR_channel);
        TH1D *hist_Phi2_2e2m9_MediumSR_channel = new TH1D("hist_Phi2_2e2m9_MediumSR_channel","hist_Phi2_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_2e2m9_MediumSR_channel);
        TH1D *hist_Phi2_2e2m0_all_channel = new TH1D("hist_Phi2_2e2m0_all_channel","hist_Phi2_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_2e2m0_all_channel);

        TH1D *hist_Phi3_2e2m1_isol_channel = new TH1D("hist_Phi3_2e2m1_isol_channel","hist_Phi3_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_2e2m1_isol_channel);
        TH1D *hist_Phi3_2e2m2_elID_channel = new TH1D("hist_Phi3_2e2m2_elID_channel","hist_Phi3_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_2e2m2_elID_channel);
        TH1D *hist_Phi3_2e2m3_imp_channel = new TH1D("hist_Phi3_2e2m3_imp_channel","hist_Phi3_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_2e2m3_imp_channel);
        TH1D *hist_Phi3_2e2m4_QVeto_channel = new TH1D("hist_Phi3_2e2m4_QVeto_channel","hist_Phi3_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_2e2m4_QVeto_channel);
        TH1D *hist_Phi3_2e2m5_lowMassVeto_channel = new TH1D("hist_Phi3_2e2m5_lowMassVeto_channel","hist_Phi3_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_2e2m5_lowMassVeto_channel);
        TH1D *hist_Phi3_2e2m7_HWinHM__channel = new TH1D("hist_Phi3_2e2m7_HWinHM__channel","hist_Phi3_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_2e2m7_HWinHM__channel);
        TH1D *hist_Phi3_2e2m6_ZVeto_channel = new TH1D("hist_Phi3_2e2m6_ZVeto_channel","hist_Phi3_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_2e2m6_ZVeto_channel);
        TH1D *hist_Phi3_2e2m8_LooseSR_channel = new TH1D("hist_Phi3_2e2m8_LooseSR_channel","hist_Phi3_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_2e2m8_LooseSR_channel);
        TH1D *hist_Phi3_2e2m9_MediumSR_channel = new TH1D("hist_Phi3_2e2m9_MediumSR_channel","hist_Phi3_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_2e2m9_MediumSR_channel);
        TH1D *hist_Phi3_2e2m0_all_channel = new TH1D("hist_Phi3_2e2m0_all_channel","hist_Phi3_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_2e2m0_all_channel);

        TH1D *hist_Phi4_2e2m1_isol_channel = new TH1D("hist_Phi4_2e2m1_isol_channel","hist_Phi4_2e2m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_2e2m1_isol_channel);
        TH1D *hist_Phi4_2e2m2_elID_channel = new TH1D("hist_Phi4_2e2m2_elID_channel","hist_Phi4_2e2m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_2e2m2_elID_channel);
        TH1D *hist_Phi4_2e2m3_imp_channel = new TH1D("hist_Phi4_2e2m3_imp_channel","hist_Phi4_2e2m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_2e2m3_imp_channel);
        TH1D *hist_Phi4_2e2m4_QVeto_channel = new TH1D("hist_Phi4_2e2m4_QVeto_channel","hist_Phi4_2e2m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_2e2m4_QVeto_channel);
        TH1D *hist_Phi4_2e2m5_lowMassVeto_channel = new TH1D("hist_Phi4_2e2m5_lowMassVeto_channel","hist_Phi4_2e2m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_2e2m5_lowMassVeto_channel);
        TH1D *hist_Phi4_2e2m7_HWinHM__channel = new TH1D("hist_Phi4_2e2m7_HWinHM__channel","hist_Phi4_2e2m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_2e2m7_HWinHM__channel);
        TH1D *hist_Phi4_2e2m6_ZVeto_channel = new TH1D("hist_Phi4_2e2m6_ZVeto_channel","hist_Phi4_2e2m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_2e2m6_ZVeto_channel);
        TH1D *hist_Phi4_2e2m8_LooseSR_channel = new TH1D("hist_Phi4_2e2m8_LooseSR_channel","hist_Phi4_2e2m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_2e2m8_LooseSR_channel);
        TH1D *hist_Phi4_2e2m9_MediumSR_channel = new TH1D("hist_Phi4_2e2m9_MediumSR_channel","hist_Phi4_2e2m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_2e2m9_MediumSR_channel);
        TH1D *hist_Phi4_2e2m0_all_channel = new TH1D("hist_Phi4_2e2m0_all_channel","hist_Phi4_2e2m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_2e2m0_all_channel);


        TH1D *hist_m4l_4m1_isol_channel = new TH1D("hist_m4l_4m1_isol_channel","hist_m4l_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4m1_isol_channel);
        TH1D *hist_m4l_4m2_elID_channel = new TH1D("hist_m4l_4m2_elID_channel","hist_m4l_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4m2_elID_channel);
        TH1D *hist_m4l_4m3_imp_channel = new TH1D("hist_m4l_4m3_imp_channel","hist_m4l_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4m3_imp_channel);
        TH1D *hist_m4l_4m4_QVeto_channel = new TH1D("hist_m4l_4m4_QVeto_channel","hist_m4l_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4m4_QVeto_channel);
        TH1D *hist_m4l_4m5_lowMassVeto_channel = new TH1D("hist_m4l_4m5_lowMassVeto_channel","hist_m4l_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4m5_lowMassVeto_channel);
        TH1D *hist_m4l_4m7_HWinHM__channel = new TH1D("hist_m4l_4m7_HWinHM__channel","hist_m4l_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4m7_HWinHM__channel);
        TH1D *hist_m4l_4m6_ZVeto_channel = new TH1D("hist_m4l_4m6_ZVeto_channel","hist_m4l_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4m6_ZVeto_channel);
        TH1D *hist_m4l_4m8_LooseSR_channel = new TH1D("hist_m4l_4m8_LooseSR_channel","hist_m4l_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4m8_LooseSR_channel);
        TH1D *hist_m4l_4m9_MediumSR_channel = new TH1D("hist_m4l_4m9_MediumSR_channel","hist_m4l_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4m9_MediumSR_channel);
        TH1D *hist_m4l_4m0_all_channel = new TH1D("hist_m4l_4m0_all_channel","hist_m4l_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m4l_4m0_all_channel);

        TH1D *hist_m12_4m1_isol_channel = new TH1D("hist_m12_4m1_isol_channel","hist_m12_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4m1_isol_channel);
        TH1D *hist_m12_4m2_elID_channel = new TH1D("hist_m12_4m2_elID_channel","hist_m12_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4m2_elID_channel);
        TH1D *hist_m12_4m3_imp_channel = new TH1D("hist_m12_4m3_imp_channel","hist_m12_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4m3_imp_channel);
        TH1D *hist_m12_4m4_QVeto_channel = new TH1D("hist_m12_4m4_QVeto_channel","hist_m12_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4m4_QVeto_channel);
        TH1D *hist_m12_4m5_lowMassVeto_channel = new TH1D("hist_m12_4m5_lowMassVeto_channel","hist_m12_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4m5_lowMassVeto_channel);
        TH1D *hist_m12_4m7_HWinHM__channel = new TH1D("hist_m12_4m7_HWinHM__channel","hist_m12_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4m7_HWinHM__channel);
        TH1D *hist_m12_4m6_ZVeto_channel = new TH1D("hist_m12_4m6_ZVeto_channel","hist_m12_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4m6_ZVeto_channel);
        TH1D *hist_m12_4m8_LooseSR_channel = new TH1D("hist_m12_4m8_LooseSR_channel","hist_m12_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4m8_LooseSR_channel);
        TH1D *hist_m12_4m9_MediumSR_channel = new TH1D("hist_m12_4m9_MediumSR_channel","hist_m12_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4m9_MediumSR_channel);
        TH1D *hist_m12_4m0_all_channel = new TH1D("hist_m12_4m0_all_channel","hist_m12_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m12_4m0_all_channel);

        TH1D *hist_m34_4m1_isol_channel = new TH1D("hist_m34_4m1_isol_channel","hist_m34_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4m1_isol_channel);
        TH1D *hist_m34_4m2_elID_channel = new TH1D("hist_m34_4m2_elID_channel","hist_m34_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4m2_elID_channel);
        TH1D *hist_m34_4m3_imp_channel = new TH1D("hist_m34_4m3_imp_channel","hist_m34_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4m3_imp_channel);
        TH1D *hist_m34_4m4_QVeto_channel = new TH1D("hist_m34_4m4_QVeto_channel","hist_m34_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4m4_QVeto_channel);
        TH1D *hist_m34_4m5_lowMassVeto_channel = new TH1D("hist_m34_4m5_lowMassVeto_channel","hist_m34_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4m5_lowMassVeto_channel);
        TH1D *hist_m34_4m7_HWinHM__channel = new TH1D("hist_m34_4m7_HWinHM__channel","hist_m34_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4m7_HWinHM__channel);
        TH1D *hist_m34_4m6_ZVeto_channel = new TH1D("hist_m34_4m6_ZVeto_channel","hist_m34_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4m6_ZVeto_channel);
        TH1D *hist_m34_4m8_LooseSR_channel = new TH1D("hist_m34_4m8_LooseSR_channel","hist_m34_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4m8_LooseSR_channel);
        TH1D *hist_m34_4m9_MediumSR_channel = new TH1D("hist_m34_4m9_MediumSR_channel","hist_m34_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4m9_MediumSR_channel);
        TH1D *hist_m34_4m0_all_channel = new TH1D("hist_m34_4m0_all_channel","hist_m34_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m34_4m0_all_channel);

        TH1D *hist_m32_4m1_isol_channel = new TH1D("hist_m32_4m1_isol_channel","hist_m32_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4m1_isol_channel);
        TH1D *hist_m32_4m2_elID_channel = new TH1D("hist_m32_4m2_elID_channel","hist_m32_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4m2_elID_channel);
        TH1D *hist_m32_4m3_imp_channel = new TH1D("hist_m32_4m3_imp_channel","hist_m32_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4m3_imp_channel);
        TH1D *hist_m32_4m4_QVeto_channel = new TH1D("hist_m32_4m4_QVeto_channel","hist_m32_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4m4_QVeto_channel);
        TH1D *hist_m32_4m5_lowMassVeto_channel = new TH1D("hist_m32_4m5_lowMassVeto_channel","hist_m32_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4m5_lowMassVeto_channel);
        TH1D *hist_m32_4m7_HWinHM__channel = new TH1D("hist_m32_4m7_HWinHM__channel","hist_m32_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4m7_HWinHM__channel);
        TH1D *hist_m32_4m6_ZVeto_channel = new TH1D("hist_m32_4m6_ZVeto_channel","hist_m32_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4m6_ZVeto_channel);
        TH1D *hist_m32_4m8_LooseSR_channel = new TH1D("hist_m32_4m8_LooseSR_channel","hist_m32_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4m8_LooseSR_channel);
        TH1D *hist_m32_4m9_MediumSR_channel = new TH1D("hist_m32_4m9_MediumSR_channel","hist_m32_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4m9_MediumSR_channel);
        TH1D *hist_m32_4m0_all_channel = new TH1D("hist_m32_4m0_all_channel","hist_m32_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m32_4m0_all_channel);

        TH1D *hist_m14_4m1_isol_channel = new TH1D("hist_m14_4m1_isol_channel","hist_m14_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4m1_isol_channel);
        TH1D *hist_m14_4m2_elID_channel = new TH1D("hist_m14_4m2_elID_channel","hist_m14_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4m2_elID_channel);
        TH1D *hist_m14_4m3_imp_channel = new TH1D("hist_m14_4m3_imp_channel","hist_m14_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4m3_imp_channel);
        TH1D *hist_m14_4m4_QVeto_channel = new TH1D("hist_m14_4m4_QVeto_channel","hist_m14_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4m4_QVeto_channel);
        TH1D *hist_m14_4m5_lowMassVeto_channel = new TH1D("hist_m14_4m5_lowMassVeto_channel","hist_m14_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4m5_lowMassVeto_channel);
        TH1D *hist_m14_4m7_HWinHM__channel = new TH1D("hist_m14_4m7_HWinHM__channel","hist_m14_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4m7_HWinHM__channel);
        TH1D *hist_m14_4m6_ZVeto_channel = new TH1D("hist_m14_4m6_ZVeto_channel","hist_m14_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4m6_ZVeto_channel);
        TH1D *hist_m14_4m8_LooseSR_channel = new TH1D("hist_m14_4m8_LooseSR_channel","hist_m14_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4m8_LooseSR_channel);
        TH1D *hist_m14_4m9_MediumSR_channel = new TH1D("hist_m14_4m9_MediumSR_channel","hist_m14_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4m9_MediumSR_channel);
        TH1D *hist_m14_4m0_all_channel = new TH1D("hist_m14_4m0_all_channel","hist_m14_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_m14_4m0_all_channel);

        TH1D *hist_mll_4m1_isol_channel = new TH1D("hist_mll_4m1_isol_channel","hist_mll_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4m1_isol_channel);
        TH1D *hist_mll_4m2_elID_channel = new TH1D("hist_mll_4m2_elID_channel","hist_mll_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4m2_elID_channel);
        TH1D *hist_mll_4m3_imp_channel = new TH1D("hist_mll_4m3_imp_channel","hist_mll_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4m3_imp_channel);
        TH1D *hist_mll_4m4_QVeto_channel = new TH1D("hist_mll_4m4_QVeto_channel","hist_mll_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4m4_QVeto_channel);
        TH1D *hist_mll_4m5_lowMassVeto_channel = new TH1D("hist_mll_4m5_lowMassVeto_channel","hist_mll_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4m5_lowMassVeto_channel);
        TH1D *hist_mll_4m7_HWinHM__channel = new TH1D("hist_mll_4m7_HWinHM__channel","hist_mll_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4m7_HWinHM__channel);
        TH1D *hist_mll_4m6_ZVeto_channel = new TH1D("hist_mll_4m6_ZVeto_channel","hist_mll_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4m6_ZVeto_channel);
        TH1D *hist_mll_4m8_LooseSR_channel = new TH1D("hist_mll_4m8_LooseSR_channel","hist_mll_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4m8_LooseSR_channel);
        TH1D *hist_mll_4m9_MediumSR_channel = new TH1D("hist_mll_4m9_MediumSR_channel","hist_mll_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4m9_MediumSR_channel);
        TH1D *hist_mll_4m0_all_channel = new TH1D("hist_mll_4m0_all_channel","hist_mll_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_4m0_all_channel);

        TH1D *hist_mll_atl_4m1_isol_channel = new TH1D("hist_mll_atl_4m1_isol_channel","hist_mll_atl_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4m1_isol_channel);
        TH1D *hist_mll_atl_4m2_elID_channel = new TH1D("hist_mll_atl_4m2_elID_channel","hist_mll_atl_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4m2_elID_channel);
        TH1D *hist_mll_atl_4m3_imp_channel = new TH1D("hist_mll_atl_4m3_imp_channel","hist_mll_atl_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4m3_imp_channel);
        TH1D *hist_mll_atl_4m4_QVeto_channel = new TH1D("hist_mll_atl_4m4_QVeto_channel","hist_mll_atl_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4m4_QVeto_channel);
        TH1D *hist_mll_atl_4m5_lowMassVeto_channel = new TH1D("hist_mll_atl_4m5_lowMassVeto_channel","hist_mll_atl_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4m5_lowMassVeto_channel);
        TH1D *hist_mll_atl_4m7_HWinHM__channel = new TH1D("hist_mll_atl_4m7_HWinHM__channel","hist_mll_atl_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4m7_HWinHM__channel);
        TH1D *hist_mll_atl_4m6_ZVeto_channel = new TH1D("hist_mll_atl_4m6_ZVeto_channel","hist_mll_atl_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4m6_ZVeto_channel);
        TH1D *hist_mll_atl_4m8_LooseSR_channel = new TH1D("hist_mll_atl_4m8_LooseSR_channel","hist_mll_atl_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4m8_LooseSR_channel);
        TH1D *hist_mll_atl_4m9_MediumSR_channel = new TH1D("hist_mll_atl_4m9_MediumSR_channel","hist_mll_atl_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4m9_MediumSR_channel);
        TH1D *hist_mll_atl_4m0_all_channel = new TH1D("hist_mll_atl_4m0_all_channel","hist_mll_atl_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_mll_atl_4m0_all_channel);

        TH1D *hist_Pt1_4m1_isol_channel = new TH1D("hist_Pt1_4m1_isol_channel","hist_Pt1_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4m1_isol_channel);
        TH1D *hist_Pt1_4m2_elID_channel = new TH1D("hist_Pt1_4m2_elID_channel","hist_Pt1_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4m2_elID_channel);
        TH1D *hist_Pt1_4m3_imp_channel = new TH1D("hist_Pt1_4m3_imp_channel","hist_Pt1_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4m3_imp_channel);
        TH1D *hist_Pt1_4m4_QVeto_channel = new TH1D("hist_Pt1_4m4_QVeto_channel","hist_Pt1_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4m4_QVeto_channel);
        TH1D *hist_Pt1_4m5_lowMassVeto_channel = new TH1D("hist_Pt1_4m5_lowMassVeto_channel","hist_Pt1_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4m5_lowMassVeto_channel);
        TH1D *hist_Pt1_4m7_HWinHM__channel = new TH1D("hist_Pt1_4m7_HWinHM__channel","hist_Pt1_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4m7_HWinHM__channel);
        TH1D *hist_Pt1_4m6_ZVeto_channel = new TH1D("hist_Pt1_4m6_ZVeto_channel","hist_Pt1_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4m6_ZVeto_channel);
        TH1D *hist_Pt1_4m8_LooseSR_channel = new TH1D("hist_Pt1_4m8_LooseSR_channel","hist_Pt1_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4m8_LooseSR_channel);
        TH1D *hist_Pt1_4m9_MediumSR_channel = new TH1D("hist_Pt1_4m9_MediumSR_channel","hist_Pt1_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4m9_MediumSR_channel);
        TH1D *hist_Pt1_4m0_all_channel = new TH1D("hist_Pt1_4m0_all_channel","hist_Pt1_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt1_4m0_all_channel);

        TH1D *hist_Pt2_4m1_isol_channel = new TH1D("hist_Pt2_4m1_isol_channel","hist_Pt2_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4m1_isol_channel);
        TH1D *hist_Pt2_4m2_elID_channel = new TH1D("hist_Pt2_4m2_elID_channel","hist_Pt2_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4m2_elID_channel);
        TH1D *hist_Pt2_4m3_imp_channel = new TH1D("hist_Pt2_4m3_imp_channel","hist_Pt2_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4m3_imp_channel);
        TH1D *hist_Pt2_4m4_QVeto_channel = new TH1D("hist_Pt2_4m4_QVeto_channel","hist_Pt2_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4m4_QVeto_channel);
        TH1D *hist_Pt2_4m5_lowMassVeto_channel = new TH1D("hist_Pt2_4m5_lowMassVeto_channel","hist_Pt2_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4m5_lowMassVeto_channel);
        TH1D *hist_Pt2_4m7_HWinHM__channel = new TH1D("hist_Pt2_4m7_HWinHM__channel","hist_Pt2_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4m7_HWinHM__channel);
        TH1D *hist_Pt2_4m6_ZVeto_channel = new TH1D("hist_Pt2_4m6_ZVeto_channel","hist_Pt2_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4m6_ZVeto_channel);
        TH1D *hist_Pt2_4m8_LooseSR_channel = new TH1D("hist_Pt2_4m8_LooseSR_channel","hist_Pt2_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4m8_LooseSR_channel);
        TH1D *hist_Pt2_4m9_MediumSR_channel = new TH1D("hist_Pt2_4m9_MediumSR_channel","hist_Pt2_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4m9_MediumSR_channel);
        TH1D *hist_Pt2_4m0_all_channel = new TH1D("hist_Pt2_4m0_all_channel","hist_Pt2_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt2_4m0_all_channel);

        TH1D *hist_Pt3_4m1_isol_channel = new TH1D("hist_Pt3_4m1_isol_channel","hist_Pt3_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4m1_isol_channel);
        TH1D *hist_Pt3_4m2_elID_channel = new TH1D("hist_Pt3_4m2_elID_channel","hist_Pt3_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4m2_elID_channel);
        TH1D *hist_Pt3_4m3_imp_channel = new TH1D("hist_Pt3_4m3_imp_channel","hist_Pt3_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4m3_imp_channel);
        TH1D *hist_Pt3_4m4_QVeto_channel = new TH1D("hist_Pt3_4m4_QVeto_channel","hist_Pt3_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4m4_QVeto_channel);
        TH1D *hist_Pt3_4m5_lowMassVeto_channel = new TH1D("hist_Pt3_4m5_lowMassVeto_channel","hist_Pt3_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4m5_lowMassVeto_channel);
        TH1D *hist_Pt3_4m7_HWinHM__channel = new TH1D("hist_Pt3_4m7_HWinHM__channel","hist_Pt3_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4m7_HWinHM__channel);
        TH1D *hist_Pt3_4m6_ZVeto_channel = new TH1D("hist_Pt3_4m6_ZVeto_channel","hist_Pt3_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4m6_ZVeto_channel);
        TH1D *hist_Pt3_4m8_LooseSR_channel = new TH1D("hist_Pt3_4m8_LooseSR_channel","hist_Pt3_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4m8_LooseSR_channel);
        TH1D *hist_Pt3_4m9_MediumSR_channel = new TH1D("hist_Pt3_4m9_MediumSR_channel","hist_Pt3_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4m9_MediumSR_channel);
        TH1D *hist_Pt3_4m0_all_channel = new TH1D("hist_Pt3_4m0_all_channel","hist_Pt3_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt3_4m0_all_channel);

        TH1D *hist_Pt4_4m1_isol_channel = new TH1D("hist_Pt4_4m1_isol_channel","hist_Pt4_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4m1_isol_channel);
        TH1D *hist_Pt4_4m2_elID_channel = new TH1D("hist_Pt4_4m2_elID_channel","hist_Pt4_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4m2_elID_channel);
        TH1D *hist_Pt4_4m3_imp_channel = new TH1D("hist_Pt4_4m3_imp_channel","hist_Pt4_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4m3_imp_channel);
        TH1D *hist_Pt4_4m4_QVeto_channel = new TH1D("hist_Pt4_4m4_QVeto_channel","hist_Pt4_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4m4_QVeto_channel);
        TH1D *hist_Pt4_4m5_lowMassVeto_channel = new TH1D("hist_Pt4_4m5_lowMassVeto_channel","hist_Pt4_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4m5_lowMassVeto_channel);
        TH1D *hist_Pt4_4m7_HWinHM__channel = new TH1D("hist_Pt4_4m7_HWinHM__channel","hist_Pt4_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4m7_HWinHM__channel);
        TH1D *hist_Pt4_4m6_ZVeto_channel = new TH1D("hist_Pt4_4m6_ZVeto_channel","hist_Pt4_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4m6_ZVeto_channel);
        TH1D *hist_Pt4_4m8_LooseSR_channel = new TH1D("hist_Pt4_4m8_LooseSR_channel","hist_Pt4_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4m8_LooseSR_channel);
        TH1D *hist_Pt4_4m9_MediumSR_channel = new TH1D("hist_Pt4_4m9_MediumSR_channel","hist_Pt4_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4m9_MediumSR_channel);
        TH1D *hist_Pt4_4m0_all_channel = new TH1D("hist_Pt4_4m0_all_channel","hist_Pt4_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Pt4_4m0_all_channel);

        TH1D *hist_Eta1_4m1_isol_channel = new TH1D("hist_Eta1_4m1_isol_channel","hist_Eta1_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4m1_isol_channel);
        TH1D *hist_Eta1_4m2_elID_channel = new TH1D("hist_Eta1_4m2_elID_channel","hist_Eta1_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4m2_elID_channel);
        TH1D *hist_Eta1_4m3_imp_channel = new TH1D("hist_Eta1_4m3_imp_channel","hist_Eta1_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4m3_imp_channel);
        TH1D *hist_Eta1_4m4_QVeto_channel = new TH1D("hist_Eta1_4m4_QVeto_channel","hist_Eta1_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4m4_QVeto_channel);
        TH1D *hist_Eta1_4m5_lowMassVeto_channel = new TH1D("hist_Eta1_4m5_lowMassVeto_channel","hist_Eta1_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4m5_lowMassVeto_channel);
        TH1D *hist_Eta1_4m7_HWinHM__channel = new TH1D("hist_Eta1_4m7_HWinHM__channel","hist_Eta1_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4m7_HWinHM__channel);
        TH1D *hist_Eta1_4m6_ZVeto_channel = new TH1D("hist_Eta1_4m6_ZVeto_channel","hist_Eta1_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4m6_ZVeto_channel);
        TH1D *hist_Eta1_4m8_LooseSR_channel = new TH1D("hist_Eta1_4m8_LooseSR_channel","hist_Eta1_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4m8_LooseSR_channel);
        TH1D *hist_Eta1_4m9_MediumSR_channel = new TH1D("hist_Eta1_4m9_MediumSR_channel","hist_Eta1_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4m9_MediumSR_channel);
        TH1D *hist_Eta1_4m0_all_channel = new TH1D("hist_Eta1_4m0_all_channel","hist_Eta1_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta1_4m0_all_channel);

        TH1D *hist_Eta2_4m1_isol_channel = new TH1D("hist_Eta2_4m1_isol_channel","hist_Eta2_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4m1_isol_channel);
        TH1D *hist_Eta2_4m2_elID_channel = new TH1D("hist_Eta2_4m2_elID_channel","hist_Eta2_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4m2_elID_channel);
        TH1D *hist_Eta2_4m3_imp_channel = new TH1D("hist_Eta2_4m3_imp_channel","hist_Eta2_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4m3_imp_channel);
        TH1D *hist_Eta2_4m4_QVeto_channel = new TH1D("hist_Eta2_4m4_QVeto_channel","hist_Eta2_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4m4_QVeto_channel);
        TH1D *hist_Eta2_4m5_lowMassVeto_channel = new TH1D("hist_Eta2_4m5_lowMassVeto_channel","hist_Eta2_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4m5_lowMassVeto_channel);
        TH1D *hist_Eta2_4m7_HWinHM__channel = new TH1D("hist_Eta2_4m7_HWinHM__channel","hist_Eta2_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4m7_HWinHM__channel);
        TH1D *hist_Eta2_4m6_ZVeto_channel = new TH1D("hist_Eta2_4m6_ZVeto_channel","hist_Eta2_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4m6_ZVeto_channel);
        TH1D *hist_Eta2_4m8_LooseSR_channel = new TH1D("hist_Eta2_4m8_LooseSR_channel","hist_Eta2_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4m8_LooseSR_channel);
        TH1D *hist_Eta2_4m9_MediumSR_channel = new TH1D("hist_Eta2_4m9_MediumSR_channel","hist_Eta2_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4m9_MediumSR_channel);
        TH1D *hist_Eta2_4m0_all_channel = new TH1D("hist_Eta2_4m0_all_channel","hist_Eta2_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta2_4m0_all_channel);

        TH1D *hist_Eta3_4m1_isol_channel = new TH1D("hist_Eta3_4m1_isol_channel","hist_Eta3_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4m1_isol_channel);
        TH1D *hist_Eta3_4m2_elID_channel = new TH1D("hist_Eta3_4m2_elID_channel","hist_Eta3_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4m2_elID_channel);
        TH1D *hist_Eta3_4m3_imp_channel = new TH1D("hist_Eta3_4m3_imp_channel","hist_Eta3_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4m3_imp_channel);
        TH1D *hist_Eta3_4m4_QVeto_channel = new TH1D("hist_Eta3_4m4_QVeto_channel","hist_Eta3_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4m4_QVeto_channel);
        TH1D *hist_Eta3_4m5_lowMassVeto_channel = new TH1D("hist_Eta3_4m5_lowMassVeto_channel","hist_Eta3_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4m5_lowMassVeto_channel);
        TH1D *hist_Eta3_4m7_HWinHM__channel = new TH1D("hist_Eta3_4m7_HWinHM__channel","hist_Eta3_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4m7_HWinHM__channel);
        TH1D *hist_Eta3_4m6_ZVeto_channel = new TH1D("hist_Eta3_4m6_ZVeto_channel","hist_Eta3_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4m6_ZVeto_channel);
        TH1D *hist_Eta3_4m8_LooseSR_channel = new TH1D("hist_Eta3_4m8_LooseSR_channel","hist_Eta3_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4m8_LooseSR_channel);
        TH1D *hist_Eta3_4m9_MediumSR_channel = new TH1D("hist_Eta3_4m9_MediumSR_channel","hist_Eta3_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4m9_MediumSR_channel);
        TH1D *hist_Eta3_4m0_all_channel = new TH1D("hist_Eta3_4m0_all_channel","hist_Eta3_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta3_4m0_all_channel);

        TH1D *hist_Eta4_4m1_isol_channel = new TH1D("hist_Eta4_4m1_isol_channel","hist_Eta4_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4m1_isol_channel);
        TH1D *hist_Eta4_4m2_elID_channel = new TH1D("hist_Eta4_4m2_elID_channel","hist_Eta4_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4m2_elID_channel);
        TH1D *hist_Eta4_4m3_imp_channel = new TH1D("hist_Eta4_4m3_imp_channel","hist_Eta4_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4m3_imp_channel);
        TH1D *hist_Eta4_4m4_QVeto_channel = new TH1D("hist_Eta4_4m4_QVeto_channel","hist_Eta4_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4m4_QVeto_channel);
        TH1D *hist_Eta4_4m5_lowMassVeto_channel = new TH1D("hist_Eta4_4m5_lowMassVeto_channel","hist_Eta4_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4m5_lowMassVeto_channel);
        TH1D *hist_Eta4_4m7_HWinHM__channel = new TH1D("hist_Eta4_4m7_HWinHM__channel","hist_Eta4_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4m7_HWinHM__channel);
        TH1D *hist_Eta4_4m6_ZVeto_channel = new TH1D("hist_Eta4_4m6_ZVeto_channel","hist_Eta4_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4m6_ZVeto_channel);
        TH1D *hist_Eta4_4m8_LooseSR_channel = new TH1D("hist_Eta4_4m8_LooseSR_channel","hist_Eta4_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4m8_LooseSR_channel);
        TH1D *hist_Eta4_4m9_MediumSR_channel = new TH1D("hist_Eta4_4m9_MediumSR_channel","hist_Eta4_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4m9_MediumSR_channel);
        TH1D *hist_Eta4_4m0_all_channel = new TH1D("hist_Eta4_4m0_all_channel","hist_Eta4_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Eta4_4m0_all_channel);

        TH1D *hist_Phi1_4m1_isol_channel = new TH1D("hist_Phi1_4m1_isol_channel","hist_Phi1_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_4m1_isol_channel);
        TH1D *hist_Phi1_4m2_elID_channel = new TH1D("hist_Phi1_4m2_elID_channel","hist_Phi1_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_4m2_elID_channel);
        TH1D *hist_Phi1_4m3_imp_channel = new TH1D("hist_Phi1_4m3_imp_channel","hist_Phi1_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_4m3_imp_channel);
        TH1D *hist_Phi1_4m4_QVeto_channel = new TH1D("hist_Phi1_4m4_QVeto_channel","hist_Phi1_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_4m4_QVeto_channel);
        TH1D *hist_Phi1_4m5_lowMassVeto_channel = new TH1D("hist_Phi1_4m5_lowMassVeto_channel","hist_Phi1_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_4m5_lowMassVeto_channel);
        TH1D *hist_Phi1_4m7_HWinHM__channel = new TH1D("hist_Phi1_4m7_HWinHM__channel","hist_Phi1_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_4m7_HWinHM__channel);
        TH1D *hist_Phi1_4m6_ZVeto_channel = new TH1D("hist_Phi1_4m6_ZVeto_channel","hist_Phi1_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_4m6_ZVeto_channel);
        TH1D *hist_Phi1_4m8_LooseSR_channel = new TH1D("hist_Phi1_4m8_LooseSR_channel","hist_Phi1_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_4m8_LooseSR_channel);
        TH1D *hist_Phi1_4m9_MediumSR_channel = new TH1D("hist_Phi1_4m9_MediumSR_channel","hist_Phi1_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_4m9_MediumSR_channel);
        TH1D *hist_Phi1_4m0_all_channel = new TH1D("hist_Phi1_4m0_all_channel","hist_Phi1_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi1_4m0_all_channel);

        TH1D *hist_Phi2_4m1_isol_channel = new TH1D("hist_Phi2_4m1_isol_channel","hist_Phi2_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_4m1_isol_channel);
        TH1D *hist_Phi2_4m2_elID_channel = new TH1D("hist_Phi2_4m2_elID_channel","hist_Phi2_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_4m2_elID_channel);
        TH1D *hist_Phi2_4m3_imp_channel = new TH1D("hist_Phi2_4m3_imp_channel","hist_Phi2_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_4m3_imp_channel);
        TH1D *hist_Phi2_4m4_QVeto_channel = new TH1D("hist_Phi2_4m4_QVeto_channel","hist_Phi2_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_4m4_QVeto_channel);
        TH1D *hist_Phi2_4m5_lowMassVeto_channel = new TH1D("hist_Phi2_4m5_lowMassVeto_channel","hist_Phi2_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_4m5_lowMassVeto_channel);
        TH1D *hist_Phi2_4m7_HWinHM__channel = new TH1D("hist_Phi2_4m7_HWinHM__channel","hist_Phi2_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_4m7_HWinHM__channel);
        TH1D *hist_Phi2_4m6_ZVeto_channel = new TH1D("hist_Phi2_4m6_ZVeto_channel","hist_Phi2_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_4m6_ZVeto_channel);
        TH1D *hist_Phi2_4m8_LooseSR_channel = new TH1D("hist_Phi2_4m8_LooseSR_channel","hist_Phi2_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_4m8_LooseSR_channel);
        TH1D *hist_Phi2_4m9_MediumSR_channel = new TH1D("hist_Phi2_4m9_MediumSR_channel","hist_Phi2_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_4m9_MediumSR_channel);
        TH1D *hist_Phi2_4m0_all_channel = new TH1D("hist_Phi2_4m0_all_channel","hist_Phi2_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi2_4m0_all_channel);

        TH1D *hist_Phi3_4m1_isol_channel = new TH1D("hist_Phi3_4m1_isol_channel","hist_Phi3_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_4m1_isol_channel);
        TH1D *hist_Phi3_4m2_elID_channel = new TH1D("hist_Phi3_4m2_elID_channel","hist_Phi3_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_4m2_elID_channel);
        TH1D *hist_Phi3_4m3_imp_channel = new TH1D("hist_Phi3_4m3_imp_channel","hist_Phi3_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_4m3_imp_channel);
        TH1D *hist_Phi3_4m4_QVeto_channel = new TH1D("hist_Phi3_4m4_QVeto_channel","hist_Phi3_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_4m4_QVeto_channel);
        TH1D *hist_Phi3_4m5_lowMassVeto_channel = new TH1D("hist_Phi3_4m5_lowMassVeto_channel","hist_Phi3_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_4m5_lowMassVeto_channel);
        TH1D *hist_Phi3_4m7_HWinHM__channel = new TH1D("hist_Phi3_4m7_HWinHM__channel","hist_Phi3_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_4m7_HWinHM__channel);
        TH1D *hist_Phi3_4m6_ZVeto_channel = new TH1D("hist_Phi3_4m6_ZVeto_channel","hist_Phi3_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_4m6_ZVeto_channel);
        TH1D *hist_Phi3_4m8_LooseSR_channel = new TH1D("hist_Phi3_4m8_LooseSR_channel","hist_Phi3_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_4m8_LooseSR_channel);
        TH1D *hist_Phi3_4m9_MediumSR_channel = new TH1D("hist_Phi3_4m9_MediumSR_channel","hist_Phi3_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_4m9_MediumSR_channel);
        TH1D *hist_Phi3_4m0_all_channel = new TH1D("hist_Phi3_4m0_all_channel","hist_Phi3_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi3_4m0_all_channel);

        TH1D *hist_Phi4_4m1_isol_channel = new TH1D("hist_Phi4_4m1_isol_channel","hist_Phi4_4m1_isol_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_4m1_isol_channel);
        TH1D *hist_Phi4_4m2_elID_channel = new TH1D("hist_Phi4_4m2_elID_channel","hist_Phi4_4m2_elID_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_4m2_elID_channel);
        TH1D *hist_Phi4_4m3_imp_channel = new TH1D("hist_Phi4_4m3_imp_channel","hist_Phi4_4m3_imp_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_4m3_imp_channel);
        TH1D *hist_Phi4_4m4_QVeto_channel = new TH1D("hist_Phi4_4m4_QVeto_channel","hist_Phi4_4m4_QVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_4m4_QVeto_channel);
        TH1D *hist_Phi4_4m5_lowMassVeto_channel = new TH1D("hist_Phi4_4m5_lowMassVeto_channel","hist_Phi4_4m5_lowMassVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_4m5_lowMassVeto_channel);
        TH1D *hist_Phi4_4m7_HWinHM__channel = new TH1D("hist_Phi4_4m7_HWinHM__channel","hist_Phi4_4m7_HWinHM__channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_4m7_HWinHM__channel);
        TH1D *hist_Phi4_4m6_ZVeto_channel = new TH1D("hist_Phi4_4m6_ZVeto_channel","hist_Phi4_4m6_ZVeto_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_4m6_ZVeto_channel);
        TH1D *hist_Phi4_4m8_LooseSR_channel = new TH1D("hist_Phi4_4m8_LooseSR_channel","hist_Phi4_4m8_LooseSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_4m8_LooseSR_channel);
        TH1D *hist_Phi4_4m9_MediumSR_channel = new TH1D("hist_Phi4_4m9_MediumSR_channel","hist_Phi4_4m9_MediumSR_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_4m9_MediumSR_channel);
        TH1D *hist_Phi4_4m0_all_channel = new TH1D("hist_Phi4_4m0_all_channel","hist_Phi4_4m0_all_channel",100,0,50);
        MyHistArray->AddLast(hist_Phi4_4m0_all_channel);
















//
//    TH1D *hist_Pt1_2e2m_channel = new TH1D("hist_Pt1_2e2m_channel","hist_Pt1_2e2m_channel",10,160,180);
//    MyHistArray->AddLast(hist_Pt1_2e2m_channel);
//    TH1D *hist_Pt1_4m_channel = new TH1D("hist_m4l_4m_channel","hist_m4l_4m_channel",10,160,180);
//    MyHistArray->AddLast(hist_m4l_4m_channel);
//
//    TH1D *hist_mll_4e_channel = new TH1D("hist_mll_4e_channel","hist_mll_4e_channel",100,0,50);
//    MyHistArray->AddLast(hist_mll_4e_channel);
//    TH1D *hist_mll_2e2m_channel = new TH1D("hist_mll_2e2m_channel","hist_mll_2e2m_channel",100,0,50);
//    MyHistArray->AddLast(hist_mll_2e2m_channel);
//    TH1D *hist_mll_4m_channel = new TH1D("hist_mll_4m_channel","hist_mll_4m_channel",100,0,50);
//    MyHistArray->AddLast(hist_mll_4m_channel);


        cout << "Reading out event numbers" << endl;
        Int_t test_MC_channel_number = 0;
        Long64_t nentries = fChain->GetEntriesFast();
        //cout << nentries <<endl,1;
        Long64_t nbytes = 0, nb = 0;
        for (Long64_t jentry = 0; jentry < nentries; jentry++) {
            Long_t ientry = LoadTree(jentry);
            if (ientry < 0) break;
            nb = fChain->GetEntry(jentry);
            nbytes += nb;

            Double_t GeV = 0.001;

            Double_t m12 = GeV * lep12->M();
            Double_t m34 = GeV * lep34->M();
            Double_t m32 = GeV * lep32->M();
            Double_t m14 = GeV * lep14->M();
            Double_t m4l = GeV * lep1234->M();
            Double_t mll = 0.5 * (m12 + m34);
            Double_t mll_alt = 0.5 * (m32 + m14);

            Double_t Pt1 = GeV * lep1->Pt();
            Double_t Pt2 = GeV * lep2->Pt();
            Double_t Pt3 = GeV * lep3->Pt();
            Double_t Pt4 = GeV * lep4->Pt();

            Double_t Eta1 = lep1->Eta();
            Double_t Eta2 = lep2->Eta();
            Double_t Eta3 = lep3->Eta();
            Double_t Eta4 = lep4->Eta();

            Double_t Phi1 = lep1->Phi();
            Double_t Phi2 = lep2->Phi();
            Double_t Phi3 = lep3->Phi();
            Double_t Phi4 = lep4->Phi();

            Double_t weight = EvtWeight;

            Bool_t impID_4e = llll_pdgIdSum == 44 && max_el_d0Sig < 5;
            Bool_t impID_2e2m = llll_pdgIdSum == 48 && max_el_d0Sig < 5 && max_mu_d0Sig < 3;
            Bool_t impID_4m = llll_pdgIdSum == 52 && max_mu_d0Sig < 3;

            bool exists = std::find(std::begin(channelArray),std::end(channelArray), MC_channel_number) != std::end(channelArray);
            if(!exists) break;

            if(ientry==0){
                test_MC_channel_number=MC_channel_number;
                cout << "The mc channel number is: "<< MC_channel_number << endl;

                //   cout << "MC_channel_number=" << MC_channel_number << endl;
            }

            if(test_MC_channel_number != MC_channel_number){
                test_MC_channel_number=MC_channel_number;
                cout << "Event Number = " << EventNumber << ", entry=" << jentry << ", nentries=" << nentries << endl;
                cout << "MC_channel_number=" << MC_channel_number << endl;
            }

//        if (llll_pdgIdSum == 44) {
//            hist_m4l_4e_channel->Fill(m4l);
//            hCutflow_4e->Fill(1);
//        } else if (llll_pdgIdSum == 48) {
//            hist_m4l_2e2m_channel->Fill(m4l);
//        } else if (llll_pdgIdSum == 52) {
//            hist_m4l_4m_channel->Fill(m4l);
//        }
//
//
//        if (llll_pdgIdSum == 44) {
//            hist_mll_4e_channel->Fill(mll);
//            hCutflow_4e->Fill(1);
//        } else if (llll_pdgIdSum == 48) {
//            hist_mll_2e2m_channel->Fill(mll);
//        } else if (llll_pdgIdSum == 52) {
//            hist_mll_4m_channel->Fill(mll);
//        }
//                if (elIDLep1 < 3 && elIDLep2 < 3 && elIDLep3 < 3 && elIDLep4 < 3) {
//                    if (llll_pdgIdSum == 44){ 
//                hist_mll_4e0_all_channel->Fill(mll);
//                hist_mll_atl_4e0_all_channel->Fill(mll_alt);
//                hist_m12_4e0_all_channel->Fill(m12);
//                hist_m34_4e0_all_channel->Fill(m34);
//                hist_m32_4e0_all_channel->Fill(m32);
//                hist_m14_4e0_all_channel->Fill(m14);
//                hist_Pt1_4e0_all_channel->Fill(Pt1);
//                hist_Pt2_4e0_all_channel->Fill(Pt2);
//                hist_Pt3_4e0_all_channel->Fill(Pt3);
//                hist_Pt4_4e0_all_channel->Fill(Pt4);
//                hist_Eta1_4e0_all_channel->Fill(Eta1);
//                hist_Eta2_4e0_all_channel->Fill(Eta2);
//                hist_Eta3_4e0_all_channel->Fill(Eta3);
//                hist_Eta4_4e0_all_channel->Fill(Eta4);
//                hist_Phi1_4e0_all_channel->Fill(Phi1);
//                hist_Phi2_4e0_all_channel->Fill(Phi2);
//                hist_Phi3_4e0_all_channel->Fill(Phi3);
//                hist_Phi4_4e0_all_channel->Fill(Phi4);;}
//                    if (llll_pdgIdSum == 48){ hCutflow_2e2m->Fill(2);   hist_m4l_2e2m_channel->Fill(m4l);}
//                    if (llll_pdgIdSum == 52){ hCutflow_4m->Fill(2);     hist_m4l_4m_channel->Fill(m4l);}}
//
//                    if (l_isIsolFixedCutLoose ==15) {
//                        if (llll_pdgIdSum == 44){ hCutflow_4e->Fill(3);  hist_m4l_4e_channel->Fill(m4l);}
//                        if (llll_pdgIdSum == 48) hCutflow_2e2m->Fill(3);
//                        if (llll_pdgIdSum == 52) hCutflow_4m->Fill(3);}
//
////                        if (max_el_d0Sig < 5) {
//                            if (llll_pdgIdSum == 44) hCutflow_4e->Fill(4);
//                            if (llll_pdgIdSum == 48) hCutflow_2e2m->Fill(4);
//                            if (llll_pdgIdSum == 52) hCutflow_4m->Fill(4);}
//
//                            if (Q_Veto) {
//                                if (llll_pdgIdSum == 44) hCutflow_4e->Fill(5);
//                                if (llll_pdgIdSum == 48) hCutflow_2e2m->Fill(5);
//                                if (llll_pdgIdSum == 52) hCutflow_4m->Fill(5);}
//
//                                if ((m34/m12) > 0.85) {
//                                    if (llll_pdgIdSum == 44)hCutflow_4e->Fill(6);
//                                    if (llll_pdgIdSum == 48) hCutflow_2e2m->Fill(6);
//                                    if (llll_pdgIdSum == 52) hCutflow_4m->Fill(6);}
//
//                                    if (m4l >115000 && m4l <130000) {
//                                        if (llll_pdgIdSum == 44) hCutflow_4e->Fill(7);
//                                        if (llll_pdgIdSum == 48) hCutflow_2e2m->Fill(7);
//                                        if (llll_pdgIdSum == 52) hCutflow_4m->Fill(7);}
//
//                                        if (m12 >10000. && m34 >10000. && m34 < 64000. && m12 < 64000.) {
//                                            if (llll_pdgIdSum == 44) hCutflow_4e->Fill(8);
//                                            if (llll_pdgIdSum == 48) hCutflow_2e2m->Fill(8);
//                                            if (llll_pdgIdSum == 52) hCutflow_4m->Fill(8);}
//
//                                            if (m14 > 5000 && m32 > 5000 && m14 < 75000 && m32 < 75000) {
// if (llll_pdgIdSum == 44) hCutflow_4e->Fill(9);
// if (llll_pdgIdSum == 48) hCutflow_2e2m->Fill(9);
// if (llll_pdgIdSum == 52) hCutflow_4m->Fill(9);}
//
// if(mll<35000) {
//     if (llll_pdgIdSum == 44){ hCutflow_4e->Fill(10);    hist_m4l_4e_channel->Fill(m4l);}
//     if (llll_pdgIdSum == 48){ hCutflow_2e2m->Fill(10);   hist_m4l_2e2m_channel->Fill(m4l);}
//     if (llll_pdgIdSum == 52){ hCutflow_4m->Fill(10);     hist_m4l_4m_channel->Fill(m4l);}}

            // cout << mll << endl;

// s2->Fill(mll/1000.);
// s3->Fill(mll/1000.);
// //Signal_2e->Fit("gausn");
//
//
//
//                                        Int_t  nentries =1455;
//                                        for (Int_t i=0; i<nentries; i++){




            if (llll_pdgIdSum == 44) {
                hist_m4l_4e0_all_channel->Fill(m4l);
                hist_mll_4e0_all_channel->Fill(mll);
                hist_mll_atl_4e0_all_channel->Fill(mll_alt);
                hist_m12_4e0_all_channel->Fill(m12);
                hist_m34_4e0_all_channel->Fill(m34);
                hist_m32_4e0_all_channel->Fill(m32);
                hist_m14_4e0_all_channel->Fill(m14);
                hist_Pt1_4e0_all_channel->Fill(Pt1);
                hist_Pt2_4e0_all_channel->Fill(Pt2);
                hist_Pt3_4e0_all_channel->Fill(Pt3);
                hist_Pt4_4e0_all_channel->Fill(Pt4);
                hist_Eta1_4e0_all_channel->Fill(Eta1);
                hist_Eta2_4e0_all_channel->Fill(Eta2);
                hist_Eta3_4e0_all_channel->Fill(Eta3);
                hist_Eta4_4e0_all_channel->Fill(Eta4);
                hist_Phi1_4e0_all_channel->Fill(Phi1);
                hist_Phi2_4e0_all_channel->Fill(Phi2);
                hist_Phi3_4e0_all_channel->Fill(Phi3);
                hist_Phi4_4e0_all_channel->Fill(Phi4);
            }
            if (llll_pdgIdSum == 48) {
                hist_m4l_2e2m0_all_channel->Fill(m4l);
                hist_mll_2e2m0_all_channel->Fill(mll);
                hist_mll_atl_2e2m0_all_channel->Fill(mll_alt);
                hist_m12_2e2m0_all_channel->Fill(m12);
                hist_m34_2e2m0_all_channel->Fill(m34);
                hist_m32_2e2m0_all_channel->Fill(m32);
                hist_m14_2e2m0_all_channel->Fill(m14);
                hist_Pt1_2e2m0_all_channel->Fill(Pt1);
                hist_Pt2_2e2m0_all_channel->Fill(Pt2);
                hist_Pt3_2e2m0_all_channel->Fill(Pt3);
                hist_Pt4_2e2m0_all_channel->Fill(Pt4);
                hist_Eta1_2e2m0_all_channel->Fill(Eta1);
                hist_Eta2_2e2m0_all_channel->Fill(Eta2);
                hist_Eta3_2e2m0_all_channel->Fill(Eta3);
                hist_Eta4_2e2m0_all_channel->Fill(Eta4);
                hist_Phi1_2e2m0_all_channel->Fill(Phi1);
                hist_Phi2_2e2m0_all_channel->Fill(Phi2);
                hist_Phi3_2e2m0_all_channel->Fill(Phi3);
                hist_Phi4_2e2m0_all_channel->Fill(Phi4);
            }
            if (llll_pdgIdSum == 52) {
                hist_m4l_4m0_all_channel->Fill(m4l);
                hist_mll_4m0_all_channel->Fill(mll);
                hist_mll_atl_4m0_all_channel->Fill(mll_alt);
                hist_m12_4m0_all_channel->Fill(m12);
                hist_m34_4m0_all_channel->Fill(m34);
                hist_m32_4m0_all_channel->Fill(m32);
                hist_m14_4m0_all_channel->Fill(m14);
                hist_Pt1_4m0_all_channel->Fill(Pt1);
                hist_Pt2_4m0_all_channel->Fill(Pt2);
                hist_Pt3_4m0_all_channel->Fill(Pt3);
                hist_Pt4_4m0_all_channel->Fill(Pt4);
                hist_Eta1_4m0_all_channel->Fill(Eta1);
                hist_Eta2_4m0_all_channel->Fill(Eta2);
                hist_Eta3_4m0_all_channel->Fill(Eta3);
                hist_Eta4_4m0_all_channel->Fill(Eta4);
                hist_Phi1_4m0_all_channel->Fill(Phi1);
                hist_Phi2_4m0_all_channel->Fill(Phi2);
                hist_Phi3_4m0_all_channel->Fill(Phi3);
                hist_Phi4_4m0_all_channel->Fill(Phi4);
            }
            if (l_isIsolFixedCutLoose ==15) {

                if (llll_pdgIdSum == 44) {
                    hist_m4l_4e1_isol_channel->Fill(m4l);
                    hist_mll_4e1_isol_channel->Fill(mll);
                    hist_mll_atl_4e1_isol_channel->Fill(mll_alt);
                    hist_m12_4e1_isol_channel->Fill(m12);
                    hist_m34_4e1_isol_channel->Fill(m34);
                    hist_m32_4e1_isol_channel->Fill(m32);
                    hist_m14_4e1_isol_channel->Fill(m14);
                    hist_Pt1_4e1_isol_channel->Fill(Pt1);
                    hist_Pt2_4e1_isol_channel->Fill(Pt2);
                    hist_Pt3_4e1_isol_channel->Fill(Pt3);
                    hist_Pt4_4e1_isol_channel->Fill(Pt4);
                    hist_Eta1_4e1_isol_channel->Fill(Eta1);
                    hist_Eta2_4e1_isol_channel->Fill(Eta2);
                    hist_Eta3_4e1_isol_channel->Fill(Eta3);
                    hist_Eta4_4e1_isol_channel->Fill(Eta4);
                    hist_Phi1_4e1_isol_channel->Fill(Phi1);
                    hist_Phi2_4e1_isol_channel->Fill(Phi2);
                    hist_Phi3_4e1_isol_channel->Fill(Phi3);
                    hist_Phi4_4e1_isol_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 48) {
                    hist_m4l_2e2m1_isol_channel->Fill(m4l);
                    hist_mll_2e2m1_isol_channel->Fill(mll);
                    hist_mll_atl_2e2m1_isol_channel->Fill(mll_alt);
                    hist_m12_2e2m1_isol_channel->Fill(m12);
                    hist_m34_2e2m1_isol_channel->Fill(m34);
                    hist_m32_2e2m1_isol_channel->Fill(m32);
                    hist_m14_2e2m1_isol_channel->Fill(m14);
                    hist_Pt1_2e2m1_isol_channel->Fill(Pt1);
                    hist_Pt2_2e2m1_isol_channel->Fill(Pt2);
                    hist_Pt3_2e2m1_isol_channel->Fill(Pt3);
                    hist_Pt4_2e2m1_isol_channel->Fill(Pt4);
                    hist_Eta1_2e2m1_isol_channel->Fill(Eta1);
                    hist_Eta2_2e2m1_isol_channel->Fill(Eta2);
                    hist_Eta3_2e2m1_isol_channel->Fill(Eta3);
                    hist_Eta4_2e2m1_isol_channel->Fill(Eta4);
                    hist_Phi1_2e2m1_isol_channel->Fill(Phi1);
                    hist_Phi2_2e2m1_isol_channel->Fill(Phi2);
                    hist_Phi3_2e2m1_isol_channel->Fill(Phi3);
                    hist_Phi4_2e2m1_isol_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 52) {
                    hist_m4l_4m1_isol_channel->Fill(m4l);
                    hist_mll_4m1_isol_channel->Fill(mll);
                    hist_mll_atl_4m1_isol_channel->Fill(mll_alt);
                    hist_m12_4m1_isol_channel->Fill(m12);
                    hist_m34_4m1_isol_channel->Fill(m34);
                    hist_m32_4m1_isol_channel->Fill(m32);
                    hist_m14_4m1_isol_channel->Fill(m14);
                    hist_Pt1_4m1_isol_channel->Fill(Pt1);
                    hist_Pt2_4m1_isol_channel->Fill(Pt2);
                    hist_Pt3_4m1_isol_channel->Fill(Pt3);
                    hist_Pt4_4m1_isol_channel->Fill(Pt4);
                    hist_Eta1_4m1_isol_channel->Fill(Eta1);
                    hist_Eta2_4m1_isol_channel->Fill(Eta2);
                    hist_Eta3_4m1_isol_channel->Fill(Eta3);
                    hist_Eta4_4m1_isol_channel->Fill(Eta4);
                    hist_Phi1_4m1_isol_channel->Fill(Phi1);
                    hist_Phi2_4m1_isol_channel->Fill(Phi2);
                    hist_Phi3_4m1_isol_channel->Fill(Phi3);
                    hist_Phi4_4m1_isol_channel->Fill(Phi4);
                }
            } else continue;
            if (Electron_ID) {
                if (llll_pdgIdSum == 44) {
                    hist_m4l_4e2_elID_channel->Fill(m4l);
                    hist_mll_4e2_elID_channel->Fill(mll);
                    hist_mll_atl_4e2_elID_channel->Fill(mll_alt);
                    hist_m12_4e2_elID_channel->Fill(m12);
                    hist_m34_4e2_elID_channel->Fill(m34);
                    hist_m32_4e2_elID_channel->Fill(m32);
                    hist_m14_4e2_elID_channel->Fill(m14);
                    hist_Pt1_4e2_elID_channel->Fill(Pt1);
                    hist_Pt2_4e2_elID_channel->Fill(Pt2);
                    hist_Pt3_4e2_elID_channel->Fill(Pt3);
                    hist_Pt4_4e2_elID_channel->Fill(Pt4);
                    hist_Eta1_4e2_elID_channel->Fill(Eta1);
                    hist_Eta2_4e2_elID_channel->Fill(Eta2);
                    hist_Eta3_4e2_elID_channel->Fill(Eta3);
                    hist_Eta4_4e2_elID_channel->Fill(Eta4);
                    hist_Phi1_4e2_elID_channel->Fill(Phi1);
                    hist_Phi2_4e2_elID_channel->Fill(Phi2);
                    hist_Phi3_4e2_elID_channel->Fill(Phi3);
                    hist_Phi4_4e2_elID_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 48) {
                    hist_m4l_2e2m2_elID_channel->Fill(m4l);
                    hist_mll_2e2m2_elID_channel->Fill(mll);
                    hist_mll_atl_2e2m2_elID_channel->Fill(mll_alt);
                    hist_m12_2e2m2_elID_channel->Fill(m12);
                    hist_m34_2e2m2_elID_channel->Fill(m34);
                    hist_m32_2e2m2_elID_channel->Fill(m32);
                    hist_m14_2e2m2_elID_channel->Fill(m14);
                    hist_Pt1_2e2m2_elID_channel->Fill(Pt1);
                    hist_Pt2_2e2m2_elID_channel->Fill(Pt2);
                    hist_Pt3_2e2m2_elID_channel->Fill(Pt3);
                    hist_Pt4_2e2m2_elID_channel->Fill(Pt4);
                    hist_Eta1_2e2m2_elID_channel->Fill(Eta1);
                    hist_Eta2_2e2m2_elID_channel->Fill(Eta2);
                    hist_Eta3_2e2m2_elID_channel->Fill(Eta3);
                    hist_Eta4_2e2m2_elID_channel->Fill(Eta4);
                    hist_Phi1_2e2m2_elID_channel->Fill(Phi1);
                    hist_Phi2_2e2m2_elID_channel->Fill(Phi2);
                    hist_Phi3_2e2m2_elID_channel->Fill(Phi3);
                    hist_Phi4_2e2m2_elID_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 52) {
                    hist_m4l_4m2_elID_channel->Fill(m4l);
                    hist_mll_4m2_elID_channel->Fill(mll);
                    hist_mll_atl_4m2_elID_channel->Fill(mll_alt);
                    hist_m12_4m2_elID_channel->Fill(m12);
                    hist_m34_4m2_elID_channel->Fill(m34);
                    hist_m32_4m2_elID_channel->Fill(m32);
                    hist_m14_4m2_elID_channel->Fill(m14);
                    hist_Pt1_4m2_elID_channel->Fill(Pt1);
                    hist_Pt2_4m2_elID_channel->Fill(Pt2);
                    hist_Pt3_4m2_elID_channel->Fill(Pt3);
                    hist_Pt4_4m2_elID_channel->Fill(Pt4);
                    hist_Eta1_4m2_elID_channel->Fill(Eta1);
                    hist_Eta2_4m2_elID_channel->Fill(Eta2);
                    hist_Eta3_4m2_elID_channel->Fill(Eta3);
                    hist_Eta4_4m2_elID_channel->Fill(Eta4);
                    hist_Phi1_4m2_elID_channel->Fill(Phi1);
                    hist_Phi2_4m2_elID_channel->Fill(Phi2);
                    hist_Phi3_4m2_elID_channel->Fill(Phi3);
                    hist_Phi4_4m2_elID_channel->Fill(Phi4);
                }
            } else continue;

            if (impID_2e2m || impID_4e || impID_4m) {
                if (impID_4e) {
                    hist_m4l_4e3_imp_channel->Fill(m4l);
                    hist_mll_4e3_imp_channel->Fill(mll);
                    hist_mll_atl_4e3_imp_channel->Fill(mll_alt);
                    hist_m12_4e3_imp_channel->Fill(m12);
                    hist_m34_4e3_imp_channel->Fill(m34);
                    hist_m32_4e3_imp_channel->Fill(m32);
                    hist_m14_4e3_imp_channel->Fill(m14);
                    hist_Pt1_4e3_imp_channel->Fill(Pt1);
                    hist_Pt2_4e3_imp_channel->Fill(Pt2);
                    hist_Pt3_4e3_imp_channel->Fill(Pt3);
                    hist_Pt4_4e3_imp_channel->Fill(Pt4);
                    hist_Eta1_4e3_imp_channel->Fill(Eta1);
                    hist_Eta2_4e3_imp_channel->Fill(Eta2);
                    hist_Eta3_4e3_imp_channel->Fill(Eta3);
                    hist_Eta4_4e3_imp_channel->Fill(Eta4);
                    hist_Phi1_4e3_imp_channel->Fill(Phi1);
                    hist_Phi2_4e3_imp_channel->Fill(Phi2);
                    hist_Phi3_4e3_imp_channel->Fill(Phi3);
                    hist_Phi4_4e3_imp_channel->Fill(Phi4);
                }
                if (impID_2e2m) {
                    hist_m4l_2e2m3_imp_channel->Fill(m4l);
                    hist_mll_2e2m3_imp_channel->Fill(mll);
                    hist_mll_atl_2e2m3_imp_channel->Fill(mll_alt);
                    hist_m12_2e2m3_imp_channel->Fill(m12);
                    hist_m34_2e2m3_imp_channel->Fill(m34);
                    hist_m32_2e2m3_imp_channel->Fill(m32);
                    hist_m14_2e2m3_imp_channel->Fill(m14);
                    hist_Pt1_2e2m3_imp_channel->Fill(Pt1);
                    hist_Pt2_2e2m3_imp_channel->Fill(Pt2);
                    hist_Pt3_2e2m3_imp_channel->Fill(Pt3);
                    hist_Pt4_2e2m3_imp_channel->Fill(Pt4);
                    hist_Eta1_2e2m3_imp_channel->Fill(Eta1);
                    hist_Eta2_2e2m3_imp_channel->Fill(Eta2);
                    hist_Eta3_2e2m3_imp_channel->Fill(Eta3);
                    hist_Eta4_2e2m3_imp_channel->Fill(Eta4);
                    hist_Phi1_2e2m3_imp_channel->Fill(Phi1);
                    hist_Phi2_2e2m3_imp_channel->Fill(Phi2);
                    hist_Phi3_2e2m3_imp_channel->Fill(Phi3);
                    hist_Phi4_2e2m3_imp_channel->Fill(Phi4);
                }
                if (impID_4m) {
                    hist_m4l_4m3_imp_channel->Fill(m4l);
                    hist_mll_4m3_imp_channel->Fill(mll);
                    hist_mll_atl_4m3_imp_channel->Fill(mll_alt);
                    hist_m12_4m3_imp_channel->Fill(m12);
                    hist_m34_4m3_imp_channel->Fill(m34);
                    hist_m32_4m3_imp_channel->Fill(m32);
                    hist_m14_4m3_imp_channel->Fill(m14);
                    hist_Pt1_4m3_imp_channel->Fill(Pt1);
                    hist_Pt2_4m3_imp_channel->Fill(Pt2);
                    hist_Pt3_4m3_imp_channel->Fill(Pt3);
                    hist_Pt4_4m3_imp_channel->Fill(Pt4);
                    hist_Eta1_4m3_imp_channel->Fill(Eta1);
                    hist_Eta2_4m3_imp_channel->Fill(Eta2);
                    hist_Eta3_4m3_imp_channel->Fill(Eta3);
                    hist_Eta4_4m3_imp_channel->Fill(Eta4);
                    hist_Phi1_4m3_imp_channel->Fill(Phi1);
                    hist_Phi2_4m3_imp_channel->Fill(Phi2);
                    hist_Phi3_4m3_imp_channel->Fill(Phi3);
                    hist_Phi4_4m3_imp_channel->Fill(Phi4);
                }
            } else continue;


            if (Q_Veto) {
                if (llll_pdgIdSum == 44) {
                    hist_m4l_4e4_QVeto_channel->Fill(m4l);
                    hist_mll_4e4_QVeto_channel->Fill(mll);
                    hist_mll_atl_4e4_QVeto_channel->Fill(mll_alt);
                    hist_m12_4e4_QVeto_channel->Fill(m12);
                    hist_m34_4e4_QVeto_channel->Fill(m34);
                    hist_m32_4e4_QVeto_channel->Fill(m32);
                    hist_m14_4e4_QVeto_channel->Fill(m14);
                    hist_Pt1_4e4_QVeto_channel->Fill(Pt1);
                    hist_Pt2_4e4_QVeto_channel->Fill(Pt2);
                    hist_Pt3_4e4_QVeto_channel->Fill(Pt3);
                    hist_Pt4_4e4_QVeto_channel->Fill(Pt4);
                    hist_Eta1_4e4_QVeto_channel->Fill(Eta1);
                    hist_Eta2_4e4_QVeto_channel->Fill(Eta2);
                    hist_Eta3_4e4_QVeto_channel->Fill(Eta3);
                    hist_Eta4_4e4_QVeto_channel->Fill(Eta4);
                    hist_Phi1_4e4_QVeto_channel->Fill(Phi1);
                    hist_Phi2_4e4_QVeto_channel->Fill(Phi2);
                    hist_Phi3_4e4_QVeto_channel->Fill(Phi3);
                    hist_Phi4_4e4_QVeto_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 48) {
                    hist_m4l_2e2m4_QVeto_channel->Fill(m4l);
                    hist_mll_2e2m4_QVeto_channel->Fill(mll);
                    hist_mll_atl_2e2m4_QVeto_channel->Fill(mll_alt);
                    hist_m12_2e2m4_QVeto_channel->Fill(m12);
                    hist_m34_2e2m4_QVeto_channel->Fill(m34);
                    hist_m32_2e2m4_QVeto_channel->Fill(m32);
                    hist_m14_2e2m4_QVeto_channel->Fill(m14);
                    hist_Pt1_2e2m4_QVeto_channel->Fill(Pt1);
                    hist_Pt2_2e2m4_QVeto_channel->Fill(Pt2);
                    hist_Pt3_2e2m4_QVeto_channel->Fill(Pt3);
                    hist_Pt4_2e2m4_QVeto_channel->Fill(Pt4);
                    hist_Eta1_2e2m4_QVeto_channel->Fill(Eta1);
                    hist_Eta2_2e2m4_QVeto_channel->Fill(Eta2);
                    hist_Eta3_2e2m4_QVeto_channel->Fill(Eta3);
                    hist_Eta4_2e2m4_QVeto_channel->Fill(Eta4);
                    hist_Phi1_2e2m4_QVeto_channel->Fill(Phi1);
                    hist_Phi2_2e2m4_QVeto_channel->Fill(Phi2);
                    hist_Phi3_2e2m4_QVeto_channel->Fill(Phi3);
                    hist_Phi4_2e2m4_QVeto_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 52) {
                    hist_m4l_4m4_QVeto_channel->Fill(m4l);
                    hist_mll_4m4_QVeto_channel->Fill(mll);
                    hist_mll_atl_4m4_QVeto_channel->Fill(mll_alt);
                    hist_m12_4m4_QVeto_channel->Fill(m12);
                    hist_m34_4m4_QVeto_channel->Fill(m34);
                    hist_m32_4m4_QVeto_channel->Fill(m32);
                    hist_m14_4m4_QVeto_channel->Fill(m14);
                    hist_Pt1_4m4_QVeto_channel->Fill(Pt1);
                    hist_Pt2_4m4_QVeto_channel->Fill(Pt2);
                    hist_Pt3_4m4_QVeto_channel->Fill(Pt3);
                    hist_Pt4_4m4_QVeto_channel->Fill(Pt4);
                    hist_Eta1_4m4_QVeto_channel->Fill(Eta1);
                    hist_Eta2_4m4_QVeto_channel->Fill(Eta2);
                    hist_Eta3_4m4_QVeto_channel->Fill(Eta3);
                    hist_Eta4_4m4_QVeto_channel->Fill(Eta4);
                    hist_Phi1_4m4_QVeto_channel->Fill(Phi1);
                    hist_Phi2_4m4_QVeto_channel->Fill(Phi2);
                    hist_Phi3_4m4_QVeto_channel->Fill(Phi3);
                    hist_Phi4_4m4_QVeto_channel->Fill(Phi4);
                }
            } else continue;

            if (LowMassVeto) {
                if (llll_pdgIdSum == 44) {
                    hist_m4l_4e5_lowMassVeto_channel->Fill(m4l);
                    hist_mll_4e5_lowMassVeto_channel->Fill(mll);
                    hist_mll_atl_4e5_lowMassVeto_channel->Fill(mll_alt);
                    hist_m12_4e5_lowMassVeto_channel->Fill(m12);
                    hist_m34_4e5_lowMassVeto_channel->Fill(m34);
                    hist_m32_4e5_lowMassVeto_channel->Fill(m32);
                    hist_m14_4e5_lowMassVeto_channel->Fill(m14);
                    hist_Pt1_4e5_lowMassVeto_channel->Fill(Pt1);
                    hist_Pt2_4e5_lowMassVeto_channel->Fill(Pt2);
                    hist_Pt3_4e5_lowMassVeto_channel->Fill(Pt3);
                    hist_Pt4_4e5_lowMassVeto_channel->Fill(Pt4);
                    hist_Eta1_4e5_lowMassVeto_channel->Fill(Eta1);
                    hist_Eta2_4e5_lowMassVeto_channel->Fill(Eta2);
                    hist_Eta3_4e5_lowMassVeto_channel->Fill(Eta3);
                    hist_Eta4_4e5_lowMassVeto_channel->Fill(Eta4);
                    hist_Phi1_4e5_lowMassVeto_channel->Fill(Phi1);
                    hist_Phi2_4e5_lowMassVeto_channel->Fill(Phi2);
                    hist_Phi3_4e5_lowMassVeto_channel->Fill(Phi3);
                    hist_Phi4_4e5_lowMassVeto_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 48) {
                    hist_m4l_2e2m5_lowMassVeto_channel->Fill(m4l);
                    hist_mll_2e2m5_lowMassVeto_channel->Fill(mll);
                    hist_mll_atl_2e2m5_lowMassVeto_channel->Fill(mll_alt);
                    hist_m12_2e2m5_lowMassVeto_channel->Fill(m12);
                    hist_m34_2e2m5_lowMassVeto_channel->Fill(m34);
                    hist_m32_2e2m5_lowMassVeto_channel->Fill(m32);
                    hist_m14_2e2m5_lowMassVeto_channel->Fill(m14);
                    hist_Pt1_2e2m5_lowMassVeto_channel->Fill(Pt1);
                    hist_Pt2_2e2m5_lowMassVeto_channel->Fill(Pt2);
                    hist_Pt3_2e2m5_lowMassVeto_channel->Fill(Pt3);
                    hist_Pt4_2e2m5_lowMassVeto_channel->Fill(Pt4);
                    hist_Eta1_2e2m5_lowMassVeto_channel->Fill(Eta1);
                    hist_Eta2_2e2m5_lowMassVeto_channel->Fill(Eta2);
                    hist_Eta3_2e2m5_lowMassVeto_channel->Fill(Eta3);
                    hist_Eta4_2e2m5_lowMassVeto_channel->Fill(Eta4);
                    hist_Phi1_2e2m5_lowMassVeto_channel->Fill(Phi1);
                    hist_Phi2_2e2m5_lowMassVeto_channel->Fill(Phi2);
                    hist_Phi3_2e2m5_lowMassVeto_channel->Fill(Phi3);
                    hist_Phi4_2e2m5_lowMassVeto_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 52) {
                    hist_m4l_4m5_lowMassVeto_channel->Fill(m4l);
                    hist_mll_4m5_lowMassVeto_channel->Fill(mll);
                    hist_mll_atl_4m5_lowMassVeto_channel->Fill(mll_alt);
                    hist_m12_4m5_lowMassVeto_channel->Fill(m12);
                    hist_m34_4m5_lowMassVeto_channel->Fill(m34);
                    hist_m32_4m5_lowMassVeto_channel->Fill(m32);
                    hist_m14_4m5_lowMassVeto_channel->Fill(m14);
                    hist_Pt1_4m5_lowMassVeto_channel->Fill(Pt1);
                    hist_Pt2_4m5_lowMassVeto_channel->Fill(Pt2);
                    hist_Pt3_4m5_lowMassVeto_channel->Fill(Pt3);
                    hist_Pt4_4m5_lowMassVeto_channel->Fill(Pt4);
                    hist_Eta1_4m5_lowMassVeto_channel->Fill(Eta1);
                    hist_Eta2_4m5_lowMassVeto_channel->Fill(Eta2);
                    hist_Eta3_4m5_lowMassVeto_channel->Fill(Eta3);
                    hist_Eta4_4m5_lowMassVeto_channel->Fill(Eta4);
                    hist_Phi1_4m5_lowMassVeto_channel->Fill(Phi1);
                    hist_Phi2_4m5_lowMassVeto_channel->Fill(Phi2);
                    hist_Phi3_4m5_lowMassVeto_channel->Fill(Phi3);
                    hist_Phi4_4m5_lowMassVeto_channel->Fill(Phi4);
                }
            } else continue;

            if (ZVeto) {
                if (llll_pdgIdSum == 44) {
                    hist_m4l_4e6_ZVeto_channel->Fill(m4l);
                    hist_mll_4e6_ZVeto_channel->Fill(mll);
                    hist_mll_atl_4e6_ZVeto_channel->Fill(mll_alt);
                    hist_m12_4e6_ZVeto_channel->Fill(m12);
                    hist_m34_4e6_ZVeto_channel->Fill(m34);
                    hist_m32_4e6_ZVeto_channel->Fill(m32);
                    hist_m14_4e6_ZVeto_channel->Fill(m14);
                    hist_Pt1_4e6_ZVeto_channel->Fill(Pt1);
                    hist_Pt2_4e6_ZVeto_channel->Fill(Pt2);
                    hist_Pt3_4e6_ZVeto_channel->Fill(Pt3);
                    hist_Pt4_4e6_ZVeto_channel->Fill(Pt4);
                    hist_Eta1_4e6_ZVeto_channel->Fill(Eta1);
                    hist_Eta2_4e6_ZVeto_channel->Fill(Eta2);
                    hist_Eta3_4e6_ZVeto_channel->Fill(Eta3);
                    hist_Eta4_4e6_ZVeto_channel->Fill(Eta4);
                    hist_Phi1_4e6_ZVeto_channel->Fill(Phi1);
                    hist_Phi2_4e6_ZVeto_channel->Fill(Phi2);
                    hist_Phi3_4e6_ZVeto_channel->Fill(Phi3);
                    hist_Phi4_4e6_ZVeto_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 48) {
                    hist_m4l_2e2m6_ZVeto_channel->Fill(m4l);
                    hist_mll_2e2m6_ZVeto_channel->Fill(mll);
                    hist_mll_atl_2e2m6_ZVeto_channel->Fill(mll_alt);
                    hist_m12_2e2m6_ZVeto_channel->Fill(m12);
                    hist_m34_2e2m6_ZVeto_channel->Fill(m34);
                    hist_m32_2e2m6_ZVeto_channel->Fill(m32);
                    hist_m14_2e2m6_ZVeto_channel->Fill(m14);
                    hist_Pt1_2e2m6_ZVeto_channel->Fill(Pt1);
                    hist_Pt2_2e2m6_ZVeto_channel->Fill(Pt2);
                    hist_Pt3_2e2m6_ZVeto_channel->Fill(Pt3);
                    hist_Pt4_2e2m6_ZVeto_channel->Fill(Pt4);
                    hist_Eta1_2e2m6_ZVeto_channel->Fill(Eta1);
                    hist_Eta2_2e2m6_ZVeto_channel->Fill(Eta2);
                    hist_Eta3_2e2m6_ZVeto_channel->Fill(Eta3);
                    hist_Eta4_2e2m6_ZVeto_channel->Fill(Eta4);
                    hist_Phi1_2e2m6_ZVeto_channel->Fill(Phi1);
                    hist_Phi2_2e2m6_ZVeto_channel->Fill(Phi2);
                    hist_Phi3_2e2m6_ZVeto_channel->Fill(Phi3);
                    hist_Phi4_2e2m6_ZVeto_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 52) {
                    hist_m4l_4m6_ZVeto_channel->Fill(m4l);
                    hist_mll_4m6_ZVeto_channel->Fill(mll);
                    hist_mll_atl_4m6_ZVeto_channel->Fill(mll_alt);
                    hist_m12_4m6_ZVeto_channel->Fill(m12);
                    hist_m34_4m6_ZVeto_channel->Fill(m34);
                    hist_m32_4m6_ZVeto_channel->Fill(m32);
                    hist_m14_4m6_ZVeto_channel->Fill(m14);
                    hist_Pt1_4m6_ZVeto_channel->Fill(Pt1);
                    hist_Pt2_4m6_ZVeto_channel->Fill(Pt2);
                    hist_Pt3_4m6_ZVeto_channel->Fill(Pt3);
                    hist_Pt4_4m6_ZVeto_channel->Fill(Pt4);
                    hist_Eta1_4m6_ZVeto_channel->Fill(Eta1);
                    hist_Eta2_4m6_ZVeto_channel->Fill(Eta2);
                    hist_Eta3_4m6_ZVeto_channel->Fill(Eta3);
                    hist_Eta4_4m6_ZVeto_channel->Fill(Eta4);
                    hist_Phi1_4m6_ZVeto_channel->Fill(Phi1);
                    hist_Phi2_4m6_ZVeto_channel->Fill(Phi2);
                    hist_Phi3_4m6_ZVeto_channel->Fill(Phi3);
                    hist_Phi4_4m6_ZVeto_channel->Fill(Phi4);
                }
            } else continue;
            
            if (HWinHM) {
                if (llll_pdgIdSum == 44) {
                    hist_m4l_4e7_HWinHM__channel->Fill(m4l);
                    hist_mll_4e7_HWinHM__channel->Fill(mll);
                    hist_mll_atl_4e7_HWinHM__channel->Fill(mll_alt);
                    hist_m12_4e7_HWinHM__channel->Fill(m12);
                    hist_m34_4e7_HWinHM__channel->Fill(m34);
                    hist_m32_4e7_HWinHM__channel->Fill(m32);
                    hist_m14_4e7_HWinHM__channel->Fill(m14);
                    hist_Pt1_4e7_HWinHM__channel->Fill(Pt1);
                    hist_Pt2_4e7_HWinHM__channel->Fill(Pt2);
                    hist_Pt3_4e7_HWinHM__channel->Fill(Pt3);
                    hist_Pt4_4e7_HWinHM__channel->Fill(Pt4);
                    hist_Eta1_4e7_HWinHM__channel->Fill(Eta1);
                    hist_Eta2_4e7_HWinHM__channel->Fill(Eta2);
                    hist_Eta3_4e7_HWinHM__channel->Fill(Eta3);
                    hist_Eta4_4e7_HWinHM__channel->Fill(Eta4);
                    hist_Phi1_4e7_HWinHM__channel->Fill(Phi1);
                    hist_Phi2_4e7_HWinHM__channel->Fill(Phi2);
                    hist_Phi3_4e7_HWinHM__channel->Fill(Phi3);
                    hist_Phi4_4e7_HWinHM__channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 48) {
                    hist_m4l_2e2m7_HWinHM__channel->Fill(m4l);
                    hist_mll_2e2m7_HWinHM__channel->Fill(mll);
                    hist_mll_atl_2e2m7_HWinHM__channel->Fill(mll_alt);
                    hist_m12_2e2m7_HWinHM__channel->Fill(m12);
                    hist_m34_2e2m7_HWinHM__channel->Fill(m34);
                    hist_m32_2e2m7_HWinHM__channel->Fill(m32);
                    hist_m14_2e2m7_HWinHM__channel->Fill(m14);
                    hist_Pt1_2e2m7_HWinHM__channel->Fill(Pt1);
                    hist_Pt2_2e2m7_HWinHM__channel->Fill(Pt2);
                    hist_Pt3_2e2m7_HWinHM__channel->Fill(Pt3);
                    hist_Pt4_2e2m7_HWinHM__channel->Fill(Pt4);
                    hist_Eta1_2e2m7_HWinHM__channel->Fill(Eta1);
                    hist_Eta2_2e2m7_HWinHM__channel->Fill(Eta2);
                    hist_Eta3_2e2m7_HWinHM__channel->Fill(Eta3);
                    hist_Eta4_2e2m7_HWinHM__channel->Fill(Eta4);
                    hist_Phi1_2e2m7_HWinHM__channel->Fill(Phi1);
                    hist_Phi2_2e2m7_HWinHM__channel->Fill(Phi2);
                    hist_Phi3_2e2m7_HWinHM__channel->Fill(Phi3);
                    hist_Phi4_2e2m7_HWinHM__channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 52) {
                    hist_m4l_4m7_HWinHM__channel->Fill(m4l);
                    hist_mll_4m7_HWinHM__channel->Fill(mll);
                    hist_mll_atl_4m7_HWinHM__channel->Fill(mll_alt);
                    hist_m12_4m7_HWinHM__channel->Fill(m12);
                    hist_m34_4m7_HWinHM__channel->Fill(m34);
                    hist_m32_4m7_HWinHM__channel->Fill(m32);
                    hist_m14_4m7_HWinHM__channel->Fill(m14);
                    hist_Pt1_4m7_HWinHM__channel->Fill(Pt1);
                    hist_Pt2_4m7_HWinHM__channel->Fill(Pt2);
                    hist_Pt3_4m7_HWinHM__channel->Fill(Pt3);
                    hist_Pt4_4m7_HWinHM__channel->Fill(Pt4);
                    hist_Eta1_4m7_HWinHM__channel->Fill(Eta1);
                    hist_Eta2_4m7_HWinHM__channel->Fill(Eta2);
                    hist_Eta3_4m7_HWinHM__channel->Fill(Eta3);
                    hist_Eta4_4m7_HWinHM__channel->Fill(Eta4);
                    hist_Phi1_4m7_HWinHM__channel->Fill(Phi1);
                    hist_Phi2_4m7_HWinHM__channel->Fill(Phi2);
                    hist_Phi3_4m7_HWinHM__channel->Fill(Phi3);
                    hist_Phi4_4m7_HWinHM__channel->Fill(Phi4);
                }
            } else continue;

            

            if (LooseSR_HM) {
                if (llll_pdgIdSum == 44) {
                    hist_m4l_4e8_LooseSR_channel->Fill(m4l);
                    hist_mll_4e8_LooseSR_channel->Fill(mll);
                    hist_mll_atl_4e8_LooseSR_channel->Fill(mll_alt);
                    hist_m12_4e8_LooseSR_channel->Fill(m12);
                    hist_m34_4e8_LooseSR_channel->Fill(m34);
                    hist_m32_4e8_LooseSR_channel->Fill(m32);
                    hist_m14_4e8_LooseSR_channel->Fill(m14);
                    hist_Pt1_4e8_LooseSR_channel->Fill(Pt1);
                    hist_Pt2_4e8_LooseSR_channel->Fill(Pt2);
                    hist_Pt3_4e8_LooseSR_channel->Fill(Pt3);
                    hist_Pt4_4e8_LooseSR_channel->Fill(Pt4);
                    hist_Eta1_4e8_LooseSR_channel->Fill(Eta1);
                    hist_Eta2_4e8_LooseSR_channel->Fill(Eta2);
                    hist_Eta3_4e8_LooseSR_channel->Fill(Eta3);
                    hist_Eta4_4e8_LooseSR_channel->Fill(Eta4);
                    hist_Phi1_4e8_LooseSR_channel->Fill(Phi1);
                    hist_Phi2_4e8_LooseSR_channel->Fill(Phi2);
                    hist_Phi3_4e8_LooseSR_channel->Fill(Phi3);
                    hist_Phi4_4e8_LooseSR_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 48) {
                    hist_m4l_2e2m8_LooseSR_channel->Fill(m4l);
                    hist_mll_2e2m8_LooseSR_channel->Fill(mll);
                    hist_mll_atl_2e2m8_LooseSR_channel->Fill(mll_alt);
                    hist_m12_2e2m8_LooseSR_channel->Fill(m12);
                    hist_m34_2e2m8_LooseSR_channel->Fill(m34);
                    hist_m32_2e2m8_LooseSR_channel->Fill(m32);
                    hist_m14_2e2m8_LooseSR_channel->Fill(m14);
                    hist_Pt1_2e2m8_LooseSR_channel->Fill(Pt1);
                    hist_Pt2_2e2m8_LooseSR_channel->Fill(Pt2);
                    hist_Pt3_2e2m8_LooseSR_channel->Fill(Pt3);
                    hist_Pt4_2e2m8_LooseSR_channel->Fill(Pt4);
                    hist_Eta1_2e2m8_LooseSR_channel->Fill(Eta1);
                    hist_Eta2_2e2m8_LooseSR_channel->Fill(Eta2);
                    hist_Eta3_2e2m8_LooseSR_channel->Fill(Eta3);
                    hist_Eta4_2e2m8_LooseSR_channel->Fill(Eta4);
                    hist_Phi1_2e2m8_LooseSR_channel->Fill(Phi1);
                    hist_Phi2_2e2m8_LooseSR_channel->Fill(Phi2);
                    hist_Phi3_2e2m8_LooseSR_channel->Fill(Phi3);
                    hist_Phi4_2e2m8_LooseSR_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 52) {
                    hist_m4l_4m8_LooseSR_channel->Fill(m4l);
                    hist_mll_4m8_LooseSR_channel->Fill(mll);
                    hist_mll_atl_4m8_LooseSR_channel->Fill(mll_alt);
                    hist_m12_4m8_LooseSR_channel->Fill(m12);
                    hist_m34_4m8_LooseSR_channel->Fill(m34);
                    hist_m32_4m8_LooseSR_channel->Fill(m32);
                    hist_m14_4m8_LooseSR_channel->Fill(m14);
                    hist_Pt1_4m8_LooseSR_channel->Fill(Pt1);
                    hist_Pt2_4m8_LooseSR_channel->Fill(Pt2);
                    hist_Pt3_4m8_LooseSR_channel->Fill(Pt3);
                    hist_Pt4_4m8_LooseSR_channel->Fill(Pt4);
                    hist_Eta1_4m8_LooseSR_channel->Fill(Eta1);
                    hist_Eta2_4m8_LooseSR_channel->Fill(Eta2);
                    hist_Eta3_4m8_LooseSR_channel->Fill(Eta3);
                    hist_Eta4_4m8_LooseSR_channel->Fill(Eta4);
                    hist_Phi1_4m8_LooseSR_channel->Fill(Phi1);
                    hist_Phi2_4m8_LooseSR_channel->Fill(Phi2);
                    hist_Phi3_4m8_LooseSR_channel->Fill(Phi3);
                    hist_Phi4_4m8_LooseSR_channel->Fill(Phi4);
                }
            } else continue;

            if (MediumSR) {
                if (llll_pdgIdSum == 44) {
                    hist_m4l_4e9_MediumSR_channel->Fill(m4l);
                    hist_mll_4e9_MediumSR_channel->Fill(mll);
                    hist_mll_atl_4e9_MediumSR_channel->Fill(mll_alt);
                    hist_m12_4e9_MediumSR_channel->Fill(m12);
                    hist_m34_4e9_MediumSR_channel->Fill(m34);
                    hist_m32_4e9_MediumSR_channel->Fill(m32);
                    hist_m14_4e9_MediumSR_channel->Fill(m14);
                    hist_Pt1_4e9_MediumSR_channel->Fill(Pt1);
                    hist_Pt2_4e9_MediumSR_channel->Fill(Pt2);
                    hist_Pt3_4e9_MediumSR_channel->Fill(Pt3);
                    hist_Pt4_4e9_MediumSR_channel->Fill(Pt4);
                    hist_Eta1_4e9_MediumSR_channel->Fill(Eta1);
                    hist_Eta2_4e9_MediumSR_channel->Fill(Eta2);
                    hist_Eta3_4e9_MediumSR_channel->Fill(Eta3);
                    hist_Eta4_4e9_MediumSR_channel->Fill(Eta4);
                    hist_Phi1_4e9_MediumSR_channel->Fill(Phi1);
                    hist_Phi2_4e9_MediumSR_channel->Fill(Phi2);
                    hist_Phi3_4e9_MediumSR_channel->Fill(Phi3);
                    hist_Phi4_4e9_MediumSR_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 48) {
                    hist_m4l_2e2m9_MediumSR_channel->Fill(m4l);
                    hist_mll_2e2m9_MediumSR_channel->Fill(mll);
                    hist_mll_atl_2e2m9_MediumSR_channel->Fill(mll_alt);
                    hist_m12_2e2m9_MediumSR_channel->Fill(m12);
                    hist_m34_2e2m9_MediumSR_channel->Fill(m34);
                    hist_m32_2e2m9_MediumSR_channel->Fill(m32);
                    hist_m14_2e2m9_MediumSR_channel->Fill(m14);
                    hist_Pt1_2e2m9_MediumSR_channel->Fill(Pt1);
                    hist_Pt2_2e2m9_MediumSR_channel->Fill(Pt2);
                    hist_Pt3_2e2m9_MediumSR_channel->Fill(Pt3);
                    hist_Pt4_2e2m9_MediumSR_channel->Fill(Pt4);
                    hist_Eta1_2e2m9_MediumSR_channel->Fill(Eta1);
                    hist_Eta2_2e2m9_MediumSR_channel->Fill(Eta2);
                    hist_Eta3_2e2m9_MediumSR_channel->Fill(Eta3);
                    hist_Eta4_2e2m9_MediumSR_channel->Fill(Eta4);
                    hist_Phi1_2e2m9_MediumSR_channel->Fill(Phi1);
                    hist_Phi2_2e2m9_MediumSR_channel->Fill(Phi2);
                    hist_Phi3_2e2m9_MediumSR_channel->Fill(Phi3);
                    hist_Phi4_2e2m9_MediumSR_channel->Fill(Phi4);
                }
                if (llll_pdgIdSum == 52) {
                    hist_m4l_4m9_MediumSR_channel->Fill(m4l);
                    hist_mll_4m9_MediumSR_channel->Fill(mll);
                    hist_mll_atl_4m9_MediumSR_channel->Fill(mll_alt);
                    hist_m12_4m9_MediumSR_channel->Fill(m12);
                    hist_m34_4m9_MediumSR_channel->Fill(m34);
                    hist_m32_4m9_MediumSR_channel->Fill(m32);
                    hist_m14_4m9_MediumSR_channel->Fill(m14);
                    hist_Pt1_4m9_MediumSR_channel->Fill(Pt1);
                    hist_Pt2_4m9_MediumSR_channel->Fill(Pt2);
                    hist_Pt3_4m9_MediumSR_channel->Fill(Pt3);
                    hist_Pt4_4m9_MediumSR_channel->Fill(Pt4);
                    hist_Eta1_4m9_MediumSR_channel->Fill(Eta1);
                    hist_Eta2_4m9_MediumSR_channel->Fill(Eta2);
                    hist_Eta3_4m9_MediumSR_channel->Fill(Eta3);
                    hist_Eta4_4m9_MediumSR_channel->Fill(Eta4);
                    hist_Phi1_4m9_MediumSR_channel->Fill(Phi1);
                    hist_Phi2_4m9_MediumSR_channel->Fill(Phi2);
                    hist_Phi3_4m9_MediumSR_channel->Fill(Phi3);
                    hist_Phi4_4m9_MediumSR_channel->Fill(Phi4);
                }
            } else continue;

//// // cout << mll << endl;
//// hCutflow_4e->Fill(10);
////// hist_m4l_4e_channel->Fill(mll/1000.);
////// s2->Fill(mll/1000.);
////// s3->Fill(mll/1000.);
//// //Signal_2e->Fit("gausn");
////
////


        }




//                                }
//                            }
//                        }
//                    }
//
//                }
//
//            }
//        }
//
//    }


    string savefolder = "Output/";
    string outputname;
    if(outputMidName[MC_channel_number].find("mc16a") != string::npos)
        outputname = savefolder+ "Signals/" +outputMidName[MC_channel_number]+ "_histos." + rootFileName.substr(rootFileName.length()-17,17) + "_L3.root";
    else
        outputname = savefolder+ "Bkgs/" + "_TotalBkgs." + rootFileName.substr(rootFileName.length()-17,17) + "_L3.root";
//    outputname = savefolder+ "Bkgs/" +outputMidName[MC_channel_number]+ "." + rootFileName.substr(rootFileName.length()-17,17) + "_L3.root";


        //********************************************************************************

        TFile *file = new TFile(outputname.c_str(), "RECREATE");
        TH1F *hist = new TH1F("test", "test",1, 0,1);
        hist->SetBinContent(1,100);
        hist->Write();

        //save histograms to this place
        for (int i = 0; i < MyHistArray->GetEntriesFast(); i++) {

            MyHistArray->At(i)->Write();
            cout << "Writing histograms to = " << outputname << endl;
        }
        file->Write();
        file->Close();

        cout << "---------------------------" << endl;

    }

//
//
//
