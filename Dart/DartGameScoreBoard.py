#!/usr/bin/python3
from os import system

players = list(map(str,input('name of players: ').split()))
scores = {}
scoreslist = {}
def printdata():
    system('clear')
    for player in players:
        print(player, ' : ', scores[player], '  ', scoreslist[player])

for player in players:
    scores[player] = 0
    scoreslist[player] = []
numberOfRounds = int(input('number of rounds: '))
for round in range(numberOfRounds):
    for player in players:
        printdata()
        this_scores = list(map(int,input().split()))
        this_score = sum(this_scores)
        scores[player] += this_score
        scoreslist[player].append(this_score)

printdata()