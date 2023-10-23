#include<iostream>
#include "vector.hpp"

// copy constructor  
Vector::Vector(const Vector & copy_from){
  _length = copy_from.get_length();
  _data = new double [_length];
  for (int i = 0; i < _length; ++i){
    _data[i] = copy_from[i];
  }
}

// copy move constructor  
Vector & Vector::operator=(const Vector & copy_from){
  if (_length != copy_from.get_length()){
    std::cout << "ERROR: vectors are not the same length";
    std::cout << std::endl;
  }
    
  for (int i = 0; i < _length; ++i){
    _data[i] = copy_from[i];
  }

  return *this;
}
  
Vector & Vector::operator+=(Vector x){
  for (int i = 0; i < x.get_length(); ++i){
      _data[i] += x[i];
  }
  return *this; // pointer to the instance 
}

Vector operator+(const Vector & x, const Vector & y){
  Vector out(x.get_length());
  for (int i = 0; i < out.get_length(); ++i){
    out[i] = x[i] + y[i];
  }
  return out;
}

Vector operator*(double x, const Vector & y){
  Vector out(y.get_length());
  for (int i = 0; i < out.get_length(); ++i){
    out[i] = x * y[i];
  }
  return out;
}

Vector operator*(const Vector & x, double y){
  return y * x;
}

void Vector::print(std::string variable_name){
  for (int i = 0; i < _length; ++i){
    std::cout << variable_name << "[" << i << "] = ";
    std::cout << _data[i] << std::endl;
  }
}

