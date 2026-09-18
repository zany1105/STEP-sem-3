#include <iostream>
#include <string>
using namespace std;

// Helper function
double rowAverage(int row[], int size) {

    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += row[i];
    }

    return (double)sum / size;
}

// Main classification function
string classifyMatches(int runsPerOver[][3], int rows, int threshold) {

    string result = "";

    for (int i = 0; i < rows; i++) {

        double average = rowAverage(runsPerOver[i], 3);

        if (average >= threshold) {
            result += "Match " + to_string(i)
                   + ": Power Surge";
        }
        else {
            result += "Match " + to_string(i)
                   + ": Normal";
        }

        if (i != rows - 1) {
            result += " | ";
        }
    }

    return result;
}

int main() {

    int runsPerOver[3][3] = {
        {4, 6, 8},
        {10, 12, 14},
        {2, 3, 1}
    };

    int threshold = 8;

    cout << classifyMatches(
        runsPerOver,
        3,
        threshold
    );

    return 0;
}
