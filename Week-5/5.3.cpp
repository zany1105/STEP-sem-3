#include <iostream>
#include <string>
using namespace std;

string findMinMaxSpread(int scores[], int n) {

    int minScore = scores[0];
    int maxScore = scores[0];

    // Single pass
    for (int i = 1; i < n; i++) {

        if (scores[i] < minScore) {
            minScore = scores[i];
        }

        if (scores[i] > maxScore) {
            maxScore = scores[i];
        }
    }

    int spread = maxScore - minScore;

    return "Min: " + to_string(minScore)
         + " | Max: " + to_string(maxScore)
         + " | Spread: " + to_string(spread);
}

int main() {

    int scores[] = {
        45, 82, 79, 90, 33, 90, 61
    };

    int n = 7;

    cout << findMinMaxSpread(scores, n);

    return 0;
}
