/*comparing values if equal
char = which one has smaller ASCII value
words/numbers which one came first in original input*/
/*
Programmer: Neil Ballard
FSUID: npb12
Instructor: Duan
Course: COP4530
Assignment#: 1

Summary:
The purpose of this program is to read in input through IO redirection
and provide 3 seperate rankings, listing in descending order based on the
number of occurences of characters, words and number sequences

Input:
Input for this program is done through IO redirection

Output:
Top occurences of characters, string and word sequences
along with the number of occurences



Code-Credit: 
The development of this program was assisted by John Nguyen and
his recitation example

*/

#include "bproj1.cpp"



int main(int argc, char **argv)

{
//local variable declarations
string s;
char x, peeker, n;

//Objects of class declared 
CharClass chard;
StringClass word, sequence;

//while loop until end of input
while(cin.peek() != char_traits<char>::eof())
{

  x = cin.get();  
  chard.fillMap(x);       //pass x into character map
  if(isalpha(x))
  {
    n = tolower(x);       //change all to lowercase
    s += n;               //add to string if alpha
    peeker = cin.peek();
    if(!isalpha(peeker))   //checking next character for continuing string
    {
       
      word.FillWordMap(s);  //pass string to string map
      s = "";

    }
  }
  else if(isdigit(x))
  {
    s += x;
    peeker = cin.peek();
    if(!isdigit(peeker))       //check if next is still a number
    { 
      sequence.FillSeqMap(s);  //pass number string to map
      s = "";
    }
  }
  else 
  {
    x = ' ';
  }
  
}
//call functions to pass map to respective vectors
chard.fillVector();
word.FillWordVector();
sequence.FillSeqVector();
cout << endl << endl;


//call functions to output vectors
chard.showVector();
cout << endl << endl;
word.ShowWordVector();
cout << endl << endl;
sequence.ShowSeqVector();


return 0;

}
