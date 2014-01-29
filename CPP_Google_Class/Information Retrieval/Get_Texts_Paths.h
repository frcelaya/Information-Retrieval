//Source: http://forums.devarticles.com/showpost.php?p=200344&postcount=4
#ifndef __GET_FILES_IN_DIR_H_INCLUDED__
#define __GET_FILES_IN_DIR_H_INCLUDED__

#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

vector<string> Get_Files_In_Dir(string path, string searchPattern)
{
  vector<string> texts_paths_v;
  string fullSearchPath = path + searchPattern;

  WIN32_FIND_DATA FindData;
  HANDLE hFind;

  hFind = FindFirstFile(fullSearchPath.c_str(), &FindData);

  if (hFind == INVALID_HANDLE_VALUE)
  {
    cout << "Error searching directory\n";
    return { "Error searching directory" };
  }

  do
  {
    string filePath = path + FindData.cFileName;
    ifstream in(filePath.c_str());
    if (in)
    {
      // do stuff with the file here
      texts_paths_v.push_back(filePath);
    }
    else
    {
      cout << "Error opening file " << FindData.cFileName << "\n";
      return{ "Error opening file" };
    }
  } while (FindNextFile(hFind, &FindData) > 0);

  system("pause");
  return texts_paths_v;
}

#endif