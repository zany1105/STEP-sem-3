#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Payment {
protected:
    double amount;

public:
    Payment(double amount) {
        this->amount = amount;
    }

    virtual double calculate() = 0;
    virtual ~Payment() {}
};

class Card : public Payment {
public:
    Card(double amount) : Payment(amount) {}

    double calculate() override {
        return amount * 1.02;
    }
};

class Wallet : public Payment {
public:
    Wallet(double amount) : Payment(amount) {}

    double calculate() override {
        return amount * 1.01;
    }
};

class BankTransfer : public Payment {
public:
    BankTransfer(double amount) : Payment(amount) {}

    double calculate() override {
        return amount;
    }
};

int main() {
    int N;
    cin >> N;

    double total = 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < N; i++) {
        string type;
        double amount;

        cin >> type >> amount;

        Payment* payment;

        if (type == "CARD")
            payment = new Card(amount);
        else if (type == "WALLET")
            payment = new Wallet(amount);
        else
            payment = new BankTransfer(amount);

        double result = payment->calculate();

        cout << type << ": " << result << endl;

        total += result;
        delete payment;
    }

    cout << "Total: " << total << endl;

    return 0;
}
