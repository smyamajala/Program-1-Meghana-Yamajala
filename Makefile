# Makefile for Program 1 - ECS 36C
CXX = g++
CXXFLAGS = -Wall -Werror
TARGET = SearchNewBooks

# Build the main executable from SearchNewBooks.cpp
$(TARGET): SearchNewBooks.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) SearchNewBooks.cpp

# Remove all generated files
clean:
	rm -f $(TARGET) found.dat newbooks.dat request.dat
