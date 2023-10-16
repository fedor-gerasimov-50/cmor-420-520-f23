#include <iostream>

class Vector{

public:
  
  Vector(int length){
    _length = length;
    _data = new double [length];
  }

  int length() const{
    return _length;
  }

  // enables indexing (e.g., x[i] = 10.0);
  double & operator[](const int i){
    return _data[i];
  }

  // a "const" version of the same operator
  const double & operator[](const int i) const{
    return _data[i];
  }

  void print(std::string name);
  
private:
  
  int _length;
  double * _data;
  friend Vector operator+(const Vector & x, const Vector & y);
  
};

void Vector::print(std::string name){
  for (int i = 0; i < _length; ++i){
    std::cout << name << "[" << i << "] = ";
    std::cout << _data[i] << std::endl;
  }
}

// a "free" function. Note that this calls the
// "const" version of the operator overloading
Vector operator+(const Vector & x, const Vector & y){
  Vector out(x._length);
  for (int i = 0; i < x.length(); ++i){
    out[i] = x[i] + y[i];
  }
  return out;
}


int main(void){

  int length = 2;
  Vector x(length);
  x[0] = 1.1;
  x[1] = 1.2;  
  x.print("x");

  Vector y(length);
  y[0] = 0.9;
  y[1] = 0.8;  
  y.print("y");

  Vector z = (x + y);
  z.print("(x+y)");
}
