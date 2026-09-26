#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Vehicle {
protected:
    int hours;

public:
    Vehicle(int hours) {
        this->hours = hours;
    }

    virtual double calculate() = 0;
    virtual ~Vehicle() {}
};

class Bike : public Vehicle {
public:
    Bike(int hours) : Vehicle(hours) {}

    double calculate() override {
        return hours * 10;
    }
};

class Car : public Vehicle {
public:
    Car(int hours) : Vehicle(hours) {}

    double calculate() override {
        if (hours == 1)
            return 30;

        return 30 + (hours - 1) * 20;
    }
};

class Truck : public Vehicle {
public:
    Truck(int hours) : Vehicle(hours) {}

    double calculate() override {
        double charge = hours * 50;

        if (charge < 100)
            charge = 100;

        return charge;
    }
};

int main() {
    int N;
    cin >> N;

    double total = 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < N; i++) {
        string type;
        int hours;

        cin >> type >> hours;

        Vehicle* vehicle;

        if (type == "BIKE")
            vehicle = new Bike(hours);
        else if (type == "CAR")
            vehicle = new Car(hours);
        else
            vehicle = new Truck(hours);

        double charge = vehicle->calculate();

        cout << type << ": " << charge << endl;
        total += charge;

        delete vehicle;
    }

    cout << "Total: " << total << endl;

    return 0;
}
