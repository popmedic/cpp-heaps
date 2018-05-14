#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

#include "heaps.hpp"

#define ARRAY_SIZE 9
#define DATA_RANGE 100

using namespace std;

int get_min_h(const int n, const int *ints) {
    MinHeap *min_heap = new MinHeap(ints[0]);
    for (int i = 1; i < n; i++) min_heap->insert(new MinNode(ints[i]));
    int rtn = min_heap->data;
    delete min_heap;
    return rtn;
}

int get_max_h(const int n, const int *ints) {
    MaxHeap *max_heap = new MaxHeap(ints[0]);
    for (int i = 1; i < n; i++) max_heap->insert(new MaxNode(ints[i]));
    int rtn = max_heap->data;
    delete max_heap;
    return rtn;
}

int get_min_a(const int n, const int *ints) {
    int rtn = ints[0];
    for(int i = 1; i < n; i++) if (rtn > ints[i]) rtn = ints[i];
    return rtn;
}

int get_max_a(const int n, const int *ints) {
    int rtn = ints[0];
    for(int i = 1; i < n; i++) if (rtn < ints[i]) rtn = ints[i];
    return rtn;
}

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

    clock_t start;
    int m;
    cout << endl << "time test:" << endl;
    start = clock();
    m = get_min_h(array_size, array);
    cout << "min_heap(" << m << "): " << clock() - start << " clicks" << endl;
    start = clock();
    m = get_min_a(array_size, array);
    cout << "min_array(" << m << "): " << clock() - start << " clicks" << endl;
    start = clock();
    m = get_max_h(array_size, array);
    cout << "max_heap(" << m << "): " << clock() - start << " clicks" << endl;
    start = clock();
    m = get_max_a(array_size, array);
    cout << "max_array(" << m << "): " << clock() - start << " clicks" << endl;

    delete array;
    delete min_heap;
    delete max_heap;

    return 0;
}