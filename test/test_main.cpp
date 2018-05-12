#include<iostream>
#include<cassert>
#include "heaps.hpp"


int main(int argc, char const *argv[])
{
    int array[] = {7, 3, 1, 4, 8, 6, 9, 2, 5, 10};
    
    MinHeap *min_heap = new MinHeap(array[0]);
    MaxHeap *max_heap = new MaxHeap(array[0]);

    for (int i = 0; i < 10; i++) {
        min_heap->insert(new MinNode(array[i]));
        max_heap->insert(new MaxNode(array[i]));
    }

    assert(min_heap->data == 1);
    assert(max_heap->data == 10);
    
    delete min_heap;
    delete max_heap;

    std::cout << "Test Success" << std::endl;
    return 0;
}
