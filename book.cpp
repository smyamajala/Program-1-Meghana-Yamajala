// help me bro i am about to crash out 
#include "book.hpp"
#include <iostream>

// CONSTRUCTOR
// we are deconstructing each entry in the file and seperating it based on the 
// ISBN number, the book's language, and the type of book
// we are using pointer references because the language and the type of book are strings
// using the private variables declared in book.hpp we are assigning new variables (deconstructed)
// to those variables
// another aspect from book.hpp is the Book class. We are referencing that class in this constructor
// and implementing the methods here
Book::Book(int i, const std::string& lang, const std::string& t) {
  isbn = i; // declaring the isbn number
  language = lang; // declaring the language of the book
  type = t; // declaring the type of book (new, used, digital)
} 

//GETTERS
// we also have to get the values, while assigning the values is fine,
// we also have to return the values as well 
// in terms of strings you would be retuning a copy of them
// the getter functions were defined in book.hpp 

int Book::getISBN() const {
  return isbn; // getting the isbn number
}

std::string Book::getLang() const {
  return language; // getting the language
}

std::string Book::getType() const {
  return type; // getting the book type
}




