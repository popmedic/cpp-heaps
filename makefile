heaps : main.o node.o min_heap.o max_heap.o 
	clang++ -o heaps main.o node.o min_heap.o max_heap.o
main.o : main.cpp
	clang++ -c main.cpp
node.o : node.cpp node.hpp
	clang++ -c node.cpp node.hpp
min_heap.o : min_heap.cpp min_heap.hpp
	clang++ -c min_heap.cpp min_heap.hpp
max_heap.o : max_heap.cpp max_heap.hpp
	clang++ -c max_heap.cpp max_heap.hpp
clean :
	rm heaps *.o *.gch