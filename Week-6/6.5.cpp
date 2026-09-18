#include <iostream>
#include <string>
using namespace std;

class Employee {
public:

    // Instance variables
    string empName;
    double salary;

    // Static variables
    static string companyName;
    static int employeeCount;

    // Constructor
    Employee(string name, double sal) {
        empName = name;
        salary = sal;

        // Increase employee count
        employeeCount++;
    }

    // Static function
    static void printCompanyInfo() {
        cout << companyName << endl;
        cout << "Employees on record: "
             << employeeCount << endl;
    }
};

// Definition of static variables
string Employee::companyName =
    "Bright Horizon Technologies";

int Employee::employeeCount = 0;

int main() {

    Employee e1("Divya", 65000);
    Employee e2("Arjun", 30000);
    Employee e3("Priya", 45000);

    // Call static function using class name
    Employee::printCompanyInfo();

    return 0;
}
