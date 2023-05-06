#include <iostream>
#include "Shapes.h"
#include <math.h>
using namespace std;


//--------------2D Shapes--------------
//SQUARE

//default constructor
Square::Square() {
    side = 0.00f;
}

//constructor
Square::Square(float side) {
    this->side = side;
}

//scale factor
void Square::Scale(float scaleFactor){
    this->scaleFactor = scaleFactor;
}

//display information about square
void Square::Display()const{
    cout << "The area of the Square is: " << Area() << endl;

    if(scaleFactor > 1){  //scale factor is greater than one
        cout << "Length of a side: " << side*scaleFactor << endl;   //multiply variable by scalefactor
    }
    else{
        cout << "Length of a side: " << side << endl;
    }
}

//area of square
float Square::Area() const{
    float area = 0.00f;
    if(scaleFactor > 1){  //scale factor is greater than one
        area = pow(side, 2.0f)*pow(scaleFactor, 2.0f);  //multiply each variable by scalefactor
    }
    else{
        area = pow(side, 2.0f); //find area using formula
    }
    return area;
}

//get name for square
string Square::GetName2D() const{
    string name = "Square";

    return name;
}


//TRIANGLE

//default constructor
Triangle::Triangle() {
    base = 0.00f;
    height = 0.00f;
}

//constructor
Triangle::Triangle(float base, float height) {
    this->base = base;
    this->height = height;
}

//scale factor
void Triangle::Scale(float scaleFactor){
    this->scaleFactor = scaleFactor;
}

//display triangle information
void Triangle::Display()const{
    cout << "The area of the Triangle is: " << Area() << endl;
    if(scaleFactor > 1){
       //multiply each variable by scalefactor
        cout << "Base: " << base*scaleFactor << endl;
        cout << "Height: " << height*scaleFactor << endl;
    }
    else{
        cout << "Base: " << base << endl;
        cout << "Height: " << height << endl;
    }
}

//area of triangle
float Triangle::Area() const{
    float area = 0.00f;
    if(scaleFactor > 1){
       //multiply each variable by scalefactor
        area = (0.5f)*base*height*pow(scaleFactor, 2.0f);  //find area using formula
    }
    else{
        area = (0.5f)*base*height;  //find area using formula
    }

    return area;
}

//get name for triangle
string Triangle::GetName2D() const{
    string name = "Triangle";

    return name;
}

//CIRCLE

//default constructor
Circle::Circle() {
    radius = 0.00f;
}

//constructor
Circle::Circle(float radius) {
    this->radius = radius;
}

//scale factor
void Circle::Scale(float scaleFactor){
    this->scaleFactor = scaleFactor;
}

//print information about circle
void Circle::Display()const{
    cout << "The area of the Circle is: " << Area() << endl;
    if(scaleFactor > 1){
       //multiply each variable by scalefactor
        cout << "Radius: " << radius*scaleFactor << endl;
    }
    else{
        cout << "Radius: " << radius << endl;
    }

}

//area of circle
float Circle::Area() const{
    float area = 0.00f;
    const float PI = 3.14159f;
    if(scaleFactor > 1){
       //multiply each variable by scalefactor
        area = PI*pow(radius,2.0f)*pow(scaleFactor, 2.0f);
    }
    else{
        area = PI*pow(radius,2.0f);  //find area using formula
    }

    return area;
}

//get name for circle
string Circle::GetName2D() const{
    string name = "Circle";

    return name;
}

//AREA

//print area of shape
void Shape2D::ShowArea() const {
    cout << "The area of the " <<  GetName2D();
    cout << " is: " << Area() << endl;
}

//greater than comparision operator
bool Shape2D::operator>(const Shape2D &rhs) const {
   //reference: Zybooks 9.13 and operator overloading lecture

    bool b = true;
    //if area of current shape is greater than area of shape given in parameter
    if(Area() > rhs.Area()){
        b = true;  //assign variable as true
    }
    //if area of current shape is less than or equal to area of shape given in parameter
    else{
        b = false;  //assign varibale false
    }

    return b;  //return variable
}

//less-than comparision operator
bool Shape2D::operator<(const Shape2D &rhs) const {
    //reference: Zybooks 9.13 and operator overloading lecture

    bool b = true;
    //if area of current shape is less than area of shape given in parameter
    if(Area() < rhs.Area()){
        b = true;  //variable is true
    }
    //if area of current shape is greater than or equal to area of shape given in parameter
    else{
        b = false;  //variable is false
    }

    return b; //return variable
}

//equality comparision operator
bool Shape2D::operator==(const Shape2D &rhs) const {
   //reference: Zybooks 9.13 and operator overloading lecture

    bool b = true;
    //if area of current shape is equal to area of shape given in parameter
    if(Area() == rhs.Area()){
        b = true;  //variable is true
    }
    //if area of current shape is not equal to area of shape given in parameter
    else{
        b = false;  //variable is false
    }

    return b; //return variable
}


//--------------3D Shapes--------------

//TRIANGULAR PYRAMID

//default constructor
TriangularPyramid::TriangularPyramid(){
    height = 0.00f;
    length = 0.00f;
    baseHeight = 0.00f;
}
//scale factor
void TriangularPyramid::Scale(float scaleFactor) {
    this->scaleFactor = scaleFactor;
}

//display triangular pyramid information
void TriangularPyramid::Display() const {
    cout << "The volume of the Triangular Pyramid is: " << Volume() << endl;
    if(scaleFactor > 1){
       //multiply each variable by scalefactor
        cout << "The height is: " << height*scaleFactor << endl;
        cout << "The area of the Triangle is: " << Triangle::Area()*pow(scaleFactor,2.0f) << endl;
        cout << "Base: " << length*scaleFactor << endl;
        cout << "Height: " << baseHeight*scaleFactor << endl;
    }
    else{
        cout << "The height is: " << height << endl;
        cout << "The area of the Triangle is: " << Triangle::Area() << endl;
        cout << "Base: " << length << endl;
        cout << "Height: " << baseHeight << endl;
    }
}

//volume of triangular pyramid
float TriangularPyramid::Volume() const {
    float volume = 0.00f;
    if(scaleFactor > 1){
       //multiply each variable by scalefactor
        volume = (0.33333f)*height*Triangle::Area()*pow(scaleFactor,2.0f);
    }
    else{
        volume = (0.33333f)*height*Triangle::Area();
    }

    return volume;  //return volume
}

//get name for triangular pyramid
string TriangularPyramid::GetName3D() const {
    string name = "Triangular Pyramid";
    return name;
}


//CYLINDER

//default contructor
Cylinder::Cylinder() {
    height = 0.00f;
    radius = 0.00f;
}

//scale factor
void Cylinder::Scale(float scaleFactor) {
    this->scaleFactor = scaleFactor;
}

//display cylinder information
void Cylinder::Display() const {
    cout << "The volume of the Cylinder is: " << Volume() << endl;
    if(scaleFactor > 1){
       //multiply each variable by scalefactor
        cout << "The height is: " << height*scaleFactor << endl;
        cout << "The area of the Circle is: " << Circle::Area()*pow(scaleFactor,2.0f) << endl;
        cout << "Radius: " << radius*scaleFactor << endl;
    }
    else{
        cout << "The height is: " << height << endl;
        cout << "The area of the Circle is: " << Circle::Area() << endl;
        cout << "Radius: " << radius << endl;
    }
}

//volume for cylinder
float Cylinder::Volume() const {
    const float PI = 3.14159f;
    float volume = 0.00f;
    if(scaleFactor > 1){
       //multiply each variable by scalefactor
        volume = PI*height*pow(radius,2.0f)*pow(scaleFactor,3.0f);
    }
    else{
        volume = PI*height*pow(radius,2.0f);  //find volume using formula
    }

    return volume;
}

//get name for cylinder
string Cylinder::GetName3D() const {
    string name = "Cylinder";
    return name;
}


//SPHERE

//default constructor
Sphere::Sphere(){
    radius = 0.00;
}

//scale factor
void Sphere::Scale(float scaleFactor){
    this->scaleFactor = scaleFactor;
}

//display sphere information
void Sphere::Display() const{
    cout << "The volume of the Sphere is: " << Volume() << endl;
    if(scaleFactor > 1){
       //multiply each variable by scalefactor
        cout << "The area of the Circle is: " << Circle::Area()*pow(scaleFactor,2.0f) << endl;
        cout << "Radius: " << radius*scaleFactor << endl;
    }
    else{
        cout << "The area of the Circle is: " << Circle::Area() << endl;
        cout << "Radius: " << radius << endl;
    }
}

//volume for sphere
float Sphere::Volume() const{
    const float PI = 3.14159f;
    float volume = 0.00f;
    if(scaleFactor > 1){
       //multiply each variable by scalefactor
        volume = (1.3333333f)*PI*pow(radius,3.0f)*pow(scaleFactor,3.0f);
    }
    else{
        volume = (1.3333333f)*PI*pow(radius,3.0f);  //find volume using formula
    }

    return volume;
}

//get name for sphere
string Sphere::GetName3D() const{
    string name = "Sphere";

    return name;
}

//VOLUME FOR 3D SHAPES
//print volume of shape
void Shape3D::ShowVolume() const {
    cout << "The volume of the " <<  GetName3D();
    cout << " is: " << Volume() << endl;
}

//greater-than comparision operator
bool Shape3D::operator>(const Shape3D &rhs) const {
   //reference: Zybooks 9.13 and operator overloading lecture

    bool b = true;
    //if area of current shape is greater than area of shape given in parameter
    if(Volume() > rhs.Volume()){
        b = true;  //variable is true
    }
    //if area of current shape is less than or equal to area of shape given in parameter
    else{
        b = false;  //variable is false
    }

    return b;  //return variable
}

//less-than comparision operator
bool Shape3D::operator<(const Shape3D &rhs) const {
   //reference: Zybooks 9.13 and operator overloading lecture

    bool b = true;
    //if area of current shape is less than area of shape given in parameter
    if(Volume() < rhs.Volume()){
        b = true; //variable is true
    }
    //if area of current shape is greater than or equal to area of shape given in parameter
    else{
        b = false;  //variable is false
    }

    return b;  //return variable
}

//equality comparision operator
bool Shape3D::operator==(const Shape3D &rhs) const {
   //reference: Zybooks 9.13 and operator overloading lecture

    bool b = true;
    //if area of current shape is equal to area of shape given in parameter
    if(Volume() == rhs.Volume()){
        b = true;  //variable is true
    }
    //if area of current shape is not equal to area of shape given in parameter
    else{
        b = false; //variable is false
    }

    return b; //return variable
}

//virtual distructor
//reference: polymorphisim lecture
Shape::~Shape(){

}
