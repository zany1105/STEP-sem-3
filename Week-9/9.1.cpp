#include <bits/stdc++.h>
using namespace std;

class Ticket {
public:
    virtual double price() const = 0;
    double amount(int n) const {
        return n * (price() + 20);
    }
    virtual ~Ticket() = default;
};

class Regular : public Ticket {
public:
    double price() const override { return 150; }
};

class Premium : public Ticket {
public:
    double price() const override { return 250; }
};

class Recliner : public Ticket {
public:
    double price() const override { return 400; }
};

int main() {
    int n;
    cin >> n;
    double total = 0;
    cout << fixed << setprecision(2);

    while (n--) {
        string seat;
        int count;
        cin >> seat >> count;

        unique_ptr<Ticket> t;
        if (seat == "REGULAR") t = make_unique<Regular>();
        else if (seat == "PREMIUM") t = make_unique<Premium>();
        else t = make_unique<Recliner>();

        double a = t->amount(count);
        cout << seat << ": " << a << '\n';
        total += a;
    }

    cout << "Total: " << total << '\n';
}
