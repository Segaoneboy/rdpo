#include <iostream>
#include "stack.h"

void Stack::spush(int val) {
    Node* newNode = new Node(val);
    newNode -> next = top;
    top = newNode;
}
void Stack::sprint() const{
    Node* current = top;
    std::cout << "Stack:";
    while (current != nullptr){
        std::cout << current->data << " ";
        current = current->next;
    }
}
void Stack::spop(){
    if (top == nullptr) return;
    Node* temp = top;
    top = top->next;
    delete temp;
}
int Stack::getTop(){
    if(top == nullptr) return -1;
    return top->data;
}
bool Stack::isEmpty() const{
    return top ==nullptr;
}

Stack::~Stack(){
    while(top != nullptr){
        Node* tmp = top;
        top = top -> next;
        delete tmp;
    }
}