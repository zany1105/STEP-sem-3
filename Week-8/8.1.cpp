#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Customer {
protected:
    double amount;

public:
    Customer(double amount) {
        this->amount = amount;
    }

    virtual double calculate() = 0;
    virtual ~Customer() {}
};

class Student : public Customer {
public:
    Student(double amount) : Customer(amount) {}

    double calculate() override {
        return amount * 0.90;
    }
};

class Staff : public Customer {
public:
    Staff(double amount) : Customer(amount) {}

    double calculate() override {
        return amount * 0.95;
    }
};

class Guest : public Customer {
public:
    Guest(double amount) : Customer(amount) {}

    double calculate() override {
        return amount + 10;
    }
};

int main() {
    int N;
    cin >> N;

    double total = 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < N; i++) {
        string type;
        double amount;
        cin >> type >> amount;

        Customer* customer;

        if (type == "STUDENT")
            customer = new Student(amount);
        else if (type == "STAFF")
            customer = new Staff(amount);
        else
            customer = new Guest(amount);

        double finalAmount = customer->calculate();

        cout << type << ": " << finalAmount << endl;
        total += finalAmount;

        delete customer;
    }

    cout << "Total: " << total << endl;

    return 0;
}
