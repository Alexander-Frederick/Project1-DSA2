CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -Ipart1 -Ipart2

MAIN_OBJS = main.o part1/tokenizer.o part1/passwords.o part1/filemaker.o part1/encryption.o part2/Node.o part2/List.o part2/HashTable.o

TEST_OBJS = part1/test.o part1/tokenizer.o part1/passwords.o part1/filemaker.o part1/encryption.o

MAIN_TARGET = main
TEST_TARGET = test

all: $(MAIN_TARGET) $(TEST_TARGET)

$(MAIN_TARGET): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) -o $(MAIN_TARGET) $(MAIN_OBJS)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

main.o: main.cpp part1/tokenizer.h part1/passwords.h part1/filemaker.h part1/encryption.h part2/HashTable.h
	$(CXX) $(CXXFLAGS) -c main.cpp

part1/test.o: part1/test.cpp part1/tokenizer.h part1/passwords.h part1/filemaker.h part1/encryption.h
	$(CXX) $(CXXFLAGS) -c part1/test.cpp -o part1/test.o

part1/tokenizer.o: part1/tokenizer.cpp part1/tokenizer.h
	$(CXX) $(CXXFLAGS) -c part1/tokenizer.cpp -o part1/tokenizer.o

part1/passwords.o: part1/passwords.cpp part1/passwords.h
	$(CXX) $(CXXFLAGS) -c part1/passwords.cpp -o part1/passwords.o

part1/filemaker.o: part1/filemaker.cpp part1/filemaker.h part1/tokenizer.h part1/passwords.h part1/encryption.h
	$(CXX) $(CXXFLAGS) -c part1/filemaker.cpp -o part1/filemaker.o

part1/encryption.o: part1/encryption.cpp part1/encryption.h
	$(CXX) $(CXXFLAGS) -c part1/encryption.cpp -o part1/encryption.o

part2/Node.o: part2/Node.cpp part2/Node.h
	$(CXX) $(CXXFLAGS) -c part2/Node.cpp -o part2/Node.o

part2/List.o: part2/List.cpp part2/List.h part2/Node.h
	$(CXX) $(CXXFLAGS) -c part2/List.cpp -o part2/List.o

part2/HashTable.o: part2/HashTable.cpp part2/HashTable.h part2/List.h part2/Node.h
	$(CXX) $(CXXFLAGS) -c part2/HashTable.cpp -o part2/HashTable.o

clean:
	rm -f *.o part1/*.o part2/*.o $(MAIN_TARGET) $(TEST_TARGET)

rebuild: clean all

run: $(MAIN_TARGET)
	./$(MAIN_TARGET)

runtest: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: all clean rebuild run runtest