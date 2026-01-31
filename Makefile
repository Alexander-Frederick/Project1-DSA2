CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -Ipart1 -Ipart2

PART1_DIR = part1
PART2_DIR = part2

PART1_SRCS = $(PART1_DIR)/tokenizer.cpp $(PART1_DIR)/passwords.cpp \
             $(PART1_DIR)/filemaker.cpp $(PART1_DIR)/encryption.cpp
PART2_SRCS = $(PART2_DIR)/Node.cpp $(PART2_DIR)/List.cpp $(PART2_DIR)/HashTable.cpp

PART1_OBJS = $(PART1_SRCS:.cpp=.o)
PART2_OBJS = $(PART2_SRCS:.cpp=.o)

MAIN_OBJS = main.o $(PART1_OBJS) $(PART2_OBJS)
TEST_OBJS = $(PART1_DIR)/test.o $(PART1_OBJS)

MAIN_TARGET = main
TEST_TARGET = test

all: $(MAIN_TARGET) $(TEST_TARGET)

$(MAIN_TARGET): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp $(PART1_DIR)/tokenizer.h $(PART1_DIR)/passwords.h \
        $(PART1_DIR)/filemaker.h $(PART1_DIR)/encryption.h $(PART2_DIR)/HashTable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PART1_DIR)/%.o: $(PART1_DIR)/%.cpp $(PART1_DIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PART2_DIR)/%.o: $(PART2_DIR)/%.cpp $(PART2_DIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(PART1_DIR)/*.o $(PART2_DIR)/*.o $(MAIN_TARGET) $(TEST_TARGET)

rebuild: clean all

run: $(MAIN_TARGET)
	./$(MAIN_TARGET)

runtest: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: all clean rebuild run runtest