#include "search.hpp"
#include <iostream>

// here we are now writing the code for the defined functions from the search.hpp file
// parameters are the same
// the searches work differently with different runtimes, but the user gets to chose... 
// poor thing...



bool linearSearch(const std::vector<Book>& books, const Book& target) {
    for (const Book& book : books) {
        if (book == target) {
            return true;
        }
    }
    return false;
}

// 

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

bool recursiveBinarySearch(const std::vector<Book>& books, const Book& target) {
    return recursiveBinarySearchHelper(books, target, 0, books.size() - 1);
}
