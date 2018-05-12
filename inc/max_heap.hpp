#ifndef _MAX_HEAP_HPP_
#define _MAX_HEAP_HPP_

#include "node.hpp"

class MaxNode:public Node {
private: 
    void swap_max(int*);
public:
    MaxNode(int data):Node(data) { }
    void insert(Node*);
};

typedef MaxNode MaxHeap;

#endif