#ifndef __TEXTS_H_INCLUDED__
#define __TEXTS_H_INCLUDED__

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 
#include <sstream>
#include <algorithm>
#include "Stop-Words.h"
#include "Get_Texts_Paths.h"


typedef map<string, int> MStrInt;

void strip(string &);
bool starts_with(string s, string t);

using namespace std;


MStrInt Create_Text_Map() {
  string line, word;
  MStrInt text_map;
  MStrInt::iterator text_map_it;
  vector<string> stop_words_v = Create_StopWords_Vector();
  vector<string> texts_paths_v = Get_Files_In_Dir("Texts\\", "*.txt");
  vector<string>::iterator texts_paths_it = texts_paths_v.begin();
  
  ifstream myfile(texts_paths_v[0]);
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      stringstream ss(line);
      while (ss.good()) {
        ss >> word;
        if (!starts_with(word, "http")){
          strip(word);
          if (!binary_search(stop_words_v.begin(), stop_words_v.end(), word)){
            text_map_it = text_map.find(word);
            (text_map_it != text_map.end()) ? text_map[word]++ : text_map[word] = 1;
          }
        }
      }
    }
    myfile.close();
  }
  else {
    cout << "Unable to open file";
    MStrInt error_map;
    error_map.insert(std::pair<string, int>("Unable to open file", -1));
    return error_map;
  }

  return text_map;
}


void strip(string &s) {
  // Strip leading and trailing punctuation
  string::iterator i = s.begin();
  while (!s.empty() && ispunct(*i)) s.erase(i);
  string::reverse_iterator j = s.rbegin();
  while (!s.empty() && ispunct(*j)) {
    s.resize(s.length() - 1);
    j = s.rbegin();
  }
}

bool starts_with(string s, string t) {
  bool b = false;
  if (s.compare(0, t.length(), t) == 0)
  {
    b = true;
  }
  return b;
}

#endif