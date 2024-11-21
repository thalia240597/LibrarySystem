#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool isAvailable;

public:
    // Constructor
    Book(std::string t = "", std::string a = "", std::string i = "", bool avail = true);

    // Set book details
    void setBookDetails(std::string t, std::string a, std::string i, bool avail);

    // Display book details
    void displayBookDetails() const;

    // Borrow book if available
    bool borrowBook();

    // Return book and mark as available
    void returnBook();

    // Check ISBN match
    bool checkISBN(const std::string& i) const;
};

class LibrarySystem {
private:
    Book books[5];
    int bookCount;

public:
    LibrarySystem();

    // Find book by ISBN
    Book* findBookByISBN(const std::string& isbn);

    // Borrow a book by ISBN
    void borrowBookByISBN(const std::string& isbn);

    // Return a book by ISBN
    void returnBookByISBN(const std::string& isbn);

    // Display all books
    void displayAllBooks() const;
};

#endif // LIBRARYSYSTEM_H
