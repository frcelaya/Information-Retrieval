#include <vector>


using namespace std;


class Token_Data {
public:
  Token_Data();
  Token_Data(int _docID, int _freq, vector<int> _lines);
  ~Token_Data();

  void set_docID(int _docID);
  int get_docID();
  void set_freq(int _freq);
  void increment_freq();
  int get_freq();
  void set_lines(vector<int> _lines);
  vector<int> get_lines();

  unsigned int docID;
  unsigned int freq;
  vector<int> lines;
};


Token_Data::Token_Data() {}

Token_Data::~Token_Data() {}

Token_Data::Token_Data(int _docID, int _freq, vector<int> _lines) {
  set_docID(_docID);
  set_freq(_freq);
  set_lines(_lines);
}

void Token_Data::set_docID(int _docID) { 
  if (_docID >= 0) { docID= _docID; }
  return;
}

int Token_Data::get_docID() { return docID; }

void Token_Data::set_freq(int _freq) {
  if (_freq >= 0) { freq = _freq; }
  return;
}

void Token_Data::increment_freq() { freq++; }

int Token_Data::get_freq() { return freq; }

void Token_Data::set_lines(vector<int> _lines) {
  lines = _lines;
  return;
}

vector<int> Token_Data::get_lines() { return lines; }