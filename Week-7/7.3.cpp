#include <iostream>
#include <string>
using namespace std;

class PasswordChecker {
private:
    const string password;

public:
    PasswordChecker(string password) : password(password) {
    }

    string getStrength() const {
        if (password.length() < 6) {
            return "Weak";
        }
        else if (password.length() <= 9) {
            return "Medium";
        }
        else {
            return "Strong";
        }
    }
};

int main() {
    PasswordChecker pc("abcd");
    cout << pc.getStrength() << endl;

    PasswordChecker pc2("abcdefghij");
    cout << pc2.getStrength() << endl;

    return 0;
}
