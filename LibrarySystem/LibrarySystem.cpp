#include <iostream>
#include "LibrarySystem.h"

using namespace std;

int main() {
    LibrarySystem library;
    int option;
    string isbn;

    while (true) {
        cout << "\nLibrary Menu:\n";
        cout << "1. Borrow Book\n";
        cout << "2. Return Book\n";
        cout << "3. Display All Books\n";
        cout << "4. Exit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
        case 1:  // Borrow Book
            cout << "Enter ISBN of the book to borrow: ";
            cin >> isbn;
            library.borrowBookByISBN(isbn);
            break;

        case 2:  // Return Book
            cout << "Enter ISBN of the book to return: ";
            cin >> isbn;
            library.returnBookByISBN(isbn);
            break;

        case 3:  // Display All Books
            library.displayAllBooks();
            break;

        case 4:  // Exit
            cout << "Exiting the program." << endl;
            return 0;

        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
}
