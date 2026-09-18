#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    string code;
    string title;
    int credits;
    int labCredits;

    // Four-argument constructor
    Course(string code, string title, int credits, int labCredits) {
        this->code = code;
        this->title = title;
        this->credits = credits;
        this->labCredits = labCredits;
    }

    // Three-argument constructor
    // Delegates to four-argument constructor
    Course(string code, string title, int credits)
        : Course(code, title, credits, 0) {
    }

    // Return total credits
    int totalCredits() {
        return credits + labCredits;
    }
};

int main() {

    // Theory-only course
    Course c1(
        "21CSC201J",
        "Data Structures",
        4
    );

    // Course with lab
    Course c2(
        "21CSC205L",
        "DSA Lab",
        3,
        1
    );

    cout << c1.code
         << " total credits: "
         << c1.totalCredits()
         << endl;

    cout << c2.code
         << " total credits: "
         << c2.totalCredits()
         << endl;

    return 0;
}
