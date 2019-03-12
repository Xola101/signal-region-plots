#include "ZdZdPlot.h"
#include<fstream>
#include<iostream>
#include<vector>
#include<string.h>
#include<cstdlib>
// root classes
#include "TStyle.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TProfile.h"
//#include "atlasstyle-0

using namespace std;
int main(){
    //  SetAtlasStyle();
    TStyle* gStyle = new TStyle();
    gStyle->SetPalette(1);

    while(1) {

        string rootFile, rootFileName;
        cin >> rootFile;
        if(cin.eof()) break;//pay attention here, if end of file break, so we should enter at the end of file
        //cout << "rootFile=" << rootFile << endl;
        if(rootFile.substr(rootFile.length()-1,rootFile.length())!="t"){
            rootFileName = rootFile.substr (0,rootFile.length()-7);
        }else{
            rootFileName = rootFile.substr (0,rootFile.length()-5);//to remove the ".root" from the rootFile
        };
        cout << "rootFileName=" << rootFileName << endl;

        cout << "Reading " << rootFile  << endl;
        TFile* file = new TFile(rootFile.c_str(),"READ");
        file->cd();

        string treeName;

        treeName = "myTree";
        cout << "treeName=" << treeName << endl;
        TTree* tree = (TTree*)file->Get(treeName.c_str());
        ZdZdPlot* m = new ZdZdPlot(tree);
        m->Loop(tree, rootFileName);

    }
    return 1;
}

