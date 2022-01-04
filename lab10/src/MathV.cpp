#include "MathV.hpp"

MathV::MathV(const int n) 
    : _n{n}, _dim{new double[n]} 
{
    for(int i=0; i<_n; i++)
        _dim[i] = 0;
}

MathV::MathV(const MathV& v) 
    : _n{v._n}, _dim{new double[v._n]}
{
    for(int i=0; i<_n; i++)
        _dim[i] = v._dim[i];
}

void MathV::operator+=(const MathV& v){
    for(int i=0; i<_n; i++)
        _dim[i] += v._dim[i];
}
const MathV& MathV::operator+=(const double k){
    for(int i=0; i<_n; i++)
        _dim[i] += k;
    return *this;
}

void MathV::print(std::string label) const{
    std::cout << label << "[";
    for(int i=0; i<_n-1; i++)
        std::cout << _dim[i] << ", ";
    std::cout << _dim[_n-1] << "]" << std::endl;
}

double MathV::dot(const MathV& a, const MathV& b){
    if(a._n != b._n){
        std::cout << "Error, vectors of different dimensions!" << std::endl;
        return 0;
    }
    double sum = 0;
    for(int i=0; i<a._n; i++)
        sum+=a._dim[i]*b._dim[i];
    return sum;
}

double MathV::norm() const{
    double sum = 0;
    for(int i=0; i<_n; i++)
        sum+=_dim[i]*_dim[i];
    return sqrt(sum);
}