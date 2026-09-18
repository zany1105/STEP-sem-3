#include <iostream>
#include <string>
using namespace std;

class HallTicket {
public:
    string studentName;
    int seatNumber;

    // Constructor
    HallTicket(string name, int seat) {
        studentName = name;
        seatNumber = seat;
    }
};

int main() {

    // Create first object
    HallTicket priya("Priya", 0);

    // copy points to the same object
    HallTicket* copy = &priya;

    // Change seat number through copy
    copy->seatNumber = 45;

    // Create a separate object
    HallTicket separate("Priya", 45);

    cout << "Priya's seatNumber (via first variable): "
         << priya.seatNumber << endl;

    // Check whether both point to same object
    cout << "copy == &priya: "
         << (copy == &priya ? "true" : "false")
         << endl;

    // Check separate object
    cout << "&separate == &priya: "
         << (&separate == &priya ? "true" : "false")
         << endl;

    return 0;
}
