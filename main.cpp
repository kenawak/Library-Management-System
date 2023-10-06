#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <windows.h>

using namespace std;

struct Book {
    string title;
    string author;
    int publishedYear = 0;
    string ISBN;
};

const int MAX_BOOKS = 1000;

Book library[MAX_BOOKS];
int numBooks = 0;
int main() {
    int result=IDCANCEL;
    int choice;
    do {
        cout << "Library Management System Menu:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Display all books" << endl;
        cout << "3. Search for a book" << endl;
        cout << "4. Edit book information" << endl;
        cout << "5. Delete a book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout<<"Preparing windows..."<<flush;
                this_thread::sleep_for(chrono::seconds(3));
                system("CLS");
                if (numBooks < MAX_BOOKS) {
                    Book newBook;
                    cout << "Enter book title: ";
                    cin.ignore();
                    getline(cin, newBook.title);
                    cout << "Enter author: ";
                    getline(cin, newBook.author);
                    cout << "Enter a valid year (e.g., 2023): ";
                    cin >> newBook.publishedYear;
                    while(newBook.publishedYear <= 1000 || newBook.publishedYear > 2023){
                        cout << "Invalid year. Please try again." << endl;
                        cout << "Enter a valid year (e.g., 2023): ";
                        cin >> newBook.publishedYear;
                    }
                    cout << "Enter ISBN: ";
                    cin.ignore();
                    getline(cin, newBook.ISBN);
                    library[numBooks] = newBook;
                    numBooks++;
                    cout<<"Book added successfully!"<<flush;
                    this_thread::sleep_for(chrono::seconds(2));
                    system("CLS");
                } else {
                    cout<<"Library is full. Cannot add more books."<<flush;
                    this_thread::sleep_for(chrono::seconds(3));
                    system("CLS");                }
                break;
            }
            case 2: {
                system("CLS");
                cout << "\t \t \t ===========List of Books===========" << endl;
                if (numBooks == 0) {
                    cout<<"No books in the store! __ Add books and try again!"<<flush;
                    this_thread::sleep_for(chrono::seconds(3));
                    system("CLS");
                }
                for (int i = 0; i < numBooks; i++) {
                    cout << "Title: " << library[i].title << endl;
                    cout << "Author: " << library[i].author << endl;
                    cout << "Published Year: " << library[i].publishedYear << endl;
                    cout << "ISBN: " << library[i].ISBN << endl;
                    cout << "======================" << endl;
                }
                break;
            }
            case 3: {
                system("CLS");
                cout << "\t \t \t ===========BOOKS SEARCH QUERY===========" << endl;
                if (numBooks == 0) {
                    cout<<"Oops... No books to search!"<<flush;
                    this_thread::sleep_for(chrono::seconds(3));
                    system("CLS");
                } else {
                    string keyword;
                    cout << "Enter title or ISBN to search: ";
                    cin.ignore();
                    getline(cin, keyword);

                    bool found = false;
                    for (int i = 0; i < numBooks; i++) {
                        if (library[i].title == keyword || library[i].ISBN == keyword) {
                            cout << "Book found:" << endl;
                            cout << "Title: " << library[i].title << endl;
                            cout << "Author: " << library[i].author << endl;
                            cout << "Published Year: " << library[i].publishedYear << endl;
                            cout << "ISBN: " << library[i].ISBN << endl;
                            found = true;
                            cout<<"=================";
                            break;
                        }
                    }

                    if (!found) {
                        cout<<"Book Not found!"<<flush;
                        this_thread::sleep_for(chrono::seconds(3));
                        system("CLS");
                    }
                }
                break;
            }
            case 4: {
                system("CLS");
                cout << "\t \t \t ===========BOOKS EDIT===========" << endl;
                string ISBN;
                cout << "Enter ISBN of the book to edit: ";
                cin.ignore();
                getline(cin, ISBN);

                bool found = false;
                for (int i = 0; i < numBooks; i++) {
                    if (library[i].ISBN == ISBN) {
                        cout << "Edit info for: " << library[i].title << " by " << library[i].author << endl;
                        cout << "Edit book title: ";
                        getline(cin, library[i].title);
                        cout << "Edit author: ";
                        getline(cin, library[i].author);
                        while (true) {
                        cout << "Enter a valid year (e.g., 2023): ";
                        cin >> library[i].publishedYear;
                        if (library[i].publishedYear >= 1000 && library[i].publishedYear <= 9999) {
                            return library[i].publishedYear;
                        } else {
                            cout << "Invalid year. Please try again." << endl;
                        }
                        }
                        cout << "Edit ISBN: ";
                        cin >> library[i].ISBN;
                        cout<<"Book information updated successfully!\nUpdated to: " + library[i].title + " by " + library[i].author + " published in " + to_string(library[i].publishedYear) + "\nISBN to: " + library[i].ISBN<<flush;
                        this_thread::sleep_for( chrono::seconds(3));
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout<<"Book not found."<<flush;
                    this_thread::sleep_for(chrono::seconds(3));
                }
                break;
            }
            case 5: {
                system("CLS");
                cout << "\t \t \t ===========Deleting Command===========" << endl;
                string ISBN;
                cout << "Enter ISBN of the book to delete: ";
                cin.ignore();
                getline(cin, ISBN);

                bool found = false;
                for (int i = 0; i < numBooks; i++) {
                    if (library[i].ISBN == ISBN) {
                        for (int j = i; j < numBooks - 1; j++) {
                            library[j] = library[j + 1];
                        }
                        numBooks--;
                        cout<<"Book deleted successfully!"<<flush;
                        this_thread::sleep_for(chrono::seconds(3));
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout<<"Book not found."<<flush;
                    this_thread::sleep_for(chrono::seconds(3));
                }
                break;
            }
            case 6:
                int result = MessageBox(NULL, "Are you sure to EXIT?", "EXIT?", MB_ICONQUESTION | MB_OKCANCEL);
                if (result == IDOK) {
                    cout << "Exiting the program. Goodbye!" << endl;
                    return 0;
                } else if (result == IDCANCEL) {
                    cout << "Redirecting to the menu..." << endl;
                    this_thread::sleep_for(chrono::seconds(3));
                    system("CLS");
                }
    }} while (result == IDCANCEL);

    return 0;
}
