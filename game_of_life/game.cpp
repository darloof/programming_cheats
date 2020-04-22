#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

const int w = 30;
const int h = 30;

bool world[h][w];

void draw() {
    cout << "\033[H";
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (world[y][x]) {
                cout << '@';
            }
            else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    cout << flush;
}

void evolution() {
    bool new_world[h][w];
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int lives = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (world[(y + i) % h][(x + j) % w] != 0) {
                        lives += 1;
                    }
                }
            }
            lives -= (world[y][x] ? 1 : 0);
            if (world[y][x]) {
                if (lives == 3 || lives == 2) {
                    new_world[y][x] = true;
                } else {
                    new_world[y][x] = false;
                }
            }
            else {
                if (lives == 3) {
                    new_world[y][x] = true;
                } else {
                    new_world[y][x] = false;
                }

            }
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            world[y][x] = new_world[y][x];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(0));
    ////  choose random map or from a file
    cout << "Select your choose:\n1.Random map   2.From file        Choose: " << flush;
    int choose = 1;
    cin >> choose;
    if (choose == 1) {     // random map
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int this_rand = rand();
                if (this_rand <= RAND_MAX / 10) {
                    world[y][x] = true;
                }
            }
        }
    }
    else if (choose == 2) {  // map from file    !!! not work right now
        cout << "Enter your file path: (like: /tmp/gol_map.txt)\n";
        string filePath;
        cin >> filePath;
        ifstream readFile;
        readFile.open(filePath);
    }
    ////
    // return draw(), 0;
    //draw();
    system("clear");
    while(1) {
        usleep(500000);
        evolution();
        draw();
    }
    return 0;
}

