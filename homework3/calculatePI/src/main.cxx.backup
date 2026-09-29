#include <vector>
#include <iostream>

#include "helper.hpp"

int main() {
  // Number of iterations to calculate Pi. Change for different accuracy
  // Default '1e6' means 1*10 at the power of 6 (1000000 iterations)
  constexpr long long N = 1e6;

  std::vector<double> x_hit, y_hit;
  std::vector<double> x_miss, y_miss;
  roothelp::calcPi<N>(x_hit, y_hit, x_miss, y_miss);

  
  TGraph* g_hit = new TGraph(x_hit.size(), &x_hit[0], &y_hit[0]);
  TGraph* g_miss = new TGraph(x_miss.size(), &x_miss[0], &y_miss[0]);

  roothelp::setGraphSettings(g_hit, g_miss);
  roothelp::drawImage(g_hit, g_miss);


  double pi_estimate = 4.0 * x_hit.size() / (x_hit.size() + x_miss.size());
  std::cout << "Estimated pi = " << pi_estimate << std::endl;
  
  delete g_hit;
  delete g_miss;

}


