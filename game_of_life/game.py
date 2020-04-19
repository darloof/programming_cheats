#!/usr/bin/python3
import random
from os import system
import time

W = 40
H = 40
REFRESH_RATE = 1
world = [[False for j in range(W)] for i in range(H)]

def evolution():
    global world
    new_world = [[False for j in range(W)] for i in range(H)]
    for y in range(H):
        for x in range(W):
            lives = 0
            for i in range(-1, 2):
                for j in range(-1, 2):
                    if (world[(y + i) % H][(x + j) % W]):
                            lives += 1
            if (world[y][x]):
                lives -= 1
            if (world[y][x]):
                if (lives == 3 or lives == 2):
                    new_world[y][x] = True
            else:
                if (lives == 3):
                    new_world[y][x] = True
    world = new_world

def draw():
    # system('clear')
    print('\33[H')
    for i in range(H):
        for j in range(W):
            if (world[i][j]):
                print('@', end='')
            else:
                print(' ', end='')
        print()

if __name__ == "__main__":
    random.seed(time.time())
    for i in range(H):
        for j in range(W):
            if (random.random() <= 0.1):
                world[i][j] = True
    draw()
    while (True):
        time.sleep(REFRESH_RATE)
        evolution()
        draw()