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
  double get_index(int i) const{
    return _data[i];
  }
  void set_index(int i, double value){
    _data[i] = value;
  }
  void print(std::string name);
  
private:
  
  int _length;
  double * _data;
};

void Vector::print(std::string name){
  for (int i = 0; i < _length; ++i){
    std::cout << name << "[" << i << "] = " << _data[i] << std::endl;
  }
}

// a "free" function
Vector operator+(const Vector & x, const Vector & y){
  Vector out(x.length());
  for (int i = 0; i < x.length(); ++i){
    out.set_index(i, x.get_index(i) + y.get_index(i));
  }
  return out;
}


int main(void){

  int length = 2;
  Vector x(length);
  x.set_index(0, 1.1);
  x.set_index(1, 2.2);  
  x.print("x");

  Vector y(length);
  y.set_index(0, 0.9);
  y.set_index(1, 0.8);  
  y.print("y");

  Vector z = (x + y);
  z.print("(x+y)");
}
