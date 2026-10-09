#include <bits/stdc++.h>
using namespace std;

class LibraryItem {
protected:
    string title;
    int days;
public:
    LibraryItem(string t, int d) : title(t), days(d) {}
    virtual double fine() = 0;
    string getTitle() { return title; }
    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
public:
    Book(string t, int d) : LibraryItem(t, d) {}
    double fine() override { return days * 2.0; }
};

class DVD : public LibraryItem {
public:
    DVD(string t, int d) : LibraryItem(t, d) {}
    double fine() override { return min(days * 5.0, 50.0); }
};

class Magazine : public LibraryItem {
public:
    Magazine(string t, int d) : LibraryItem(t, d) {}
    double fine() override { return days * 1.0; }
};

int main() {
    int n;
    cin >> n;
    double total = 0;
    cout << fixed << setprecision(2);

    while (n--) {
        string type, title;
        int days;
        cin >> type >> title >> days;

        unique_ptr<LibraryItem> item;
        if (type == "BOOK")
            item = make_unique<Book>(title, days);
        else if (type == "DVD")
            item = make_unique<DVD>(title, days);
        else
            item = make_unique<Magazine>(title, days);

        double f = item->fine();
        cout << item->getTitle() << ": " << f << '\n';
        total += f;
    }

    cout << "Total Fines: " << total << '\n';
}
