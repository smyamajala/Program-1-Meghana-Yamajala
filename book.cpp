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

// OPERATORS
// the purpose of these is to sort the books in order
// basically we are implementing the std::sort methods
// we have three main comparisions... 

bool Book::operator<(const Book& other) const {
    if (isbn != other.isbn) {
        return isbn < other.isbn;  // Lower ISBN comes first
    }
  
    if (type != other.type) {
        // Define custom priority: new < used < digital
        // Helper lambda function to assign numeric weights to types
        auto typeOrder = [](const std::string& t) -> int {
            if (t == "new") return 1;      // Highest priority
            if (t == "used") return 2;     // Middle priority  
            if (t == "digital") return 3;  // Lowest priority
            return 0; // fallback for unknown types
        };
        
        // compare using our custom priority system
        return typeOrder(type) < typeOrder(other.type);
    }
    
    // Use built-in string comparison for alphabetical order
    return language < other.language;
}

//EQUALITY OPERATOR (==)
// defines when two Book objects are considered identical
bool Book::operator==(const Book& other) const {
    // All three fields must match exactly for books to be equal
    return (isbn == other.isbn) && 
           (language == other.language) && 
           (type == other.type);
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    // Output format: "ISBN,language,type"
    os << book.isbn << "," << book.language << "," << book.type;
    
    // Return the stream to allow chaining: cout << book1 << book2
    return os;
}


