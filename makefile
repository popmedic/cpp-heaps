SRC = src
INC = inc
TEST = test
LIB = lib
BIN = bin
FLAGS = -I$(INC)
APP = heaps

heaps : main.o node.o min_heap.o max_heap.o $(BIN)
	$(CXX) $(FLAGS) -o $(BIN)/$(APP) $(LIB)/main.o $(LIB)/node.o $(LIB)/min_heap.o $(LIB)/max_heap.o
main.o : $(SRC)/main.cpp $(INC)/heaps.hpp $(LIB)
	$(CXX) $(FLAGS) -c $(SRC)/main.cpp -o $(LIB)/main.o
node.o : $(SRC)/node.cpp $(INC)/node.hpp $(LIB)
	$(CXX) $(FLAGS) -c $(SRC)/node.cpp -o $(LIB)/node.o
min_heap.o : $(SRC)/min_heap.cpp $(INC)/min_heap.hpp $(LIB)
	$(CXX) $(FLAGS) -c $(SRC)/min_heap.cpp -o $(LIB)/min_heap.o
max_heap.o : $(SRC)/max_heap.cpp $(INC)/max_heap.hpp $(LIB)
	$(CXX) $(FLAGS) -c $(SRC)/max_heap.cpp -o $(LIB)/max_heap.o
test : node.o min_heap.o max_heap.o test_main.o
	$(CXX) $(FLAGS) -o $(BIN)/$(APP)_$(TEST) $(LIB)/test_main.o $(LIB)/node.o $(LIB)/min_heap.o $(LIB)/max_heap.o
	$(BIN)/$(APP)_$(TEST)
test_main.o : $(TEST)/test_main.cpp $(INC)/heaps.hpp $(INC)/heaps.hpp $(LIB)
	$(CXX) $(FLAGS) -c $(TEST)/test_main.cpp -o $(LIB)/test_main.o
run : heaps
	$(BIN)/heaps
clean :
	rm -rf heaps $(LIB) $(INC)/*.gch $(BIN)
$(LIB) :
	mkdir -p $(LIB)
$(BIN) :
	mkdir -p $(BIN)
