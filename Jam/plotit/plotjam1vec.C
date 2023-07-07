// for looking at v3
// load c++ and c headers
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

void plotjam1vec (string cmdstr = "HELP",string filestr = "jam1_3_b0-14_RQMDS_all.root", string histstr = "xvsyvspt_mid_bin4", double ptmin=0., double ptmax=2. , double axissize=30.) {
  // HELP, CHECK, DUMP, SLICEZ, SLICEZALL, SLICEX, SLICEY, DUMPSLICE, SLICEZXZ
  char cmdchr[50];
  strcpy(cmdchr,cmdstr.c_str());
  if(cmdstr=="HELP"){
    cout<<" commands are HELP, CHECK, DUMP, DUMPSLICE, SLICEZ, SLICEZALL, SLICEX, SLICEY, SLICEZXZ"<<endl;
    cout<<" there are 5 arguments: "<<endl;
    cout<<" command, root_file_in, histogram, ptmin, ptmax "<<endl;
    cout<<" for DUMP, just give the last part of the name e.g. mid_binp4 for the histogram name"<<endl;
    return;
  }
  char filechr[50];
  strcpy(filechr,filestr.c_str());
  char histchr[50];
  strcpy(histchr,histstr.c_str());
  
  cout << "Input CMD:  " << cmdchr << endl;
  cout << "Input root file:  " << filechr << endl;
  cout << "Input hist:  " << histchr << endl;
  
  TFile *fin = new TFile(filechr,"read");
  
  //  TProfile2D *histtp2;
  //  histtp2 = (TPofile2D*) fc->Get(histchr);
  
  if(cmdstr == "SLICEZ" || cmdstr == "SLICEZXZ" ){
    cout<<" SLICING in Z"<<endl;
    TH3D *hist;  // for reasons I don't understand, this works for any histogram
    hist = (TH3D*) fin->Get(histchr);
    if (gDirectory->FindObject(hist)) printf ("%s exists \n", histchr); else {printf ("%s doesn't exist \n", histchr); return;} 
    TH2D *hist2 =(TH2D*) fin->Get("xvsz_allnh");
    if (gDirectory->FindObject("xvsz_allnh")) printf ("%s exists \n", "xvsz_allnh"); else {printf ("%s doesn't exist \n", "xvsz_allnh"); return;} 
    
    // get bins x, y, xminmax y, zbin=ptminmax
    int nx=hist->GetNbinsX();
    int ny=hist->GetNbinsY();
    int nz=hist->GetNbinsZ();
    double dx = hist->GetXaxis()->GetBinCenter(2)-hist->GetXaxis()->GetBinCenter(1);
    double xmin=hist->GetXaxis()->GetBinCenter(1)-dx/2.;
    double xmax=hist->GetXaxis()->GetBinCenter(nx)+dx/2.;
    cout<<" nx xmin xmax="<<nx<<" "<<xmin<<" "<<xmax<<endl;
    
    double dy = hist->GetYaxis()->GetBinCenter(2)-hist->GetYaxis()->GetBinCenter(1);
    double ymin=hist->GetYaxis()->GetBinCenter(1)-dy/2.;
    double ymax=hist->GetYaxis()->GetBinCenter(ny)+dy/2.;
    cout<<" ny ymin ymax="<<ny<<" "<<ymin<<" "<<ymax<<endl;
    
    double dz = hist->GetZaxis()->GetBinCenter(2)-hist->GetZaxis()->GetBinCenter(1);
    double zmin=hist->GetZaxis()->GetBinCenter(1)-dz/2.;
    double zmax=hist->GetZaxis()->GetBinCenter(nz)+dz/2.;
    cout<<" nz zmin zmax="<<nz<<" "<<zmin<<" "<<zmax<<endl;
    
    int iptmin=hist->GetZaxis()->FindBin(ptmin);
    int iptmax=hist->GetZaxis()->FindBin(ptmax);
    cout<<" ptmin iptmin ptmax iptmax="<<ptmin<<" "<<iptmin<<" "<<ptmax<<" "<<iptmax<<endl;
    
    TH2D *hist2D = new TH2D("xvsy","xvsy",nx,xmin,xmax,ny,ymin,ymax);
    for(int i=1; i<nx+1; i++){
      for(int j=1; j<ny+1; j++){
	double content=0.;
	for(int k=iptmin; k<iptmax+1; k++){
	  content+=hist->GetBinContent(i,j,k);
	}
	hist2D->SetBinContent(i,j,content);
      }
    }
    TCanvas *c1 = new TCanvas("c1","c1",0,0,1000,1000);
    int ixmin=hist2D->GetXaxis()->FindBin(-axissize);
    int ixmax=hist2D->GetXaxis()->FindBin(axissize);
    hist2D->GetXaxis()->SetRange(ixmin,ixmax);
    int iymin=hist2D->GetYaxis()->FindBin(-axissize);
    int iymax=hist2D->GetYaxis()->FindBin(axissize);
    hist2D->GetYaxis()->SetRange(iymin,iymax);
    hist2D->Draw("COLZ");
    c1->SaveAs("slicez.png");

    if(cmdstr == "SLICEZXZ" ){
      TCanvas *c3 = new TCanvas("c3","c3",0,0,1000,500);
      c3->Divide(2,1);
      c3->cd(1);
      hist2D->Draw("COLZ");
      c3->cd(2);

      ixmin=hist2->GetXaxis()->FindBin(-axissize);
      ixmax=hist2->GetXaxis()->FindBin(axissize);
      hist2->GetXaxis()->SetRange(ixmin,ixmax);
      iymin=hist2->GetYaxis()->FindBin(-axissize);
      iymax=hist2->GetYaxis()->FindBin(axissize);
      hist2->GetYaxis()->SetRange(iymin,iymax);

      hist2->Draw("COLZ");
      c3->SaveAs("slicezxz.png");
    }

  }

  //--------------------

  if(cmdstr == "SLICEZALL"){
    cout<<" SLICING in Z draw all slices and xmean"<<endl;
    TH3D *hist;  // for reasons I don't understand, this works for any histogram
    hist = (TH3D*) fin->Get(histchr);
    if (gDirectory->FindObject(hist)) printf ("%s exists \n", histchr); else {printf ("%s doesn't exist \n", histchr); return;} 
    
    // get bins x, y, xminmax y, zbin=ptminmax
    int nx=hist->GetNbinsX();
    int ny=hist->GetNbinsY();
    int nz=hist->GetNbinsZ();
    double dx = hist->GetXaxis()->GetBinCenter(2)-hist->GetXaxis()->GetBinCenter(1);
    double xmin=hist->GetXaxis()->GetBinCenter(1)-dx/2.;
    double xmax=hist->GetXaxis()->GetBinCenter(nx)+dx/2.;
    cout<<" nx xmin xmax="<<nx<<" "<<xmin<<" "<<xmax<<endl;
    
    double dy = hist->GetYaxis()->GetBinCenter(2)-hist->GetYaxis()->GetBinCenter(1);
    double ymin=hist->GetYaxis()->GetBinCenter(1)-dy/2.;
    double ymax=hist->GetYaxis()->GetBinCenter(ny)+dy/2.;
    cout<<" ny ymin ymax="<<ny<<" "<<ymin<<" "<<ymax<<endl;
    
    double dz = hist->GetZaxis()->GetBinCenter(2)-hist->GetZaxis()->GetBinCenter(1);
    double zmin=hist->GetZaxis()->GetBinCenter(1)-dz/2.;
    double zmax=hist->GetZaxis()->GetBinCenter(nz)+dz/2.;
    cout<<" nz zmin zmax="<<nz<<" "<<zmin<<" "<<zmax<<endl;
    
    int iptmin=hist->GetZaxis()->FindBin(ptmin);
    int iptmax=hist->GetZaxis()->FindBin(ptmax);
    cout<<" ptmin iptmin ptmax iptmax="<<ptmin<<" "<<iptmin<<" "<<ptmax<<" "<<iptmax<<endl;

    TCanvas *c1 = new TCanvas("c1","c1",0,0,1500,600);    
    c1->Divide(5,2);
    TH2D *hist2Dall[10];
    double xmeans[10];
    double ptmeans[10];
    for(int m=1; m<11; m++){
      stringstream ss;
      ss << m;
      string numstr = ss.str();
      string namestr="xvsy_"+numstr;
      cout<<" namestr="<<namestr<<endl;
      char namechr[50];
      strcpy(namechr,namestr.c_str());
      hist2Dall[m] = new TH2D(namechr,namechr,nx,xmin,xmax,ny,ymin,ymax);

      for(int i=1; i<nx+1; i++){
	for(int j=1; j<ny+1; j++){
	  double content=0.;
	  for(int k=m; k<m+1; k++){
	    content+=hist->GetBinContent(i,j,k);
	  }
	  hist2Dall[m]->SetBinContent(i,j,content);
	}
      }
      double xmean=hist2Dall[m]->GetMean(1);     
      xmeans[m-1]=xmean;
      //      ptmeans[m]=m*2./10.;
      ptmeans[m-1]=hist->GetZaxis()->GetBinCenter(m);
      cout<<" m pt xmean="<<m<<" "<<ptmeans[m]<<" "<<xmean<<endl;
      c1->cd(m);
      hist2Dall[m]->Draw("COLZ");      
    }
    TCanvas *c2 = new TCanvas("c2","c2",0,0,600,600);    
    c2->cd(1);
    auto g = new TGraph(10,ptmeans,xmeans);
    g->SetTitle("xmeans vs pt");
    g->SetMaximum(15.);
    g->SetMinimum(-15.);
    g->Draw("AC*");
  }
  //-------------------------------

  
  //  TCanvas *c1 = new TCanvas("c1","c1",0,0,1000,1000);
  //  hist->Draw();
  // c1->Divide(5,4);
  //  c1->Divide(2,2);
  
  //  int ipad=0;
  
  //  histstr="xvsy_p_pt0_binm4";
  
  if(cmdstr == "DUMP"){
    TProfile2D *histpx;  // for reasons I don't understand, this works for any histogram
    TProfile2D *histpy;  // for reasons I don't understand, this works for any histogram
    TProfile2D *histpz;  // for reasons I don't understand, this works for any histogram
    string histpxstr="rvsphivspr_"+histstr;
    cout<<" histpxstr="<<histpxstr<<endl;
    char histpxchr[50];
    strcpy(histpxchr,histpxstr.c_str());
    histpx = (TProfile2D*) fin->Get(histpxchr);
    if (gDirectory->FindObject(histpx)) printf ("%s exists \n", histpxchr); else {printf ("%s doesn't exist \n", histpxchr); return;} 
    
    string histpystr="rvsphivspth_"+histstr;
    cout<<" histpystr="<<histpystr<<endl;
    char histpychr[50];
    strcpy(histpychr,histpystr.c_str());
    histpy = (TProfile2D*) fin->Get(histpychr);
    if (gDirectory->FindObject(histpy)) printf ("%s exists \n", histpychr); else {printf ("%s doesn't exist \n", histpychr); return;} 
    
    string histpzstr="rvsphivspz_"+histstr;
    cout<<" histpzstr="<<histpzstr<<endl;
    char histpzchr[50];
    strcpy(histpzchr,histpzstr.c_str());
    histpz = (TProfile2D*) fin->Get(histpzchr);
    if (gDirectory->FindObject(histpz)) printf ("%s exists \n", histpzchr); else {printf ("%s doesn't exist \n", histpzchr); return;} 
    
    
    int nx=histpx->GetNbinsX();
    int ny=histpx->GetNbinsY();
    int nz=histpx->GetNbinsZ();
    double dx = histpx->GetXaxis()->GetBinCenter(2)-histpx->GetXaxis()->GetBinCenter(1);
    double xmin=histpx->GetXaxis()->GetBinCenter(1)-dx/2.;
    double xmax=histpx->GetXaxis()->GetBinCenter(nx)+dx/2.;
    cout<<" nx xmin xmax="<<nx<<" "<<xmin<<" "<<xmax<<endl;
    
    double dy = histpx->GetYaxis()->GetBinCenter(2)-histpx->GetYaxis()->GetBinCenter(1);
    double ymin=histpx->GetYaxis()->GetBinCenter(1)-dy/2.;
    double ymax=histpx->GetYaxis()->GetBinCenter(ny)+dy/2.;
    cout<<" ny ymin ymax="<<ny<<" "<<ymin<<" "<<ymax<<endl;
    
    ofstream vectoroutfile;
    vectoroutfile.open("vectoroutfile.txt");
    for(int i=1; i<nx+1; i++){
      for(int j=1; j<ny+1; j++){
	int gbin=histpx->GetBin(i,j);
	double x=histpx->GetXaxis()->GetBinCenter(i);
	double y=histpx->GetYaxis()->GetBinCenter(j);
	double px=histpx->GetBinContent(i,j);
	double py=histpy->GetBinContent(i,j);
	double ptt=sqrt(px*px+py*py);
	if(ptt>ptmin && ptt<ptmax){
	  cout<<i<<" "<<j<<" x y px py = "<<x<<" "<<y<<" "<<px<<" "<<py<<" "<<gbin<<endl;
	  vectoroutfile<<x<<" "<<y<<" "<<px<<" "<<py<<endl;	
	}
      }
    }
    vectoroutfile.close();    
  }

  if(cmdstr == "DUMPSLICE"){
    cout<<" DUMP a SLICE in pt"<<endl;
    TProfile3D *hist3Dpx;  // for reasons I don't understand, this works for any histogram
    TProfile3D *hist3Dpy;  // for reasons I don't understand, this works for any histogram
    TProfile3D *hist3Dpz;  // for reasons I don't understand, this works for any histogram

   string hist3Dpxstr="rvsphivspr_3D_"+histstr;
    cout<<" hist3Dpxstr="<<hist3Dpxstr<<endl;
    char hist3Dpxchr[50];
    strcpy(hist3Dpxchr,hist3Dpxstr.c_str());
    hist3Dpx = (TProfile3D*) fin->Get(hist3Dpxchr);
    if (gDirectory->FindObject(hist3Dpx)) printf ("%s exists \n", hist3Dpxchr); else {printf ("%s doesn't exist \n", hist3Dpxchr); return;} 
    
    string hist3Dpystr="rvsphivspth_3D_"+histstr;
    cout<<" hist3Dpystr="<<hist3Dpystr<<endl;
    char hist3Dpychr[50];
    strcpy(hist3Dpychr,hist3Dpystr.c_str());
    hist3Dpy = (TProfile3D*) fin->Get(hist3Dpychr);
    if (gDirectory->FindObject(hist3Dpy)) printf ("%s exists \n", hist3Dpychr); else {printf ("%s doesn't exist \n", hist3Dpychr); return;} 
    
    string hist3Dpzstr="rvsphivspz_3D_"+histstr;
    cout<<" hist3Dpzstr="<<hist3Dpzstr<<endl;
    char hist3Dpzchr[50];
    strcpy(hist3Dpzchr,hist3Dpzstr.c_str());
    hist3Dpz = (TProfile3D*) fin->Get(hist3Dpzchr);
    if (gDirectory->FindObject(hist3Dpz)) printf ("%s exists \n", hist3Dpzchr); else {printf ("%s doesn't exist \n", hist3Dpzchr); return;} 
    
    
    int nx=hist3Dpx->GetNbinsX();
    int ny=hist3Dpx->GetNbinsY();
    int nz=hist3Dpx->GetNbinsZ();
    double dx = hist3Dpx->GetXaxis()->GetBinCenter(2)-hist3Dpx->GetXaxis()->GetBinCenter(1);
    double xmin=hist3Dpx->GetXaxis()->GetBinCenter(1)-dx/2.;
    double xmax=hist3Dpx->GetXaxis()->GetBinCenter(nx)+dx/2.;
    cout<<" nx xmin xmax="<<nx<<" "<<xmin<<" "<<xmax<<endl;
    
    double dy = hist3Dpx->GetYaxis()->GetBinCenter(2)-hist3Dpx->GetYaxis()->GetBinCenter(1);
    double ymin=hist3Dpx->GetYaxis()->GetBinCenter(1)-dy/2.;
    double ymax=hist3Dpx->GetYaxis()->GetBinCenter(ny)+dy/2.;
    cout<<" ny ymin ymax="<<ny<<" "<<ymin<<" "<<ymax<<endl;

    double dz = hist3Dpx->GetZaxis()->GetBinCenter(2)-hist3Dpx->GetZaxis()->GetBinCenter(1);
    double zmin=hist3Dpx->GetZaxis()->GetBinCenter(1)-dz/2.;
    double zmax=hist3Dpx->GetZaxis()->GetBinCenter(nz)+dz/2.;
    cout<<" nz zmin zmax="<<nz<<" "<<zmin<<" "<<zmax<<endl;
    
    
    int iptmin=hist3Dpx->GetZaxis()->FindBin(ptmin);
    int iptmax=hist3Dpx->GetZaxis()->FindBin(ptmax);
    cout<<" ptmin iptmin ptmax iptmax="<<ptmin<<" "<<iptmin<<" "<<ptmax<<" "<<iptmax<<endl;
    
    TH2D *prof2Dpx = new TH2D("profile_xvsy_px","profile_xvsy_px",nx,xmin,xmax,ny,ymin,ymax);
    TH2D *prof2Dpy = new TH2D("profile_xvsy_py","profile_xvsy_py",nx,xmin,xmax,ny,ymin,ymax);
    ofstream vector3Doutfile;
    vector3Doutfile.open("vector3Doutfile.txt");

    for(int i=1; i<nx+1; i++){
      for(int j=1; j<ny+1; j++){
	double contentpx=0.;
	double contentpy=0.;
	int nentriestotx=0;
	int nentriestoty=0;
	for(int k=iptmin; k<iptmax+1; k++){

	  int gbin=hist3Dpx->GetBin(i,j,k);
	  nentriestotx+=hist3Dpx->GetBinEntries(gbin);
	  contentpx+=hist3Dpx->GetBinContent(i,j,k)*hist3Dpx->GetBinEntries(gbin);
	  gbin=hist3Dpy->GetBin(i,j,k);
	  nentriestoty+=hist3Dpy->GetBinEntries(gbin);
	  contentpy+=hist3Dpy->GetBinContent(i,j,k)*hist3Dpy->GetBinEntries(gbin);
	}
	if(nentriestotx>0)contentpx/=double(nentriestotx);
	if(nentriestoty>0)contentpy/=double(nentriestoty);
	cout<<" i j contentpx contentpy "<<i<<" "<<j<<" "<<contentpx<<" "<<contentpy<<endl;
	prof2Dpx->SetBinContent(i,j,contentpx);
	prof2Dpy->SetBinContent(i,j,contentpy);
	double x=prof2Dpx->GetXaxis()->GetBinCenter(i);
	double y=prof2Dpy->GetYaxis()->GetBinCenter(j);
	double px=prof2Dpx->GetBinContent(i,j);
	double py=prof2Dpy->GetBinContent(i,j);
	cout<<i<<" "<<j<<" x y px py = "<<x<<" "<<y<<" "<<px<<" "<<py<<" "<<endl;
	vector3Doutfile<<x<<" "<<y<<" "<<px<<" "<<py<<endl;	
      }
    }
    vector3Doutfile.close();    
    TCanvas *c1 = new TCanvas("c1","c1",0,0,1000,500);
    c1->Divide(2,1);
    c1->cd(1);
    prof2Dpx->Draw("COLZ");
    c1->cd(2);
    prof2Dpy->Draw("COLZ");
  }    


    
}  

