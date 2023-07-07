void prelimPtPlots2(int ido=1, string dat2s="JAM1= 3 GeV - hard2 potential b=0-14")
{
  char *dat2;
  dat2 = &dat2s[0];

  TString fileName = "Normal.picoDst.result.combined.root";
  TFile *file = TFile::Open(fileName);
  if(!file) {std::cout << "Wrong file!" << std::endl; return;}

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

  TProfile2D *p2_vn_pT_cent_pr = (TProfile2D*)file->Get("p2_vn_pT_cent_pr");
  TProfile *p_vn_pT_00to10_pr = p2_vn_pT_cent_pr->ProfileY("p_vn_pT_00to10_pr", 15, 16);
  TProfile *p_vn_pT_10to40_pr = p2_vn_pT_cent_pr->ProfileY("p_vn_pT_10to40_pr", 9, 14);
  TProfile *p_vn_pT_40to60_pr = p2_vn_pT_cent_pr->ProfileY("p_vn_pT_40to60_pr", 5, 8);

  TH1D *h_vn_pT_00to10_pr = new TH1D("h_vn_pT_00to10_pr", ";p_{T} (GeV);v_{3}", 10, 0, 2);
  TH1D *h_vn_pT_10to40_pr = new TH1D("h_vn_pT_10to40_pr", ";p_{T} (GeV);v_{3}", 10, 0, 2);
  TH1D *h_vn_pT_40to60_pr = new TH1D("h_vn_pT_40to60_pr", ";p_{T} (GeV);v_{3}", 10, 0, 2);

  // Convert profiles to histograms
  h_vn_pT_00to10_pr = p_vn_pT_00to10_pr->ProjectionX();
  h_vn_pT_10to40_pr = p_vn_pT_10to40_pr->ProjectionX();
  h_vn_pT_40to60_pr = p_vn_pT_40to60_pr->ProjectionX();


  // Retrieve systematic uncertainties
  TFile* systematicFile = TFile::Open("systematicErrors.root", "READ");
  TGraphErrors* sys_pT_00to10_pr = (TGraphErrors*)systematicFile->Get("Graph_from_p_vn_pT_00to10_pr_px");
  TGraphErrors* sys_pT_10to40_pr = (TGraphErrors*)systematicFile->Get("Graph_from_p_vn_pT_10to40_pr_px");
  TGraphErrors* sys_pT_40to60_pr = (TGraphErrors*)systematicFile->Get("Graph_from_p_vn_pT_40to60_pr_px");
  ////

  int whitecolor=19;
  
  // Set various aesthetics
    h_vn_pT_00to10_pr->SetMarkerStyle(21);
  h_vn_pT_10to40_pr->SetMarkerStyle(20);
  h_vn_pT_40to60_pr->SetMarkerStyle(22);
  h_vn_pT_00to10_pr->SetMarkerColor(whitecolor);
  h_vn_pT_10to40_pr->SetMarkerColor(whitecolor);
  h_vn_pT_40to60_pr->SetMarkerColor(whitecolor);
  h_vn_pT_00to10_pr->SetMarkerSize(2);
  h_vn_pT_10to40_pr->SetMarkerSize(2);
  h_vn_pT_40to60_pr->SetMarkerSize(2);
  h_vn_pT_00to10_pr->SetLineColor(whitecolor);
  h_vn_pT_10to40_pr->SetLineColor(whitecolor);
  h_vn_pT_40to60_pr->SetLineColor(whitecolor);
  h_vn_pT_00to10_pr->SetLineWidth(3);
  h_vn_pT_10to40_pr->SetLineWidth(3);
  h_vn_pT_40to60_pr->SetLineWidth(3);

  sys_pT_00to10_pr->SetMarkerColor(whitecolor);
  sys_pT_10to40_pr->SetMarkerColor(whitecolor);
  sys_pT_40to60_pr->SetMarkerColor(whitecolor);
  sys_pT_00to10_pr->SetLineColor(whitecolor);
  sys_pT_10to40_pr->SetLineColor(whitecolor);
  sys_pT_40to60_pr->SetLineColor(whitecolor);
  ////
  
  THStack *prPtStack   = new THStack("prPtStack", ";p_{T} (GeV/c);v_{3} {#psi_{1} EP}");
  prPtStack->Add(h_vn_pT_00to10_pr);
  prPtStack->Add(h_vn_pT_10to40_pr);
  prPtStack->Add(h_vn_pT_40to60_pr);


  // Make text boxes, legends, and line at zero
  TLegend *prLegend = new TLegend(0.19, 0.15, 0.39, 0.3);
  prLegend->AddEntry(h_vn_pT_00to10_pr, "0 - 10%");
  prLegend->AddEntry(h_vn_pT_10to40_pr, "10 - 40%");
  prLegend->AddEntry(h_vn_pT_40to60_pr, "40 - 60%");
  prLegend->SetBorderSize(0);
  prLegend->SetFillColorAlpha(0,0);
  prLegend->SetTextSize(0.04);

  TPaveText *prText = new TPaveText(0.28, 0.03, 1.28, 0.055, "NB");
  prText->AddText("Proton");
  prText->AddText("Au+Au #sqrt{s_{NN}} = 3.0 GeV FXT (year 2018)");
  prText->AddText("0 < y_{CM} < 0.5 GeV");
  prText->SetFillColorAlpha(0,0);
  prText->SetLineColorAlpha(0,0);
  prText->SetTextSize(0.035);

  TPaveText* prelimText = new TPaveText(0.3, 0.02, 1.28, 0.03, "NB");
  prelimText->AddText("STAR");
  prelimText->SetTextColor(kRed);
  prelimText->SetFillColorAlpha(0,0);
  prelimText->SetTextSize(0.04);

  TLine *zeroLine_pt = new TLine(0, 0, 2, 0);
  zeroLine_pt->SetLineStyle(9);
  ////

  prPtStack->Draw();
  prPtStack->GetYaxis()->SetLabelSize(0.043);
  prPtStack->GetXaxis()->SetLabelSize(0.043);
  prPtStack->GetYaxis()->SetTitleOffset(1.4);
  prPtStack->GetXaxis()->SetTitleOffset(1.0);
  prPtStack->GetXaxis()->SetNdivisions(210);
  prPtStack->GetXaxis()->SetTitleSize(0.045);
  prPtStack->GetYaxis()->SetTitleSize(0.05);
  prPtStack->Draw();
  prPtStack->SetMaximum(0.04);
  prPtStack->SetMinimum(-0.12);
  prPtStack->Draw("NOSTACK E1P");
  zeroLine_pt->Draw("SAME");
  prPtStack->Draw("NOSTACK E1P SAME");

  TPaveText *prText_urqmd = new TPaveText(0.5, -0.13, 0.8, 0.03, "NB");
  // CHANGE FILE AND LABEL

  char dat1[100];
  strcpy(dat1,"jam1ana6.root"); //RKS  
  prText_urqmd->AddText(dat2); 
  cout << "Input file name = " << dat1 << endl;  //RKS
  cout << "Label = " << dat2 << endl;  //RKS

  TFile *fa = new TFile(dat1,"read");  //RKS
  if(!fa) {cout << "Wrong simulation file!" << endl; return;} //RKS

  TProfile *cth_3_pt_ycut1_cent_pr_a = (TProfile*) fa->Get("cth_3_pt_ycut1_cent_pr_h"); //RKS
  cth_3_pt_ycut1_cent_pr_a->SetMaximum(0.06);
  cth_3_pt_ycut1_cent_pr_a->SetMinimum(-.09);
  cth_3_pt_ycut1_cent_pr_a->SetAxisRange(0.,1.99);
  cth_3_pt_ycut1_cent_pr_a->SetMarkerColorAlpha(2,1.0);
  cth_3_pt_ycut1_cent_pr_a->SetMarkerStyle(8);
  cth_3_pt_ycut1_cent_pr_a->SetMarkerSize(1.2);
  cth_3_pt_ycut1_cent_pr_a->SetLineColor(2);
      cth_3_pt_ycut1_cent_pr_a->SetLineWidth(3);
  cth_3_pt_ycut1_cent_pr_a->Draw("SAME hist L p");
  
  TProfile *cth_3_pt_ycut1_periph_pr_a = (TProfile*) fa->Get("cth_3_pt_ycut1_periph_pr_h"); //RKS
  cth_3_pt_ycut1_periph_pr_a->SetMaximum(0.06);
  cth_3_pt_ycut1_periph_pr_a->SetMinimum(-.09);
  cth_3_pt_ycut1_periph_pr_a->SetAxisRange(0.,1.99);
  cth_3_pt_ycut1_periph_pr_a->SetMarkerColorAlpha(8,1.0);
  cth_3_pt_ycut1_periph_pr_a->SetMarkerStyle(8);
    cth_3_pt_ycut1_periph_pr_a->SetMarkerSize(1.2);
  cth_3_pt_ycut1_periph_pr_a->SetLineColor(8);
  cth_3_pt_ycut1_periph_pr_a->SetLineWidth(3);
  cth_3_pt_ycut1_periph_pr_a->Draw("SAME hist L p");
 
  
  TProfile *cth_3_pt_ycut1_mid_pr_a = (TProfile*) fa->Get("cth_3_pt_ycut1_mid_pr_h"); //RKS
  cth_3_pt_ycut1_mid_pr_a->SetMaximum(0.06);
  cth_3_pt_ycut1_mid_pr_a->SetMinimum(-.09);
  cth_3_pt_ycut1_mid_pr_a->SetAxisRange(0.,1.99);
  cth_3_pt_ycut1_mid_pr_a->SetMarkerColorAlpha(4,1.0);
  cth_3_pt_ycut1_mid_pr_a->SetMarkerStyle(8);
  cth_3_pt_ycut1_mid_pr_a->SetMarkerSize(1.2);
  cth_3_pt_ycut1_mid_pr_a->SetLineColor(4);
  cth_3_pt_ycut1_mid_pr_a->SetLineWidth(3);
  cth_3_pt_ycut1_mid_pr_a->Draw("SAME hist L p");

  // Make legend for JAM1
  prText_urqmd->SetFillColorAlpha(0,0);
  prText_urqmd->SetLineColorAlpha(0,0);
  prText_urqmd->SetTextSize(.035);
  prText_urqmd->Draw();
  TLegend *prLegend2 = new TLegend(0.41, 0.15, 0.55, 0.3);
  prLegend2->AddEntry(cth_3_pt_ycut1_cent_pr_a, " JAM1 - 0% - 10%");
  prLegend2->AddEntry(cth_3_pt_ycut1_mid_pr_a, " JAM1 - 10% - 40%");
  prLegend2->AddEntry(cth_3_pt_ycut1_periph_pr_a, " JAM1 - 40% - 60%");
  prLegend2->SetBorderSize(0);
  prLegend2->SetFillColorAlpha(0,0);
  prLegend2->SetTextSize(0.03);
  prLegend2->Draw();


  
  sys_pT_00to10_pr->Draw("[]");
  sys_pT_10to40_pr->Draw("[]");
  sys_pT_40to60_pr->Draw("[]");
  prLegend->Draw();
  prText->Draw();
  prelimText->Draw();
  canvas->SaveAs("v3_prPtStack.png");
  canvas->Clear();
  
  systematicFile->Close();
  file->Close();
}
