# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Target executable name
TARGET = main

# Source files
SRCS = main.cpp

# entry point
all: $(TARGET)

# Build rule
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Run the executable (normal run)
run: $(TARGET)
	./$(TARGET)

# Run with input from input.txt
run-input: $(TARGET)
	./$(TARGET) < input.txt

# Run with input from input.txt and output to output.txt
run-io: $(TARGET)
	./$(TARGET) < input.txt > output.txt

# Clean rule
clean:
	rm -f $(TARGET)

.PHONY: all run run-input run-io clean
