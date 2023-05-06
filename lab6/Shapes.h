#pragma once

#include <iostream>
using namespace std;

class Shape{
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
    virtual ~Shape();  //virtual distructor; Reference: polymorphisim lecture
};

class Shape2D : virtual public Shape{
public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual string GetName2D() const = 0;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;
};

class Shape3D : virtual public Shape{
public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual string GetName3D() const = 0;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
};

//------------2D Shapes--------------
class Square:public Shape2D{
public:
    float side;
    float scaleFactor;
    Square();
    Square(float side);

    void Scale(float scaleFactor);
    void Display() const;
    float Area() const;
    string GetName2D() const;
};

class Triangle:public Shape2D{
public:
    float base;
    float height;
    float scaleFactor;
    Triangle();
    Triangle(float base, float height);

    void Scale(float scaleFactor);
    void Display() const;
    float Area() const;
    string GetName2D() const;
};

class Circle:public Shape2D{
public:
    float radius;
    float scaleFactor;
    Circle();
    Circle(float radius);

    void Scale(float scaleFactor);
    void Display() const;
    float Area() const;
    string GetName2D() const;
};

//------------3D Shapes--------------
class TriangularPyramid:public Shape3D, private Triangle{
private:
    float height;
public:
    float length;
    float baseHeight;
    float scaleFactor;
    TriangularPyramid();

    //reference: inheritance lecture
    TriangularPyramid(float height, float length, float baseHeight): Triangle(length, baseHeight){
        this->height = height;
        this->length = length;
        this->baseHeight = baseHeight;
    }

    void Scale(float scaleFactor);
    void Display() const;
    float Volume() const;
    string GetName3D() const;
};
class Cylinder:public Shape3D, private Circle{
private:
    float height;
public:
    float radius;
    float scaleFactor;
    Cylinder();

    //reference: inheritance lecture
    Cylinder(float height, float radius): Circle(radius){
        this->height = height;
        this->radius = radius;
    }

    void Scale(float scaleFactor);
    void Display() const;
    float Volume() const;
    string GetName3D() const;
};

class Sphere:public Shape3D, private Circle{
private:
    float radius;
public:
    float scaleFactor;
    Sphere();

    //reference: inheritance lecture
    Sphere(float radius): Circle(radius){
        this->radius = radius;
    }

    void Scale(float scaleFactor);
    void Display() const;
    float Volume() const;
    string GetName3D() const;
};

