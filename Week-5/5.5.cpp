#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Player {
private:
    string name;
    int matchesPlayed;
    double battingAverage;
    bool injured;

public:

    // Constructor
    Player(string name, int matchesPlayed,
           double battingAverage, bool injured) {

        this->name = name;
        this->matchesPlayed = matchesPlayed;
        this->battingAverage = battingAverage;
        this->injured = injured;
    }

    // Rule 1:
    // Experienced player
    static bool isDraftable(int matchesPlayed) {

        return matchesPlayed >= 10;
    }

    // Rule 2:
    // Less experienced but fit player
    static bool isDraftable(int matchesPlayed,
                            bool injured) {

        return matchesPlayed >= 5 && !injured;
    }

    // Getter
    string getName() const {
        return name;
    }

    // Fantasy points
    double getPoints() const {
        return battingAverage;
    }

    // Used by sort()
    bool operator<(const Player& other) const {

        // Descending order
        return battingAverage > other.battingAverage;
    }

    // Draft and rank
    static string draftAndRank(
        vector<Player> players) {

        vector<Player> draftable;

        // Check every player
        for (Player& player : players) {

            // Experienced player
            if (isDraftable(player.matchesPlayed)) {
                draftable.push_back(player);
            }

            // Less experienced but fit player
            else if (isDraftable(
                        player.matchesPlayed,
                        player.injured)) {

                draftable.push_back(player);
            }
        }

        // Sort by batting average
        sort(draftable.begin(), draftable.end());

        string result = "";

        for (int i = 0; i < draftable.size(); i++) {

            result += to_string(i + 1);
            result += ". ";
            result += draftable[i].name;

            if (i != draftable.size() - 1) {
                result += " | ";
            }
        }

        return result;
    }
};

int main() {

    vector<Player> players = {

        Player("Virat", 15, 48.0, false),

        Player("Rahul", 7, 55.0, false),

        Player("Sameer", 3, 60.0, false),

        Player("Dev", 12, 20.0, true)
    };

    cout << Player::draftAndRank(players);

    return 0;
}
