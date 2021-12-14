// to include only once
#pragma once
// adding necessary libraries
#include <string>
#include <iostream>
// adding definition of the list element
#include "Node.hpp"

///////////////////////////
/*   class declaration   */
/////////////////////////// 

// used to oparate on one-way linked list
class OneWayList{

    public:
        // adds another list element with provided string
        void add(std::string);
        // prints whole list
        void dump() const;
        // returns true if list is epmty or false if it's not
        bool empty() const;
        // returns address of the first list element
        Node* getHead() const;
        // deallocates used memory and deletes the list
        void clear();

    private:
        // stores address of the first list element
        Node* head = NULL;
};

/////////////////////////////
/*   inline definitions    */
///////////////////////////// 

inline Node* OneWayList::getHead() const{
    return head;
}
inline bool OneWayList::empty() const{
    return !head;
}