#include<iostream>
#include "node.hpp"

Node::Node(int data) {
    this->data = data;
    this->left = this->right = NULL;
}

Node::~Node(){
    if (this->left != NULL) delete this->left;
    if (this->right != NULL) delete this->right;
}

void Node::swap(int *d) {
    int temp = this->data;
    this->data = *d;
    *d = temp;
}

int Node::count() {
    int r = 1;
    if (this->left != NULL) r += this->left->count();
    if (this->right != NULL) r += this->right->count();
    return r;
}

void Node::insert(Node* n){
    if (this->left == NULL) this->left = n;
    else if (this->right == NULL) this->right = n;
    else if (this->left->count() > this->right->count()) this->right->insert(n);
    else this->left->insert(n);
}

void Node::print(const int indent, const char *note) {
    for(int i = 0; i < indent; i++) std::cout << " ";
    std::cout << this->data << " " << note << std::endl;
    if (this->left != NULL) this->left->print(indent+1, "(l)");
    if (this->right != NULL) this->right->print(indent+1, "(r)");
}