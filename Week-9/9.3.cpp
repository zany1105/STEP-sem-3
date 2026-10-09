#include <bits/stdc++.h>
using namespace std;

class BusUser {
public:
    virtual bool usesBus() const = 0;
    virtual ~BusUser() = default;
};

class Student {
protected:
    string name;
public:
    Student(string n) : name(n) {}
    virtual double tuition() const = 0;
    virtual double extraFee() const { return 0; }

    double totalFee() const {
        double fee = tuition() + extraFee();
        const BusUser* b = dynamic_cast<const BusUser*>(this);
        if (b && b->usesBus()) fee += 12000;
        return fee;
    }

    string getName() const { return name; }
    virtual ~Student() = default;
};

class DayScholar : public Student, public BusUser {
public:
    DayScholar(string n) : Student(n) {}
    double tuition() const override { return 40000; }
    bool usesBus() const override { return true; }
};

class Hosteller : public Student {
public:
    Hosteller(string n) : Student(n) {}
    double tuition() const override { return 40000; }
    double extraFee() const override { return 60000; }
};

class Scholar : public Student, public BusUser {
public:
    Scholar(string n) : Student(n) {}
    double tuition() const override { return 20000; }
    bool usesBus() const override { return true; }
};

int main() {
    int n;
    cin >> n;
    double total = 0;
    cout << fixed << setprecision(2);

    while (n--) {
        string type, name;
        cin >> type >> name;

        unique_ptr<Student> s;
        if (type == "DAY_SCHOLAR")
            s = make_unique<DayScholar>(name);
        else if (type == "HOSTELLER")
            s = make_unique<Hosteller>(name);
        else
            s = make_unique<Scholar>(name);

        double fee = s->totalFee();
        cout << s->getName() << ": " << fee << '\n';
        total += fee;
    }

    cout << "Total Collected: " << total << '\n';
}
