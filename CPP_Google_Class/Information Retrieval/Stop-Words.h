#ifndef __STOP_WORDS_H_INCLUDED__
#define __STOP_WORDS_H_INCLUDED__

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

vector<string> Create_StopWords_Vector() {
  string line;
  vector<string> stopwords_v;

  ifstream myfile("Texts/Stop-words.txt");
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      stopwords_v.push_back(line);
    }
    myfile.close();
  }
  else {
    cout << "Unable to open file";
    return { "Unable to open file" };
  }

  return stopwords_v;
}

#endif