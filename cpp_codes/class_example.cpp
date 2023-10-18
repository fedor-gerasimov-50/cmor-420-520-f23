#include <cstdio> 
#include <iostream>

class Vector{
public:
  Vector(int length){
    _length = length;
    _data = new double [length];
  }

  //  return_type operator[](inputs){
  //    
  //  }

  // function declaration
  void print(std::string variable_name); 
  
private:  
  int _length;
  double * _data;
  
};

void Vector::print(std::string variable_name){
  for (int i = 0; i < _length; ++i){
    std::cout << variable_name << "[" << i << "] = ";
    std::cout << _data[i] << std::endl;
  }
}

int main(void) {

  Vector xx(13);
  xx.print("xx");
  
  return 0;
}
