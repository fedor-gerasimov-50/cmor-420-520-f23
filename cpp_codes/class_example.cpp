#include <iostream>

class Vector{

public:
  // constructor
  Vector(int length){
    _length = length;
    _data = new double [length];
  }

  // destructor  
  ~Vector(){
    delete [] _data;
  }

  // copy constructor
  Vector(const Vector & copy_from){
    _length = copy_from.get_length();
    _data = new double [_length];
    for (int i = 0; i < _length; ++i){
      _data[i] = copy_from[i];
    }
  }

  // copy move constructor
  Vector & operator=(const Vector & copy_from){
    if (_length != copy_from.get_length()){
      std::cout << "ERROR: vectors are not the same length";
      std::cout << std::endl;
    }
    
    for (int i = 0; i < _length; ++i){
      _data[i] = copy_from[i];
    }

    return *this;
  }
  
  
  // function declarations
  int get_length() const{
    return _length;
  };

  void print(std::string variable_name);

  double & operator[](const int index) const {  
    return _data[index];
  }
  
  Vector & operator+=(Vector x){
    for (int i = 0; i < x.get_length(); ++i){
      _data[i] += x[i];
    }
    return *this; // pointer to the instance 
  }
  
private:  

  int _length;
  double * _data;
  
};

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

int main(void) {

  int n = 5;
  Vector x(n);
  Vector y(n);
  for (int i = 0; i < n; ++i){
    x[i] = i;
    y[i] = 1-i;
  }

  x.print("x");
  y.print("y");
  
  // this calls the "copy constructor"
  Vector z = x;
  z.print("(Vector z = x)");

  // this calls the "copy move constructor"
  z = y;
  y[0] = 13;
  z.print("(z = y)");
  
  return 0;
}
