#include <iostream>
#include <string>
using namespace std;

class AttendanceSheet {
private:
    string* students;
    const int maxSize;
    int count;

public:
    AttendanceSheet(int size) : maxSize(size) {
        students = new string[maxSize];
        count = 0;
    }

    void markPresent(string name) {
        if (isPresent(name)) {
            return;
        }

        if (count < maxSize) {
            students[count] = name;
            count++;
        }
    }

    int getPresentCount() const {
        return count;
    }

    bool isPresent(string name) const {
        for (int i = 0; i < count; i++) {
            if (students[i] == name) {
                return true;
            }
        }

        return false;
    }

    ~AttendanceSheet() {
        delete[] students;
    }
};

int main() {
    AttendanceSheet sheet(30);

    sheet.markPresent("Ana");
    sheet.markPresent("Ben");
    sheet.markPresent("Ana");

    cout << sheet.getPresentCount() << endl;
    cout << boolalpha << sheet.isPresent("Ben") << endl;
    cout << boolalpha << sheet.isPresent("Chen") << endl;

    return 0;
}
