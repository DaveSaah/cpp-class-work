/**
 * ID: 72522025
 * author: David Saah
 */
#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
using std::cout;
using std::endl;
using std::invalid_argument;
using std::make_shared;
using std::setfill;
using std::setw;
using std::shared_ptr;
using std::string;

// shape_size defines the size of a shape
struct shape_size {
  double width;
  double length;
  double radius;
};

// ShapeAttributesFactory defines the attributes of a shape
class ShapeAttributesFactory {
public:
  /**
   * createColor creates a color for a shape
   * @return color
   */
  virtual string createColor() const = 0;

  /**
   * createSize creates the size of the shape
   * @return size of the shape
   */
  virtual shape_size createSize() const = 0;
};

class ColorFactory : public ShapeAttributesFactory {
public:
  string createColor() const override { return "red"; }
  shape_size createSize() const override { return shape_size{0, 0, 5}; }
};

class SizeFactory : public ShapeAttributesFactory {
public:
  string createColor() const override { return "blue"; }
  shape_size createSize() const override { return shape_size{4, 5, 0}; }
};

// Shape defines a base class from which other shapes are created
class Shape {
protected:
  string name, color;
  shape_size shapeSize;
  string edge;

public:
  /**
   * Constructor
   *
   * @param n name of the shape
   * @param attr a shape attributes factory
   */
  Shape(string n, const ShapeAttributesFactory &attr)
      : name(n), color(attr.createColor()), shapeSize(attr.createSize()) {}

  /**
   * Displays information about the shape
   */
  virtual void display() const = 0;

  /** Sets the edge of the shape
   *
   * @param e edge of the shape
   */
  void setEdge(string e) { edge = e; }
};

// Circle defines a circle shape
class Circle : public Shape {
public:
  /**
   * Constructor
   *
   * @param attr a shape attributes factory
   */
  Circle(const ShapeAttributesFactory &attr) : Shape("Circle", attr) {}

  /**
   * Displays information about the circle
   */
  void display() const override {
    cout << "Name: " << name << endl;
    cout << "Color: " << color << endl;
    cout << "Radius: " << shapeSize.radius << endl;
    cout << "Edge: " << edge << endl;
    cout << setw(18) << setfill('-') << " " << endl;
    cout << endl;
  }
};

// Rectangle defines a rectangle shape
class Rectangle : public Shape {
public:
  /**
   * Constructor
   *
   * @param attr a shape attributes factory
   */
  Rectangle(const ShapeAttributesFactory &attr) : Shape("Rectangle", attr) {}

  /**
   * Displays information about the circle
   */
  void display() const override {
    cout << "Name: " << name << endl;
    cout << "Color: " << color << endl;
    cout << "Width: " << shapeSize.width << endl;
    cout << "Length: " << shapeSize.length << endl;
    cout << "Edge: " << edge << endl;
    cout << setw(18) << setfill('-') << " " << endl;
    cout << endl;
  }
};

// ShapeFactory defines a factory class that creates shapes
class ShapeFactory {
public:
  /**
   * Creates a shape based on the type
   *
   * @param type type of shape to create
   * @return a pointer to the created shape
   * @throws error if an invalid type is provided
   */
  shared_ptr<Shape> makeShape(string type) {
    ColorFactory colorFactory;
    SizeFactory sizeFactory;

    if (type == "Circle") {
      return make_shared<Circle>(colorFactory);
    } else if (type == "Rectangle") {
      return make_shared<Rectangle>(sizeFactory);
    }

    throw invalid_argument("Invalid shape type provided");
  }
};

// ShapeBuilder build custom shapes
class ShapeBuilder {
protected:
  string name;
  string edge_type;
  ShapeAttributesFactory *attributes;

public:
  virtual void buildEdgeType() = 0;
  virtual void buildAttributeFactory() = 0;
};

// RectangleBuilder builds a rectangle shape
class RectangleBuilder : public ShapeBuilder {
private:
  Rectangle *shape;

public:
  void buildEdgeType() override { edge_type = "Straight"; }
  void buildAttributeFactory() override { attributes = new SizeFactory(); }
  shared_ptr<Rectangle> build() {
    shape = new Rectangle(*attributes);
    shape->setEdge(edge_type);
    return make_shared<Rectangle>(*shape);
  }
};

// CircleBuilder builds a circle shape
class CircleBuilder : public ShapeBuilder {
private:
  Circle *shape;

public:
  void buildEdgeType() override { edge_type = "Curved"; }
  void buildAttributeFactory() override { attributes = new ColorFactory(); }
  shared_ptr<Circle> build() {
    shape = new Circle(*attributes);
    shape->setEdge(edge_type);
    return make_shared<Circle>(*shape);
  }
};

int main() {
  ShapeFactory shapeFactory;

  shared_ptr<Shape> circle = shapeFactory.makeShape("Circle");
  shared_ptr<Shape> rectangle = shapeFactory.makeShape("Rectangle");

  RectangleBuilder rectangleBuilder;
  rectangleBuilder.buildEdgeType();
  rectangleBuilder.buildAttributeFactory();
  shared_ptr<Rectangle> customRectangle = rectangleBuilder.build();

  CircleBuilder circleBuilder;
  circleBuilder.buildEdgeType();
  circleBuilder.buildAttributeFactory();
  shared_ptr<Circle> customCircle = circleBuilder.build();

  circle->display();
  rectangle->display();
  customRectangle->display();
  customCircle->display();
}
