#include <iostream>
using namespace std;

class Scorecard {
private:
    bool* results;
    const int totalQuestions;
    int recorded;

public:
    Scorecard(int questions) : totalQuestions(questions) {
        results = new bool[totalQuestions];
        recorded = 0;
    }

    void recordAnswer(bool correct) {
        if (recorded < totalQuestions) {
            results[recorded] = correct;
            recorded++;
        }
    }

    int getScore() const {
        int score = 0;

        for (int i = 0; i < recorded; i++) {
            if (results[i] == true) {
                score++;
            }
        }

        return score;
    }

    ~Scorecard() {
        delete[] results;
    }
};

int main() {
    Scorecard sc(4);

    sc.recordAnswer(true);
    sc.recordAnswer(true);
    sc.recordAnswer(false);
    sc.recordAnswer(true);

    cout << sc.getScore() << endl;

    return 0;
}
