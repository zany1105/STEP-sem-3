#include <iostream>
#include <string>
using namespace std;

string findDuplicatePick(string playerNames[], int n) {

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            if (playerNames[i] == playerNames[j]) {
                return "Duplicate Found: " + playerNames[i];
            }
        }
    }

    return "No Duplicates Found";
}

int main() {

    string playerNames[] = {
        "Kohli",
        "Bumrah",
        "Kohli",
        "Rohit"
    };

    int n = 4;

    cout << findDuplicatePick(playerNames, n);

    return 0;
}
