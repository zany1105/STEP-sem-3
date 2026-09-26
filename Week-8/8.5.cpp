#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;

class Plan {
protected:
    string name;
    string startDate;

public:
    Plan(string name, string startDate) {
        this->name = name;
        this->startDate = startDate;
    }

    virtual int validityDays() = 0;

    void printRenewalDate() {
        int year, month, day;

        sscanf(startDate.c_str(), "%d-%d-%d", &year, &month, &day);

        tm date = {};
        date.tm_year = year - 1900;
        date.tm_mon = month - 1;
        date.tm_mday = day;

        mktime(&date);

        date.tm_mday += validityDays();

        mktime(&date);

        cout << name << ": "
             << date.tm_year + 1900 << "-"
             << setw(2) << setfill('0') << date.tm_mon + 1 << "-"
             << setw(2) << setfill('0') << date.tm_mday
             << endl;

        cout << setfill(' ');
    }

    virtual ~Plan() {}
};

class Basic : public Plan {
public:
    Basic(string name, string startDate) : Plan(name, startDate) {}

    int validityDays() override {
        return 30;
    }
};

class Standard : public Plan {
public:
    Standard(string name, string startDate) : Plan(name, startDate) {}

    int validityDays() override {
        return 90;
    }
};

class Premium : public Plan {
public:
    Premium(string name, string startDate) : Plan(name, startDate) {}

    int validityDays() override {
        return 365;
    }
};

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string type, name, date;

        cin >> type >> name >> date;

        Plan* plan;

        if (type == "BASIC")
            plan = new Basic(name, date);
        else if (type == "STANDARD")
            plan = new Standard(name, date);
        else
            plan = new Premium(name, date);

        plan->printRenewalDate();

        delete plan;
    }

    return 0;
}
