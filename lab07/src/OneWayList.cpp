#include "OneWayList.hpp"

void OneWayList::add(std::string str){

    Node* temp = new Node;
    temp->setData(str);

    if(this->empty()){
        head = temp;
    }
    else{
        Node* elem = head;
        while(elem->getNext() != NULL)
            elem = elem->getNext();
        elem->setNext(temp);
    }
}

void OneWayList::dump() const{
    
    if(!this->empty()){
        Node* elem = head;
        while(elem != NULL){
            std::cout << elem->getData() << " ";
            elem = elem->getNext();
        }
    }
}

void OneWayList::clear(){

    if(!this->empty()){
        Node* current = head;
        Node* following = NULL;
        while(current != NULL){
            following = current->getNext();
            delete current;
            current = following;
        }
    }
    head = NULL;
}