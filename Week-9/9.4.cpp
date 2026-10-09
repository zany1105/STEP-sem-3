#include <bits/stdc++.h>
using namespace std;

class NightService {
public:
    virtual bool supportsNight() const = 0;
    double nightFare(double fare) const {
        return fare * 1.20;
    }
    virtual ~NightService() = default;
};

class Cab {
public:
    virtual double rate() const = 0;
    double fare(double km) const {
        return max(100.0, km * rate());
    }
    virtual ~Cab() = default;
};

class Mini : public Cab {
public:
    double rate() const override { return 10; }
};

class Sedan : public Cab, public NightService {
public:
    double rate() const override { return 14; }
    bool supportsNight() const override { return true; }
};

class SUV : public Cab, public NightService {
public:
    double rate() const override { return 18; }
    bool supportsNight() const override { return true; }
};

int main() {
    int n;
    cin >> n;
    double total = 0;
    cout << fixed << setprecision(2);

    while (n--) {
        string type, time;
        double km;
        cin >> type >> km >> time;

        unique_ptr<Cab> c;
        if (type == "MINI") c = make_unique<Mini>();
        else if (type == "SEDAN") c = make_unique<Sedan>();
        else c = make_unique<SUV>();

        auto night = dynamic_cast<NightService*>(c.get());

        if (time == "NIGHT" &&
            (!night || !night->supportsNight())) {
            cout << type << ": night service not available\n";
            continue;
        }

        double f = c->fare(km);
        if (time == "NIGHT")
            f = night->nightFare(f);

        cout << type << ": " << f << '\n';
        total += f;
    }

    cout << "Total: " << total << '\n';
}
