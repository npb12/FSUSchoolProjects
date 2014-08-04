#include "List.h"


/*
const_iterator class
*/

//default constructor
template <class T>
List<T>::const_iterator::const_iterator()
{
  current = nullptr;
}

//overload of * operator
template <class T>
const T& List<T>::const_iterator::operator*() const
{
  return retrieve();
}

//overload of preincrement operator
template <class T>
typename List<T>::const_iterator::
const_iterator& List<T>::const_iterator::operator++()
{
  current = current->next;
  return *this;

}

//post increment operator
template <class T>
typename List<T>::const_iterator
List<T>::const_iterator::operator++(int)
{
  const_iterator old = *this;
  ++(*this);
  return old;

}

//overaload of predecrement operator
template <class T>
typename List<T>::const_iterator&
List<T>::const_iterator::operator--()
{
  current = current->prev;
  return *this;

}

//overload of postincrement operator
template <class T>
typename List<T>::const_iterator
List<T>::const_iterator::operator--(int)
{
  const_iterator old = *this;
  --(*this);
  return old;

} 

//overload of == opeartor
template <class T>
bool List<T>::const_iterator::operator==(const const_iterator &rhs) const
{
  return current == rhs.current;
}

//overload of != operator
template <class T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const
{
  return !(*this == rhs);
}

//retrieve function
template <class T>
T& List<T>::const_iterator::retrieve() const
{
  return current->data;
}
//current node declared
template <class T>
List<T>::const_iterator::const_iterator(Node *p)
{
  current = p;
}



/*
beginning of iterator class
*/
//overload of * operator
template <class T>
T& List<T>::iterator::operator*()
{
  return const_iterator::retrieve();
}

//overload of * const operator
template <class T>
const T& List<T>::iterator::operator*() const
{
  return const_iterator::operator*();
}

//overload of preincrmenet operator
template <class T>
typename List<T>::iterator&
List<T>::iterator::operator++()
{
  this->current = this->current->next;
  return *this;
}

//overload of post increment
template <class T>
typename List<T>::iterator
List<T>::iterator::operator++(int)
{
  iterator old = *this;
  ++(*this);
  return old;

}

//overload of predecrement operator
template <class T>
typename List<T>::iterator&
List<T>::iterator::operator--()
{
  this->current = this->current->prev;
  return *this;

}

//overload of post decrement operator
template <class T>
typename List<T>::iterator
List<T>::iterator::operator--(int)
{
  iterator old = *this;
  --(*this);
  return old;

}

template <class T>
List<T>::iterator::iterator(Node *p)
{
 this->current = p;
}









/*
beginning of list class
*/



//init function new node
template <class T>
void List<T>::init()
{
  theSize = 0;
  head = new Node;
  tail = new Node;
  head->next = tail;
  tail->prev = head;
}

//default constructor
//default constructor for List class
template <class T>
List<T>::List()
{
  init();
}

//push_back list elemnts 
template <class T>
List<T>::List(const List & rhs)
{
  init();
  for(auto &x: rhs)
    push_back(x);
}

//explicit constructor
template <class T>
List<T>::List(int num, const T& val)
{
  head = new Node;
  Node* n = head;
  for(int i = 0; i < num; i++)
  {       
    n = n->next = new Node(val, n, NULL);
  }       
  n->next = tail; 
  tail->prev = n; 
  theSize = 0;

}

template <class T>
List<T>::List(List && rhs): theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
{
  rhs.theSize = 0;
  rhs.head = nullptr;
  rhs.tail = nullptr;
}
//inputIterator start/end constructor
template <class T>
List<T>::List(const_iterator start, const_iterator end)
{

  init();
  while(start != end)
  {
    push_back(*start);
    start++;
  }
}

//destructor
template <class T>
List<T>::~List()
{
  clear();
  delete head;
  delete tail;
}


//assignment operator overload
template <class T>
const List<T>& List<T>::operator=(const List & rhs)
{
  List copy = rhs;
  std::swap(*this, copy);
  return *this;
}

template <class T>
List<T>& List<T>::operator=(List && rhs)
{
  std::swap(theSize, rhs.theSize);
  std::swap(head, rhs.head);
  std::swap(tail, rhs.tail);

}

//return theSize
template <class T>
int List<T>::size() const
{
  return theSize;
}

//return if size is 0
template <class T>
bool List<T>::empty() const
{
  return size() == 0;
}
//pop through list
template <class T>
void List<T>::clear()
{
  while(!empty())
      pop_front();
}


//reverse function produces segfault
template <class T>
void List<T>::reverse()
{
/*
     Node *temp = NULL;  
     Node *current = head;
      
    
     while (current !=  NULL)
     {
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;              
       current = current->prev;
     }      
      
     if(temp != NULL )
        head = temp->prev; 
*/
}


template <class T>
T& List<T>::front()
{
  return *begin();
}

template <class T>
const T& List<T>::front() const
{
  return *begin();
}

template <class T>
T& List<T>::back()
{
  return *--end();
}

template <class T>
const T& List<T>::back() const
{
  return *--end();
}

template <class T>
void List<T>::push_front(const T & val)
{
  insert(begin(), val);
}

template <class T>
void List<T>::push_front(T && val)
{
  insert(begin(), std::move(val));
}

template <class T>
void List<T>::push_back(const T & val)
{
  insert(end(), val);
}

template <class T>
void List<T>::push_back(T && val)
{
  insert(end(), std::move(val));
}

template <class T>
void List<T>::pop_front()
{
  erase(begin());
}

template <class T>
void List<T>::pop_back()
{
  erase(--end());
}


//remove function specific key
template <class T>
void List<T>::remove(const T &val)
{
/*
  if(head==NULL) 
  { 
     return; 
  } 
  if(head->data==val) 
  { 
    head=head->next; 
    head->prev=NULL; 
    return; 
  } 
  if(tail->data==val) 
  { 
    tail=tail->prev; 
    tail->next=NULL; 
    return; 
  } 
  Node *p= head->next; 
  while(p!=NULL) 
  { 
    if(p->data==val) 
      break; 
    p=p->next; 
  } 
  if(p==NULL) 
  { 
    return; 
  } 
  (p->prev)->next=p->next; 
  
  (p->next)->prev=p->prev; 

  
*/
}
//print function
template <class T>
void List<T>::print(std::ostream& os, char o) const
{
 
  for(Node* l = head->next; l != tail; l = l->next)
  {
    os << l->data; 
    if(l->next != tail)
      os << o;
  }

}

template <class T>
typename List<T>::iterator
List<T>::begin()
{
  return {head->next};
}

template <class T>
typename List<T>::const_iterator
List<T>::begin() const
{
  return {head->next};
}

template <class T>
typename List<T>::iterator
List<T>::end()
{
  return{tail};
}


template <class T>
typename List<T>::const_iterator
List<T>::end() const
{
  return{tail};
}


template <class T>
typename List<T>::iterator
List<T>::insert(iterator itr, const T & val)
{
  Node *p = itr.current;
  theSize++;
  return{p->prev = p->prev->next = new Node{val, p->prev, p}};

}


template <class T>
typename List<T>::iterator
List<T>::insert(iterator itr, T && val)
{
  Node *p = itr.current;
  theSize++;
  return{p->prev = p->prev->next = new Node{std::move(val), p->prev, p}};

}


template <class T>
typename List<T>::iterator
List<T>::erase(iterator itr)
{
  Node *p = itr.current;
  iterator retVal{p->next};
  p->prev->next = p->next;
  p->next->prev = p->prev;
  delete p;
  theSize--;

  return retVal;

}

template <class T>
typename List<T>::iterator
List<T>::erase(iterator start, iterator end)
{
  for(iterator itr = start; itr != end;)
    itr = erase(itr); 
  
  return end;
}


/*


overloading operators outside of class

*/

//overload output stream operator
template <class T>
std::ostream& operator<<(std::ostream &os, const List<T> &l)
{
  l.print(os); 
  return os;
}

/*
overload comparison operators
*/
template <class T>
bool operator==(const List<T> & lhs, const List<T> &rhs)
{

   auto ls = lhs.begin();
   auto rs = rhs.begin();
   while (ls != lhs.end() && rs != rhs.end())
   {
     if(*ls != *rs)
       return false;
     ls++; 
     rs++;
    }
    return true;

 
}

template <class T> 
bool operator!=(const List<T> & lhs, const List<T> &rhs)
{   
  return !(lhs==rhs);
}


