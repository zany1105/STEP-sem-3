#include <iostream>
#include <algorithm>
using namespace std;

class Character {
private:
    int health;
    const int maxHealth;

public:
    Character(int maxHealth) : maxHealth(maxHealth) {
        health = maxHealth;
    }

    void takeDamage(int amount) {
        health = max(0, health - amount);
    }

    void heal(int amount) {
        health = min(maxHealth, health + amount);
    }

    int getHealth() const {
        return health;
    }
};

int main() {
    Character c(100);

    c.takeDamage(30);
    cout << c.getHealth() << endl;

    c.heal(50);
    cout << c.getHealth() << endl;

    c.takeDamage(150);
    cout << c.getHealth() << endl;

    return 0;
}
