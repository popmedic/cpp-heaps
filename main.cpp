#include<iostream>
#include "heaps.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int array[] = {10, 4, 8, 2, 1, 7, 9, 6, 5, 3};
    
    MinHeap *min_heap = new MinHeap(array[0]);
    for (int i = 1; i < 10; i++) min_heap->insert(new MinNode(array[i]));
    cout << "Min Heap result:" << endl;
    min_heap->print();
    delete min_heap;

    MaxHeap *max_heap = new MaxHeap(array[0]);
    for (int i = 1; i < 10; i++) max_heap->insert(new MaxNode(array[i]));
    cout << "Max Heap result:" << endl;
    max_heap->print();
    delete max_heap;

    return 0;
}