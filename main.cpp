#include "./compute.cpp"
#include "./parse.cpp"
#include "./pretty.cpp"
using namespace std;

int main(void) {
  string user_in;
  //repl
  cout << "> ";
  while(getline(cin, user_in)) {
    vector<string> sorted;
    sorted = categorize(user_in);
    vector<int> data, data_out;
    data = cycle(sorted);
    data_out = computeCycle(data);
    vector<vector<int> > hist;
    hist.push_back(genOrdList(data));
    hist.push_back(data_out);
    cout << endl << prettyPerm(hist)
         << endl << endl;
    cout << "> ";
  }
  return 0;
}
