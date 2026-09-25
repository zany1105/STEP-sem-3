#include <iostream>
#include <string>
using namespace std;

class Playlist {
private:
    string* songs;
    int maxSize;
    int count;

public:
    Playlist(int size) {
        maxSize = size;
        count = 0;
        songs = new string[maxSize];
    }

    void addSong(string song) {
        if (count < maxSize) {
            songs[count] = song;
            count++;
        }
    }

    string* getSongs() const {
        string* copy = new string[count];

        for (int i = 0; i < count; i++) {
            copy[i] = songs[i];
        }

        return copy;
    }

    int getSongCount() const {
        return count;
    }

    ~Playlist() {
        delete[] songs;
    }
};

int main() {
    Playlist p(10);

    p.addSong("Song A");
    p.addSong("Song B");

    string* copy = p.getSongs();

    copy[0] = "Hacked";

    string* original = p.getSongs();

    for (int i = 0; i < p.getSongCount(); i++) {
        cout << original[i] << endl;
    }

    delete[] copy;
    delete[] original;

    return 0;
}
