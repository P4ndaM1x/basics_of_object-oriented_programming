// to only include once
#pragma once
// adding necessary libraries
#include <iostream>
#include <cmath>
#include <string>
#include <utility>

// used to manage n-dimensional vector 
class MathV{

    public:
        // creates a vector with provided number of dimensions
        explicit MathV(const int);
        // copy constructor
        MathV(const MathV&);
        // move constructor 
        MathV(MathV&&);
        // destructor
        ~MathV();

        // returns reference to the selected coordinate of vector
        double& at(const int) const;
        // converts vector to its length
        operator double() const;
        // adds provided vector accordingly
        void operator+=(const MathV&);
        // adds provided number to every vector coordinate
        const MathV& operator+=(const double);
        // prints vector with an optional label
        void print(std::string = "") const;
        // returns the dot product of two vectors
        static double dot(const MathV&, const MathV&);
        // returns length of the vector
        double norm() const;

    private:
        // number of vector dimensions (size of _dim table)
        int _n;
        // pointer to the table that stores vector coordinates
        double *_dim;
};

// inline definitions
inline MathV::MathV(MathV&& v) 
    : _n{std::exchange(v._n, 0)}, _dim{std::exchange(v._dim, nullptr)} 
{}
inline MathV::~MathV(){ 
    delete[] _dim; 
}
inline double& MathV::at(const int i) const{
    return _dim[i];
}
inline MathV::operator double() const{
    return norm();
}