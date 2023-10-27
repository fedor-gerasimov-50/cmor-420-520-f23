#include <iostream>

class ScaledVector;

class Vector{
public:
  Vector(int length){
    _length = length;
    _ptr = new double[length];
  }

  ~Vector(){
    delete[] _ptr;
  }

  int get_length() const { return _length; }

  double & operator[](int i){
    return _ptr[i];
  }
  
  void operator+=(const Vector &x){
    for (int i = 0; i < _length; ++i){
      this->_ptr[i] += x._ptr[i];
    }
  }

  // provide a function declaration
  void operator+=(const ScaledVector &x);
  
  void print(std::string variable_name);

protected:
  int _length;
  double * _ptr;
};

// (a scaling factor) * (x::Vector)
class ScaledVector : public Vector{
public:  
  ScaledVector(int length, double scaling) : Vector(length){
    _scaling = scaling;
  }

  double & operator[](int i){
    return _ptr[i];
  }
  
  double operator[](int i) const{
    return _ptr[i] * _scaling;
  }
  
protected:
  double _scaling;
};

void Vector::print(std::string variable_name){  
  for (int i = 0; i < _length; ++i){
    std::cout << variable_name << "[" << i << "] = ";
    std::cout << (*this)[i] << std::endl;
  }
}


// now that ScaledVector is defined, we can define +=
void Vector::operator+=(const ScaledVector & x){
  for (int i = 0; i < _length; ++i){
    this->_ptr[i] += x[i];
  }
}


int main(void){

  Vector x(4);
  ScaledVector y(4, 1.0);  
  for (int i = 0; i < x.get_length(); ++i){
    x[i] = i;
    y[i] = 1-i;
  }
  x.print("x");
  y.print("y");  
  x += y; 
  x.print("(x+y)");
 
}
