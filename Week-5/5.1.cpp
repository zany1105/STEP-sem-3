#include <iostream>
using namespace std;

void applyMultipliers(double playerScores[], int captainIndex, int viceCaptainIndex) {
    playerScores[captainIndex] *= 2;
    playerScores[viceCaptainIndex] *= 1.5;
}

int main() {

    double scores[] = {40, 55, 30, 62};

    applyMultipliers(scores, 1, 3);

    for (int i = 0; i < 4; i++) {
        cout << scores[i] << " ";
    }

    return 0;
}
