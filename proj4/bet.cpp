/*
Author: Neil Ballard
Project: 4
Date: 3/31/14
*/

/*
sources:
I used this source to help me get started constructing the 
binary expression tree
  http://www.cprogramming.com/tutorial/lesson18.html
*/


#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>
#include <stack>
#include <cctype>
#include <algorithm>
using namespace std;

/*
functions used by members
*/
/*
series of lambda functions used for checking 
for correct characters
*/
bool isalnumb(const string& s)
{
  return !s.empty() &&  find_if(s.begin(),
    s.end(), [](char c){ return !isalnum(c); }) == s.end();
}

bool isHigher(const string& s)
{
  return !s.empty() &&  find_if(s.begin(),
    s.end(), [](char c){ return !(c=='*') && !(c=='/'); })  == s.end();
}

bool isLower(const string& s)
{
  return !s.empty() &&  find_if(s.begin(),
    s.end(), [](char c){ return !(c=='+') && !(c=='-'); })  == s.end();
}


/*
public member functions
*/


//default constructor
BET::BET()
{

  root = NULL;

}

//single param constructor, postifix passed in
//passed value to buildfrompostfix
BET::BET(const string postfix)
{
  root = NULL;
  buildFromPostfix(postfix);

}

//copy constructor
//calls the operator= method
BET::BET(const BET& rhs)
{
  root = NULL;
  operator=(rhs);
}

//destructor
//calls makeEmpty function
BET::~BET()
{
  makeEmpty(root);

}

/*
this function recieves a string which is 
then sepearated into a vector. The vector is then
passed into the stack and made into a BinaryExpressionTree 
*/
bool BET::buildFromPostfix(const string postfix)
{
   istringstream ss;
   vector<string> v;
   stack<BinaryNode *> s;
   string st;
   if( !empty( ) )
      makeEmpty(root);
   ss.str(postfix);
   copy(istream_iterator<string>(ss), istream_iterator<string>( ), 
         back_inserter(v));
   ss.str("");
 
   auto itr = v.begin();

   while(itr != v.end())
   {
     st = *itr;
     if(isalnumb(st))
     {
       BinaryNode *n = new BinaryNode;
       n->element = st;
       n->right = NULL;
       n->left = NULL;
       s.push(n);
     }
     else
     {
       root = new BinaryNode;
       root->element = st;
       root->right = s.top();
       s.pop();
       root->left = s.top();
       s.pop();
       s.push(root);
     }
     st = ""; 
     ++itr;
   } 
  
   
   if(s.size() > 0)
    return true;
   else
     return false;
  
}

//assignment operator calls clone function
const BET & BET::operator= (const BET & rhs)
{
  if(this != &rhs)
  {
    makeEmpty(root);
    root = clone(rhs.root);
  }
  return *this;
}

//calls private printinfixExpression function
void BET::printInfixExpression()
{
  if(root == NULL)
    return;

  printInfixExpression(root);
  cout << endl;
}

//calls private version of print postfix
void BET::printPostfixExpression()
{
  if(root == NULL)
    return;

  printPostfixExpression(root);
  cout << endl;
}

//calls private version of size function 
//returns number of nodes
size_t BET::size()
{
  return size(root);
}

//calls private version of leaf_nodes
//returns # of leaf nodes
size_t BET::leaf_nodes()
{

  return leaf_nodes(root);

}

//returns true if tree is empty
//false otherwise
bool BET::empty()
{

  return (root == NULL);

}



/*
private functions
all functions are ran recursively
*/
//print infix expression
//Uses lambda functions for correct output
//add parenthesis when necessary
void BET::printInfixExpression(BinaryNode *n)
{
  if(n->left != NULL)
  { 
    if(isHigher(n->element) && isLower(n->left->element))
    { 
      cout << "( "; 
    }
    
    printInfixExpression(n->left);
    
    if(isHigher(n->element) && isLower(n->left->element))
    { 
       cout << ") "; 
    }
  }
  cout << n->element << " ";
 
  if(n->right != NULL)
  {
    if((isHigher(n->element) && (isHigher(n->right->element) || isLower(n->right->element))) || (isLower(n->element) && isLower(n->right->element)))
    {
      cout << "( ";
    }

    printInfixExpression(n->right);

    if((isHigher(n->element) && (isHigher(n->right->element) || isLower(n->right->element))) || (isLower(n->element) && isLower(n->right->element)))
    {
      cout << ") ";
    }
  }
}

//deletes all nodes in subtree pointed to by t
//called by destructor
void BET::makeEmpty(BinaryNode* &t)
{
  if(t != NULL)
  { 
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
  }

  t = NULL;

}

//clones all nodes in subtree of t
//called by the assignment operator
BET::BinaryNode * BET::clone(BinaryNode *t) const
{
  if(t == NULL)
    return NULL;
 

  BinaryNode *n = new BinaryNode; 
  n->element = t->element;
  n->left = clone(t->left);
  n->right = clone(t->right);
  return n;
}

//print postfix expression
//called by public member function 
void BET::printPostfixExpression(BinaryNode *n)
{
  if(n->left != NULL)
    printPostfixExpression(n->left);
  
  if(n->right != NULL)
    printPostfixExpression(n->right);
  
  
  cout << n->element << " ";


  

}

//return # of nodes in subtree
//called by public member
size_t BET::size(BinaryNode *t)
{
  if(t == NULL)
    return 0;
  else
    return 1+ size(t->left) + size(t->right);

}

//return # of leaf nodes in subtree
//called by public member function  
size_t BET::leaf_nodes(BinaryNode *t)
{
  if(t == NULL)
    return 0;
  else if(t->left == NULL && t->right == NULL)
    return 1;
  else
    return leaf_nodes(t->left) + leaf_nodes(t->right);  


}  

