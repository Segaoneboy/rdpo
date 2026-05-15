#ifndef STACK_H
#define STACK_H

class Stack {
    private:
        struct Node {
            int data;
            Node* next;
            Node(int val) : data(val), next(nullptr) {}
        };
        Node* top = nullptr;
    public:
        Stack() = default;
        ~Stack();
        void spush(int val);
        void sprint() const;
        void spop();
        int getTop();
        bool isEmpty() const;

};
#endif