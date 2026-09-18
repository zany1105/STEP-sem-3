#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string empId;
    string empName;
    double salary;
    bool isIntern;

    // Constructor for permanent employee
    Employee(string id, string name, double sal) {
        empId = id;
        empName = name;
        salary = sal;
        isIntern = false;
    }

    // Constructor for intern
    Employee(string id, string name)
        : Employee(id, name, 0) {

        isIntern = true;
    }

    // Print profile
    void printProfile() {

        cout << empId << " | "
             << empName << " | Rs "
             << salary << " | Intern: "
             << (isIntern ? "true" : "false")
             << endl;
    }
};

int main() {

    // Permanent employee
    Employee e1("E-101", "Divya", 65000);

    // Intern
    Employee e2("E-102", "Arjun");

    e1.printProfile();
    e2.printProfile();

    return 0;
}
