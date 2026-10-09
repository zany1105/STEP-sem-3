#include <bits/stdc++.h>
using namespace std;

class Connection {
protected:
    double units;
public:
    Connection(double u) : units(u) {}
    virtual double bill() = 0;
    virtual ~Connection() {}
};

class Home : public Connection {
public:
    Home(double u) : Connection(u) {}
    double bill() override {
        return min(units, 100.0) * 5
             + max(0.0, units - 100) * 7;
    }
};

class Shop : public Connection {
public:
    Shop(double u) : Connection(u) {}
    double bill() override { return units * 8 + 100; }
};

class Factory : public Connection {
public:
    Factory(double u) : Connection(u) {}
    double bill() override { return max(1000.0, units * 6); }
};

int main() {
    int n;
    cin >> n;
    double total = 0;
    cout << fixed << setprecision(2);

    while (n--) {
        string type;
        double units;
        cin >> type >> units;

        unique_ptr<Connection> c;
        if (type == "HOME")
            c = make_unique<Home>(units);
        else if (type == "SHOP")
            c = make_unique<Shop>(units);
        else
            c = make_unique<Factory>(units);

        double b = c->bill();
        cout << type << ": " << b << '\n';
        total += b;
    }

    cout << "Total: " << total << '\n';
}
