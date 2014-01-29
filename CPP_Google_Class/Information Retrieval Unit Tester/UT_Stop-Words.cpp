#include "stdafx.h"
#include "CppUnitTest.h"
#include "Stop-Words.h"
#include "Texts.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InformationRetrievalUnitTester
{		
  TEST_CLASS(Stop_Words_Tester)
  {
  public:
    TEST_METHOD(Test_Create_StopWords_Vector)
    {
      vector<string> stop_words_v1 = Create_StopWords_Vector();
      vector<string> stop_words_v2 = Create_StopWords_Vector();
      Assert::AreEqual(stop_words_v1.size(), stop_words_v2.size());

      bool are_equal = true;
      for (int i = 0; i < stop_words_v1.size(); i++) {
        if (stop_words_v1[i] != stop_words_v2[2]) {
          are_equal = false;
        }
      }
      Assert::AreEqual(true, are_equal);
    }
  };

  TEST_CLASS(Get_Texts_Paths_Tester)
  {
  public:
    TEST_METHOD(Test_Get_Files_In_Dir)
    {
      vector<string> texts_paths_v = Get_Files_In_Dir("Texts\\", "*.txt");
      vector<string> wrong_params_v = Get_Files_In_Dir("x", "y");
      vector<string> error_v = { "Error searching directory" };

      bool error_is_equal = (wrong_params_v == error_v)? true: false;
      Assert::AreEqual(true, error_is_equal);

      bool empty = false;
      vector<string>::iterator it = texts_paths_v.begin();
      for (it; it != texts_paths_v.end(); ++it) {
        empty = (*it == "") ? true : false;
      }
      Assert::AreEqual(false, empty);
    }
  };
}