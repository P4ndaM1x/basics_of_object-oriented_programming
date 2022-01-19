// to only include once
#pragma once

// adding necessary libraries
#include <iostream>
#include <cstring>
#include <utility>

// wrapping content in namespace
namespace mystring{

    // container for text
    class MyString{

        public:

            // default constructor
            MyString();
            // creates container for text of provided length
            MyString(int);
            // converting constructor from char
            MyString(const char);
            // converting constructor from string literal
            MyString(const char*);
            // copy constructor
            MyString(const MyString&);
            // move constructor
            MyString(MyString&&);
            // deallocates used memory
            ~MyString();

            // prints strored text with provided label
            void print(const char*) const;
            // returns number of text characters
            int length() const;

            // assigns string literal
            MyString& operator=(const char *);
            // concatenates two strings
            MyString operator+(const MyString&) const;
            // adds string literal
            MyString operator+(const char*) const;
            // adds one character
            MyString operator+(const char) const;
            // compares two strings
            bool operator==(const MyString&) const;
            // converting operator, returns pointer to the table storing text
            explicit operator char*() const;

        private:
            // number of stored chars except null character
            int _n;
            // pointer to the table storing text
            char* _str;
    };

    // alias of MyString type
    using String = MyString;

    // adds functionality of printing stored text with "<<" operator
    inline std::ostream& operator<<(std::ostream& stream, const MyString& s){
        return stream << static_cast<char*>(s);
    }
    
    // adds functionality of multiplicating stored text n-times
    MyString operator*(int n, const MyString& s){
        MyString temp(n*s.length());
        strcpy(static_cast<char*>(temp), static_cast<char*>(s));
        for(int i=0; i<n-1; i++)
            strcat(static_cast<char*>(temp), static_cast<char*>(s));
        return temp;
    }

    // definitions of inline operators
    inline MyString MyString::operator+(const char* s) const{
        MyString temp(s);
        return *this + temp;
    }
    inline MyString MyString::operator+(const char c) const{
        MyString temp(c);
        return *this + temp;
    }
    inline MyString::operator char*() const{
        return _str;
    }
    inline bool MyString::operator==(const MyString& s) const{
        return !strcmp(_str, s._str);
    }
}