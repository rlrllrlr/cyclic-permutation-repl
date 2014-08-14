#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string prettyPerm(vector<vector<int> > given) {
  stringstream result;
  vector<vector<int> >::iterator git = given.begin();
  vector<int>::iterator sgit;
  result << "(";
    for(; git != given.end(); ++git) {
      sgit = git->begin();
      for(; sgit != git->end(); ++sgit) {
        result << *sgit;
        if(sgit != git->end()-1)
          result << " ";
      }
      if(git != given.end()-1)
        result << " -> ";
    }
  result << ")";
  return result.str();
}
