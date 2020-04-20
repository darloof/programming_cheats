#!/usr/bin/python3
import random
from os import system
import time

playerScore = 0
computerScore = 0

playerscorelist = []
computerScorelist = []

playername = ''

def clear():
    system('clear')

def computerChoice():
    rps = ['r', 'p', 's']
    cmpc = random.choice(rps)
    print('computer choice: %s' % cmpc)
    return cmpc

def printScores():
    # print('\t\t',end='')
    # for i in range(len(playerscorelist)):
    #     print(i+1,end='  ')
    # print()
    print('%s\t\t ' % playername, end='')
    for score in playerscorelist:
        print(score, end='  ')
    print('\ncomputer\t ', end='')
    for score in computerScorelist:
        print(score, end='  ')
    print()


if __name__ == '__main__':
    playername = input('Your name : ')
    limitNo = int(input('Limit for win : '))
    print('Hello dear %s, Welcome to Rock, Paper, Scissors game ; I hope you enjoy :)' %
          playername)

    while playerScore < limitNo and computerScore < limitNo:
        clear()
        print('PlayerScore: %s  ,  ComputerScore: %s' %
              (playerScore, computerScore))
        print('Enter r , p , s  as Rock , Paper , Scissors')
        playerInput = input('Your choice : ')
        computerInput = computerChoice()

        if playerInput == computerInput:
            print('Hahaha ;)')
            playerscorelist.append('.')
            computerScorelist.append('.')
        else:
            if playerInput == 'r':
                if computerInput == 'p':
                    print('Computer get +1 ')
                    computerScore += 1
                    computerScorelist.append('*')
                    playerscorelist.append('.')
                elif computerInput == 's':
                    print('You get +1 ')
                    playerScore += 1
                    computerScorelist.append('.')
                    playerscorelist.append('*')
            elif playerInput == 'p':
                if computerInput == 'r':
                    print('You get +1')
                    playerScore += 1
                    computerScorelist.append('.')
                    playerscorelist.append('*')
                elif computerInput == 's':
                    print('Computer get +1')
                    computerScore += 1
                    computerScorelist.append('*')
                    playerscorelist.append('.')
            elif playerInput == 's':
                if computerInput == 'r':
                    print('Computer get +1')
                    computerScore += 1
                    computerScorelist.append('*')
                    playerscorelist.append('.')
            elif computerInput == 'p':
                    print('You get +1')
                    playerScore +=1
                    computerScorelist.append('.')
                    playerscorelist.append('*')
        time.sleep(2.35)
    clear()

    if playerScore == 5:
        print('Hooora %s Wins :)'%playername)
    else:
        print('Computer Wins !')

    printScores()
    print('Bye Bye :-) ')
