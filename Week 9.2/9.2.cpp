#include <bits/stdc++.h>
using namespace std;

class Staff {
protected:
    string name;
public:
    Staff(string n) : name(n) {}
    virtual double pay() = 0;
    string getName() { return name; }
    virtual ~Staff() {}
};

class FullTime : public Staff {
    double salary;
public:
    FullTime(string n, double s) : Staff(n), salary(s) {}
    double pay() override { return salary; }
};

class Hourly : public Staff {
    double hours, rate;
public:
    Hourly(string n, double h, double r)
        : Staff(n), hours(h), rate(r) {}
    double pay() override {
        return min(hours, 40.0) * rate
             + max(0.0, hours - 40) * rate * 1.5;
    }
};

class Intern : public Staff {
    double stipend;
public:
    Intern(string n, double s) : Staff(n), stipend(s) {}
    double pay() override { return stipend; }
};

int main() {
    int n;
    cin >> n;
    double total = 0;
    cout << fixed << setprecision(2);

    while (n--) {
        string type, name;
        cin >> type >> name;
        unique_ptr<Staff> s;

        if (type == "FULLTIME") {
            double salary;
            cin >> salary;
            s = make_unique<FullTime>(name, salary);
        } else if (type == "HOURLY") {
            double h, r;
            cin >> h >> r;
            s = make_unique<Hourly>(name, h, r);
        } else {
            double stipend;
            cin >> stipend;
            s = make_unique<Intern>(name, stipend);
        }

        double p = s->pay();
        cout << s->getName() << ": " << p << '\n';
        total += p;
    }

    cout << "Total Payroll: " << total << '\n';
}
