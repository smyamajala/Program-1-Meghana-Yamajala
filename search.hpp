#indef SEARCH_H
#define SEARCH_H

#include <vector>
#include "book.hpp" // implementing the book class to search for the books

// the main function of this header is to showcase all the available search methods
// the user is given three methods to chose from
// linear, binary, and recursive
// here, we are just saying "These are the functions we will be using for this search
// in search.cpp we will define each individual search function
// it is important to note that the parameters for each function are the same
// since the user is deciding what to do with the data, the process will change
// but not what's being analyzed

bool linearSearch(const std::vector<Book>& books, const Book& target);
// we are defining the linear search function
// the parameters are the groups of books (indicated by the vector) and the specific book
// we want to find (the target)

bool binarySearch(const std::vector<Book>& books, const Book& target);
// we are defining the binary search function
// the parameters are the same as the linear search function

bool recursiveBinarySearch(const std::vector<Book>& books, const Book& target);
// we are defining the recursive binary search function

#endif
