#pragma once

#include <TGraph.h>
#include <TCanvas.h>
#include <TRandom3.h>
#include <iostream>

namespace roothelp {

  
  template <long long N, typename vec>
  void calcPi(vec& x_hit,vec& y_hit,vec& x_miss,vec& y_miss) { 
    TRandom3 rng(0);

    for (long long i = 0; i < N; ++i) {

      // this lines below has been added for debugging purposes only
      // It makes the code very slow due to disk writes
      //  comment it out for better performance
      long long step = i % 1000;
      if ( step == 0 ) {
        std::cout << "Processing datapoint: " << i << " of " << N << std::endl;      
      }

      double x = rng.Uniform();
      double y = rng.Uniform();

      if (x * x + y * y <= 1.0) {
        x_hit.push_back(x);
        y_hit.push_back(y);
      } else {
        x_miss.push_back(x);
        y_miss.push_back(y);
      }
    }
  }

  void setGraphSettings(TGraph* g_hit, TGraph* g_miss) {
    g_hit->SetMarkerColor(kBlue + 2);
    g_hit->SetMarkerStyle(7);
    g_hit->SetMarkerSize(0.4);

    g_miss->SetMarkerColor(kRed + 2);
    g_miss->SetMarkerStyle(7);
    g_miss->SetMarkerSize(0.4);
  }

  void drawImage(TGraph* g_hit, TGraph* g_miss) { 
     
    // this line below has been added for debugging purposes only
    std::cout << "Graph creation in progress..." << std::endl;

    TCanvas* c = new TCanvas("c", "", 800, 800);
    g_miss->Draw("AP");
    g_hit->Draw("P same");

    c->SaveAs("pi_hit_miss.png");
    delete c;
  }

}

