#include <stdio.h>
#include <windows.h>
#include "Texts.h"
#include "token_data.h"

using namespace std;



int main(int argc, char *argv[]) {
  /*
  vector<MStrInt> text_maps_v = Create_Text_Map();
  vector<MStrInt>::iterator text_maps_it = text_maps_v.begin();
  MStrInt::iterator current_map_it;

  for (int i = 0; i < text_maps_v.size(); i++){
    int c = 0;
    cout << text_maps_v.size() << endl; 

    for (text_maps_it; text_maps_it != text_maps_v.end(); ++text_maps_it) {
      c++;
      string next_file = "textmap" + to_string(c);
      ofstream text_maps_file("Texts/Maps/" + next_file + ".txt");
      MStrInt current_map = *text_maps_it;
      text_maps_file << current_map.size() << endl;

      for (current_map_it = current_map.begin(); current_map_it != current_map.end(); ++current_map_it) {
        text_maps_file << current_map_it->first << " = " << current_map_it->second << endl;
      }
      text_maps_file.close();
    }    
  }*/

  /*
  Token_Data untoken = Token_Data();

  untoken.set_docID(0);
  untoken.set_freq(10);
  vector<int> lineas = { 1, 2, 3, 4, 5, 10 };
  untoken.set_lines(lineas);

  Token_Data otrotoken = Token_Data(untoken.get_docID(), untoken.get_freq(), untoken.get_lines());
  otrotoken.increment_freq();

  cout << "Un token" << endl;
  cout << "DocID: " << untoken.docID << endl;
  cout << "Freq: " << untoken.freq << endl;
  cout << "Lines: ";
  for (int i = 0; i < untoken.lines.size(); i++)
    cout << untoken.lines[i] << " ";
  cout << endl << endl;

  cout << "Otro token" << endl;
  cout << "DocID: " << otrotoken.docID << endl;
  cout << "Freq: " << otrotoken.freq << endl;
  cout << "Lines: ";
  for (int i = 0; i < otrotoken.lines.size(); i++)
    cout << otrotoken.lines[i] << " ";
  cout << endl << endl;
  */

  cin.sync();
  cout << "Presione una tecla para salir...";
  cin.get();

  return 0;
}
