// to include only once
#pragma once
// to add string functionality
#include <string>

///////////////////////////
/*   class declaration   */
/////////////////////////// 

// used as element of the one-way linked list
class Node{

    public:
        // returns stored data
        std::string getData() const;
        // returs address of the stored Node instance
        Node* getNext() const;
        // sets "data" field with provided string
        void setData(std::string);
        // sets "next" field with provided address of a Node instance
        void setNext(Node*);

    private:
        // address of the next list element
        Node* next = NULL;
        // string containing text
        std::string data = "";
};

/////////////////////////////
/*   inline definitions    */
///////////////////////////// 

inline Node* Node::getNext() const{
    return next;
}
inline std::string Node::getData() const{
    return data;
}
inline void Node::setData(std::string data){
    this->data = data;
}
inline void Node::setNext(Node* next){
    this->next = next;
}