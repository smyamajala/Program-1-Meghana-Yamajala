//killing myself before I even start the assignment 
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

// creating a class Book... this will help in the seperation of the individual parts of the input
// received in the original newbooks and requestedbooks files
// the main thing to note are the three components: ISBN number, book language, and tu[e
class Book {
private:
  int isbn; // identifier for the ISBN number 
  std::string language; // identifier for the language of the book
  std::string type;  // identifier for the type of book (digital, used, new)

public:
  Book(int isbn = 0, const std::string& lang = "", const std::string& t = "");
// here we are creating a template for the constructor. Basically how the book will be split
// and stored in the appropriate vector
// we can change the values but if there is an empty book we can create one with the 
// default values shown :)

// we are also going to crate methods to extract the different components of the class Book
// we are NOT modifying the object, just extracting the data we need from the object
  int getISBN() const; // getter for the ISBN number
  std::string getLang() const; // getter for the book's language
  std::string getType() const; // getter for the book type

// ask about the operator overloading cause i dont exactly understand that shit

  std::ostream& operator<<(std::ostream& os, const Book& book); 
// output operator 

#endif // ending it rn if my questions don't get answered
