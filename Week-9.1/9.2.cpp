#include <bits/stdc++.h>
using namespace std;

class Insurable {
public:
    virtual double insurance(double value) const = 0;
    virtual ~Insurable() = default;
};

class Parcel {
protected:
    double weight;
public:
    Parcel(double w) : weight(w) {}
    virtual double charge() const = 0;
    virtual ~Parcel() = default;
};

class Standard : public Parcel {
public:
    Standard(double w) : Parcel(w) {}
    double charge() const override {
        return 40 + 10 * weight;
    }
};

class Express : public Parcel, public Insurable {
public:
    Express(double w) : Parcel(w) {}
    double charge() const override {
        return 80 + 15 * weight;
    }
    double insurance(double v) const override {
        return v * 0.02;
    }
};

class Fragile : public Parcel, public Insurable {
public:
    Fragile(double w) : Parcel(w) {}
    double charge() const override {
        return 40 + 10 * weight + 50;
    }
    double insurance(double v) const override {
        return v * 0.02;
    }
};

int main() {
    int n;
    cin >> n;
    double grand = 0;
    cout << fixed << setprecision(2);

    while (n--) {
        string type;
        double w, value;
        cin >> type >> w >> value;

        unique_ptr<Parcel> p;
        if (type == "STANDARD") p = make_unique<Standard>(w);
        else if (type == "EXPRESS") p = make_unique<Express>(w);
        else p = make_unique<Fragile>(w);

        double c = p->charge(), ins = 0;
        if (auto i = dynamic_cast<Insurable*>(p.get()))
            ins = i->insurance(value);

        cout << type << ": Charge=" << c
             << " Insurance=" << ins
             << " Total=" << c + ins << '\n';

        grand += c + ins;
    }

    cout << "Grand Total: " << grand << '\n';
}
