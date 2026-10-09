#include <bits/stdc++.h>
using namespace std;

class SaverMode {
public:
    virtual bool supportsSaver() const = 0;
    double save(double units) const {
        return units * 0.75;
    }
    virtual ~SaverMode() = default;
};

class Appliance {
public:
    virtual double power() const = 0;
    virtual ~Appliance() = default;
};

class Fridge : public Appliance {
public:
    double power() const override { return 150; }
};

class AC : public Appliance, public SaverMode {
public:
    double power() const override { return 1500; }
    bool supportsSaver() const override { return true; }
};

class TV : public Appliance {
public:
    double power() const override { return 100; }
};

class Washer : public Appliance, public SaverMode {
public:
    double power() const override { return 500; }
    bool supportsSaver() const override { return true; }
};

int main() {
    int n;
    cin >> n;
    double total = 0;
    cout << fixed << setprecision(2);

    while (n--) {
        string type, rest;
        double hours;
        cin >> type >> hours;
        getline(cin, rest);

        bool requested = rest.find("SAVER") != string::npos;

        unique_ptr<Appliance> a;
        if (type == "FRIDGE") a = make_unique<Fridge>();
        else if (type == "AC") a = make_unique<AC>();
        else if (type == "TV") a = make_unique<TV>();
        else a = make_unique<Washer>();

        auto saver = dynamic_cast<SaverMode*>(a.get());

        if (requested && (!saver || !saver->supportsSaver())) {
            cout << type << ": saver mode not supported\n";
            continue;
        }

        double units = a->power() * hours / 1000.0;
        if (requested) units = saver->save(units);

        double cost = units * 8;
        cout << type << ": Units=" << units
             << " Cost=" << cost << '\n';

        total += cost;
    }

    cout << "Total Cost: " << total << '\n';
}
