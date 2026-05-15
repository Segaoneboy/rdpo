#include "btree.h"
#include <iostream>

void Tree::bpush(int val) {
    recursivePush(root, val);
}

void Tree::bprint() const {
    std::cout << "Tree (Прямой порядок вывода): ";
    recursivePrint(root);
}
void Tree::bpop(int val){
    recursivePop(root,val);
}
bool Tree::contains(int val) const{
    Node* current = root;
    while(current != nullptr){
        if(val == current->data) return true;
        else if(val < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}

Tree::~Tree() {
    clear(root);
}


void Tree::recursivePush(Node* &node, int val) {
    if (node == nullptr) {
        node = new Node(val); 
    } else if (val < node->data) {
        recursivePush(node->left, val); 
    } else if (val > node->data) {
        recursivePush(node->right, val); 
    }
}

void Tree::recursivePrint(Node* node) const {
    if (node != nullptr) {
        recursivePrint(node->left);        
        std::cout << node->data << " ";    
        recursivePrint(node->right);       
    }
}
Tree::Node* Tree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void Tree::recursivePop(Node* &node, int val) {
    if (node == nullptr) return;

    if (val < node->data) {
        recursivePop(node->left, val);
    } else if (val > node->data) {
        recursivePop(node->right, val);
    } else {
        if (node->left == nullptr) { 
            Node* temp = node->right;
            delete node;
            node = temp;
        } else if (node->right == nullptr) { 
            Node* temp = node->left;
            delete node;
            node = temp;
        } else { 
            Node* temp = findMin(node->right); 
            node->data = temp->data;
            recursivePop(node->right, temp->data);
        }
    }
}

void Tree::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}