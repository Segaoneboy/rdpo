#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    private:
        struct Node{
            int data;
            Node* next;
            Node(int val) : data(val), next(nullptr) {}
        };
        Node* head = nullptr;
        Node* tail = nullptr;
    public:
        Queue() = default;
        ~Queue();
        void qpush(int val);
        void qprint() const;
        void qpop();
        int getHead();
        bool isEmpty() const;
};

#endif