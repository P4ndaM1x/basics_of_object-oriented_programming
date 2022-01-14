// to only include once
#pragma once

// including Grade class functionality
#include "Grade.hpp"

// aggregates Grades
class GradeBook{

    public:
        // default constructor
        GradeBook();
        // adds a Grade copy
        void Insert(const Grade);
        // adds a Grade passed by pointer
        void Insert(const Grade*);
        // returns const pointer to grade with provided index
        const Grade* GetPtrConst(int);
        // returns pointer to grade with provided index
        Grade* GetPtr(int);
        // prints all of the stored Grades with an optional label
        void Print(std::string = "") const;
        // dealocates used memory
        ~GradeBook();

    private:
        // number of stored grades
        int _n;
        // pointer to the table storing pointers to grades
        const Grade** _grades;
};