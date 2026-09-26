#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

class LibraryItem {
protected:
    string title;

public:
    LibraryItem(string title) {
        this->title = title;
    }

    virtual int getDays() = 0;

    void displayDueDate() {
        tm date = {};

        date.tm_year = 2023 - 1900;
        date.tm_mon = 9;
        date.tm_mday = 26 + getDays();

        mktime(&date);

        cout << title << ": "
             << date.tm_year + 1900 << "-"
             << setw(2) << setfill('0') << date.tm_mon + 1 << "-"
             << setw(2) << setfill('0') << date.tm_mday
             << endl;

        cout << setfill(' ');
    }

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
public:
    Book(string title) : LibraryItem(title) {}

    int getDays() override {
        return 14;
    }
};

class DVD : public LibraryItem {
public:
    DVD(string title) : LibraryItem(title) {}

    int getDays() override {
        return 7;
    }
};

class Magazine : public LibraryItem {
public:
    Magazine(string title) : LibraryItem(title) {}

    int getDays() override {
        return 3;
    }
};

int main() {
    int N;
    cin >> N;

    cin.ignore();

    for (int i = 0; i < N; i++) {
        string type;
        cin >> type;

        string title;
        getline(cin, title);

        if (!title.empty() && title[0] == ' ')
            title.erase(0, 1);

        if (title.front() == '"' && title.back() == '"')
            title = title.substr(1, title.length() - 2);

        LibraryItem* item;

        if (type == "BOOK")
            item = new Book(title);
        else if (type == "DVD")
            item = new DVD(title);
        else
            item = new Magazine(title);

        item->displayDueDate();

        delete item;
    }

    return 0;
}
