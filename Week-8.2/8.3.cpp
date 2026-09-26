#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Delivery {
protected:
    double weight;
    double distance;

public:
    Delivery(double weight, double distance) {
        this->weight = weight;
        this->distance = distance;
    }

    virtual double calculateFee() = 0;
    virtual ~Delivery() {}
};

class Standard : public Delivery {
public:
    Standard(double weight, double distance)
        : Delivery(weight, distance) {}

    double calculateFee() override {
        return 5 + 0.50 * weight + 0.10 * distance;
    }
};

class Express : public Delivery {
public:
    Express(double weight, double distance)
        : Delivery(weight, distance) {}

    double calculateFee() override {
        return 15 + 1.00 * weight + 0.20 * distance;
    }
};

class International : public Delivery {
private:
    double customsFee;

public:
    International(double weight, double distance, double customsFee)
        : Delivery(weight, distance) {
        this->customsFee = customsFee;
    }

    double calculateFee() override {
        return 25 + 2.00 * weight + 0.50 * distance + customsFee;
    }
};

int main() {
    int N;
    cin >> N;

    double total = 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < N; i++) {
        string type;
        double weight, distance;

        cin >> type >> weight >> distance;

        Delivery* delivery;

        if (type == "STANDARD") {
            delivery = new Standard(weight, distance);
        }
        else if (type == "EXPRESS") {
            delivery = new Express(weight, distance);
        }
        else {
            double customsFee;
            cin >> customsFee;

            delivery = new International(weight, distance, customsFee);
        }

        double fee = delivery->calculateFee();

        cout << type << ": " << fee << endl;

        total += fee;

        delete delivery;
    }

    cout << "Total: " << total << endl;

    return 0;
}
