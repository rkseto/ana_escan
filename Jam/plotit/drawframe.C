
void drawframe()
{
  // just draws frme
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
#include "TH3.h"
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

  TCanvas *canvas = new TCanvas("canvas", "Canvas", 1000, 1000);
  //canvas->SetGrid();
  //  canvas->SetTicks();
  canvas->SetFrameLineWidth(3);
  canvas->SetLeftMargin(0.15);
  canvas->SetTopMargin(0.04);
  canvas->SetRightMargin(0.04);
  canvas->SetBottomMargin(0.1);
  canvas->cd();

  gStyle->SetErrorX(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(6);
  gStyle->SetLineWidth(3);

  TH2D *frame1 = new TH2D("frame1"," ",90,-9.0,9.0, 90,-2.,16.0);
  frame1->GetXaxis()->SetTitle("x(fm)");
  frame1->GetYaxis()->SetTitle("y(fm)");
  frame1->Draw();
  canvas->Print("frame1.png");
}
