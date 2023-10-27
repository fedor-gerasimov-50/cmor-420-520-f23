#include <iostream>

class Rectangle {
public:
  void set_width(double w) { width = w; }
  void set_height(double h) { height = h; }
  double area() const { return width * height; }

private:
  double width, height;
};

// protected/private inheritance = implemented-in-terms-of
class Square : protected Rectangle {
public:
  void set_side(double s) {
    // `set_width` and `set_height` become "protected"
    // functions, usable within Square but not outside
    // the class. 
    set_width(s);  
    set_height(s);
  }
  
  double area() const {
    // Specify the base class to access private function
    return Rectangle::area(); 
  }
};

int main(void){
  Square square;
  square.set_side(1.0);
  std::cout << "Square area is " << square.area();
  std::cout << std::endl;
  return 0;
}
