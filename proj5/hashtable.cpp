#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include "hashtable.h"


static const unsigned int default_capacity = 11;

namespace cop4530
{

/*
default constructor
*/
HashTable::HashTable()
{
  bucketVector.resize(default_capacity);
}

/*
Constructor initializes the vector to the 
value of s
*/
HashTable::HashTable(size_t s)
{
  bucketVector.resize(prime_below(s));
}


/*
destructor
*/
HashTable::~HashTable()
{


  for(unsigned int i = 0; i < bucketVector.size(); i++)
  {
    bucketVector[i].clear();
  }


}


/*
Loadfile function gets the file from user input
and reads the file to the end, storing each 
username and password
*/
void HashTable::loadFile()
{
  ifstream infile;      
  string file;  
  string name;        
  string password;
  bool exists;
  int index;
     
  pair< string, string > info;      
  list< pair< string, string > >::iterator itr;

  cout << "Enter password file name to load from: ";
  cin >> file;

  infile.open( file.c_str());
  if(!infile)
  {
    cout << "*****Error: Unable to open file " << file << endl;
    return;
  }

  for( ; ; )
  {
    exists = false;
    if( infile.peek() == '\n')
    {
      infile.ignore( 1, '\n');
      continue;
    }
        
    getline( infile, name, ':');
    getline( infile, password, '\n' );
    password = "$1$########$" + password;
    
    info = make_pair(name, password);
       
    if( infile.eof())
        break;
    
    index = Index(name);

    
    itr = bucketVector[index].begin();
    while(itr != bucketVector[index].end())
    {
      if(itr->first == name)
      {
        if(itr->second == password)
        {
          cout << "*****Error: Duplicate username '" << name;
          cout << "'.  Duplicate ignored." << endl;
          exists = true;
          break;
        }
      }
      ++itr;
    }
    if(!exists)
        bucketVector[index].push_back(info);
   }
   infile.close();
}


/* function addUser recieves
input from the user. If the username is a 
duplicate, the user is retured a message,
otherwise the new user is added to the 
collection
*/
void HashTable::addUser()
{
  string name;
  string encryptedPass;
  string password;
  char salt[] = "$1$########";
  char* charPass = new char[40];
  int index;
  pair< string, string > info;
  list< pair< string, string > >::iterator itr;
	 
	 
  cout << "Enter name: ";
  cin >> name;
   
  cout << "Enter password: ";
  cin >> password;
    
   index = Index(name);
  
  itr = bucketVector[ index ].begin();
  while(itr != bucketVector[index].end())
  {
    if(itr->first == name)
    {
      cout << endl << "*****Error: User already exists. Could not add user." << endl;
      return;
    }
    ++itr;
  }
  
  strcpy( charPass, crypt(password.c_str(), salt));
  encryptedPass.assign(charPass);
  info = make_pair(name, encryptedPass);
  bucketVector[index].push_back(info);
  cout << endl << "User " << name << " added."<< endl;

}


/*
function deleteUser recieves a username
from the user. If the name is found, 
the index of the user is erased.
*/
void HashTable::deleteUser()
{
  string name;
  int index;
  bool found = false;
  list< pair< string, string > >::iterator itr;
  
  cout << "Enter username: ";
  cin >> name;
    
   index = Index(name);

   itr = bucketVector[index].begin();
   while(itr != bucketVector[index].end())
   {
     if(itr->first == name)
     {
       bucketVector[index].erase(itr);
       cout << "User " << name << " deleted." << endl;
       found = true;
       return;
     }
     ++itr;
   }
   if(!found)
      cout << "*****Error: User not found.  Could not delete user" << endl;
}

/*
function changePass recieves a username and
password from the user. The user is then
instructed to give a new password. The new
password 
*/ 
void HashTable::changePass()
{
  string name;
  string password;
  string newPass;
  string encryptedPass;
    
  int index;
  char* charPass = new char[40];
  char salt[] = "$1$########";
  list< pair< string, string > >::iterator itr;
   
  cout << "Enter name    : "; 
  cin >> name;
  
  cout << "Enter Password    : ";
  cin >> password;
  
  cout << endl << "Enter new password: ";
  cin >> newPass;
  
  index = Index(name);
    
  itr = bucketVector[index].begin(); 
  while(itr != bucketVector[index].end())
  {
    if(itr->first == name)
    {
      strcpy(charPass, crypt(password.c_str(), itr->second.c_str()));
      encryptedPass.assign(charPass);
      if(itr->second == encryptedPass)
      {
        strcpy(charPass, crypt(newPass.c_str(), salt));
        encryptedPass.assign(charPass);
        itr->second = encryptedPass;
        cout << endl << "Password changed for user " << name << endl;
        return;
      }
      else
      {
        cout << endl << "*****Error: Password incorrect.  Could not change user password" << endl;
        return;
      }
    } 
    itr++; 
  }
  
  cout << endl << "*****Error: User not found.  Could not change user password" << endl;

     
}


/*
function findUser recieves the username and
password for the desired user and returns 
a message based on whether the user was 
found or not
*/
void HashTable::findUser()
{
  string name;
  string password;
  string encryptedPass;
  int index;
  char* charPass = new char[40];
  list< pair< string, string > >::iterator itr;
  
  cout << "Enter name    : ";
  cin >> name;
     
  cout << "Enter password    : ";
  cin >> password;
     
  index = Index(name);
	 
  itr = bucketVector[index].begin();
  while(itr != bucketVector[index].end())
  {
    if(itr->first == name)
    {
      strcpy( charPass, crypt(password.c_str(), itr->second.c_str()));
      encryptedPass.assign(charPass);
  
      if(itr->second == encryptedPass)
      {
        cout << endl << "User '" << name << "' found." << endl;
        return;
      }
      else
      {
        cout << endl << "User '" << name << "' not found." << endl;
      }
    }
    ++itr;
  }

  cout << endl << "User '" << name << "' not found." << endl;
}


/*
function print hash outputs the elements of bucketVector
*/
void HashTable::printHash()
{
  list< pair< string, string > >::iterator itr;
  string output;
  string password;
  
  for(unsigned int i = 0; i < bucketVector.size(); i++)
  {
    cout << "v[" << i << "]: ";
    output.clear();
		
    itr = bucketVector[i].begin(); 
    while(itr != bucketVector[i].end())
    {
      if(itr->second[0] == '$')
      {
        password = itr->second.substr(12, 33);
      }
      else
      {
        password = itr->second;
      }    
      output = itr->first + ":" + password;
      cout << setw(34) << left << output;
      ++itr; 
    }
    cout << endl;
  }

}

/*
function size returns the size of the bucketVector
*/
int HashTable::size()
{
  int size = 0;

  for(unsigned int i = 0; i < bucketVector.size(); i++)
  {
    size = size + bucketVector[i].size();
  }
 
  return size;

}


/*
function writeFile allows the user to have the 
contents of the bucketVector written to a file
*/
void HashTable::writeFile()
{
  ofstream outfile;
  string file;
  string password;
     
  list< pair< string, string > >::iterator itr;
   
  cout << "Enter password file name to write to: ";
  cin >> file;
  
  outfile.open(file.c_str());
  for(unsigned int i = 0; i < bucketVector.size(); i++)
  {
    itr = bucketVector[i].begin(); 
    while(itr != bucketVector[i].end())
    {
      if(itr->second[0] == '$')
      {
        password = itr->second.substr(12, 33);
      }
      else
      {
        password = itr->second;
        outfile << itr->first << ":" << password << endl;
      }
      ++itr;
    }
  }
    outfile.close();

}



/*
Private Member functions
*/


//Returns the bucket index where the pair should be inserted
unsigned int HashTable::Index (const string & key)
{
  return hash_function(key) % bucketVector.capacity();
}

//Returns the hashed index
unsigned int HashTable::hash_function (const string & s)
{
  unsigned int i;
  unsigned long bigval = s[0];
  
  for (i = 1; i < s.size(); ++i)
    bigval = ((bigval & 65535) * 18000) + (bigval >> 16) + s[i];
    
  bigval = ((bigval & 65535) * 18000) + (bigval >> 16);
		
  return bigval & 65535;

}

// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n
unsigned int HashTable::prime_below (unsigned int n)
{
  if (n > max_prime)
  {
        std::cerr << "** input too large for prime_below()\n";
    return 0;
  }
  if (n == max_prime)
  {
    return max_prime;
  }
  if (n <= 1)
  {
        std::cerr << "** input too small\n";
    return 0;
  }

  // now: 2 <= n < max_prime
  vector <unsigned int> v (n + 1);
  setPrimes(v);
  
  while (n > 2)
  {
    if (v[n] == 1)
      return n;
    --n;
  }
 
  return 2;
}

//Sets all prime number indexes to 1. Called by method prime_below(n) 
void HashTable::setPrimes(vector<unsigned int>& vprimes)
{
  int i = 0;
  int j = 0;

  vprimes[0] = 0;
  vprimes[1] = 0;

  int n = vprimes.capacity();

  for (i = 2; i < n; ++i)
    vprimes[i] = 1;

  for( i = 2; i*i < n; ++i)
  {
    if (vprimes[i] == 1)
        for(j = i + i ; j < n; j += i)
            vprimes[j] = 0;
  }
}

}
#endif

