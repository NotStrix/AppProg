/*
Jose Rosario
ECE Application Programming 2160
Project Three: Random Number Guessing Game
Due: 10/27/2025

Description
This program uses loops to make a simple guessing game.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int seed = 0;
    int minEndpoint = 0;
    int maxEndpoint = 0;
    int randomNumber = 0;
    int numberOfRounds = 0;
    int numberOfGuesses = 0;
    int userGuess = 0;
    int round = 1;
    int guessCount = 1;
    int wins = 0;
    int losses = 0;


    //Loops until valid seed is entered
    do
    {
        printf("Enter seed for random number generator: \n");
        scanf("%d", &seed);
        if (seed < 0 || seed == 0)
        {
            //Clears input buffer
            printf("ERROR: Seed value should be > 0\n");
            char junk;
            do
            {
                scanf("%c", &junk);
            } while (junk != '\n');
        }
        else if (seed > 0)
        {
            printf("Seed: %d\n", seed);

            //Loops until valid range endpoints are entered
            do
            {
                printf("\nEnter range endpoints: \n");
                scanf("%d %d", &minEndpoint, &maxEndpoint);
                if (maxEndpoint < minEndpoint + 4)
                {
                    printf("ERROR: Max value should be at least 4 more than min value\n");
                }
                if (maxEndpoint < 0)
                {
                    printf("ERROR: Max value should be positive\n");
                }
                if (minEndpoint < 0)
                {
                    printf("ERROR: Min value should be positive\n");
                }

            } while (minEndpoint < 0 || maxEndpoint < 0 || maxEndpoint < minEndpoint + 4); 
            printf("Range endpoints: %d %d\n", minEndpoint, maxEndpoint);

            //Sets the seed and generates the first random number
            srand(seed);
            randomNumber = rand() % (maxEndpoint - minEndpoint + 1) + minEndpoint;

            //Loops until valid number of guesses is entered
            do
            {
                printf("\nEnter number of guesses per round: \n");
                scanf("%d", &numberOfGuesses);
                if (numberOfGuesses < 2)
                {
                    printf("ERROR: Must allow at least 2 guesses\n");
                }
            } while (numberOfGuesses < 2);
            printf("Number of guesses: %d\n", numberOfGuesses);

            //Loops until valid number of rounds is entered
            do
            {
                printf("\nEnter number of rounds for game: \n");
                scanf("%d", &numberOfRounds);
                if (numberOfRounds < 1)
                {
                    printf("ERROR: Must allow at least 1 round\n");
                }
            } while (numberOfRounds < 1);
            printf("Number of rounds: %d\n", numberOfRounds);

            //Main game loop which repeats for each round
            do
            {
                printf("\nROUND %d\n", round);
                round++;
                guessCount = 1;
                //Loop for each guess within a round
                do
                {
                    printf("\nEnter guess #%d: ", guessCount);
                    scanf("%d", &userGuess);
                    guessCount++;

                    //Checks if guess is out of range
                    if (userGuess < randomNumber && guessCount > numberOfGuesses && userGuess != randomNumber)
                    {
                        printf("%d is too low!\n", userGuess);
                        printf("No more guesses--the correct answer was %d\n", randomNumber);
                    }
                    else if (userGuess > randomNumber && guessCount > numberOfGuesses && userGuess != randomNumber)
                    {
                        printf("%d is too high!\n", userGuess);
                        printf("No more guesses--the correct answer was %d\n", randomNumber);
                    }
                    else if (userGuess < randomNumber)
                    {
                        printf("%d is too low!\n", userGuess);
                    }

                    else if (userGuess > randomNumber)
                    {
                        printf("%d is too high!\n", userGuess);
                    }

                } while (userGuess != randomNumber && guessCount <= numberOfGuesses);

                //Updates wins/losses and prints current stats
                if (userGuess == randomNumber)
                {
                    printf("Correct guess!\n");
                    wins++;
                }
                else if (userGuess != randomNumber && guessCount > numberOfGuesses)
                {
                    losses++;
                }
                printf("Current wins: %d\nCurrent losses: %d\n", wins, losses);
                
                //Generates new random number for next round
                randomNumber = rand() % (maxEndpoint - minEndpoint + 1) + minEndpoint;
            } while (round <= numberOfRounds && userGuess != randomNumber);
        }
    } while (seed < 0 || seed == 0);

    //Prints final stats
    printf("\nFINAL STATS\nWins: %d\nLosses: %d\nWinning percentage: %.2lf%%\n", wins, losses, (double)wins / (wins + losses) * 100);

    return 0;
}