/* Name: Mareerose Possi    Student ID: 240456  Date: 12/03/26*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
int getGuess(int attempts);
void printSuccess();
void printHint(int guess, int randomNum);
void printSorry(int randomNum);

int main() {
    int randomNum, guess, attempts;

    srand(time(0));
    randomNum = (rand() % 20) + 1;

    printf("I am thinking of a number between 1 and 20.\n");

    for (attempts = 1; attempts <= 5; attempts++) {
        guess = getGuess(attempts);

        if (guess == randomNum) {
            printSuccess();
            return 0;
        } else if (attempts < 5) {
            printHint(guess, randomNum);
        }
    }

    printSorry(randomNum);
    return 0;
}

// Function to get user guesses
int getGuess(int attempts) {
    int g;
    if (attempts == 1) {
        printf("Can you guess what it is? ");
    } else {
        printf("Try again: ");
    }
    scanf("%d", &g);
    return g;
}

// Function to print success message
void printSuccess() {
    printf("Congratulations! You did it.\n");
}

// Function to print hint message
void printHint(int guess, int randomNum) {
    if (guess > randomNum) {
        printf("Your guess is high.\n");
    } else {
        printf("Your guess is low.\n");
    }
}

// Function to print sorry message
void printSorry(int randomNum) {
    printf("Sorry. The number was %d.\n", randomNum);
    printf("You should have gotten it by now.\n");
    printf("Better luck next time.\n");
}
