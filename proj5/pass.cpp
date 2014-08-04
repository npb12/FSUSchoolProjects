#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include "hashtable.h"


using namespace std;
using namespace cop4530;

void Menu();

int main()
{

int capacity;
string s;
char c;
bool num;
     
stringstream ss;	 
	 
num = false;

while(!num)
{
  cout << "Enter preferred hash table capacity: ";
  cin >> s;
   
  for(unsigned int i = 0; i < s.size(); i++)
  {
    if(!isdigit(s[i]))
    {
      cout << "*****Error: Invalid capacity. Try again." << endl;
      num = false;
      break;
    }
  }
  num = true;
}
  ss.str(s);
  ss >> capacity;
  
   HashTable table(capacity);
   while(c != 'x')
   {
      Menu();
        
      
      cin >> s;
  
      while(s.size() > 1)
      {
        cout << "*****Error: Invalid entry. Try again." << endl;
      }
      c = s[0];
         
      switch(c)
      {
         case 'l':
            table.loadFile( );
            break;
         case 'a':
            table.addUser( );
            break;
         case 'r':
            table.deleteUser( );
            break;
         case 'c':
            table.changePass( );
            break;
         case 'f':
            table.findUser( );
            break;
         case 'd':
            table.printHash( );
            break;
         case 's':
            cout << "Size of hashtable: " << table.size( ) << endl;
            break;
         case 'w':
            table.writeFile( );
            break;
         case 'x':
            break;
         default:
            cout << "*****Error: Invalid entry. Try again." << endl;
            break;
      }
   }

   return(EXIT_SUCCESS);
}

void Menu()
{
  cout << "\n\n";
  cout << "l - Load From File" << endl;
  cout << "a - Add User" << endl;
  cout << "r - Remove User" << endl;
  cout << "c - Change User Password" << endl;
  cout << "f - Find User" << endl;
  cout << "d - Dump HashTable" << endl;
  cout << "s - HashTable Size" << endl;
  cout << "w - Write to Password File" << endl;
  cout << "x - Exit program" << endl;
  cout << "\nEnter choice : ";
}
