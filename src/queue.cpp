#include "queue.h"
#include <iostream>

void Queue::qpush(int val){
    Node* newNode = new Node(val);
    if (tail != nullptr){
        tail -> next = newNode;
    }
    tail = newNode;
    if (head == nullptr){
        head = newNode;
    }
}
void Queue::qprint() const{
    Node* current = head;
    std::cout << "Queue:";
    while (current != nullptr){
        std::cout << current->data << " ";
        current = current->next;
    }
}
void Queue::qpop() {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) {
        tail = nullptr;
    }
}
int Queue::getHead(){
    if(head == nullptr) return -1;
    return head->data;
}
bool Queue::isEmpty() const{
    return head == nullptr;
}

Queue::~Queue(){
    while(head != nullptr){
        Node* tmp = head;
        head = head -> next;
        delete tmp;
    }
}