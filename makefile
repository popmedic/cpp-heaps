heaps : main.o node.o min_heap.o max_heap.o
	${CXX} -o heaps main.o node.o min_heap.o max_heap.o
main.o : main.cpp heaps.hpp
	${CXX} -c main.cpp
node.o : node.cpp node.hpp
	${CXX} -c node.cpp node.hpp
min_heap.o : min_heap.cpp min_heap.hpp
	${CXX} -c min_heap.cpp min_heap.hpp
max_heap.o : max_heap.cpp max_heap.hpp
	${CXX} -c max_heap.cpp max_heap.hpp
clean :
	rm heaps *.o *.gch
run : heaps
	./heaps
