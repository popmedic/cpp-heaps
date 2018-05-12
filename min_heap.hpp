#ifndef _MIN_HEAP_HPP
#define _MIN_HEAP_HPP

#include "node.hpp"

class MinNode:public Node {
private: 
    void swap_min(int*);
public:
    MinNode(int data):Node(data) { }
    void insert(Node*);
};

typedef MinNode MinHeap;

#endif