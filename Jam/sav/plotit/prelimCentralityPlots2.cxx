#include "PlotUtils.h"

void prelimCentralityPlots2(int ido=1, string dat2s="JAM1 3 GeV - hard2 potential b=0-14")
{
  char *dat2;
  dat2 = &dat2s[0];

  TString fileName = "Normal.picoDst.result.combined.root";
  TFile *file = TFile::Open(fileName);
  if(!file) {std::cout << "Wrong file!" << std::endl; return;}

  TCanvas *canvas = new TCanvas("canvas", "Canvas", 1000, 1000);//1200, 1200);
  //canvas->SetGridx();
  //canvas->SetGridy();
  canvas->SetLogy(0);
  canvas->SetTicks();
  canvas->SetTopMargin(0.04);
  canvas->SetRightMargin(0.04);
  canvas->SetBottomMargin(0.1);
  canvas->SetLeftMargin(0.15);
  canvas->cd();
  
  gStyle->SetErrorX(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(6);
  gStyle->SetLineWidth(3);


  TProfile *p_vn_pp   = (TProfile*)file->Get("p_vn_pp");
  TProfile *p_vn_pm   = (TProfile*)file->Get("p_vn_pm");
  TProfile *p_vn_pr   = (TProfile*)file->Get("p_vn_pr");

  // Convert profiles to histograms
  TH1D *h_vn_pp = p_vn_pp->ProjectionX();
  TH1D *h_vn_pm = p_vn_pm->ProjectionX();
  TH1D *h_vn_pr = p_vn_pr->ProjectionX();

  // Flip centrality plots
  h_vn_pp = PlotUtils::flipHisto(h_vn_pp);
  h_vn_pm = PlotUtils::flipHisto(h_vn_pm);
  h_vn_pr = PlotUtils::flipHisto(h_vn_pr);

  // Trim and clean up x-axis
  h_vn_pp = PlotUtils::trimCentralityPlot(h_vn_pp);
  h_vn_pm = PlotUtils::trimCentralityPlot(h_vn_pm);
  h_vn_pr = PlotUtils::trimCentralityPlot(h_vn_pr);

  // Retrieve systematic uncertainties
  TFile* systematicFile = TFile::Open("systematicErrors.root", "READ");
  TGraphErrors* sys_pp = (TGraphErrors*)systematicFile->Get("Graph_from_p_vn_pp_Normal_flip");
  TGraphErrors* sys_pm = (TGraphErrors*)systematicFile->Get("Graph_from_p_vn_pm_Normal_flip");
  TGraphErrors* sys_pr = (TGraphErrors*)systematicFile->Get("Graph_from_p_vn_pr_Normal_flip");
  ////
  
  int whitecolor=19;
  // Set various aesthetics
  sys_pp->SetMarkerColor(whitecolor);
  sys_pp->SetLineColor(whitecolor);

  sys_pm->SetMarkerColor(whitecolor);
  sys_pm->SetLineColor(whitecolor);

  //sys_pr should be fine as it is
  
  h_vn_pp->SetMarkerStyle(21);
  h_vn_pp->SetMarkerSize(2.5);
  h_vn_pp->SetMarkerColor(whitecolor);
  h_vn_pp->SetLineColor(whitecolor);
  h_vn_pp->SetLineWidth(3);
  h_vn_pp->GetYaxis()->SetTitleOffset(1.7);

  h_vn_pm->SetMarkerStyle(22);
  h_vn_pm->SetMarkerSize(2.5);
  h_vn_pm->SetMarkerColor(whitecolor);
  h_vn_pm->SetLineColor(whitecolor);
  h_vn_pm->SetLineWidth(3);
  h_vn_pm->GetYaxis()->SetTitleOffset(1.7);

  h_vn_pr->SetMarkerStyle(20);
  h_vn_pr->SetMarkerSize(2.5);
  h_vn_pr->SetMarkerColor(whitecolor);
  h_vn_pr->SetLineColor(whitecolor);
  h_vn_pr->SetLineWidth(3);
  h_vn_pr->GetYaxis()->SetTitleOffset(1.7);
  ////

  THStack *allCentralityStack = new THStack("allCentralityStack", ";Centrality (%);v_{3} {#psi_{1} EP}");
  allCentralityStack->Add(h_vn_pr);
  allCentralityStack->Add(h_vn_pp);
  allCentralityStack->Add(h_vn_pm);
  
  // Make text boxes, legends, and line at zero
  TPaveText* prelimText = new TPaveText(12, 0.012, 42, 0.02, "NB");
  prelimText->AddText("STAR");
  prelimText->SetTextColor(kRed);
  prelimText->SetFillColorAlpha(0,0);
  prelimText->SetTextSize(0.04);

  TPaveText *allText = new TPaveText(12, 0.018, 42, 0.027, "NB");
  allText->AddText("Au+Au #sqrt{s_{NN}} = 3.0 GeV FXT (year 2018)");
  allText->AddText("0 < y_{CM} < 0.5 GeV");
  //allText->AddText("0.4 #leq p_{T} #leq 2.0 GeV");
  allText->SetFillColorAlpha(0,0);
  allText->SetLineColorAlpha(0,0);
  allText->SetTextSize(0.035);

  TLegend *allLegend = new TLegend(0.3, 0.14, 0.6, 0.27);
  allLegend->AddEntry(h_vn_pp,"#pi^{+}, 0.18 #leq p_{T} #leq 1.6 GeV");
  allLegend->AddEntry(h_vn_pm,"#pi^{-}, 0.18 #leq p_{T} #leq 1.6 GeV");
  allLegend->AddEntry(h_vn_pr,"p, 0.4 #leq p_{T} #leq 2.0 GeV");
  allLegend->SetFillColorAlpha(0,0);
  allLegend->SetLineColorAlpha(0,0);
  allLegend->SetTextSize(0.04);

  TLine *zeroLine = new TLine(0, 0, 60, 0);
  zeroLine->SetLineStyle(9);
  zeroLine->SetLineWidth(3);
  ////

  allCentralityStack->Draw();
  allCentralityStack->GetXaxis()->SetLabelSize(0.045);
  allCentralityStack->GetYaxis()->SetLabelSize(0.045);
  allCentralityStack->GetXaxis()->SetTitleOffset(1.0);
  allCentralityStack->GetYaxis()->SetTitleOffset(1.4);
  allCentralityStack->GetXaxis()->SetTitleSize(0.045);
  allCentralityStack->GetYaxis()->SetTitleSize(0.05);
  allCentralityStack->GetXaxis()->SetNdivisions(210);
  allCentralityStack->SetMaximum(0.02);
  allCentralityStack->SetMinimum(-0.03);
  allCentralityStack->Draw("NOSTACK E1P");
  zeroLine->Draw("SAME");
  allCentralityStack->Draw("NOSTACK E1P SAME");

  TPaveText *prText_urqmd = new TPaveText(12, 0.010, 42, 0.015, "NB");
  // CHANGE FILE AND LABEL

  char dat1[100];
  strcpy(dat1,"jam1ana6.root"); //RKS  
  prText_urqmd->AddText(dat2); 
  cout << "Input file name = " << dat1 << endl;  //RKS
  cout << "Label = " << dat2 << endl;  //RKS

  TFile *fa = new TFile(dat1,"read");  //RKS
  if(!fa) {cout << "Wrong simulation file!" << endl; return;} //RKS

  //  fix centrality to set radius = 6.644 fm
  
  //    TProfile *cth_3_b_ycut1_ptcut2_pr_a = (TProfile*) fa->Get("cth_3_b_ycut1_ptcut2_pr_h"); //RKS
  TProfile *cth_3_b_ycut1_ptcut1_pr_a = (TProfile*) fa->Get("cth_3_b_ycut1_ptcut1_pr_h"); //RKS
  TH1F *cth_3_b_ycut1_ptcut1_pr_a2 = new TH1F("cth_3_b_pr_b","cth_3_b_pr_a2",42,0.,60.);   

  TProfile *cth_3_b_ycut1_ptcut1_pip_b = (TProfile*) fa->Get("cth_3_b_ycut1_ptcut1_pip_h"); //pip
  TH1F *cth_3_b_ycut1_ptcut1_pip_b2 = new TH1F("cth_3_b_pip_b","cth_3_b_pip_a2",42,0.,60.);  //pip
  TProfile *cth_3_b_ycut1_ptcut1_pim_c = (TProfile*) fa->Get("cth_3_b_ycut1_ptcut1_pim_h"); //pim
  TH1F *cth_3_b_ycut1_ptcut1_pim_c2 = new TH1F("cth_3_b_pim_b","cth_3_b_pim_a2",42,0.,60.);  //pim

  
  double bincontent=0;
  for(int ii=1; ii<43; ii++){    
    bincontent=cth_3_b_ycut1_ptcut1_pr_a->GetBinContent(ii);
    //    cout<<bincontent<<endl;
    cth_3_b_ycut1_ptcut1_pr_a2->SetBinContent(ii,bincontent);

    bincontent=cth_3_b_ycut1_ptcut1_pip_b->GetBinContent(ii);    //pip
    cth_3_b_ycut1_ptcut1_pip_b2->SetBinContent(ii,bincontent);    //pip

    bincontent=cth_3_b_ycut1_ptcut1_pim_c->GetBinContent(ii);   //pim
    cth_3_b_ycut1_ptcut1_pim_c2->SetBinContent(ii,bincontent);   //pim
  }
  cth_3_b_ycut1_ptcut1_pr_a2->SetMaximum(0.03);
  cth_3_b_ycut1_ptcut1_pr_a2->SetMinimum(-.04);
  //  cth_3_b_ycut1_ptcut1_pr_a2->SetAxisRange(0., 108.); // in b^2
  cth_3_b_ycut1_ptcut1_pr_a2->SetAxisRange(0., 120.); // in b^2 
  cth_3_b_ycut1_ptcut1_pr_a2->SetMarkerColorAlpha(2,1.0);
  cth_3_b_ycut1_ptcut1_pr_a2->SetMarkerStyle(8);
  cth_3_b_ycut1_ptcut1_pr_a2->SetMarkerSize(1.2);
  cth_3_b_ycut1_ptcut1_pr_a2->SetLineColor(2);
  cth_3_b_ycut1_ptcut1_pr_a2->SetLineWidth(3);
  int rbin=2;
  cth_3_b_ycut1_ptcut1_pr_a2->Rebin(rbin);
  cth_3_b_ycut1_ptcut1_pr_a2->Scale(1./float(rbin));
  cth_3_b_ycut1_ptcut1_pr_a2->Draw("SAME hist L p");


  cth_3_b_ycut1_ptcut1_pip_b2->SetMaximum(0.03);    //pip
  cth_3_b_ycut1_ptcut1_pip_b2->SetMinimum(-.04);    //pip
  cth_3_b_ycut1_ptcut1_pip_b2->SetAxisRange(0., 120.);    //pip // in b^2 
  cth_3_b_ycut1_ptcut1_pip_b2->SetMarkerColorAlpha(1,1.0);    //pip
  cth_3_b_ycut1_ptcut1_pip_b2->SetMarkerStyle(8);    //pip
  cth_3_b_ycut1_ptcut1_pip_b2->SetMarkerSize(1.2);    //pip
  cth_3_b_ycut1_ptcut1_pip_b2->SetLineColor(1);    //pip
  cth_3_b_ycut1_ptcut1_pip_b2->SetLineWidth(3);    //pip
  cth_3_b_ycut1_ptcut1_pip_b2->Rebin(rbin);    //pip
  cth_3_b_ycut1_ptcut1_pip_b2->Scale(1./float(rbin));    //pip
  cth_3_b_ycut1_ptcut1_pip_b2->Draw("SAME hist L p");    //pip

  cth_3_b_ycut1_ptcut1_pim_c2->SetMaximum(0.03);    //pim
  cth_3_b_ycut1_ptcut1_pim_c2->SetMinimum(-.04);    //pim
  cth_3_b_ycut1_ptcut1_pim_c2->SetAxisRange(0., 120.);    //pim // in b^2 
  cth_3_b_ycut1_ptcut1_pim_c2->SetMarkerColorAlpha(4,1.0);    //pim
  cth_3_b_ycut1_ptcut1_pim_c2->SetMarkerStyle(8);    //pim
  cth_3_b_ycut1_ptcut1_pim_c2->SetMarkerSize(1.2);    //pim
  cth_3_b_ycut1_ptcut1_pim_c2->SetLineColor(4);    //pim
  cth_3_b_ycut1_ptcut1_pim_c2->SetLineWidth(3);    //pim
  cth_3_b_ycut1_ptcut1_pim_c2->Rebin(rbin);    //pim
  cth_3_b_ycut1_ptcut1_pim_c2->Scale(1./float(rbin));    //pim
  cth_3_b_ycut1_ptcut1_pim_c2->Draw("SAME hist L p");    //pim
  
  // Make legend for JAM1
  prText_urqmd->SetFillColorAlpha(0,0);
  prText_urqmd->SetLineColorAlpha(0,0);
  prText_urqmd->SetTextSize(.035);
  prText_urqmd->Draw();
  //  TLegend *prLegend2 = new TLegend(0.3, 0.28, 0.6, 0.29);
  TLegend *prLegend2 = new TLegend(0.3, 0.40, 0.6, 0.29);
  prLegend2->AddEntry(cth_3_b_ycut1_ptcut1_pip_b2, " #pi^{+} JAM1 "); // pip
  prLegend2->AddEntry(cth_3_b_ycut1_ptcut1_pim_c2, " #pi^{-} JAM1"); //  pim
  prLegend2->AddEntry(cth_3_b_ycut1_ptcut1_pr_a2, " p JAM1 ");

  //  prLegend2->AddEntry(cth_3_b_ycut1_ptcut1_pr_a2, " JAM1 protons ");
  prLegend2->SetBorderSize(0);
  prLegend2->SetFillColorAlpha(0,0);
  prLegend2->SetTextSize(0.04);
  prLegend2->Draw();

  
  sys_pp->Draw("[]");
  sys_pm->Draw("[]");
  sys_pr->Draw("[]");
  allLegend->Draw();
  allText->Draw();
  prelimText->Draw();
  canvas->SaveAs("v3_allCentralityStack.png");
  canvas->Clear();

  systematicFile->Close();
  file->Close();
}
