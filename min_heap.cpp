#include<iostream>
#include "min_heap.hpp"

void MinNode::swap_min(int *d) {
    if (this->data > *d) {
        this->swap(d);
    }
    if ((MinNode*)(this->left) != NULL) ((MinNode*)(this->left))->swap_min(d);
    if ((MinNode*)(this->right) != NULL) ((MinNode*)(this->right))->swap_min(d);
}

void MinNode::insert(Node* n){
    this->swap_min(&n->data);
    Node::insert(n);
}