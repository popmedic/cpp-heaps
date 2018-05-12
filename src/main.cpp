#include<iostream>
#include<cstdlib>
#include<ctime>

#include "heaps.hpp"

#define ARRAY_SIZE 10
#define DATA_RANGE 100

using namespace std;

int main(int argc, char const *argv[])
{
    int array[ARRAY_SIZE];

    srand(time(NULL));
    for(int i = 0; i < ARRAY_SIZE; i++) array[i] = rand()%DATA_RANGE;
    
    MinHeap *min_heap = new MinHeap(array[0]);
    for (int i = 1; i < ARRAY_SIZE; i++) min_heap->insert(new MinNode(array[i]));
    cout << "Min Heap result:" << endl;
    min_heap->print();
    delete min_heap;

    MaxHeap *max_heap = new MaxHeap(array[0]);
    for (int i = 1; i < ARRAY_SIZE; i++) max_heap->insert(new MaxNode(array[i]));
    cout << "Max Heap result:" << endl;
    max_heap->print();
    delete max_heap;

    return 0;
}