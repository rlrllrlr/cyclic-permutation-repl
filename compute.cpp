#include <iostream>
#include <vector>

using namespace std;

void swap(int &alpha, int &beta) {
  if(alpha == beta) return;
  alpha = alpha ^ beta;
  beta  = alpha ^ beta;
  alpha = alpha ^ beta;
}

vector<int> genOrdList(vector<int> given) {
  int min = given.at(0),
      max = given.at(0);
  vector<int>result;
  vector<int>::iterator git = given.begin();
  for(; git != given.end(); ++git)
    if(*git > max) max = *git;
    else if(*git < min) min = *git;
  for(; min <= max; ++min)
    result.push_back(min);
  return result;
}

vector<int> computeCycle(vector<int> given) {
  //create ordered list (min, min+1, ..., max)
  vector<int> result = genOrdList(given);
  //permute ordered list
  /* (a b c ... z) = (a z)(a y)...(a b) */
  vector<int>::reverse_iterator rit = result.rbegin();
  for(; rit != result.rend()-1; ++rit)
    swap(*rit, result.at(0));
  return result;
}
