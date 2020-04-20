#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

const int w = 30;
const int h = 30;
const int xdir[8]={1, -1, -1, 1, 1, 0, -1, 0},
            ydir[8]={1, -1, 1, -1, 0, 1, 0, -1};
bool world[h][w];
bool new_world[h][w];

void zset() {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            new_world[y][x] = false;
        }
    }
}
bool check_stat(int lives, bool cell) {
    if (cell) {
        if (lives > 3 || lives < 2) {
            return false;
        }
    }
    else {
        if (lives == 3) {
            return true;
        }
    }
}
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
    //zset();
    /*new_world memset to zero */for (int y = 0; y < h; y++) {for (int x = 0; x < w; x++) {new_world[y][x] = world[y][x];}}
    for (int y = 1; y < h - 1; y++) {
        for (int x = 1; x < w - 1; x++) {
            int lives = 0;
            for (int q = 0; q < 8; q++) {
                if (world[y + ydir[q]][x + xdir[q]]) {
                    lives++;
                }
            }
            new_world[y][x] = check_stat(lives, world[y][x]);
            // new_world[y][x] = (lives == 3 || (lives == 2 && world[y][x]));
        }
    }
    for (int i = 1; i < w - 1; i++) {
        int lives = 0;
        lives += world[0][i - 1] + world[0][i + 1] + world[1][i] + world[1][i - 1] + world[1][i + 1];
        new_world[0][i] = check_stat(lives, world[0][i]);
        // new_world[0][i] = (lives == 3 || (lives == 2 && world[0][i]));
        lives = 0;
        lives += world[h - 1][i - 1] + world[h - 1][i + 1] + world[h - 2][i] + world[h - 2][i - 1] + world[h - 2][i + 1];
        new_world[h - 1][i] = check_stat(lives, world[h - 1][i]);
        // new_world[h - 1][i] = (lives == 3 || (lives == 2 && world[h - 1][i]));
    }
    for (int i = 1; i < h - 1; i++) {
        int lives = 0;
        lives += world[i - 1][0] + world[i + 1][0] + world[i][1] + world[i - 1][1] + world[i + 1][1];
        new_world[i][0] = check_stat(lives, world[i][0]);
        // new_world[i][0] = (lives == 3 || (lives == 2 && world[i][0]));
        lives = 0;
        lives += world[i - 1][w - 1] + world[i + 1][w - 1] + world[i][w - 2] + world[i - 1][w - 2] + world[i + 1][w - 2];
        new_world[i][w - 1] = check_stat(lives, world[i][w - 1]);
        // new_world[i][w - 1] = (lives == 3 || (lives == 2 && world[i][w - 1]));
    }
    {
        int lives = 0;
        lives += world[0][1] + world[1][0] + world[1][1];
        new_world[0][0] = check_stat(lives, world[0][0]);
        // new_world[0][0] = (lives == 3 || (lives == 2 && world[0][0]));
        lives = 0;
        lives += world[0][w - 2] + world[1][w - 1] + world[1][w - 2];
        new_world[0][w - 1] = check_stat(lives, world[0][w - 1]);
        // new_world[0][w - 1] = (lives == 3 || (lives == 2 && world[0][w - 1]));
        lives = 0;
        lives += world[h - 2][0] + world[h - 2][1] + world[h - 1][1];
        new_world[h - 1][0] = check_stat(lives, world[h - 1][0]);
        // new_world[h - 1][0] = (lives == 3 || (lives == 2 && world[h - 1][0]));
        lives = 0;
        lives += world[h - 2][w - 1] + world[h - 2][w - 2] + world[h - 1][w - 2];
        new_world[h - 1][w - 1] = check_stat(lives, world[h - 1][w - 1]);
        // new_world[h - 1][w - 1] = (lives == 3 || (lives == 2 && world[h - 1][w - 1]));
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
    // cout << "Select your choose:\n1.Random map   2.From file        Choose: " << flush;
    int choose = 1;
    // cin >> choose;
    if (choose == 1) {     // random map
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int this_rand = rand();
                if (this_rand < RAND_MAX / 40) {
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
    while(1) {
        usleep(500000);
        evolution();
        draw();
    }
    return 0;
}

