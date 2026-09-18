#include <iostream>
#include <string>
using namespace std;

class PlacementRecord {
public:
    string studentName;
    string company;
    double packageLpa;

    // Constructor
    PlacementRecord(string studentName, string company, double packageLpa) {
        this->studentName = studentName;
        this->company = company;
        this->packageLpa = packageLpa;
    }

    // Print record
    void printRecord() {
        cout << studentName << " -> "
             << company << " @ "
             << packageLpa << " LPA" << endl;
    }
};

int main() {

    PlacementRecord p1("Ravi", "TCS", 4.5);
    PlacementRecord p2("Anitha", "Zoho", 6.2);
    PlacementRecord p3("Karthik", "Infosys", 4.0);

    // Array of objects
    PlacementRecord records[] = {p1, p2, p3};

    // Print all records
    for (int i = 0; i < 3; i++) {
        records[i].printRecord();
    }

    return 0;
}
