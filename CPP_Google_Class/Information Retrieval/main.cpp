#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "Stop-Words.h"

using namespace std;

int main(){
  vector<string> stop_words_v = Create_StopWords_Vector();
  vector<string>::iterator stop_words_it = stop_words_v.begin();

  cout << "List of stop-words:\n";
  for (stop_words_it; stop_words_it != stop_words_v.end(); stop_words_it++) {
    cout << *stop_words_it << endl;
  }

  cin.sync();
  cin.get();

  return 0;
}