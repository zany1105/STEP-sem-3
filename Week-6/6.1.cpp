#include <iostream>
#include <string>
using namespace std;

class BookInventory {
public:
    string title;
    string author;
    int copiesAvailable;

    // Constructor
    BookInventory(string title, string author, int copiesAvailable) {
        this->title = title;
        this->author = author;
        this->copiesAvailable = copiesAvailable;
    }

    // Instance method
    void printEntry() {
        cout << title << " by " << author << " - "
             << copiesAvailable << " copies available" << endl;
    }
};

int main() {

    BookInventory b1("Clean Code", "Robert C. Martin", 3);
    BookInventory b2("Effective Java", "Joshua Bloch", 5);
    BookInventory b3("Refactoring", "Martin Fowler", 0);
    BookInventory b4("Design Patterns", "GoF", 2);

    // Array of objects
    BookInventory books[] = {b1, b2, b3, b4};

    // Print each book
    for (int i = 0; i < 4; i++) {
        books[i].printEntry();
    }

    return 0;
}
