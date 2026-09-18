#include <iostream>
#include <string>
using namespace std;

class IdCard {
public:
    string name;
    int booksIssued;

    // Constructor
    IdCard(string name, int booksIssued) {
        this->name = name;
        this->booksIssued = booksIssued;
    }
};

int main() {

    // Create Ravi's ID card
    IdCard ravi("Ravi", 0);

    // Point to the same object
    IdCard* duplicate = &ravi;

    // Change booksIssued through duplicate
    duplicate->booksIssued = 3;

    // Create a separate object
    IdCard separate("Ravi", 3);

    cout << "Ravi's booksIssued "
         << "(via first variable): "
         << ravi.booksIssued << endl;

    // Check if duplicate and ravi refer to same object
    cout << "duplicate == &ravi: "
         << (duplicate == &ravi ? "true" : "false")
         << endl;

    // Check separate object
    cout << "&separate == &ravi: "
         << (&separate == &ravi ? "true" : "false")
         << endl;

    return 0;
}
