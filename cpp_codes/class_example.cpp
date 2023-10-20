#include <iostream>

class Vector{
public:
  Vector(int length){
    _length = length;
    _data = new double [length];
  }

  /*
  // destructor
  ~Vector(){
    delete [] _data;
  }
  */

  // function declarations
  int get_length(){
    return _length;
  };

  void print(std::string variable_name);

  double & operator[](const int index){
    return _data[index];
  }

  Vector & operator+=(Vector x){
    for (int i = 0; i < x.get_length(); ++i){
      _data[i] += x[i];
    }
    return *this; // pointer to the instance that calls this function
  }
  
private:  

  int _length;
  double * _data;
  
};

Vector operator+(Vector x, Vector y){
  Vector out(x.get_length());
  for (int i = 0; i < out.get_length(); ++i){
    out[i] = x[i] + y[i];
  }
  return out;
}

Vector operator*(double x, Vector & y){
  Vector out(y.get_length());
  for (int i = 0; i < out.get_length(); ++i){
    out[i] = x * y[i];
  }
  return out;
}

Vector operator*(Vector x, double y){
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

  Vector z = x + y;
  z.print("z");

  return 0;
}
