#include "search.hpp"
#include <iostream>

// here we are now writing the code for the defined functions from the search.hpp file
// parameters are the same
// the searches work differently with different runtimes, but the user gets to chose... 
// poor thing...

// LINEAR SEARCH
// the main essence of this kind of search is to just sift through the list until
// it finds the target

bool linearSearch(const std::vector<Book>& books, const Book& target) {
    for (const Book& book : books) {
        if (book == target) {
            return true;
        }
    }
    return false;
}

// ITERATIVE BINARY SEARCH
// this search is for sorted data
// if you recall from book.cpp and book.hpp we did sort the books using 
// using operation overloading... 
// the main essence of this search is to continue splitting the search range 
// in half and comparing both sides until we find the target 

bool binarySearch(const std::vector<Book>& books, const Book& target) {
    int left = 0;
    int right = books.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (books[mid] == target) {
            return true;
        }
        
        if (books[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

// RECURSIVE BINARY SEARCH (helper)
// does the actual messy work
// the parameters for the actual recursive search is just the vector and the target... 
// HOWEVER we also need the left and right sides as parameters... this will account for that

bool recursiveBinarySearchHelper(const std::vector<Book>& books, 
                                const Book& target, 
                                int left, int right) {
    if (left > right) {
        return false;
    }
    
    int mid = left + (right - left) / 2;
    
    if (books[mid] == target) {
        return true;
    }
    
    if (books[mid] < target) {
        return recursiveBinarySearchHelper(books, target, mid + 1, right);
    } else {
        return recursiveBinarySearchHelper(books, target, left, mid - 1);
    }
}

// calls the helper to account for the messy parameters...

bool recursiveBinarySearch(const std::vector<Book>& books, const Book& target) {
    return recursiveBinarySearchHelper(books, target, 0, books.size() - 1);
}
