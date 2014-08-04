#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


//declaration of namespace
namespace cop4530
{

//template class declaration class Stack
template <typename T>
class Stack{

//adaptee class vector
protected:
 std::vector<T> Container;

public:
//public member functions
  Stack();
  ~Stack ();
  Stack(const Stack<T>&);  
  Stack(Stack<T> &&);
  Stack<T>& operator= (const Stack <T>&);
  Stack<T> & operator=(Stack<T> &&);
  bool empty() const; 
  void clear();
  void push(const T& x);
  void push(T && x);
  void pop();
  T& top();
  const T& top() const;  
  int size() const;
  void print(std::ostream& os, char ofc = ' ') const;

}; //end of Stack class

//non-member functions
template <typename T>
std::ostream& operator<< (std::ostream& os, const Stack<T>& a);    

template <typename T>
bool operator== (const Stack<T>&, const Stack <T>&);

template <typename T>
bool operator!= (const Stack<T>&, const Stack <T>&);

template <typename T>
bool operator< (const Stack<T>& a, const Stack <T>& b);



#include "stack.hpp"



}//end of namespace

#endif
