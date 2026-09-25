#include <iostream>
#include <string>
using namespace std;

class PiggyBank {
private:
    double savings;
    const string id;

public:
    PiggyBank(string id) : id(id) {
        savings = 0;
    }

    void deposit(double amount) {
        savings += amount;
    }

    void withdraw(double amount) {
        if (amount <= savings) {
            savings -= amount;
        }
    }

    double getSavings() const {
        return savings;
    }
};

int main() {
    PiggyBank pb("PB-1");

    pb.deposit(100);
    cout << pb.getSavings() << endl;

    pb.withdraw(30);
    cout << pb.getSavings() << endl;

    pb.withdraw(500);
    cout << pb.getSavings() << endl;

    return 0;
}
