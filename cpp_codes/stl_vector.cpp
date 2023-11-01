#include <iostream>
#include <vector>

int main(void){

  // vector examples
  std::vector<int> x = {1, 2, 3, 4};

  std::cout << "x is size " << x.size() << " before `push_back`" << std::endl;
  
  x.push_back(4); // see also insert, pop_back, erase, swap, clear

  std::cout << "x is size " << x.size() << " after `push_back`" << std::endl;

  x.resize(10);
  
  std::cout << "x is size " << x.size() << " after `resize`" << std::endl;

  // iterators in C++
  std::vector<int>::iterator i; // generalized loop variable
  for (i = x.begin(); i != x.end(); ++i){
    std::cout << *i << " ";
  }
  std::cout << "]" << std::endl;
  
}
