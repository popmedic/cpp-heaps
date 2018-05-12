#include<iostream>
#include "max_heap.hpp"

void MaxNode::swap_max(int *d) {
    if (this->data < *d) {
        this->swap(d);
    }
    if ((MaxNode*)(this->left) != NULL) ((MaxNode*)(this->left))->swap_max(d);
    if ((MaxNode*)(this->right) != NULL) ((MaxNode*)(this->right))->swap_max(d);
}

void MaxNode::insert(Node* n) {
    this->swap_max(&n->data);
    Node::insert(n);
}