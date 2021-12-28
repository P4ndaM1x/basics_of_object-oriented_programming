// to only include once
#pragma once
// adding necessary libraries
#include <iostream>
#include <cmath>
#include <string>
#include <utility>

// used to manage two-dimensional vector 
class Vector2D{

    public:
        // named constructor that creates a vector from Cartesian coordinates 
        // 1. argument - x coordinate, 2. argument - y coordinate
        static Vector2D fromCarthesian(double, double);
        // named constructor that creates a vector from polar coordinates 
        // 1. argument - distance, 2. argument - angle in degrees
        static Vector2D fromPolar(double, double);
        // copy constructor
        Vector2D(const Vector2D&);
        // move constructor 
        Vector2D(Vector2D&&);
        // destructor
        ~Vector2D();

        // prints vector coordinates with provided label
        void print(const std::string) const;
        // returns the dot product of two vectors
        double dot(const Vector2D&) const;
        // returns vector - the sum of two vectors
        Vector2D add(const Vector2D&) const;
        // tracks how many vector instances are currently in use 
        static int count;

    private:
        // creates vector with provided Cartesian coordinates
        Vector2D(double, double);
        // vector coordinates
        double _x, _y;
};

// definition of static variable tracking how many vector instances are currently in use
int Vector2D::count = 0;

// definitions of class constructors
inline Vector2D Vector2D::fromCarthesian(double x, double y){
    return Vector2D(x,y);
}
inline Vector2D Vector2D::fromPolar(double r, double phi){
    double radians = phi*2*M_PI/360;
    return Vector2D(r*cos(radians), r*sin(radians));
}
Vector2D::Vector2D(const Vector2D& v){
    v.print("copying ");
    _x = v._x;
    _y = v._y;
    count++;
}
Vector2D::Vector2D(Vector2D&& v){
    v.print("moving ");
    _x = std::exchange(v._x, 0);
    _y = std::exchange(v._y, 0);
    count++;
}
inline Vector2D::Vector2D(double x, double y) : _x{x}, _y{y} {count++;}
inline Vector2D::~Vector2D() {count--;}

// inline definitions of class methods
inline void Vector2D::print(const std::string label) const{
    std::cout << label << "(" << _x << ", " << _y << ")" << std::endl;
}
inline double Vector2D::dot(const Vector2D& v) const{
    return this->_x*v._x + this->_y*v._y;
}
inline Vector2D Vector2D::add(const Vector2D& v) const{
    return Vector2D(this->_x+v._x, this->_y+v._y);
}