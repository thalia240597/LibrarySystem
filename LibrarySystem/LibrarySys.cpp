#include "LibrarySystem.h"
#include <iostream>

using namespace std;

// Book class constructor
Book::Book(string t, string a, string i, bool avail)
    : title(t), author(a), isbn(i), isAvailable(avail) {}

// Set book details
void Book::setBookDetails(string t, string a, string i, bool avail) {
    title = t;
    author = a;
    isbn = i;
    isAvailable = avail;
}

// Display book details
void Book::displayBookDetails() const {
    cout << "Title: " << title << ", Author: " << author
        << ", ISBN: " << isbn << ", Availability: "
        << (isAvailable ? "Available" : "Borrowed") << endl;
}

// Borrow book if available
bool Book::borrowBook() {
    if (isAvailable) {
        isAvailable = false;
        cout << "Book borrowed successfully." << endl;
        return true;
    }
    else {
        cout << "Error: Book is currently unavailable." << endl;
        return false;
    }
}

// Return book and mark as available
void Book::returnBook() {
    isAvailable = true;
    cout << "Book returned successfully." << endl;
}

// Check ISBN match
bool Book::checkISBN(const string& i) const {
    return isbn == i;
}

// LibrarySystem class constructor
LibrarySystem::LibrarySystem() : bookCount(5) {
    // Initialize library with 5 books
    books[0].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "111111", true);
    books[1].setBookDetails("1984", "George Orwell", "222222", true);
    books[2].setBookDetails("To Kill a Mockingbird", "Harper Lee", "333333", true);
    books[3].setBookDetails("Pride and Prejudice", "Jane Austen", "444444", true);
    books[4].setBookDetails("The Catcher in the Rye", "J.D. Salinger", "555555", true);
}

// Find book by ISBN
Book* LibrarySystem::findBookByISBN(const string& isbn) {
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].checkISBN(isbn)) {
            return &books[i];
        }
    }
    return nullptr;
}

// Borrow a book by ISBN
void LibrarySystem::borrowBookByISBN(const string& isbn) {
    Book* book = findBookByISBN(isbn);
    if (book != nullptr) {
        book->borrowBook();
    }
    else {
        cout << "Error: No book with ISBN " << isbn << " found in the library." << endl;
    }
}

// Return a book by ISBN
void LibrarySystem::returnBookByISBN(const string& isbn) {
    Book* book = findBookByISBN(isbn);
    if (book != nullptr) {
        book->returnBook();
    }
    else {
        cout << "Error: No book with ISBN " << isbn << " found in the library." << endl;
    }
}

// Display all books
void LibrarySystem::displayAllBooks() const {
    for (int i = 0; i < bookCount; ++i) {
        books[i].displayBookDetails();
    }
}