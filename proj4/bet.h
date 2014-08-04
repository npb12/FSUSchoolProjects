#ifndef BET_H
#define BET_H

#include <string>


using namespace std;
/*
class declaration
*/
class BET
{
//declaring private members and a constructing BinaryNode
private:
  struct BinaryNode
  {
    string element;
    BinaryNode *left;
    BinaryNode *right;

  };


  void printInfixExpression(BinaryNode *n);
  void makeEmpty(BinaryNode* &t);
  BinaryNode * clone(BinaryNode *t) const;
  void printPostfixExpression(BinaryNode *n);
  size_t size(BinaryNode *t);
  size_t leaf_nodes(BinaryNode *t);
  BinaryNode *root;

//public members
public:

  BET(); 
  BET(const string postfix);
  BET(const BET&);
  ~BET();
  bool buildFromPostfix(const string postfix); 
  const BET & operator= (const BET &);
  void printInfixExpression(); 
  void printPostfixExpression();
  size_t size(); 
  size_t leaf_nodes();
  bool empty();


}; //end of BET class

#include "bet.cpp"


#endif
