#ifndef PLOT_TOOLS
#define PLOT_TOOLS

#include <TStyle.h>
#include <TROOT.h>
#include <TColor.h>
#include <TCanvas.h>
#include <TH1.h>
#include <TH2.h>
#include <TGraph.h>
#include <TRandom.h>
#include <TChain.h>
#include <TString.h>

#include <Event.hpp>

class plotterTools{

public:

  plotterTools(char* filename, char*outfname, char*outdname);



  TChain* inputTree_;
  TFile* inputFile_;
  TFile* outputFile_;
  TString outputDir_;

  TString module_, group_;
  int historyStep_;//set the step of events for history plots

  treeStructData treeStruct_;

  std::map<TString,TObject*> outObjects_;
  std::map<TString,TString> plotShortNames_;
  std::map<TString,TString> plotLongNames_;
  std::vector<float> variables_;//<value,dimension>
  std::map<TString,float*> variablesMap_;
  std::map<TString,int> variablesIterator_;
  std::map<TString,std::vector<float> > variablesContainer_;
  std::map<TString,TString > variablesContainerTitles_;

  void set_plot_blue ();
  void set_palette_fancy ();
  void setPlotsFormat ();
  void plotMe (TH1F * histo);
  void plotMe (TH2F * histo);
  void plotMe (TGraph * graph, const TString & name);
  void setAxisTitles (TH1 * histo, const TString  xTitle, const TString  yTitle);
  void setAxisTitles (TH2 * histo, const TString  xTitle, const TString  yTitle);
  void setAxisTitles (TGraph * graph, const TString  xTitle, const TString  yTitle);
  void readInputTree ();
  void Loop();
  void saveHistos();
  void plotHistos();
  void printHistos();
  void bookPlotsScaler (int nBinsHistory);
  TGraph* bookGraph (TString name, int nPoints, TString type, TString group, TString module);
  void setGroup(TString group);
  void setModule(TString module);
  void setStepHistoryPlots(int n);
  int getTreeEntries();
  int getStepHistoryPlots();
  void FillPlot(TString name, int point, float X);//TGraph
  void FillPlot(TString name, bool is2D=false,int varDim=1);//TH1F
  void addPlot(TString name,int nPoints,TString type, TString group, TString module);//TGraph
  void addPlot(TString name,int nBinsX, float xMin, float xMax, TString type, TString group, TString module, int varDim=1);//TH1F
  void addPlot(TString name,int nBinsX, float xMin, float xMax, int nBinsY, float yMin, float yMax, TString xTitle, TString yTitle, TString type, TString group, TString module);//TH2F
  TH1F* bookHisto(TString name,int nBinsX,float xMin, float xMax, TString type, TString group, TString module);
  TH2F* bookHisto2D(TString name,int nBinsX,float xMin, float xMax,int nBinsY, float yMin, float yMax,TString xTitle, TString yTitle, TString type, TString group, TString module);
  void initVariable(TString name, int varDim=1);
  void computeVariable(TString name, int varDim=1);
  pair<int, string> execute (const string & command);
};

#endif
