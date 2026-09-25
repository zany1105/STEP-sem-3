#include <iostream>
#include <string>
using namespace std;

class NameTag {
private:
    const string firstName;
    const string lastName;

public:
    NameTag(string fullName)
        : firstName(fullName.substr(0, fullName.find(' '))),
          lastName(fullName.substr(fullName.find(' ') + 1)) {
    }

    string getNickname() const {
        return firstName + " " + lastName[0] + ".";
    }
};

int main() {
    NameTag tag("Maria Gomez");

    cout << tag.getNickname() << endl;

    return 0;
}
