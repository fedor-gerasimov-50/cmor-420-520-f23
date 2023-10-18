#include <iostream>

class Vector{

public:
  
  Vector(int length){
    _length = length;
    _data = new double [length];
  }

  ~Vector(){
    delete [] _data;
  }

  Vector(const Vector & copy_from){
    _length = copy_from.length();
    _data = new double [_length];
    for (int i = 0; i < _length; ++i){
      _data[i] = copy_from[i];
    }
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

  Vector & operator+=(const double scalar){
    for (int i = 0; i < _length; ++i){
      _data[i] += scalar;
    }
    return *this;
  }

  Vector & operator+=(const Vector & x){
    for (int i = 0; i < _length; ++i){
      _data[i] += x[i];
    }
    return *this;
  }

  
  void print(std::string name);
  
private:
  
  int _length;
  double * _data;

  // declaring a "friend" method can be done anywhere
  //friend Vector operator+(const Vector & x, const Vector & y);
    
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
  Vector out(x.length());
  for (int i = 0; i < x.length(); ++i){
    out[i] = x[i] + y[i];
  }
  return out;
}

Vector operator*(const double x, const Vector & y){
  Vector out(y.length());
  for (int i = 0; i < y.length(); ++i){
    out[i] = x * y[i];
  }
  return out;
}

// for symmetry
Vector operator*(const Vector & x, const double y){
  return y * x;
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

  Vector z = 2 * (x + y);
  z.print("2 * (x+y)");

  // chained assignment
  x += y += z;
  x.print("x after +=");
  y.print("y after +=");
  z.print("z after +=");  

  //  Vector z = x;
  //z = y;
}
