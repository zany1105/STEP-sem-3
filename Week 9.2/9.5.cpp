#include <bits/stdc++.h>
using namespace std;

class Booking {
protected:
    double distance;
    static constexpr double FEE = 50.0;

public:
    Booking(double d) : distance(d) {}
    virtual double fare() = 0;

    double total() {
        return fare() + FEE;
    }

    virtual ~Booking() {}
};

class Bus : public Booking {
public:
    Bus(double d) : Booking(d) {}
    double fare() override { return distance * 2; }
};

class Train : public Booking {
public:
    Train(double d) : Booking(d) {}
    double fare() override { return distance * 1.5; }
};

class Flight : public Booking {
public:
    Flight(double d) : Booking(d) {}
    double fare() override { return 2500 + distance * 4; }
};

int main() {
    int n;
    cin >> n;
    cout << fixed << setprecision(2);

    while (n--) {
        string mode;
        double km;
        cin >> mode >> km;

        unique_ptr<Booking> b;
        if (mode == "BUS")
            b = make_unique<Bus>(km);
        else if (mode == "TRAIN")
            b = make_unique<Train>(km);
        else
            b = make_unique<Flight>(km);

        cout << mode << ": " << b->total() << '\n';
    }
}
