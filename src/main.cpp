#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

#include "heaps.hpp"

#define ARRAY_SIZE 13
#define DATA_RANGE 100

using namespace std;

int main(int argc, char const *argv[])
{
    int *array;
    int array_size;

    if (argc > 1) {
        array_size = argc - 1;
        array = new int[array_size];
        for(int i = 0; i < array_size; i++) array[i] = atoi(argv[i+1]);
    } else {
        array_size = ARRAY_SIZE;
        array = new int[array_size];
        srand(time(NULL));
        for(int i = 0; i < array_size; i++) array[i] = rand()%DATA_RANGE;
    }
    
    MinHeap *min_heap = new MinHeap(array[0]);
    MaxHeap *max_heap = new MaxHeap(array[0]);

    for (int i = 1; i < array_size; i++) {
        min_heap->insert(new MinNode(array[i]));
        max_heap->insert(new MaxNode(array[i]));
    }

    cout << endl << "smallest number: " << min_heap->data << endl;
    cout << "largest number: " << max_heap->data << endl << endl;
    
    cout << "min_heap dump:" << endl;
    min_heap->print();
    cout << "max_heap dump:" << endl;
    max_heap->print();

    delete array;
    delete min_heap;
    delete max_heap;

    return 0;
}