#include <iostream>
using namespace std;

class MessWallet {
private:
    double balance;

public:

    // Constructor
    MessWallet(double openingBalance) {

        if (openingBalance < 0) {
            cout << "Warning: Negative opening balance. "
                 << "Starting at 0." << endl;

            balance = 0;
        }
        else {
            balance = openingBalance;
        }
    }

    // Add money
    void topUp(double amount) {

        if (amount <= 0) {
            cout << "Top-up rejected: invalid amount" << endl;
        }
        else {
            balance += amount;

            cout << "Balance after top-up: "
                 << balance << endl;
        }
    }

    // Deduct money
    void deduct(double amount) {

        if (amount > balance) {
            cout << "Deduct rejected: insufficient balance"
                 << endl;
        }
        else if (amount <= 0) {
            cout << "Deduct rejected: invalid amount"
                 << endl;
        }
        else {
            balance -= amount;

            cout << "Balance after deduction: "
                 << balance << endl;
        }
    }

    // Getter
    double getBalance() {
        return balance;
    }
};

int main() {

    MessWallet wallet(500);

    wallet.topUp(200);

    wallet.deduct(1000);

    cout << "Final balance: "
         << wallet.getBalance() << endl;

    return 0;
}
