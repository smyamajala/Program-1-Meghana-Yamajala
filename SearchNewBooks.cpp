#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "book.hpp"
#include "search.hpp"
#include "timer.hpp"

// READ FILE
// because I have to read from the files I just used a blurb of code I used a lot last quarter 
// basically the first thing is to make sure the file the user wants to read is valid
// then we read line by line and get the different values 
// we are also seperating the components of the data based on the "," token
// this is basically PARSING each component

bool readBooksFromFile(const std::string& filename, std::vector<Book>& books) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return false;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string token;
        
        int isbn;
        std::string language, type;
        
        // Parse ISBN
        if (std::getline(ss, token, ',')) {
            isbn = std::stoi(token);
        } else continue;
        
        // Parse language
        if (std::getline(ss, language, ',')) {
            // language is ready
        } else continue;
        
        // Parse type
        if (std::getline(ss, type)) {
            // type is ready
        } else continue;
        
        books.push_back(Book(isbn, language, type));
    }
    
    file.close();
    return true;
}


bool writeResultToFile(const std::string& filename, int count) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return false;
    }
    
    file << count << std::endl;
    file.close();
    return true;
}

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc < 3 || argc > 4) {
        std::cerr << "Usage: " << argv[0] << " <newBooks.dat> <request.dat> [<result_file.dat>]" << std::endl;
        return 1;
    }
    
    // Set output filename (default or user provided)
    std::string outputFile = "found.dat";
    if (argc == 4) {
        outputFile = argv[3];
    }
    
    // Create vectors to store books
    std::vector<Book> newBooks;
    std::vector<Book> requests;
    
    // Read input files
    if (!readBooksFromFile(argv[1], newBooks)) {
        return 1;
    }
    if (!readBooksFromFile(argv[2], requests)) {
        return 1;
    }
    
    // Get user's search method choice
    char choice;
    do {
        std::cout << "Choice of search method ([l]inear, [b]inary, [r]ecursiveBinary)? ";
        std::cin >> choice;
        
        if (choice != 'l' && choice != 'b' && choice != 'r') {
            std::cerr << "Incorrect choice" << std::endl;
        }
    } while (choice != 'l' && choice != 'b' && choice != 'r');
    
    // Initialize timer and counter
    Timer timer;
    int foundCount = 0;
    
    // Start timing and perform search based on user choice
    timer.Reset();
    
    switch (choice) {
        case 'l':
            // Linear search - no sorting needed
            for (const Book& request : requests) {
                if (linearSearch(newBooks, request)) {
                    foundCount++;
                }
            }
            break;
            
        case 'b':
            // Binary search - sort first, then search
            std::sort(newBooks.begin(), newBooks.end());
            for (const Book& request : requests) {
                if (binarySearch(newBooks, request)) {
                    foundCount++;
                }
            }
            break;
            
        case 'r':
            // Recursive binary search - sort first, then search
            std::sort(newBooks.begin(), newBooks.end());
            for (const Book& request : requests) {
                if (recursiveBinarySearch(newBooks, request)) {
                    foundCount++;
                }
            }
            break;
    }
    
    // Stop timing and display results
    double elapsed = timer.CurrentTime();
    std::cout << "CPU time: " << elapsed << " microseconds" << std::endl;
    
    // Write result to output file
    if (!writeResultToFile(outputFile, foundCount)) {
        return 1;
    }
    
    return 0;
}
