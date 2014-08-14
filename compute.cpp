#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(vector<int> &given, int alpha, int beta) {
  vector<int>::iterator ait, bit;
  ait = find(given.begin(), given.end(), alpha);
  bit = find(given.begin(), given.end(), beta);

  *ait = *ait ^ *bit;
  *bit = *ait ^ *bit;
  *ait = *ait ^ *bit;
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
  vector<int> ordered = genOrdList(given);
  //permute ordered list
  /* (a b c ... z) = (a z)(a y)...(a b) */
  vector<int>::iterator git = given.begin()+1;
  for(; git != given.end(); ++git)
    swap(ordered, given.at(0), *git);
  return ordered;
}
