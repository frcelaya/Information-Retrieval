#include <iostream>
#include <fstream>
#include "Stop-Words.h"
#include "Texts.h"

using namespace std;

int main(){
  vector<string> stop_words_v = Create_StopWords_Vector();
  vector<string> texts_paths_v = Get_Files_In_Dir("Texts\\", "*.txt");
  //vector<string>::iterator stop_words_it = stop_words_v.begin();
  //vector<string>::iterator texts_paths_it = texts_paths_v.begin();

  //cout << "List of stop-words:\n";
  //for (stop_words_it; stop_words_it != stop_words_v.end(); stop_words_it++) {
  //  cout << *stop_words_it << endl;
  //}

  cout << "List of text paths:\n";
  for (int i = 0; i < texts_paths_v.size(); i++) {
    cout << texts_paths_v[i] << endl;
  }

  cin.sync();
  cin.get();

  return 0;
}