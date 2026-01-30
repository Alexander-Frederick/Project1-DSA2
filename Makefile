# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Object files for main program
MAIN_OBJS = main.o tokenizer.o passwords.o filemaker.o encryption.o

# Object files for test program
TEST_OBJS = test.o tokenizer.o passwords.o filemaker.o encryption.o

# Executables
MAIN_TARGET = main
TEST_TARGET = test

# Default target - builds both executables
all: $(MAIN_TARGET) $(TEST_TARGET)

# Build main executable
$(MAIN_TARGET): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) -o $(MAIN_TARGET) $(MAIN_OBJS)

# Build test executable
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

# Compile main.cpp
main.o: main.cpp tokenizer.h passwords.h filemaker.h encryption.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile test.cpp
test.o: test.cpp tokenizer.h passwords.h filemaker.h encryption.h
	$(CXX) $(CXXFLAGS) -c test.cpp

# Compile tokenizer.cpp
tokenizer.o: tokenizer.cpp tokenizer.h
	$(CXX) $(CXXFLAGS) -c tokenizer.cpp

# Compile passwords.cpp
passwords.o: passwords.cpp passwords.h
	$(CXX) $(CXXFLAGS) -c passwords.cpp

# Compile filemaker.cpp
filemaker.o: filemaker.cpp filemaker.h tokenizer.h passwords.h encryption.h
	$(CXX) $(CXXFLAGS) -c filemaker.cpp

# Compile encryption.cpp
encryption.o: encryption.cpp encryption.h
	$(CXX) $(CXXFLAGS) -c encryption.cpp

# Clean up compiled files
clean:
	rm -f *.o $(MAIN_TARGET) $(TEST_TARGET)

# Clean and rebuild everything
rebuild: clean all

# Run main program
run: $(MAIN_TARGET)
	./$(MAIN_TARGET)

# Run test program
runtest: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: all clean rebuild run runtest