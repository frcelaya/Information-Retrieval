#ifndef __TEXTS_H_INCLUDED__
#define __TEXTS_H_INCLUDED__

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include "Get_Texts_Paths.h"

typedef map<string, int> MStrInt;

using namespace std;

MStrInt Create_Text_Map() {
  string line;
  MStrInt text_map;

  ifstream myfile("Texts/Stop-words.txt");
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      //TODO: Llenar el mapa
    }
    myfile.close();
  }
  else {
    cout << "Unable to open file";
  }

  return text_map;
}

#endif