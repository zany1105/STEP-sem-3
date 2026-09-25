#include <iostream>
using namespace std;

class Cart {
private:
    double* prices;
    int maxSize;
    int count;
    const string cartId;

public:
    Cart(string id, int size) : cartId(id) {
        maxSize = size;
        count = 0;
        prices = new double[maxSize];
    }

    void addItem(double price) {
        if (count < maxSize) {
            prices[count] = price;
            count++;
        }
    }

    double getTotal() const {
        double total = 0;

        for (int i = 0; i < count; i++) {
            total += prices[i];
        }

        return total;
    }

    int getItemCount() const {
        return count;
    }

    ~Cart() {
        delete[] prices;
    }
};

int main() {
    Cart cart("CART-5", 20);

    cart.addItem(250);
    cart.addItem(99);
    cart.addItem(151);

    cout << cart.getTotal() << endl;
    cout << cart.getItemCount() << endl;

    return 0;
}
