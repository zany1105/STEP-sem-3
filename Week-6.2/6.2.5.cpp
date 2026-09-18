#include <iostream>
#include <string>
using namespace std;

class Student {
public:

    // Instance variables
    string name;
    double attendance;

    // Static variables
    static string collegeName;
    static int studentCount;

    // Constructor
    Student(string name, double attendance) {
        this->name = name;
        this->attendance = attendance;

        // Increment student count
        studentCount++;
    }

    // Static function
    static void printCollegeInfo() {

        cout << collegeName << endl;

        cout << "Students created: "
             << studentCount << endl;
    }
};

// Define static variables
string Student::collegeName =
    "SRM Institute of Science and Technology";

int Student::studentCount = 0;

int main() {

    Student s1("Ravi", 90);
    Student s2("Anitha", 95);

    // Call static function using class name
    Student::printCollegeInfo();

    return 0;
}
