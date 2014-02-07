#include "stdafx.h"
#include "CppUnitTest.h"
#include "Stop-Words.h"
#include "Texts.h"
#include "Token_Data.h"


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
      for (unsigned int i = 0; i < stop_words_v1.size(); i++) {
        if (stop_words_v1[i] != stop_words_v2[i]) {
          are_equal = false;
        }
      }
      Assert::AreEqual(true, are_equal);
    }
  };

  TEST_CLASS(Texts_Tester)
  {
  public:
    TEST_METHOD(Test_Get_Files_In_List)
    {
      vector<string> texts_paths_v = Get_Files_In_List("Texts/List.txt");
      vector<string> wrong_params_v = Get_Files_In_List("x");
      vector<string> error_v = { "Error opening file " };

      bool error_is_equal = (wrong_params_v == error_v)? true: false;
      Assert::AreEqual(true, error_is_equal);
    }

    TEST_METHOD(Test_Is_Bad_Word)
    {
      Assert::AreEqual(true, Is_Bad_Word(""), L"Error with empty string");
      Assert::AreEqual(true, Is_Bad_Word("1989"), L"Error with string 1989");
      Assert::AreEqual(true, Is_Bad_Word("-1989"), L"Error with string -1989");
      Assert::AreEqual(false, Is_Bad_Word("--1989"), L"Error with string --1989");
      Assert::AreEqual(true, Is_Bad_Word("01z"), L"Error with string 01z");
      Assert::AreEqual(true, Is_Bad_Word("10"), L"Error with string 10");
      Assert::AreEqual(true, Is_Bad_Word("http://www.gutenberg.net/2/4/6/8/24689"), L"Error with http string");
    }

    TEST_METHOD(Test_Is_Stop_Word)
    {
      vector<string> v;
      string word = "";
      Assert::AreEqual(false, Is_Stop_Word(v, word));
    }

    TEST_METHOD(Test_Starts_With)
    {
      Assert::AreEqual(false, Starts_With("", "string"), L"Error comparing empty string to string");
      Assert::AreEqual(false, Starts_With("string", ""), L"Error comparing string to empty string");
      Assert::AreEqual(true, Starts_With("", ""), L"Error comparing two empty string");
    }

    TEST_METHOD(Test_Strip)
    {
      char* test = "";
      Strip(string(test));
      Assert::AreEqual("", test, L"Error sending empty string");

      test = "under_score";
      Strip(string(test));
      Assert::AreEqual("under_score", test, L"Error sending under_score");
    }
  };

  /*
  TEST_CLASS(Token_Data_Tester)
  {
  public:
    TEST_METHOD(Test_Token_Data_Constructor)
    {
      bool test = false;
      vector<int> vl = { 1, 2, 3 };
      Token_Data td = Token_Data(-1, -1, vl);
      if (td.docID == -1 && td.freq == -1 && td.lines == vl) { test = true; }
      Assert::AreEqual(false, test, L"Error constructing with parameters.");

      td.set_freq(td.get_freq() - (td.get_freq() + 1));
      Assert::AreEqual(false, (td.get_freq() == -1), L"Error when testing negative frequency.");

      td.set_docID(td.get_docID() - (td.get_docID() + 1));
      Assert::AreEqual(false, (td.get_docID() == -1), L"Error when testing negative docID.");
    }
  };
  */
}