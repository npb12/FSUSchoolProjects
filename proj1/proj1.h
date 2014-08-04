#ifndef PROJ1_H
#define PROJ1_H

#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <typeinfo>

using namespace std;

/*
template that takes in all types
and returns the second value that is 
greater than
*/

template<typename T1, typename T2>
struct LessThan
{
  typedef pair<T1, T2> T;
  bool operator()(T const& a, T const& b) const
  {
     return a.second > b.second;
  }
};


class CharClass
{


//public member function declarations
public:
  void fillVector();  
  void fillMap(char);
  void showVector();
//private data declarations
  private:
  map<char, int> chars;
  vector<pair<char,int> > top_chars;
  
};

//class declaration
class StringClass
{
  vector<pair<string,int> > copy1, copy2;
  map<string,int>::iterator itr;  //map iterator for class to use

//public member function declarations
public:
  void FillWordMap(string);
  void FillSeqMap(string);
  void FillWordVector();
  void FillSeqVector();
  void ShowWordVector();
  void ShowSeqVector();

  private:
  map<string, int> words;
  vector<pair<string,int> > top_words;
  map<string, int> sequence;
  vector<pair<string,int> > top_seq;
};


#endif
