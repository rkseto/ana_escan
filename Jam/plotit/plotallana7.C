// for looking at v3
// load c++ and c headers
// r phi z is really x y  -> rvsphivspr means xvsyvspx
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "TSystem.h"
#include "TChain.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TProfile3D.h"
#include "TFrame.h"
#include "TROOT.h"
#include "TLeaf.h"
#include "TRandom.h"
#include "TRandom3.h"
#include "TFormula.h"
#include "TPaveLabel.h"
#include "TFile.h"
#include "TMath.h"
#include "TLeaf.h"
#include "TComplex.h"

#include "TDatabasePDG.h"
#include "TParticlePDG.h"
#include "TLorentzVector.h"

void plotallana7 () {
  //  void plotallana7 (string filestr = "jam1_3_b0-14_RQMDS_all.root", double ptmin=0., double ptmax=5. ) {
  int nfiles=6;
  string filestr_ar[10]={
    "../3p0/Jam1_3GeV_b0-14_RQMDRMF_NS2_all_bcut0_14_ana7_hist.root",
    "../3p2/Jam1_3p2GeV_b0-14_RQMDRMF_NS2_all_bcut0_14_ana7_hist.root",
    "../3p5/Jam1_3p5GeV_b0-14_RQMDRMF_NS2_all_bcut0_14_ana7_hist.root",
    "../3p9/Jam1_3p9GeV_b0-14_RQMDRMF_NS2_all_bcut0_14_ana7_hist.root",
    "../4p5/Jam1_4p5GeV_b0-14_RQMDRMF_NS2_all_bcut0_14_ana7_hist.root",
    "../3p0cascade/Jam1_3GeV_b0-14_cascade1M_all_bcut0_14_ana7_hist.root",
    " ",
    " ",
    " ",
    " "
  };
  string name_a_str_ar[10]={
    "3p0",
    "3p2",
    "3p5",
    "3p9",    
    "4p5",
    "3p0cascade ",
    " ",
    " ",
    " ",
    " "
  };
  // string filestr="../3p0/Jam1_3GeV_b0-14_RQMDRMF_NS2_all_bcut0_14_ana7_hist.root";
  TFile *fin_ar[10]; 
  char filechr[500];

  for (int i=0; i<nfiles; i++){
    //  strcpy(filechr,filestr.c_str());
    //  TFile *fin = new TFile(filechr,"read");
    strcpy(filechr,filestr_ar[i].c_str());
    fin_ar[i] = new TFile(filechr,"read");
    cout << "Input root file:  " << filechr << endl;
  }
	 

  TProfile *myraphist_ar[10];
  TH1D *myraphistodd_ar[10];
  TH1D *myraphisteven_ar[10];
  TH1D *mycenthist_ar[10];
  TProfile *mypthist_ar[10];
  char histchr[500];
  char namechr[500];
  string histstr="xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
  string name_b_str="xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
  
  for (int j=0; j<=4; j++){
    if(j==0){histstr="cth_3_rapidity_ptcut1_mid_pr_h"; name_b_str ="Jam_v3_rap_mid";}
    if(j==1){histstr="cth_3_b_ycut1_ptcut1_pr_h"; name_b_str ="Jam_v3_centrality";  }
    if(j==2){histstr="cth_3_pt_ycut1_mid_pr_h"; name_b_str ="Jam_v3_pt_mid";  }
    if(j==3){histstr="cth_3_rapidity_ptcut1_mid_pr_h"; name_b_str ="Jam_v3_rap_mid_odd";}
    if(j==4){histstr="cth_3_rapidity_ptcut1_mid_pr_h"; name_b_str ="Jam_v3_rap_mid_even";}

    strcpy(histchr,histstr.c_str());
    TProfile *tmp;
    TProfile *tmp2;
    for (int i=0; i<nfiles; i++){
      string namestr=name_b_str+"_"+name_a_str_ar[i];
      //      string namestr=name_b_str++Form("myhist%d",i);
      strcpy(namechr,namestr.c_str());
      cout<<" name of new histogram: "<<j<<" "<<namechr<<endl;
      if(j==0){ myraphist_ar[i] = (TProfile *) fin_ar[i]->Get(histchr);myraphist_ar[i]->SetNameTitle(namechr,namechr);}
      if(j==1){
	tmp = (TProfile *) fin_ar[i]->Get(histchr);
	mycenthist_ar[i] = new TH1D(namechr,namechr,42,0.,60.);
	double bincontent=0;
	for(int ii=1; ii<43; ii++){    
	  bincontent=tmp->GetBinContent(ii);
	  mycenthist_ar[i]->SetBinContent(ii,bincontent);
	}
	int rbin=2;
	mycenthist_ar[i]->Rebin(rbin);
	mycenthist_ar[i]->Scale(1./float(rbin));	
	tmp->Reset();      
      }
      if(j==2){ mypthist_ar[i] = (TProfile *) fin_ar[i]->Get(histchr);mypthist_ar[i]->SetNameTitle(namechr,namechr);}      

      if(j==3){
	tmp2 = (TProfile *) fin_ar[i]->Get(histchr);
	tmp = (TProfile *) tmp2->Clone();
	int nbins=tmp->GetXaxis()->GetNbins();
	double xmin=tmp->GetXaxis()->GetXmin();
	double xmax=tmp->GetXaxis()->GetXmax();
	myraphistodd_ar[i] = new TH1D(namechr,namechr,nbins,xmin,xmax);
	double bincontent=0;
	double binerror=0;
	double bincontentreflect=0;
	double binerrorreflect=0;
	for(int ii=1; ii<=nbins; ii++){    
	  bincontent=tmp->GetBinContent(ii);
	  binerror=tmp->GetBinError(ii);
	  bincontentreflect=tmp->GetBinContent(nbins-ii+1);
	  binerrorreflect=tmp->GetBinError(nbins-ii+1);
	  myraphistodd_ar[i]->SetBinContent(ii,(bincontent-bincontentreflect)/2.0);
	  myraphistodd_ar[i]->SetBinError(ii,binerror);
	} //ii
	tmp->Reset();
	// don't do a reset on tmp2
      } // j=3
      // If you don't do the clone thing, tmp for j=4 gives zeros
      if(j==4){
	tmp2 = (TProfile *) fin_ar[i]->Get(histchr);
	tmp = (TProfile *) tmp2->Clone();
	int nbins=tmp->GetXaxis()->GetNbins();
	double xmin=tmp->GetXaxis()->GetXmin();
	double xmax=tmp->GetXaxis()->GetXmax();
	myraphisteven_ar[i] = new TH1D(namechr,namechr,nbins,xmin,xmax);
	double bincontent=0;
	double binerror=0;
	double bincontentreflect=0;
	double binerrorreflect=0;
	for(int ii=1; ii<=nbins; ii++){    
	  bincontent=tmp->GetBinContent(ii);
	  binerror=tmp->GetBinError(ii);
	  bincontentreflect=tmp->GetBinContent(nbins-ii+1);
	  binerrorreflect=tmp->GetBinError(nbins-ii+1);
	  myraphisteven_ar[i]->SetBinContent(ii,(bincontent+bincontentreflect)/2.0);
	  myraphisteven_ar[i]->SetBinError(ii,binerror);
	  //	  cout<<" 1-even bin content: "<<ii<<" "<<bincontent<<" "<<bincontentreflect<<" "<<bincontent+bincontentreflect<<" "<<myraphisteven_ar[i]->GetBinContent(ii)<<endl;;	  
	} //ii
	tmp->Reset();
	// don't do a reset on tmp2

	//	for(int ii=1; ii<=nbins; ii++){    
	//	  cout<<" 2-even bin content: "<<ii<<" "<<myraphisteven_ar[i]->GetBinContent(ii)<<endl;;
	//	} //ii
	
      } // j=4
      
    } // i (files)
  } // j type - rap, cent, pt, odd, even
  
  TFile *myfile = new TFile("plotallana7.root","RECREATE");
  for (int i=0; i<nfiles; i++){
    myraphist_ar[i]->Write();
    mycenthist_ar[i]->Write();
    mypthist_ar[i]->Write();
    myraphistodd_ar[i]->Write();    
    myraphisteven_ar[i]->Write();
  }

  TCanvas *c1 = new TCanvas("c1", "Canvas", 1000, 1000);
  myraphist_ar[0]->GetXaxis()->SetRangeUser(-1.,1.);
  myraphist_ar[0]->GetYaxis()->SetRangeUser(-0.04,0.04);
  myraphist_ar[0]->SetLineColor(kRed);
  myraphist_ar[0]->SetLineWidth(3);
  myraphist_ar[0]->Draw("hist L p");
  for (int i=1; i<nfiles; i++){
    if(i==1)myraphist_ar[i]->SetLineColor(kBlue);
    if(i==2)myraphist_ar[i]->SetLineColor(kMagenta);
    if(i==3)myraphist_ar[i]->SetLineColor(kBlack);
    if(i==4)myraphist_ar[i]->SetLineColor(kGray);
    if(i==5)myraphist_ar[i]->SetLineColor(kGreen);
    myraphist_ar[i]->SetLineWidth(3);
    myraphist_ar[i]->Draw("SAME hist L p");
  }
  c1->Print("v3_Jam_all_rapidity.png");

  TCanvas *c2 = new TCanvas("c2", "Canvas", 1000, 1000);
  mycenthist_ar[0]->GetXaxis()->SetRangeUser(0.,60.);
  mycenthist_ar[0]->GetYaxis()->SetRangeUser(-0.03,0.02);
  mycenthist_ar[0]->SetLineColor(kRed);
  mycenthist_ar[0]->SetLineWidth(3);
  mycenthist_ar[0]->Draw("hist L p");
  for (int i=1; i<nfiles; i++){
    if(i==1)mycenthist_ar[i]->SetLineColor(kBlue);
    if(i==2)mycenthist_ar[i]->SetLineColor(kMagenta);
    if(i==3)mycenthist_ar[i]->SetLineColor(kBlack);
    if(i==4)mycenthist_ar[i]->SetLineColor(kGray);
    if(i==5)mycenthist_ar[i]->SetLineColor(kGreen);
    mycenthist_ar[i]->SetLineWidth(3);
    mycenthist_ar[i]->Draw("SAME hist L p");
  }
  c2->Print("v3_Jam_all_centrality.png");

  TCanvas *c3 = new TCanvas("c3", "Canvas", 1000, 1000);
  mypthist_ar[0]->GetXaxis()->SetRangeUser(0.,2.);
  mypthist_ar[0]->GetYaxis()->SetRangeUser(-0.04,0.04);
  mypthist_ar[0]->SetLineColor(kRed);
  mypthist_ar[0]->SetLineWidth(3);
  mypthist_ar[0]->Draw("hist L p");
  for (int i=1; i<nfiles; i++){
    if(i==1)mypthist_ar[i]->SetLineColor(kBlue);
    if(i==2)mypthist_ar[i]->SetLineColor(kMagenta);
    if(i==3)mypthist_ar[i]->SetLineColor(kBlack);
    if(i==4)mypthist_ar[i]->SetLineColor(kGray);
    if(i==5)mypthist_ar[i]->SetLineColor(kGreen);
    mypthist_ar[i]->SetLineWidth(3);
    mypthist_ar[i]->Draw("SAME hist L p");
  }
  c3->Print("v3_Jam_all_pt.png");

  TCanvas *c4 = new TCanvas("c4", "Canvas", 1000, 1000);
  myraphist_ar[0]->GetXaxis()->SetRangeUser(-1.,1.);
  myraphist_ar[0]->GetYaxis()->SetRangeUser(-0.025,0.025);
  myraphist_ar[0]->SetLineColor(kRed);
  myraphist_ar[0]->SetLineWidth(3);
  myraphist_ar[0]->Draw("hist L p");
  for (int i=1; i<nfiles; i++){
    if(i==1)myraphist_ar[i]->SetLineColor(kBlue);
    if(i==2)myraphist_ar[i]->SetLineColor(kMagenta);
    if(i==3)myraphist_ar[i]->SetLineColor(kBlack);
    if(i==4)myraphist_ar[i]->SetLineColor(kGray);
    if(i==5)myraphist_ar[i]->SetLineColor(kGreen);
    myraphist_ar[i]->SetLineWidth(3);
    myraphist_ar[i]->Draw("SAME hist L p");
  }

  TLegend *prLegend = new TLegend(0.19, 0.10, 0.39, 0.3);
  prLegend->AddEntry(myraphist_ar[0], "3GeV");
  prLegend->AddEntry(myraphist_ar[1], "3.2GeV");
  prLegend->AddEntry(myraphist_ar[2], "3.5GeV");
  prLegend->AddEntry(myraphist_ar[3], "3.9GeV");
  prLegend->AddEntry(myraphist_ar[4], "4.5GeV");
  prLegend->AddEntry(myraphist_ar[5], "3GeV cascade");
  prLegend->SetBorderSize(0);
  prLegend->SetFillColorAlpha(0,0);
  prLegend->SetTextSize(0.04);
  prLegend->Draw();
  TLine *zeroLine_y_pr = new TLine(-1, 0, 1, 0);
  zeroLine_y_pr->SetLineStyle(9);
  zeroLine_y_pr->SetLineWidth(3);
  zeroLine_y_pr->Draw();
  c4->Print("v3_Jam_all_rapidity_legend.png");

  TCanvas *c5 = new TCanvas("c5", "Canvas", 1000, 1000);
  myraphistodd_ar[0]->GetXaxis()->SetRangeUser(-1.,1.);
  myraphistodd_ar[0]->GetYaxis()->SetRangeUser(-0.025,0.025);
  myraphistodd_ar[0]->SetLineColor(kRed);
  myraphistodd_ar[0]->SetLineWidth(3);
  myraphistodd_ar[0]->Draw("hist L p");
  for (int i=1; i<nfiles; i++){
    if(i==1)myraphistodd_ar[i]->SetLineColor(kBlue);
    if(i==2)myraphistodd_ar[i]->SetLineColor(kMagenta);
    if(i==3)myraphistodd_ar[i]->SetLineColor(kBlack);
    if(i==4)myraphistodd_ar[i]->SetLineColor(kGray);
    if(i==5)myraphistodd_ar[i]->SetLineColor(kGreen);
    myraphistodd_ar[i]->SetLineWidth(3);
    myraphistodd_ar[i]->Draw("SAME hist L p");
  }

  prLegend->Draw();
  zeroLine_y_pr->SetLineStyle(9);
  zeroLine_y_pr->SetLineWidth(3);
  zeroLine_y_pr->Draw();
  c5->Print("v3_Jam_all_rapidity_odd.png");

  TCanvas *c6 = new TCanvas("c6", "Canvas", 1000, 1000);
  myraphisteven_ar[0]->GetXaxis()->SetRangeUser(-1.,1.);
  myraphisteven_ar[0]->GetYaxis()->SetRangeUser(-0.025,0.025);
  myraphisteven_ar[0]->SetLineColor(kRed);
  myraphisteven_ar[0]->SetLineWidth(3);
  myraphisteven_ar[0]->Draw("hist L p");
  for (int i=1; i<nfiles; i++){
    if(i==1)myraphisteven_ar[i]->SetLineColor(kBlue);
    if(i==2)myraphisteven_ar[i]->SetLineColor(kMagenta);
    if(i==3)myraphisteven_ar[i]->SetLineColor(kBlack);
    if(i==4)myraphisteven_ar[i]->SetLineColor(kGray);
    if(i==5)myraphisteven_ar[i]->SetLineColor(kGreen);
    myraphisteven_ar[i]->SetLineWidth(3);
    myraphisteven_ar[i]->Draw("SAME hist L p");
  }
  prLegend->Draw();
  zeroLine_y_pr->SetLineStyle(9);
  zeroLine_y_pr->SetLineWidth(3);
  zeroLine_y_pr->Draw();
  c6->Print("v3_Jam_all_rapidity_even.png");
  
  myfile->Close();
  std::cout << "Histograms saved to plotallana7_hists.root" << std::endl;
  
}  

