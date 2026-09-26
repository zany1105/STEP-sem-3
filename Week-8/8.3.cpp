#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Room {
protected:
    int units;

public:
    Room(int units) {
        this->units = units;
    }

    virtual double calculate() = 0;
    virtual ~Room() {}
};

class Single : public Room {
public:
    Single(int units) : Room(units) {}

    double calculate() override {
        return units * 8;
    }
};

class Shared : public Room {
private:
    int occupants;

public:
    Shared(int units, int occupants) : Room(units) {
        this->occupants = occupants;
    }

    double calculate() override {
        return (units * 6.0) / occupants;
    }
};

class AC : public Room {
public:
    AC(int units) : Room(units) {}

    double calculate() override {
        return units * 10 + 200;
    }
};

int main() {
    int N;
    cin >> N;

    double total = 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < N; i++) {
        string type;
        int units;

        cin >> type >> units;

        Room* room;

        if (type == "SINGLE") {
            room = new Single(units);
        }
        else if (type == "SHARED") {
            int occupants;
            cin >> occupants;
            room = new Shared(units, occupants);
        }
        else {
            room = new AC(units);
        }

        double bill = room->calculate();

        cout << type << ": " << bill << endl;
        total += bill;

        delete room;
    }

    cout << "Total: " << total << endl;

    return 0;
}
