// for looking at v3
// load c++ and c headers
#include <stdio.h>
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

void plotit(string histstr, TFile *fc, TCanvas *c1, int ipad=1);

void ploteps(string histstr,string histstrepsx,string histstrepsy,string histsqrrsq2, TFile *fc, TCanvas *c1, int ipad=1);

void ploteps2(string histstr,string histstrepsx,string histstrepsy,string histsqrrsq2, TFile *fc, TCanvas *c2, int ipad=1, bool isame=false, int icol=1, double xhistmin=0., double xhistmax=1., double yhistmin=0., double yhistmax=1.);


void plotjam1xy6 (string dirstr="../3p0",string filestr = "jam1_3_b0-14_RQMDS_all.root", string labelstr="JAM1_RQMD.RMF:_NS2") {

  cout<<" LABEL = "<<labelstr<<endl;
  
  string histstr;
  string histsqrrsq2;
  string histstrepsx;
  string histstrepsy;
  string histsqrrsq;

  double labelsize=0.04;
  double titlesize=0.05;
  double titleoffsetx=0.9;
  double titleoffsety=1.2;

  string datafilename=dirstr+"/"+filestr;
  
  char dat1[50];
  strcpy(dat1,datafilename.c_str());

  char dat2[50];
  strcpy(dat2,labelstr.c_str());

  cout << "Input file  " << dat1 << endl;
  
  TFile *fc = new TFile(dat1,"read");
  TCanvas *c1 = new TCanvas("c1","c1",0,0,1500,1200);
  c1->Divide(5,4);
  //  c1->Divide(2,2);

  c1->SetTicks();
  c1->SetLeftMargin(0.15);
  c1->SetTopMargin(0.04);
  c1->SetRightMargin(0.04);
  c1->SetBottomMargin(0.1);
  c1->cd();

  gStyle->SetErrorX(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(6);
  gStyle->SetLineWidth(3);

  
  int ipad=0;
  
  histstr="xvsy_p_pt0_binm4";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt0_binm3";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt0_binm2";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt0_binm1";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt0_bin0";
  ipad++;  plotit(histstr,fc,c1,ipad);

  histstr="xvsy_p_pt1_binm4";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt1_binm3";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt1_binm2";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt1_binm1";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt1_bin0";
  ipad++;  plotit(histstr,fc,c1,ipad);

  histstr="xvsy_p_pt2_binm4";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt2_binm3";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt2_binm2";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt2_binm1";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt2_bin0";
  ipad++;  plotit(histstr,fc,c1,ipad);

  histstr="xvsy_p_pt3_binm4";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt3_binm3";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt3_binm2";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt3_binm1";
  ipad++;  plotit(histstr,fc,c1,ipad);
  histstr="xvsy_p_pt3_bin0";
  ipad++;  plotit(histstr,fc,c1,ipad);

  c1->SaveAs("xy.png");
  //    c1->SaveAs("xyarray_jam.png");  

  //  TCanvas *c2 = new TCanvas("c2","c2",0,0,1000,1000);
  TCanvas *c2 = new TCanvas("c2","c2",1000,1000);
  ipad=1;

  c2->SetTicks();
  c2->SetLeftMargin(0.15);
  c2->SetTopMargin(0.04);
  c2->SetRightMargin(0.04);
  c2->SetBottomMargin(0.1);
  c2->cd();

  gStyle->SetErrorX(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(6);
  gStyle->SetLineWidth(3);

  cout<<"1"<<endl;
  
  histstr="eps_3_rapidity_ptcut1_cent_pr_h";
  cout<<"1a"<<endl;
  histstrepsx="eps_x_rapidity_ptcut1_cent_pr_h";
  cout<<"1b"<<endl;
  histstrepsy="eps_y_rapidity_ptcut1_cent_pr_h";
  cout<<"1c"<<endl;
  histsqrrsq2="rsq_rapidity_ptcut1_cent_pr_h";

  cout<<"2"<<endl;
  ploteps2(  histstr, histstrepsx, histstrepsy, histsqrrsq2, fc, c2, ipad, false, 2, -1.6, 1.6, -0.15, 0.15 ); // try what shinichi suggested 
  cout<<"3"<<endl;
  
histstr="eps_3_rapidity_ptcut1_mid_pr_h";
  histstrepsx="eps_x_rapidity_ptcut1_mid_pr_h";
  histstrepsy="eps_y_rapidity_ptcut1_mid_pr_h";
  histsqrrsq2="rsq_rapidity_ptcut1_mid_pr_h";
  ploteps2(  histstr, histstrepsx, histstrepsy, histsqrrsq2, fc, c2, ipad, true, 1, -1.6, 1.6, 0., 0.15);
 
  histstr="eps_3_rapidity_ptcut1_periph_pr_h";
  histstrepsx="eps_x_rapidity_ptcut1_periph_pr_h";
  histstrepsy="eps_y_rapidity_ptcut1_periph_pr_h";
  histsqrrsq2="rsq_rapidity_ptcut1_periph_pr_h";
  ploteps2(  histstr, histstrepsx, histstrepsy, histsqrrsq2, fc, c2, ipad, true, 4, -1.6, 1.6, 0., 0.15);

  TH1D *h1 =(TH1D*)gDirectory->FindObject("eps_3_rapidity_ptcut1_cent_pr_h");
  TH1D *h2 =(TH1D*)gDirectory->FindObject("eps_3_rapidity_ptcut1_mid_pr_h");
  TH1D *h3 =(TH1D*)gDirectory->FindObject("eps_3_rapidity_ptcut1_periph_pr_h");
  h1->SetTitle("; y-y_{mid}; #epsilon_{3}");
  h1->SetTitleSize(titlesize,"xy");
  h1->GetXaxis()->SetNdivisions(505);
  h1->GetXaxis()->SetLabelSize(labelsize);
  h1->GetYaxis()->SetLabelSize(labelsize);
  h1->GetXaxis()->SetTitleOffset(titleoffsetx);
  h1->GetXaxis()->SetTitleOffset(0.8);
  h1->GetYaxis()->SetTitleOffset(titleoffsety);
  // Make text boxes, legends, and line at zero
  TLegend *prLegend = new TLegend(0.19, 0.15, 0.39, 0.3);
  prLegend->AddEntry(h1, "0 - 10%");
  prLegend->AddEntry(h2, "10 - 40%");
  prLegend->AddEntry(h3, "40 - 60%");
  prLegend->SetBorderSize(0);
  prLegend->SetFillColorAlpha(0,0);
  prLegend->SetTextSize(0.04);

  //  TPaveText *prText_y = new TPaveText(-0.35, 0.048, 0.75, 0.075, "NB");
  TPaveText *prText_y = new TPaveText(-0.35, 0.06, 0.55, 0.10, "NB");
  prText_y->AddText("Protons #epsilon_{3}");
  //  prText_y->AddText("  ");
  prText_y->AddText("JAM");
  //  prText_y->AddText("  ");
  prText_y->AddText(dat2);
  prText_y->SetFillColorAlpha(0,0);
  prText_y->SetLineColorAlpha(0,0);
  prText_y->SetTextSize(.04);
  
  TLine *zeroLine_y_pr = new TLine(-1, 0, 1, 0);
  zeroLine_y_pr->SetLineStyle(9);
  zeroLine_y_pr->SetLineWidth(3);

  zeroLine_y_pr->Draw();
  prText_y->Draw();
  prLegend->Draw();

  TPaveText *prText_abc = new TPaveText(0.825, -0.145, 0.95, -0.125, "NB");
  prText_abc->AddText("(g)");
  prText_abc->SetFillColorAlpha(0,0);
  prText_abc->SetLineColorAlpha(0,0);
  prText_abc->SetTextSize(.05);
  //  prText_abc->Draw();
  
  c2->SaveAs("eps3_rapidity.png");
  
  TCanvas *c3 = new TCanvas("c3","c3",0,0,1000,1000);
  c3->SetTicks();
  c3->SetLeftMargin(0.15);
  c3->SetTopMargin(0.04);
  c3->SetRightMargin(0.04);
  c3->SetBottomMargin(0.1);
  c3->cd();
  
 histstr="eps_3_pt_ycut1_cent_pr_h"; 
 histstrepsx="eps_x_pt_ycut1_cent_pr_h";
 histstrepsy="eps_y_pt_ycut1_cent_pr_h"; 
 histsqrrsq2="rsq_pt_ycut1_cent_pr_h";
 ploteps2(  histstr, histstrepsx, histstrepsy, histsqrrsq2, fc, c3, ipad, false, 2, 0., 2., -0.05, 0.05); // try what shinichi suggested

histstr="eps_3_pt_ycut1_mid_pr_h";  
histstrepsx="eps_x_pt_ycut1_mid_pr_h";
  histstrepsy="eps_y_pt_ycut1_mid_pr_h";  
  histsqrrsq2="rsq_pt_ycut1_mid_pr_h";
  ploteps2(  histstr, histstrepsx, histstrepsy, histsqrrsq2, fc, c3, ipad, true, 1, -1., 1., 0., 0.15);

histstr="eps_3_pt_ycut1_periph_pr_h";
  histstrepsx="eps_x_pt_ycut1_periph_pr_h";
  histstrepsy="eps_y_pt_ycut1_periph_pr_h";
  histsqrrsq2="rsq_pt_ycut1_periph_pr_h";
  ploteps2(  histstr, histstrepsx, histstrepsy, histsqrrsq2, fc, c3, ipad, true, 4, -1., 1., 0., 0.15);

  TH1D *h4 =(TH1D*)gDirectory->FindObject("eps_3_pt_ycut1_cent_pr_h");
  TH1D *h5 =(TH1D*)gDirectory->FindObject("eps_3_pt_ycut1_mid_pr_h");
  TH1D *h6 =(TH1D*)gDirectory->FindObject("eps_3_pt_ycut1_periph_pr_h");
  h4->SetTitle("; p_{T}(GeV/c); #epsilon_{3}");
  h4->SetTitleSize(titlesize,"xy");
  h4->GetXaxis()->SetNdivisions(505);
  h4->GetXaxis()->SetLabelSize(labelsize);
  h4->GetYaxis()->SetLabelSize(labelsize);
  h4->GetXaxis()->SetTitleOffset(titleoffsetx);
  h4->GetYaxis()->SetTitleOffset(titleoffsety);
  // Make text boxes, legends, and line at zero
  TLegend *prLegend2 = new TLegend(0.19, 0.15, 0.39, 0.3);
  prLegend2->AddEntry(h4, "0 - 10%");
  prLegend2->AddEntry(h5, "10 - 40%");
  prLegend2->AddEntry(h6, "40 - 60%");
  prLegend2->SetBorderSize(0);
  prLegend2->SetFillColorAlpha(0,0);
  prLegend2->SetTextSize(0.04);

  TPaveText *prText_y2 = new TPaveText(0.19, 0.020, 1.75, 0.040, "NB");
  prText_y2->AddText("  ");
  prText_y2->AddText("Protons #epsilon_{3}");
  prText_y2->AddText("JAM");
  prText_y2->AddText(dat2);
  prText_y2->SetFillColorAlpha(0,0);
  prText_y2->SetLineColorAlpha(0,0);
  prText_y2->SetTextSize(.04);

  TLine *zeroLine_y_pr2 = new TLine(0, 0, 2, 0);
  zeroLine_y_pr2->SetLineStyle(9);
  zeroLine_y_pr2->SetLineWidth(3);

  zeroLine_y_pr2->Draw();
  prText_y2->Draw();
  prLegend2->Draw();

  TPaveText *prText_abc2 = new TPaveText(1.85, -0.047, 1.95, -0.044, "NB");
  prText_abc2->AddText("(h)");
  prText_abc2->SetFillColorAlpha(0,0);
  prText_abc2->SetLineColorAlpha(0,0);
  prText_abc2->SetTextSize(.05);
  //  prText_abc2->Draw(); 
  
  c3->SaveAs("eps3_pt.png");
  
  TCanvas *c4 = new TCanvas("c4","c4",0,0,1000,1000);

  c4->SetTicks();
  c4->SetLeftMargin(0.15);
  c4->SetTopMargin(0.04);
  c4->SetRightMargin(0.04);
  c4->SetBottomMargin(0.1);
  c4->cd();

  histstr="eps_3_b_ycut1_ptcut1_pr_h"; 
  histstrepsx="eps_x_b_ycut1_ptcut1_pr_h";
  histstrepsy="eps_y_b_ycut1_ptcut1_pr_h";
  histsqrrsq2="rsq_b_ycut1_ptcut1_pr_h";
  ploteps2(  histstr, histstrepsx, histstrepsy, histsqrrsq2, fc, c4, ipad, false, 2, 0., 180., -0.05, 0.05); // try what shinichi suggested

  TH1D *h7 =(TH1D*)gDirectory->FindObject("eps_3_b_ycut1_ptcut1_pr_h");

  // note b^2=106. is at 60%
  int inumbins=h7->FindBin(106.)-1;
  // we need to transfer this into another histogram to plot
  c4->Clear();
  TH1F *eps_3_b_ycut1_ptcut1_pr_a = new TH1F("eps_3_b_ycut1_ptcut1_pr_a","eps_3_b_ycut1_ptcut1_pr_a",inumbins,0.,60.);  
  float bincontent=0;
  for(int ii=1; ii<inumbins+1; ii++){
    bincontent=h7->GetBinContent(ii);    //pip
    eps_3_b_ycut1_ptcut1_pr_a->SetBinContent(ii,bincontent);    //pip
  }
  eps_3_b_ycut1_ptcut1_pr_a->SetTitle(";Centrality(%); #epsilon_{3}");
  eps_3_b_ycut1_ptcut1_pr_a->SetTitleSize(titlesize,"xy");
  eps_3_b_ycut1_ptcut1_pr_a->GetXaxis()->SetNdivisions(505);
  eps_3_b_ycut1_ptcut1_pr_a->GetXaxis()->SetLabelSize(labelsize);
  eps_3_b_ycut1_ptcut1_pr_a->GetYaxis()->SetLabelSize(labelsize);
  eps_3_b_ycut1_ptcut1_pr_a->GetXaxis()->SetTitleOffset(titleoffsetx);
  eps_3_b_ycut1_ptcut1_pr_a->GetYaxis()->SetTitleOffset(titleoffsety);
  eps_3_b_ycut1_ptcut1_pr_a->SetLineColor(2);
  eps_3_b_ycut1_ptcut1_pr_a->SetLineWidth(4);
  eps_3_b_ycut1_ptcut1_pr_a->SetMinimum(-0.05);
  eps_3_b_ycut1_ptcut1_pr_a->SetMaximum(0.05);
  
  TPaveText *prText_y3 = new TPaveText(25.19, 0.020, 35.75, 0.040, "NB");
  prText_y3->AddText("  ");
  prText_y3->AddText("Protons #epsilon_{3}");
  prText_y3->AddText("JAM");
  prText_y3->AddText(dat2);
  prText_y3->SetFillColorAlpha(0,0);
  prText_y3->SetLineColorAlpha(0,0);
  prText_y3->SetTextSize(.04);

  TLine *zeroLine_y_pr3 = new TLine(0, 0, 60, 0);
  zeroLine_y_pr3->SetLineStyle(9);
  zeroLine_y_pr3->SetLineWidth(3);

  eps_3_b_ycut1_ptcut1_pr_a->Draw("HIST L P");
  zeroLine_y_pr3->Draw();
  prText_y3->Draw();

  TPaveText *prText_abc3 = new TPaveText(56., -0.047, 58., -0.044, "NB");
  prText_abc3->AddText("(i)");
  prText_abc3->SetFillColorAlpha(0,0);
  prText_abc3->SetLineColorAlpha(0,0);
  prText_abc3->SetTextSize(.05);
  //  prText_abc3->Draw();
  
  c4->SaveAs("eps3_b.png");
  cout<<"2"<<endl;
  exit(0);
  return true;
}  


void plotit(string histstr, TFile *fc, TCanvas *c1, int ipad=1){
  char histname[50];
  TH2D *hist;
  strcpy(histname,histstr.c_str());
  cout<<" histname="<<histstr<<endl;
  hist = (TH2D*) fc->Get(histname);
  double rang=40.;
  hist->GetXaxis()->SetRangeUser(-rang,rang);
  hist->GetYaxis()->SetRangeUser(-rang,rang);
  hist->SetTitleSize(0.1);
  hist->SetTitleOffset(-0.5);
  if(ipad==1) hist->SetTitle("-1.2<y<-0.85 0<p_{T}<0.1");
  if(ipad==2) hist->SetTitle("-0.85<y<-0.6 0<p_{T}<0.1");
  if(ipad==3) hist->SetTitle("-0.6<y<-0.35 0<p_{T}<0.1");
  if(ipad==4) hist->SetTitle("-0.35<y<-0.1 0<p_{T}<0.1");
  if(ipad==5) hist->SetTitle("-0.10<y<0.1 0<p_{T}<0.1");

  if(ipad==6) hist->SetTitle("-1.2<y<-0.85 0.1<p_{T}<0.25");
  if(ipad==7) hist->SetTitle("-0.85<y<-0.6 0.1<p_{T}<0.25");
  if(ipad==8) hist->SetTitle("-0.6<y<-0.35 0.1<p_{T}<0.25");
  if(ipad==9) hist->SetTitle("-0.35<y<-0.1 0.1<p_{T}<0.25");
  if(ipad==10) hist->SetTitle("-0.1<y<0.1 0.1<p_{T}<0.25");

  if(ipad==11) hist->SetTitle("-1.2<y<-0.85 0.25<p_{T}<1");
  if(ipad==12) hist->SetTitle("-0.85<y<-0.6 0.25<p_{T}<1");
  if(ipad==13) hist->SetTitle("-0.6<y<-0.35 0.25<p_{T}<1");
  if(ipad==14) hist->SetTitle("-0.35<y<-0.1 0.25<p_{T}<1");
  if(ipad==15) hist->SetTitle("-0.1<y<0.1 0.25<p_{T}<1");

  if(ipad==16) hist->SetTitle("-1.2<y<-0.85 1<p_{T}<3");
  if(ipad==17) hist->SetTitle("-0.85<y<-0.6 1<p_{T}<3");
  if(ipad==18) hist->SetTitle("-0.6<y<-0.35 1<p_{T}<3");
  if(ipad==19) hist->SetTitle("-0.35<y<-0.1 1<p_{T}<3");
  if(ipad==20) hist->SetTitle("-0.1<y<0.1 1<p_{T}<3");

  hist->GetXaxis()->SetTitle("x(fm)");
  hist->GetXaxis()->SetTitleSize(0.07);
  hist->GetXaxis()->SetTitleOffset(0.65);
  hist->GetXaxis()->SetLabelSize(0.06);
  hist->GetXaxis()->SetLabelOffset(0.005);
  
  hist->GetYaxis()->SetTitle("y(fm)");
  hist->GetYaxis()->SetTitleSize(0.07);
  hist->GetYaxis()->SetTitleOffset(0.65);
  hist->GetYaxis()->SetLabelSize(0.06);
  hist->GetYaxis()->SetLabelOffset(0.005);
  
  double xmean=hist->GetMean(1);
  double ymean=hist->GetMean(2);
  double xRMS=hist->GetRMS(1);
  double yRMS=hist->GetRMS(2);
  
  double xcentr=xmean;
  double ycentr=ymean;
  double radx=2*xRMS;
  double rady=2*xRMS;

  cout<<" x= "<<xcentr<<" y="<<ycentr<<" r="<<radx<<endl;
  
  //  TMarker *centr = new TMarker(xcentr,ycentr, 8);
  TMarker *centr = new TMarker(0.,0., 8);
  centr->SetMarkerColorAlpha(kRed, 1.0);
  centr->SetMarkerSize(0.8);

  TEllipse *circl = new TEllipse(xcentr,ycentr,radx,rady);
  circl->SetLineColor(kRed);
  circl->SetLineWidth(3);
  circl->SetLineStyle(2);
  circl->SetFillStyle(0);
  
  
  c1->cd(ipad);
  hist->Draw("colz");
  centr->Draw();
  //  circl->Draw();
}

void ploteps(string histstr,string histstrepsx,string histstrepsy,string histsqrrsq2, TFile *fc, TCanvas *c2, int ipad=1){
  char histname[50];
  //  TProfile *hist;
  TProfile *histepsx;
  TProfile *histepsy;
  TProfile *histrsq;


  strcpy(histname,histstrepsx.c_str());
  cout<<" histname epsx="<<histstrepsx<<endl;
  histepsx = (TProfile*) fc->Get(histname);

  strcpy(histname,histstrepsy.c_str());
  cout<<" histname epsy="<<histstrepsy<<endl;
  histepsy = (TProfile*) fc->Get(histname);

  strcpy(histname,histsqrrsq2.c_str());
  cout<<" histname rsq="<<histsqrrsq2<<endl;
  histrsq = (TProfile*) fc->Get(histname);

  strcpy(histname,histstr.c_str());
  cout<<" histname="<<histstr<<endl;
  //  hist = (TProfile*) fc->Get(histname);
  //  TProfile *hist = (TProfile*)histepsx->Clone(histname);

  histepsx->Sumw2();
  histepsy->Sumw2();
  histrsq->Sumw2();
  
  int nbins = histepsx->GetNbinsX();
  double xmin=histepsx->GetXaxis()->GetXmin();
  double xmax=histepsx->GetXaxis()->GetXmax();
  cout<<" nbins="<<nbins<<" min max ="<<xmin<<" "<<xmax<<endl;
  
  strcpy(histname,histstr.c_str());
  TH1D *hist = new TH1D(histname,histname,nbins,xmin,xmax);
  hist->Sumw2();
  
  for(int i=1; i<=nbins; i++){
    double epsx=histepsx->GetBinContent(i);
        double epsx_err=histepsx->GetBinError(i);
    double epsy=histepsy->GetBinContent(i);
        double epsy_err=histepsy->GetBinError(i);
    double rsq=histrsq->GetBinContent(i);
        double rsq_err=histrsq->GetBinError(i);
    double eps3=0;
    if(rsq!=0.) eps3=sqrt(epsx*epsx+epsy*epsy)/rsq;
    double err=0.1;
    double ferr1=epsx_err*epsx_err*epsx*epsx+epsy_err*epsy_err*epsy*epsy;
    ferr1=ferr1/(epsx*epsx+epsy*epsy)/(epsx*epsx+epsy*epsy);
    double ferr=sqrt(ferr1+rsq_err*rsq_err/rsq/rsq);
    if(rsq!=0.)err=eps3*ferr;
    cout<<" eps3 ="<<eps3<<" err= "<<err<<" epsx="<<epsx<<"+-"<<epsx_err
	<<" epsy="<<epsy<<"+-"<<epsy_err<<" rsq="<<rsq<<"+-"<<rsq_err<<endl;
    hist->SetBinContent(i,eps3);
    hist->SetBinError(i,err);    
  }
  
  /*
  histepsx->Multiply(histepsx,histepsx,1.,1.);
  histepsy->Multiply(histepsy,histepsy,1.,1.);
  histrsq->Multiply(histrsq,histrsq,1.,1.);
  hist->Add(histepsx,histepsy,1.,1.);
  hist->Divide(hist,histrsq,1.,1.);
  */    
  //  TProfile *hist = (histepsx*histepsx+histepsy*histepsy)/(histrsq*histrsq);
  //  TProfile *hist = histepsx*histepsx;
  /*

  hist->GetXaxis()->SetRangeUser(-rang,rang);
  hist->GetYaxis()->SetRangeUser(-rang,rang);
  */
  
  double rang=1000.;
  histepsx->SetMaximum(rang);
  histepsx->SetMinimum(-rang);
  
  //  if(gDirectory->FindObject(histepsx))printf("%s exits \n",histepsx);
  //  else printf("%s doesn't exist \n",histepsx);
  
  c2->cd(ipad);
  hist->Draw("E");
}

void ploteps2(string histstr,string histstrepsx,string histstrepsy,string histsqrrsq2, TFile *fc, TCanvas *c2, int ipad=1, bool isame=false, int icol=1, double xhistmin=0., double xhistmax=1., double yhistmin=0., double yhistmax=1.){
  cout<<" in ploteps2"<<endl;
  char histname[50];
  //  TProfile *hist;
  TProfile *histepsx;
  TProfile *histepsy;
  TProfile *histrsq;

  cout<<" in ploteps2"<<endl;
  
  strcpy(histname,histstrepsx.c_str());
  cout<<" histname epsx="<<histstrepsx<<endl;
  histepsx = (TProfile*) fc->Get(histname);

  cout<<" ploteps2 - 1"<<endl;
  
  if(gDirectory->FindObject(histepsx))
    printf("%s exits \n",histname);
  else
    {printf("%s doesn't exist \n",histname);
    }
  
  strcpy(histname,histstrepsy.c_str());
  cout<<" histname epsy="<<histstrepsy<<endl;
  histepsy = (TProfile*) fc->Get(histname);

  strcpy(histname,histsqrrsq2.c_str());
  cout<<" histname rsq="<<histsqrrsq2<<endl;
  histrsq = (TProfile*) fc->Get(histname);

  strcpy(histname,histstr.c_str());
  cout<<" histname="<<histstr<<endl;
  //  hist = (TProfile*) fc->Get(histname);
  //  TProfile *hist = (TProfile*)histepsx->Clone(histname);

  histepsx->Sumw2();
  histepsy->Sumw2();
  histrsq->Sumw2();
  
  int nbins = histepsx->GetNbinsX();
  double xmin=histepsx->GetXaxis()->GetXmin();
  double xmax=histepsx->GetXaxis()->GetXmax();
  cout<<" nbins="<<nbins<<" min max ="<<xmin<<" "<<xmax<<endl;
  
  strcpy(histname,histstr.c_str());
  TH1D *hist = new TH1D(histname,histname,nbins,xmin,xmax);
  hist->Sumw2();
  
  for(int i=1; i<=nbins; i++){
    double epsx=histepsx->GetBinContent(i);
        double epsx_err=histepsx->GetBinError(i);
    double epsy=histepsy->GetBinContent(i);
        double epsy_err=histepsy->GetBinError(i);
    double rsq=histrsq->GetBinContent(i);
        double rsq_err=histrsq->GetBinError(i);
    double eps3=0;

    //    if(rsq!=0.) eps3=sqrt(epsx*epsx+epsy*epsy)/rsq;
    if(rsq!=0.) eps3=epsx/rsq;   // try what shinichi suggested

    double err=0.1;
    double ferr1=epsx_err*epsx_err*epsx*epsx+epsy_err*epsy_err*epsy*epsy;
    ferr1=ferr1/(epsx*epsx+epsy*epsy)/(epsx*epsx+epsy*epsy);
    double ferr=sqrt(ferr1+rsq_err*rsq_err/rsq/rsq);
    if(rsq!=0.)err=eps3*ferr;
    //    cout<<" eps3 ="<<eps3<<" err= "<<err<<" epsx="<<epsx<<"+-"<<epsx_err
    //	<<" epsy="<<epsy<<"+-"<<epsy_err<<" rsq="<<rsq<<"+-"<<rsq_err<<endl;
    hist->SetBinContent(i,eps3);
    hist->SetBinError(i,err);    
  }
  
  /*
  histepsx->Multiply(histepsx,histepsx,1.,1.);
  histepsy->Multiply(histepsy,histepsy,1.,1.);
  histrsq->Multiply(histrsq,histrsq,1.,1.);
  hist->Add(histepsx,histepsy,1.,1.);
  hist->Divide(hist,histrsq,1.,1.);
  */    
  //  TProfile *hist = (histepsx*histepsx+histepsy*histepsy)/(histrsq*histrsq);
  //  TProfile *hist = histepsx*histepsx;
  /*

  hist->GetXaxis()->SetRangeUser(-rang,rang);
  hist->GetYaxis()->SetRangeUser(-rang,rang);
  */

  cout<<" isame="<<isame<<endl;

  hist->SetLineColor(icol);
  hist->SetLineWidth(4);
  if(!isame){
  c2->cd(ipad);
    hist->GetXaxis()->SetRangeUser(xhistmin,xhistmax);
    hist->SetMinimum(yhistmin);
    hist->SetMaximum(yhistmax);    
    //    hist->Draw("E");
    hist->Draw("HIST L P");
  }else{
    //    hist->Draw("SAME");
    hist->Draw("HIST L P SAME");
  }

}
