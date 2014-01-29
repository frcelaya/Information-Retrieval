#include <iostream>
#include <fstream>
#include "Texts.h"


using namespace std;


int main(int argc, char *argv[]) {
  //vector<string> stop_words_v = Create_StopWords_Vector();
  //vector<string> texts_paths_v = Get_Files_In_Dir("Texts\\", "*.txt");
  map<string, int> text_map = Create_Text_Map();
  map<string, int>::iterator text_map_it;
  //vector<string>::iterator stop_words_it = stop_words_v.begin();
  //vector<string>::iterator texts_paths_it = texts_paths_v.begin();
  //cout << "List of stop-words:\n";
  //for (stop_words_it; stop_words_it != stop_words_v.end(); stop_words_it++) {
  //  cout << *stop_words_it << endl;
  //}
  //cout << "List of text paths:\n";
  //for (int i = 0; i < texts_paths_v.size(); i++) {
  //  cout << texts_paths_v[i] << endl;
  //}

  //ofstream text_map1("C:/Users/Fernando/Desktop/textmap1.txt");
  //for (text_map_it = text_map.begin(); text_map_it != text_map.end(); ++text_map_it) {
  //  text_map1 << text_map_it->first << " = " << text_map_it->second << endl;
  //}
  //text_map1.close();

  cin.sync();
  cin.get();

  return 0;
}
