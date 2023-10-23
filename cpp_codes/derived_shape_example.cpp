#include <iostream>

class Shape2D {
 public:
  Shape2D(void) {}

  // note: this is new constructor syntax!
  Shape2D(double w, double h) : width_(w), height_(h) {
    // other constructor stuff goes here.
  }
  
  void SetWidth(double w){ width_ = w; }
  void SetHeight(double h){ height_ = h; }
  double GetWidth(void) const { return width_; }
  double GetHeight(void) const { return height_; }

  // "= 0" implements a "pure" virtual function
  // "pure" virtual functions *must* be specialized or
  // implemented in any derived classes
  virtual double GetArea(void) = 0;

 protected:
  double width_;
  double height_;
};

class Triangle : public Shape2D{
 public:
  // new constructor syntax
  Triangle(double w, double h) : internal_field_(12), Shape2D(w, h) {}
  
  double GetArea(void) { return 0.5 * GetWidth() * GetHeight(); }
  
 private:
   int internal_field_;
};

class Polygon2D: public Shape2D {
  virtual double GetArea(void){
    std::cout << "Polygon2D GetArea implementation TBD" << std::endl;
    return 0.0;
  };
};

class Rectangle : public Polygon2D { // Polygon2D is a subclass of Shape2D
 public:
  double GetArea(void) { return width_ * height_; }
};

int main(void) {
  /*
  // Create an instance of Shape2D
  Shape2D shape;
  shape.SetWidth(3.0);
  shape.SetHeight(1.0);

  // equivalent to above
  Shape2D another_shape(3.0, 1.0);
  // No way to compute area for a Shape2D type
  */  

  // How to create a Rectangle instance? The following doesn't work...
  // Rectangle rect(3.0, 1.0);
  // This is because constructors aren't inherited.
  // Instead, we need to do:
  Rectangle rect;
  rect.SetWidth(3.0);
  rect.SetHeight(1.0);
  std::cout << "rectangle width is " << rect.GetWidth() << std::endl;
  std::cout << "rectangle area is " << rect.GetArea() << std::endl;

  Triangle tri(3.0, 1.0);
  std::cout << "triangle width is " << tri.GetWidth() << std::endl;
  std::cout << "triangle area is " << tri.GetArea() << std::endl;

}

