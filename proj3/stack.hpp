
//default constructor
template <class T>
Stack<T>::Stack()
{
 
}
//destructor
template <class T>
Stack<T>::~Stack()
{
  Container.clear();
}
//copy constructor
template <class T>
Stack<T>::Stack(const Stack<T>& rhs)
{
  operator=(rhs);
}

template <class T>
Stack<T>::Stack(Stack<T> && rhs) : Container{rhs.Container}
{
  rhs.Container = nullptr; //maybe change back
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack <T>& rhs)
{
  if(this != &rhs)
    Container = rhs.Container;
  return *this;

}

template <class T>
Stack<T>& Stack<T>::operator=(Stack<T> && rhs)
{
  std::swap(Container, rhs.Container);
  return *this;

}

template <class T>
bool Stack<T>::empty() const
{
  if(Container.empty())
    return true;
  else
    return false;
}

template <class T>
void Stack<T>::clear()
{
  while(!empty())
  {
    Container.pop_back();
  }

}

template <class T>
void Stack<T>::push(const T& x)
{
  Container.push_back(x);
}

template <class T>
void Stack<T>::push(T && x)
{
  Container.push_back(x);

}

template <class T>
void Stack<T>::pop()
{
  Container.pop_back();
}

template <class T>
T& Stack<T>::top()
{
  return Container.back();
}

template <class T>
const T& Stack<T>::top() const
{
  return Container.back();
}

template <class T>
int Stack<T>::size() const
{
  return Container.size();

}

template <class T>
void Stack<T>::print(std::ostream& os, char ofc) const
{
  for(auto &x: Container)
    os << ofc;

}



//non-member functions
template <class T>
std::ostream& operator<< (std::ostream& os, const Stack<T>& a)
{
  a.print(os);
  return os;
}

template <class T>
bool operator== (const Stack<T>& lhs, const Stack <T>& rhs)
{        

  return (&lhs ==&rhs);
               

}   

template <class T>
bool operator!= (const Stack<T>& lhs, const Stack <T>& rhs)
{
  return !(lhs == rhs); 
}

template <class T>
bool operator< (const Stack<T>& lhs, const Stack <T>& rhs)
{
  return (&lhs < &rhs);
}

