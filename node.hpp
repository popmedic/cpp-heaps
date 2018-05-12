#ifndef _NODE_HPP
#define _NODE_HPP

class Node{
protected:
    void swap(int*);
public:
    int data;
    Node *left, *right;

    Node(int);
    ~Node();
    int count();
    void insert(Node*);
    void print(const int indent=0, const char* note="");
};

#endif