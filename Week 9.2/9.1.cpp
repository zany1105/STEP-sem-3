#include <bits/stdc++.h>
using namespace std;

class Plot {
protected:
    string owner;
public:
    Plot(string o) : owner(o) {}
    virtual double area() = 0;
    virtual string shape() = 0;
    string getOwner() { return owner; }
    virtual ~Plot() {}
};

class Circle : public Plot {
    double r;
public:
    Circle(string o, double x) : Plot(o), r(x) {}
    double area() override { return acos(-1.0) * r * r; }
    string shape() override { return "CIRCLE"; }
};

class Rectangle : public Plot {
    double l, w;
public:
    Rectangle(string o, double x, double y) : Plot(o), l(x), w(y) {}
    double area() override { return l * w; }
    string shape() override { return "RECTANGLE"; }
};

class Triangle : public Plot {
    double b, h;
public:
    Triangle(string o, double x, double y) : Plot(o), b(x), h(y) {}
    double area() override { return 0.5 * b * h; }
    string shape() override { return "TRIANGLE"; }
};

int main() {
    int n;
    cin >> n;
    double total = 0;
    cout << fixed << setprecision(2);

    while (n--) {
        string type, name;
        double x, y = 0;
        cin >> type >> name >> x;

        unique_ptr<Plot> p;
        if (type == "CIRCLE")
            p = make_unique<Circle>(name, x);
        else if (type == "RECTANGLE") {
            cin >> y;
            p = make_unique<Rectangle>(name, x, y);
        } else {
            cin >> y;
            p = make_unique<Triangle>(name, x, y);
        }

        double a = p->area();
        cout << p->getOwner() << " (" << p->shape()
             << "): " << a << '\n';
        total += a;
    }

    cout << "Total Area: " << total << '\n';
}
