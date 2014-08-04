#include "proj1.h"
 
//add character to map and increment
void CharClass::fillMap(char c)
{ 
  ++chars[c];
}


//loop to pass map pairs to vector
void CharClass::fillVector()
{
  map<char,int>::iterator ptr;

  for(ptr = chars.begin(); ptr != chars.end(); ++ptr)
  {
    top_chars.push_back(*ptr);
  }
}




/*
Function: ShowVector
function calls LessThan to sort vector in descening 
order from beginning to end. The size of vector is checked
for output in order to avoid seg fault. Function also 
checks for tab and newline in order to output characters 
correctly
*/
void CharClass::showVector()
{
int x = top_chars.size();
  
  sort(top_chars.begin(), top_chars.end(), LessThan<char,int>());
if(x >= 10)
{
  cout << "Total " << x << " characters, 10 most used characters:" << endl;
  for(int i = 0; i < 10; ++i)
  {
    if(top_chars[i].first == '\t')
    {
       cout << "No. " << i << ": " << "\\t" << "\t\t" << top_chars[i].second << endl;
    }
    else if(top_chars[i].first == '\n')
    {
       cout << "No. " << i << ": " << "\\n" << "\t\t" << top_chars[i].second << endl;
    }
    else
    {
      cout << "No. " << i << ": " << top_chars[i].first << "\t\t" << top_chars[i].second << endl;
    }

  }
}
else
{
  cout << "Total " << x << " characters, " << x << " most used characters:" << endl;
  for(int c = 0; c < x; ++c)
  { 
    if(top_chars[c].first == '\t')
    {
       cout << "No. " << c << ": " << "\\t" << "\t\t" << top_chars[c].second << endl;
    }
    else if(top_chars[c].first == '\n')
    {
      cout << "No. " << c << ": " << "\\n" << "\t\t" << top_chars[c].second << endl;
    }
    else
    {
      cout << "No. " << c << ": " << top_chars[c].first << "\t\t" << top_chars[c].second << endl;
    }
  }
}

}

//add string pass to map
void StringClass::FillWordMap(string s)
{
  ++words[s];
}

//add number string to map
void StringClass::FillSeqMap(string s)
{
  ++sequence[s];

}

//pushing word map into vector
void StringClass::FillWordVector()
{

  for(itr = words.begin(); itr != words.end(); ++itr)
  {
     top_words.push_back(*itr);
  }
}

//pushing number sequence map into vector
void StringClass::FillSeqVector()
{

  for(itr = sequence.begin(); itr != sequence.end(); ++itr)
  {
    top_seq.push_back(*itr);
  }

}

/*
Function: ShowWordVector
Function sorts top_words vector and outputs vector element and number
of occurences in descending order
*/
void StringClass::ShowWordVector()
{
int x = top_words.size();
//stable sort should be sorting function from first appearance if a equal second element is met
stable_sort(top_words.begin(), top_words.end(), LessThan<string,int>());

if(x >= 10)
{
  cout << "Total " << x << " different words, 10 most used words:" << endl;
  for(int i = 0; i < 10; ++i)
  {
    cout << "No. " << i << ": " << top_words[i].first << "\t\t" << top_words[i].second << endl;
  }
}
else
{
  cout << "Total " << x << " different words, " << x << " most used words:" << endl;
  for(int n = 0; n < x; ++n)
  {
    cout << "No. " << n << ": " << top_words[n].first << "\t\t" 
    << top_words[n].second << endl;
  }
}

}

//same function as ShowWordVector except outputs top_seq vector pairs
void StringClass::ShowSeqVector()
{

int x = top_seq.size();

stable_sort(top_seq.begin(), top_seq.end(), LessThan<string,int>());


if(x >= 10)
{ 
  cout << "Total " << x << " different numbers, 10 most used numbers:" << endl;
  for(int i = 0; i < 10; ++i)
  {
    cout << "No. " << i << ": " <<  top_seq[i].first << "\t\t" <<
    top_seq[i].second << endl;

  }
}
else
{ 
  cout << "Total " << x << " different numbers, " << x << " most used numbers:" << endl;
  for(int c = 0; c < x; ++c)
  {
    cout << "No. " << c << ": " <<  top_seq[c].first << "\t\t" <<
    top_seq[c].second << endl;
  }
}

}
