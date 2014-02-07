#ifndef __TEXTS_H_INCLUDED__
#define __TEXTS_H_INCLUDED__

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include "Stop-Words.h"
#include "Token_Data.h"
#include <windows.h>


typedef map<string, int> MStrInt;
typedef map<string, map<int, Token_Data>> PostingList;


bool Is_Bad_Word(string s);
bool Is_Stop_Word(vector<string> stop_words_v, string word);
bool Starts_With(string s, string t);
void Strip(string &);
vector<MStrInt> Create_Text_Map();
vector<string> Get_Files_In_List(string path);
map<int, string> Create_DocIDs_M();


using namespace std;


vector<MStrInt> Create_Text_Map() {
  string line, word;
  MStrInt text_map;
  MStrInt::iterator text_map_it;
  vector<MStrInt> text_maps_v;
  vector<string> stop_words_v = Create_StopWords_Vector();
  vector<string> texts_paths_v = Get_Files_In_List("Texts/List.txt");
  vector<string>::iterator texts_paths_it = texts_paths_v.begin();
  
  for (texts_paths_it; texts_paths_it != texts_paths_v.end(); ++texts_paths_it) {
    cout << "Starting map for "<< *texts_paths_it << endl;
    ifstream myfile(*texts_paths_it);
    if (myfile.is_open()) {
      while (getline(myfile, line)) {
        stringstream ss(line);
        while (ss.good()) {
          ss >> word;
          if (!Is_Bad_Word(word)){
            Strip(word);
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (!Is_Stop_Word(stop_words_v, word)){
              text_map_it = text_map.find(word);
              (text_map_it != text_map.end()) ? text_map[word]++ : text_map[word] = 1;
            }
          }
        }
      }
      text_maps_v.push_back(text_map);
      text_map.clear();
      myfile.close();
    }
    else {
      cout << "Unable to open file";
      MStrInt error_map;
      error_map.insert(std::pair<string, int>("Unable to open file " + *texts_paths_it, -1));
      text_maps_v.push_back(error_map);
    }
  }

  return text_maps_v;
}


PostingList Create_Posting_List() {
  unsigned int line_count;
  string line, word;
  PostingList pl;
  PostingList::iterator pl_it;
  map<int, Token_Data>::iterator td_it;
  vector<string> stop_words_v = Create_StopWords_Vector();
  vector<string> texts_paths_v = Get_Files_In_List("Texts/List.txt");


  for (unsigned int i = 0; i < texts_paths_v.size(); i++) {
    cout << "Starting map for " << texts_paths_v[i] << endl;
    ifstream myfile(texts_paths_v[i]);
    if (myfile.is_open()) {
      line_count = 0;
      while (getline(myfile, line)) {
        line_count++;
        stringstream ss(line);
        while (ss.good()) {
          ss >> word;
          if (!Is_Bad_Word(word)){
            Strip(word);
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (!Is_Stop_Word(stop_words_v, word)) {
              pl_it = pl.find(word);
              if (pl_it != pl.end()) {
                td_it = pl_it->second.find(i);
                if (td_it != pl_it->second.end()) {
                  pl_it->second[i].increment_freq();
                  pl_it->second[i].push_back_line(line_count);
                }
                else {
                  pl_it->second[i] = Token_Data(1, { line_count });
                }
              }
              else {
                Token_Data tk = Token_Data(1, { line_count });
                map<int, Token_Data> m;
                m[i] = tk;
                pl[word] = m;
              }
            }
          }
        }
      }
      myfile.close();
    }
    /*else {
    cout << "Unable to open file";
    MStrInt error_map;
    error_map.insert(std::pair<string, int>("Unable to open file " + *texts_paths_it, -1));
    text_maps_v.push_back(error_map);
    }*/
  }

  return pl;
}


map<int, string> Create_DocIDs_M() {
  map<int, string> docIDs;
  vector<string> texts_paths_v = Get_Files_In_List("Texts/List.txt");

  for (unsigned int i=0; i < texts_paths_v.size(); i++) {
    docIDs[i] = texts_paths_v[i];
  }

    return docIDs;
}

bool Is_Bad_Word(string s){
  bool bad_word = false;

  if (s == "")                                                      { bad_word = true; }
  else if (s[0] >= 48 && s[0] <= 57)                                { bad_word = true; }
  else if (s[0] == '-' && (s[1] >= 48 && s[1] <= 57))               { bad_word = true; }
  else if (Starts_With(s, "http"))                                  { bad_word = true; }

  for (unsigned int i = 0; i < s.size(); i++) {
    if (s[i] < -1 || s[i] > 255) {
      bad_word = true;
      break;
    }
  }

  return bad_word;
}


bool Is_Stop_Word(vector<string> stop_words_v, string word){
  return binary_search(stop_words_v.begin(), stop_words_v.end(), word);
}


void Strip(string &s) {
  // Strip leading and trailing punctuation
  string::iterator i = s.begin();
  while (!s.empty() && ispunct(*i)) s.erase(i);
  string::reverse_iterator j = s.rbegin();
  while (!s.empty() && ispunct(*j)) {
    s.resize(s.length() - 1);
    j = s.rbegin();
  }
}


bool Starts_With(string s, string t) {
  bool b = false;

  if (s.empty() || t.empty()) { (s == t) ? b = true : b = false; }
  else if (s.compare(0, t.length(), t) == 0) { b = true; }

  return b;
}


vector<string> Get_Files_In_List(string path)
{
  vector<string> texts_paths_v;
  string line;
  ifstream in(path);
  if (in.is_open())
  {
    while (getline(in, line)) {
      // do stuff with the file here
      texts_paths_v.push_back("Texts/" + line);
    }
  }
  else
  {
    cout << "Error opening file " << "\n";
    return { "Error opening file " };
  }

  return texts_paths_v;
}


#endif