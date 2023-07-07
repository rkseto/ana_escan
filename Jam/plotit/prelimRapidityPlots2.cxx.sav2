#include "PlotUtils.h"

void prelimRapidityPlots2(int ido=1, string dat2s="JAM1 3 GeV - hard2 potential b=0-14")
{
  char *dat2;
  dat2 = &dat2s[0];
  
  TString fileName = "Normal.picoDst.result.combined.root";
  TFile *file = TFile::Open(fileName);
  if(!file) {cout << "Wrong Cameron file!" << endl; return;}

  TCanvas *canvas = new TCanvas("canvas", "Canvas", 1000, 1000);
  //canvas->SetGrid();
  canvas->SetTicks();
  canvas->SetLeftMargin(0.15);
  canvas->SetTopMargin(0.04);
  canvas->SetRightMargin(0.04);
  canvas->SetBottomMargin(0.1);
  canvas->cd();

  gStyle->SetErrorX(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(6);
  gStyle->SetLineWidth(3);

  TProfile2D *p2_vn_yCM_cent_pr = (TProfile2D*)file->Get("p2_vn_yCM_cent_pr");
  TProfile2D *p2_vn_yCM_cent_pr_symmetry = (TProfile2D*)file->Get("p2_vn_yCM_cent_pr_symmetry");

  TProfile *p_vn_yCM_00to10_pr = p2_vn_yCM_cent_pr->ProfileY("p_vn_yCM_00to10_pr", 15, 16);
  TProfile *p_vn_yCM_10to40_pr = p2_vn_yCM_cent_pr->ProfileY("p_vn_yCM_10to40_pr", 9, 14);
  TProfile *p_vn_yCM_40to60_pr = p2_vn_yCM_cent_pr->ProfileY("p_vn_yCM_40to60_pr", 5, 8);
  TProfile *p_vn_yCM_00to10_pr_symm = p2_vn_yCM_cent_pr_symmetry->ProfileY("p_vn_yCM_00to10_pr_symm", 15, 16);
  TProfile *p_vn_yCM_10to40_pr_symm = p2_vn_yCM_cent_pr_symmetry->ProfileY("p_vn_yCM_10to40_pr_symm", 9, 14);
  TProfile *p_vn_yCM_40to60_pr_symm = p2_vn_yCM_cent_pr_symmetry->ProfileY("p_vn_yCM_40to60_pr_symm", 5, 8);

  TH1D *h_vn_yCM_00to10_pr = new TH1D("h_vn_yCM_00to10_pr", ";y-y_{mid};v_{3}", 20, -1, 1);
  TH1D *h_vn_yCM_10to40_pr = new TH1D("h_vn_yCM_10to40_pr", ";y-y_{mid};v_{3}", 20, -1, 1);
  TH1D *h_vn_yCM_40to60_pr = new TH1D("h_vn_yCM_40to60_pr", ";y-y_{mid};v_{3}", 20, -1, 1);
  TH1D *h_vn_yCM_00to10_pr_symm = new TH1D("h_vn_yCM_00to10_pr_symm", ";y-y_{mid};v_{3}", 20, -1, 1);
  TH1D *h_vn_yCM_10to40_pr_symm = new TH1D("h_vn_yCM_10to40_pr_symm", ";y-y_{mid};v_{3}", 20, -1, 1);
  TH1D *h_vn_yCM_40to60_pr_symm = new TH1D("h_vn_yCM_40to60_pr_symm", ";y-y_{mid};v_{3}", 20, -1, 1);

  // Mirrored Plots
  TH1D *h_vn_yCM_00to10_pr_mirror = new TH1D("h_vn_yCM_00to10_pr_mirror", ";y-y_{mid};v_{3}", 20, -1, 1);
  TH1D *h_vn_yCM_10to40_pr_mirror = new TH1D("h_vn_yCM_10to40_pr_mirror", ";y-y_{mid};v_{3}", 20, -1, 1);
  TH1D *h_vn_yCM_40to60_pr_mirror = new TH1D("h_vn_yCM_40to60_pr_mirror", ";y-y_{mid};v_{3}", 20, -1, 1);

  // Convert profiles to histograms
  h_vn_yCM_00to10_pr = p_vn_yCM_00to10_pr->ProjectionX();
  h_vn_yCM_10to40_pr = p_vn_yCM_10to40_pr->ProjectionX();
  h_vn_yCM_40to60_pr = p_vn_yCM_40to60_pr->ProjectionX();
  h_vn_yCM_00to10_pr_symm = p_vn_yCM_00to10_pr_symm->ProjectionX();
  h_vn_yCM_10to40_pr_symm = p_vn_yCM_10to40_pr_symm->ProjectionX();
  h_vn_yCM_40to60_pr_symm = p_vn_yCM_40to60_pr_symm->ProjectionX();

  // Retrieve systematic uncertainties
  TFile* systematicFile = TFile::Open("systematicErrors.root", "READ");
  TGraphErrors* sys_yCM_00to10_pr = (TGraphErrors*)systematicFile->Get("Graph_from_p_vn_yCM_00to10_pr_px");
  TGraphErrors* sys_yCM_10to40_pr = (TGraphErrors*)systematicFile->Get("Graph_from_p_vn_yCM_10to40_pr_px");
  TGraphErrors* sys_yCM_40to60_pr = (TGraphErrors*)systematicFile->Get("Graph_from_p_vn_yCM_40to60_pr_px");
  TGraphErrors* sys_yCM_00to10_pr_symm = (TGraphErrors*)systematicFile->Get("Graph_from_p_vn_yCM_00to10_pr_symm_px");
  TGraphErrors* sys_yCM_10to40_pr_symm = (TGraphErrors*)systematicFile->Get("Graph_from_p_vn_yCM_10to40_pr_symm_px");
  TGraphErrors* sys_yCM_40to60_pr_symm = (TGraphErrors*)systematicFile->Get("Graph_from_p_vn_yCM_40to60_pr_symm_px");
  ////


  // Make mirrored plots
  for (int i = 1; i <= 20; i++)
    {
      int j = 0;  // mirrored bin
      
      switch(i)
	{
	case 11: j = 10; break;
	case 12: j = 9; break;
	case 13: j = 8; break;
	case 14: j = 7; break;
	case 15: j = 6; break;
	case 16: j = 5; break;
	case 17: j = 4; break;
	case 18: j = 3; break;
	case 19: j = 2; break;
	case 20: j = 1; break;
	}
      
      if(j != 0)
	{
	  h_vn_yCM_00to10_pr_mirror->SetBinContent(j, -h_vn_yCM_00to10_pr->GetBinContent(i));
	  h_vn_yCM_00to10_pr_mirror->SetBinError(j, h_vn_yCM_00to10_pr->GetBinError(i));
	  h_vn_yCM_10to40_pr_mirror->SetBinContent(j, -h_vn_yCM_10to40_pr->GetBinContent(i));
	  h_vn_yCM_10to40_pr_mirror->SetBinError(j, h_vn_yCM_10to40_pr->GetBinError(i));
	  h_vn_yCM_40to60_pr_mirror->SetBinContent(j, -h_vn_yCM_40to60_pr->GetBinContent(i));
	  h_vn_yCM_40to60_pr_mirror->SetBinError(j, h_vn_yCM_40to60_pr->GetBinError(i));
	}
    }

  int j = 19;
  for (int i = 0; i < 10; i++)
    {
      sys_yCM_00to10_pr->SetPointY(i, -sys_yCM_00to10_pr->GetPointY(j));
      sys_yCM_00to10_pr->SetPointError(i,0.0, sys_yCM_00to10_pr->GetErrorY(j));
      sys_yCM_10to40_pr->SetPointY(i, -sys_yCM_10to40_pr->GetPointY(j));
      sys_yCM_10to40_pr->SetPointError(i,0.0, sys_yCM_10to40_pr->GetErrorY(j));
      sys_yCM_40to60_pr->SetPointY(i, -sys_yCM_40to60_pr->GetPointY(j));
      sys_yCM_40to60_pr->SetPointError(i,0.0, sys_yCM_40to60_pr->GetErrorY(j));
      j--;
    }

  int whitecolor=19;  
  // Set various aesthetics
  h_vn_yCM_00to10_pr->SetMarkerStyle(21);
  h_vn_yCM_10to40_pr->SetMarkerStyle(20);
  h_vn_yCM_40to60_pr->SetMarkerStyle(22);
  h_vn_yCM_00to10_pr->SetMarkerColor(whitecolor);
  h_vn_yCM_10to40_pr->SetMarkerColor(whitecolor);
  h_vn_yCM_40to60_pr->SetMarkerColor(whitecolor);
  h_vn_yCM_00to10_pr->SetMarkerSize(2);
  h_vn_yCM_10to40_pr->SetMarkerSize(2);
  h_vn_yCM_40to60_pr->SetMarkerSize(2);
  h_vn_yCM_00to10_pr->SetLineColor(whitecolor);
  h_vn_yCM_10to40_pr->SetLineColor(whitecolor);
  h_vn_yCM_40to60_pr->SetLineColor(whitecolor);
  h_vn_yCM_00to10_pr->SetLineWidth(3);
  h_vn_yCM_10to40_pr->SetLineWidth(3);
  h_vn_yCM_40to60_pr->SetLineWidth(3);

  h_vn_yCM_00to10_pr_symm->SetMarkerStyle(21);
  h_vn_yCM_10to40_pr_symm->SetMarkerStyle(20);
  h_vn_yCM_40to60_pr_symm->SetMarkerStyle(22);
  h_vn_yCM_00to10_pr_symm->SetMarkerColor(whitecolor);
  h_vn_yCM_10to40_pr_symm->SetMarkerColor(whitecolor);
  h_vn_yCM_40to60_pr_symm->SetMarkerColor(whitecolor);
  h_vn_yCM_00to10_pr_symm->SetMarkerSize(2);
  h_vn_yCM_10to40_pr_symm->SetMarkerSize(2);
  h_vn_yCM_40to60_pr_symm->SetMarkerSize(2);
  h_vn_yCM_00to10_pr_symm->SetLineColor(whitecolor);
  h_vn_yCM_10to40_pr_symm->SetLineColor(whitecolor);
  h_vn_yCM_40to60_pr_symm->SetLineColor(whitecolor);
  h_vn_yCM_00to10_pr_symm->SetLineWidth(3);
  h_vn_yCM_10to40_pr_symm->SetLineWidth(3);
  h_vn_yCM_40to60_pr_symm->SetLineWidth(3);

  sys_yCM_00to10_pr->SetMarkerColor(whitecolor);
  sys_yCM_10to40_pr->SetMarkerColor(whitecolor);
  sys_yCM_40to60_pr->SetMarkerColor(whitecolor);
  sys_yCM_00to10_pr->SetLineColor(whitecolor);
  sys_yCM_10to40_pr->SetLineColor(whitecolor);
  sys_yCM_40to60_pr->SetLineColor(whitecolor);

  sys_yCM_00to10_pr_symm->SetMarkerColor(whitecolor);
  sys_yCM_10to40_pr_symm->SetMarkerColor(whitecolor);
  sys_yCM_40to60_pr_symm->SetMarkerColor(whitecolor);
  sys_yCM_00to10_pr_symm->SetLineColor(whitecolor);
  sys_yCM_10to40_pr_symm->SetLineColor(whitecolor);
  sys_yCM_40to60_pr_symm->SetLineColor(whitecolor);

  //  h_vn_yCM_00to10_pr_mirror->SetMarkerStyle(25);
  //  h_vn_yCM_10to40_pr_mirror->SetMarkerStyle(24);
  //  h_vn_yCM_40to60_pr_mirror->SetMarkerStyle(26);
  h_vn_yCM_00to10_pr_mirror->SetMarkerStyle(21);
  h_vn_yCM_10to40_pr_mirror->SetMarkerStyle(20);
  h_vn_yCM_40to60_pr_mirror->SetMarkerStyle(22);
  h_vn_yCM_00to10_pr_mirror->SetMarkerColor(whitecolor);
  h_vn_yCM_10to40_pr_mirror->SetMarkerColor(whitecolor);
  h_vn_yCM_40to60_pr_mirror->SetMarkerColor(whitecolor);
  h_vn_yCM_00to10_pr_mirror->SetMarkerSize(2);
  h_vn_yCM_10to40_pr_mirror->SetMarkerSize(2);
  h_vn_yCM_40to60_pr_mirror->SetMarkerSize(2);
  h_vn_yCM_00to10_pr_mirror->SetLineColor(whitecolor);
  h_vn_yCM_10to40_pr_mirror->SetLineColor(whitecolor);
  h_vn_yCM_40to60_pr_mirror->SetLineColor(whitecolor);
  h_vn_yCM_00to10_pr_mirror->SetLineWidth(3);
  h_vn_yCM_10to40_pr_mirror->SetLineWidth(3);
  h_vn_yCM_40to60_pr_mirror->SetLineWidth(3);
  ////


  THStack *prRapidityStack   = new THStack("prRapidityStack", ";y-y_{mid};v_{3} {#psi_{1} EP}");
  prRapidityStack->Add(h_vn_yCM_00to10_pr);
  prRapidityStack->Add(h_vn_yCM_40to60_pr);
  prRapidityStack->Add(h_vn_yCM_10to40_pr);
  prRapidityStack->Add(h_vn_yCM_00to10_pr_mirror);
  prRapidityStack->Add(h_vn_yCM_40to60_pr_mirror);
  prRapidityStack->Add(h_vn_yCM_10to40_pr_mirror);

  THStack *prRapidityStack_symm = new THStack("prRapidityStack_symm", ";y-y_{mid};v_{3} {#psi_{1} EP}");
  prRapidityStack_symm->Add(h_vn_yCM_00to10_pr_symm);
  prRapidityStack_symm->Add(h_vn_yCM_40to60_pr_symm);
  prRapidityStack_symm->Add(h_vn_yCM_10to40_pr_symm);
  

  // Make text boxes, legends, and line at zero
  TLegend *prLegend = new TLegend(0.19, 0.15, 0.39, 0.3);
  prLegend->AddEntry(h_vn_yCM_00to10_pr, "0 - 10%");
  prLegend->AddEntry(h_vn_yCM_10to40_pr, "10 - 40%");
  prLegend->AddEntry(h_vn_yCM_40to60_pr, "40 - 60%");
  prLegend->SetBorderSize(0);
  prLegend->SetFillColorAlpha(0,0);
  prLegend->SetTextSize(0.04);

  TLegend *prLegend_symm = new TLegend(0.19, 0.15, 0.39, 0.3);
  prLegend_symm->AddEntry(h_vn_yCM_00to10_pr_symm, "0 - 10%");
  prLegend_symm->AddEntry(h_vn_yCM_10to40_pr_symm, "10 - 40%");
  prLegend_symm->AddEntry(h_vn_yCM_40to60_pr_symm, "40 - 60%");
  prLegend_symm->SetBorderSize(0);
  prLegend_symm->SetFillColorAlpha(0,0);
  prLegend_symm->SetTextSize(0.04);

  TPaveText *prText_y = new TPaveText(-0.35, 0.048, 0.75, 0.075, "NB");
  prText_y->AddText("Proton");
  prText_y->AddText("Au+Au #sqrt{s_{NN}} = 3.0 GeV FXT (year 2018)");
  prText_y->AddText("0.4 #leq p_{T} #leq 2.0 GeV");
  prText_y->SetFillColorAlpha(0,0);
  prText_y->SetLineColorAlpha(0,0);
  prText_y->SetTextSize(.035);
 
  TPaveText *prText_y_symm = new TPaveText(-0.4, 0.045, 0.8, 0.075, "NB");
  prText_y_symm->AddText("Proton");
  prText_y_symm->AddText("Au+Au #sqrt{s_{NN}} = 3.0 GeV FXT (year 2018)");
  prText_y_symm->AddText("1.0 #leq p_{T} #leq 2.5 GeV");
  prText_y_symm->SetFillColorAlpha(0,0);
  prText_y_symm->SetLineColorAlpha(0,0);
  prText_y_symm->SetTextSize(.035);

  TPaveText* prelimText_symm = new TPaveText(-0.4, 0.03, 0.8, 0.05, "NB");
  prelimText_symm->AddText("STAR");
  prelimText_symm->SetTextColor(kRed);
  prelimText_symm->SetFillColorAlpha(0,0);
  prelimText_symm->SetTextSize(0.04);

  TPaveText* prelimText = new TPaveText(-0.2, 0.04, 0.6, 0.045, "NB");
  prelimText->AddText("STAR");
  prelimText->SetTextColor(kRed);
  prelimText->SetFillColorAlpha(0,0);
  prelimText->SetTextSize(0.04);

  TLine *zeroLine_y_pr = new TLine(-1, 0, 1, 0);
  zeroLine_y_pr->SetLineStyle(9);
  zeroLine_y_pr->SetLineWidth(3);
  ////

  prRapidityStack->Draw();
  prRapidityStack->GetYaxis()->SetLabelSize(0.043);
  prRapidityStack->GetXaxis()->SetLabelSize(0.043);
  prRapidityStack->GetYaxis()->SetTitleOffset(1.4);
  prRapidityStack->GetXaxis()->SetTitleOffset(1.0);
  prRapidityStack->GetXaxis()->SetNdivisions(210);
  prRapidityStack->GetXaxis()->SetTitleSize(0.045);
  prRapidityStack->GetYaxis()->SetTitleSize(0.05);
  prRapidityStack->Draw();
  prRapidityStack->SetMaximum(0.06);
  prRapidityStack->SetMinimum(-0.06);
  prRapidityStack->Draw("NOSTACK E1P");
  zeroLine_y_pr->Draw("SAME");
  prRapidityStack->Draw("NOSTACK E1P SAME");

  TPaveText *prText_urqmd = new TPaveText(-0.2, 0.025, 0.75, 0.03, "NB");
  // CHANGE FILE AND LABEL

  char dat1[100];
  strcpy(dat1,"jam1ana6.root"); //RKS  
  prText_urqmd->AddText(dat2); 
  cout << "Input file name = " << dat1 << endl;  //RKS
  cout << "Label = " << dat2 << endl;  //RKS

  TFile *fa = new TFile(dat1,"read");  //RKS
  if(!fa) {cout << "Wrong simulation file!" << endl; return;} //RKS
      
  TProfile *cth_3_rapidity_ptcut1_cent_pr_a = (TProfile*) fa->Get("cth_3_rapidity_ptcut1_cent_pr_h"); //RKS
  cth_3_rapidity_ptcut1_cent_pr_a->SetMaximum(0.08);
  cth_3_rapidity_ptcut1_cent_pr_a->SetMinimum(-0.08);
  cth_3_rapidity_ptcut1_cent_pr_a->SetAxisRange(-1.,0.99);
  cth_3_rapidity_ptcut1_cent_pr_a->SetMarkerColorAlpha(2,1.0);
  cth_3_rapidity_ptcut1_cent_pr_a->SetMarkerStyle(8);
  cth_3_rapidity_ptcut1_cent_pr_a->SetMarkerSize(1.2);
  cth_3_rapidity_ptcut1_cent_pr_a->SetLineColor(2);
  cth_3_rapidity_ptcut1_cent_pr_a->SetLineWidth(3);
  cth_3_rapidity_ptcut1_cent_pr_a->Draw("SAME hist L p");
  
  TProfile *cth_3_rapidity_ptcut1_periph_pr_a = (TProfile*) fa->Get("cth_3_rapidity_ptcut1_periph_pr_h"); //RKS
  cth_3_rapidity_ptcut1_periph_pr_a->SetMaximum(0.08);
  cth_3_rapidity_ptcut1_periph_pr_a->SetMinimum(-0.08);
  cth_3_rapidity_ptcut1_periph_pr_a->SetAxisRange(-1.,0.99);
  cth_3_rapidity_ptcut1_periph_pr_a->SetMarkerColorAlpha(8,1.0);
  cth_3_rapidity_ptcut1_periph_pr_a->SetMarkerStyle(8);
  cth_3_rapidity_ptcut1_periph_pr_a->SetMarkerSize(1.2);
  cth_3_rapidity_ptcut1_periph_pr_a->SetLineColor(8);
  cth_3_rapidity_ptcut1_periph_pr_a->SetLineWidth(3);
  cth_3_rapidity_ptcut1_periph_pr_a->Draw("SAME hist L p");
 
  TProfile *cth_3_rapidity_ptcut1_mid_pr_a = (TProfile*) fa->Get("cth_3_rapidity_ptcut1_mid_pr_h"); //RKS
  cth_3_rapidity_ptcut1_mid_pr_a->SetMaximum(0.08);
  cth_3_rapidity_ptcut1_mid_pr_a->SetMinimum(-0.08);
  cth_3_rapidity_ptcut1_mid_pr_a->SetAxisRange(-1.,0.99);
  cth_3_rapidity_ptcut1_mid_pr_a->SetMarkerColorAlpha(4,1.0);
  cth_3_rapidity_ptcut1_mid_pr_a->SetMarkerStyle(8);
  cth_3_rapidity_ptcut1_mid_pr_a->SetMarkerSize(1.2);
  cth_3_rapidity_ptcut1_mid_pr_a->SetLineColor(4);
  cth_3_rapidity_ptcut1_mid_pr_a->SetLineWidth(3);
  cth_3_rapidity_ptcut1_mid_pr_a->Draw("SAME hist L p");
  
  TF1 *f1 = new TF1("f1","[0]*x+[1]*x*x*x",-0.4,0.4);
  cth_3_rapidity_ptcut1_cent_pr_a->Fit("f1","R");
  double slopecent=f1->GetParameter(0);
  f1->SetLineColor(2);  
  f1->DrawCopy("SAME");
  cth_3_rapidity_ptcut1_periph_pr_a->Fit("f1","R");
  double slopeperiph=f1->GetParameter(0);
  f1->SetLineColor(8);  
  f1->DrawCopy("SAME");
  cth_3_rapidity_ptcut1_mid_pr_a->Fit("f1","R");
  double slopemid=f1->GetParameter(0);
  f1->SetLineColor(4);  
  f1->DrawCopy("SAME");
  cout<<" SLOPE = "<<slopecent<<" "<<slopemid<<" "<<slopeperiph<<endl;
  
  // Make legend for JAM1
  prText_urqmd->SetFillColorAlpha(0,0);
  prText_urqmd->SetLineColorAlpha(0,0);
  prText_urqmd->SetTextSize(.035);
  prText_urqmd->Draw();
  TLegend *prLegend2 = new TLegend(0.41, 0.15, 0.55, 0.3);
  char tempname[256];
  
  //  prLegend2->AddEntry(cth_3_rapidity_ptcut1_cent_pr_a, " JAM1 - 0% - 10%");
  sprintf(tempname,"JAM1 - 0 - 10%%,  slope=%4.3f",slopecent);
  prLegend2->AddEntry(cth_3_rapidity_ptcut1_cent_pr_a, tempname);

  //  prLegend2->AddEntry(cth_3_rapidity_ptcut1_mid_pr_a, " JAM1 - 10% - 40%");
  sprintf(tempname,"JAM1 - 10 - 40%%, slope=%4.3f",slopemid);
  prLegend2->AddEntry(cth_3_rapidity_ptcut1_mid_pr_a, tempname);

  //  prLegend2->AddEntry(cth_3_rapidity_ptcut1_periph_pr_a, " JAM1 - 40% - 60%");
  sprintf(tempname,"JAM1 - 40 - 60%%, slope=%4.3f",slopeperiph);
  prLegend2->AddEntry(cth_3_rapidity_ptcut1_periph_pr_a, tempname);

  prLegend2->SetBorderSize(0);
  prLegend2->SetFillColorAlpha(0,0);
  prLegend2->SetTextSize(0.03);
  prLegend2->Draw();

  
  sys_yCM_40to60_pr->Draw("[]");
  sys_yCM_00to10_pr->Draw("[]");
  sys_yCM_10to40_pr->Draw("[]");
  prLegend->Draw();
  prText_y->Draw();
  prelimText->Draw();
  canvas->SaveAs("v3_prRapidityStack.png");
  canvas->Clear();


  /*
  prRapidityStack_symm->Draw();
  prRapidityStack_symm->GetYaxis()->SetLabelSize(0.043);
  prRapidityStack_symm->GetXaxis()->SetLabelSize(0.043);
  prRapidityStack_symm->GetYaxis()->SetTitleOffset(1.4);
  prRapidityStack_symm->GetXaxis()->SetTitleOffset(1.0);
  prRapidityStack_symm->GetXaxis()->SetNdivisions(210);
  prRapidityStack_symm->GetXaxis()->SetTitleSize(0.045);
  prRapidityStack_symm->GetYaxis()->SetTitleSize(0.05);
  prRapidityStack_symm->Draw();
  prRapidityStack_symm->SetMaximum(0.08);
  prRapidityStack_symm->SetMinimum(-0.095);
  prRapidityStack_symm->Draw("NOSTACK E1P");
  zeroLine_y_pr->Draw("SAME");
  prRapidityStack_symm->Draw("NOSTACK E1P SAME");
  sys_yCM_00to10_pr_symm->Draw("[]");
  sys_yCM_10to40_pr_symm->Draw("[]");
  sys_yCM_40to60_pr_symm->Draw("[]");
  prLegend_symm->Draw();
  prText_y_symm->Draw();
  prelimText_symm->Draw();
  canvas->SaveAs("v3_prRapidityStack_symm.png");
  canvas->Clear();
  */

  systematicFile->Close();
  file->Close();

}
