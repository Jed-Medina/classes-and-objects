#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Book 
{
    private:
        string title;
        string author;
        int year;

    public:
        Book(string t, string a, int y)
        {
            title = t;
            author = a;
            year = y;
        }

        string getTitle() { return title; }
        string getAuthor() { return author; }
        int getYear() { return year; }

        void displayBook() 
        {
            cout << setw(20) << left << title
                << setw(5) << left << "|" 
                << setw(20) << left << author
                << setw(5) << left << "|" 
                << setw(4) << year << endl;
        }
};

class Library 
{
    private:
        vector<Book> books;

    public:
        void addBook(string title, string author, int year) 
        {
            books.push_back(Book(title, author, year));
            cout << "Book added successfully!" << endl;
        }

        void displayBooks() 
        {
            if (books.empty()) 
            {
                cout << "There are no books!" << endl;
                return;
            }

            cout << setw(22) << left << "Title:"
                << setw(5) << left << "|" 
                << setw(20) << left << "Author:"
                << setw(5) << left << "|" 
                << setw(4) << "Year:" << endl;
            for (int i = 0; i < books.size(); i++) 
            {
                Book book = books.at(i);
                cout << i+1 << ".";
                book.displayBook();
            }
        }

        void searchBook(string title) {
            for (int i = 0; i < books.size(); i++) {
                Book book = books.at(i);
                if (book.getTitle() == title) {
                    cout << "Book found!" << endl;
                    cout << "Title: " << book.getTitle() << endl;
                    cout << "Author: " << book.getAuthor() << endl;
                    cout << "Year: " << book.getYear() << endl;
                    return;
                }
            }
            cout << "Book not found!" << endl;
        }
};

void displayMenu() 
{
    cout << "Menu:" << endl;
    cout << "1 - Add Book" << endl;
    cout << "2 - Display Books" << endl;
    cout << "3 - Search Book" << endl;
    cout << "4 - Exit" << endl;
}

void displayAddBook(string *title, string *author, int *year)
{
    cout << "Enter title: ";
    getline(cin, *title);
    cout << "Enter author: ";
    getline(cin, *author);
    cout << "Enter year: ";
    cin >> *year;
}

int main() 
{
    Library library;
    int choice;
    string title, author;
    int year;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                displayAddBook(&title, &author, &year);
                library.addBook(title, author, year);
                cout << endl;
                break;

            case 2:
                cout << "Book List:" << endl;
                library.displayBooks();
                cout << endl;
                break;

            case 3:
                cout << "Enter a book to search: ";
                getline(cin, title);
                library.searchBook(title);
                cout << endl;
                break;

            case 4:
                cout << "EXITING!" << endl;
                break;

            default:
                cout << "INVALID INPUT!" << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}