#include "MyString.hpp"

using namespace mystring;

MyString::MyString() 
    : _n{0}, _str{nullptr}
{}

MyString::MyString(int n) 
    : _n{n}, _str{new char[n+1]} 
{}

MyString::MyString(const char s)
    : _n{1}, _str{new char[2]} 
{
    _str[0] = s;
    _str[1] = '\0';
}

MyString::MyString(const char* s) 
    : _n{static_cast<int>(strlen(s))}, _str{new char[static_cast<int>(strlen(s))+1]} 
{
    strcpy(_str, s);
}

MyString::MyString(const MyString& s) 
    : _n{s._n}, _str{new char[s._n+1]}
{
    strcpy(_str, s._str);
}

MyString::MyString(MyString&& s)
    : _n{std::exchange(s._n, 0)}, _str{std::exchange(s._str, nullptr)}
{}

MyString::~MyString()
{ 
    delete[] _str; 
}

void MyString::print(const char* s) const{
    for(int i=0; i<static_cast<int>(strlen(s)); i++)
        std::cout << s[i];
    for(int i=0; i<_n; i++)
        std::cout << _str[i];
    std::cout << std::endl;
}

inline int MyString::length() const{
    return _n;
}

MyString& MyString::operator=(const char *s){
    delete[] _str;
    _n = strlen(s) + 1;
    _str = new char[_n];
    strcpy(_str, s);
    return *this;
}

MyString MyString::operator+(const MyString& s) const{
    MyString temp;
    temp._n = _n + s._n;
    temp._str = new char[temp._n+1];
    strcpy(temp._str, _str);
    strcat(temp._str, s._str);
    return temp;
}