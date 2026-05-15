#ifndef TREE_H
#define TREE_H

class Tree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    void recursivePush(Node* &node, int val);
    void recursivePrint(Node* node) const;
    void clear(Node* node);
    Node* findMin(Node* node);
    void recursivePop(Node* &node, int val);

public:
    Tree() = default;
    ~Tree();

    void bpush(int val);
    void bprint() const;
    void bpop(int val);
    bool contains(int val) const;
};

#endif