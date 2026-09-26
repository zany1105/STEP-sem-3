#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    double salary;

public:
    Employee(string name, double salary) {
        this->name = name;
        this->salary = salary;
    }

    virtual double calculateBonus() = 0;

    string getName() {
        return name;
    }

    virtual ~Employee() {}
};

class FullTime : public Employee {
public:
    FullTime(string name, double salary) : Employee(name, salary) {}

    double calculateBonus() override {
        return salary * 0.10;
    }
};

class PartTime : public Employee {
public:
    PartTime(string name, double salary) : Employee(name, salary) {}

    double calculateBonus() override {
        return salary * 0.05;
    }
};

class Intern : public Employee {
public:
    Intern(string name, double salary) : Employee(name, salary) {}

    double calculateBonus() override {
        return 2000;
    }
};

int main() {
    int N;
    cin >> N;

    double total = 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < N; i++) {
        string type, name;
        double salary;

        cin >> type >> name >> salary;

        Employee* employee;

        if (type == "FULLTIME")
            employee = new FullTime(name, salary);
        else if (type == "PARTTIME")
            employee = new PartTime(name, salary);
        else
            employee = new Intern(name, salary);

        double bonus = employee->calculateBonus();

        cout << employee->getName() << ": " << bonus << endl;
        total += bonus;

        delete employee;
    }

    cout << "Total Bonus: " << total << endl;

    return 0;
}
