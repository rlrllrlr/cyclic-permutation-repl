#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

bool isInt(string given) {
  string::iterator foo = given.begin();
  for(; foo != given.end(); ++foo)
    if(!isdigit(*foo))
      return false;
  return true;
}

vector<string> categorize(string given) {
  string::iterator foo = given.begin();
  vector<string> result;
  string collect;
  while(foo != given.end()) {
    if(isdigit(*foo))
      collect += *foo;
    else switch(*foo) {
      case ' ':
        if(collect != "") {
          result.push_back(collect);
          collect = "";
        }
      break;
      case ')':
        if(collect != "")
          result.push_back(collect);
        result.push_back(")");
      break;
      default:
        result.push_back(string(1, *foo));
    }
    foo += 1;
  }
  return result;
}

void match(string token, vector<string>& given) {
  if(given.at(0) == token)
    given.erase(given.begin());
  else {
    cout << "error, expected '"
         << token << "'\n";
    exit(0);
  }
}

vector<int> series(vector<string>& given) {
  vector<string>::iterator git = given.begin();
  vector<int> nums;
  for(; git != given.end(); ++git) {
    if(isInt(*git))
      nums.push_back(atoi(git->c_str()));
    else if(*git == ")") {
      given.erase(given.begin(), git);
      return nums;
    }
    else {
      cout << "error in series, unexpected '"
           << *git << "'\n";
      exit(0);
    }
  }
}

vector<int> cycle(vector<string> given) {
  vector<int> nums;
  match("(", given);
  nums = series(given);
  match(")", given);
  return nums;
}
