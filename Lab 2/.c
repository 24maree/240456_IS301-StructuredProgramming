/* Name: Mareerose Possi  Student ID: 240456  Date: 12/03/26 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
int getGuess();
void printSuccess();
void printHint(int guess, int randomNum);
void printSorry(int randomNum);

int main() {
    int randomNum, guess, attempts;
    srand(time(0)); // Seed for random number generation
    randomNum = (rand() % 20) + 1; // Generate number 1-20

    printf("I am thinking of a number between 1 and 20.\n");

    // Repetition Logic: 5 tries
    for (attempts = 1; attempts <= 5; attempts++) {
        guess = getGuess();

        // Selection Logic
        if (guess == randomNum) {
            printSuccess();
            return 0; // Terminate immediately after correct guess
        } else if (attempts < 5) {
            printHint(guess, randomNum);
        }
    }

    // If 5 attempts fail
    printSorry(randomNum);
    return 0;
}

// Function to get user guesses
int getGuess() {
    int g;
    printf("Can you guess what it is? ");
    scanf("%d", &g);
    return g;
}

// Function to print success message
void printSuccess() {
    printf("Congratulations! You did it.\n");
}

// Function to print unsuccessful/hint message
void printHint(int guess, int randomNum) {
    if (guess > randomNum) {
        printf("Your guess is high. Try again:\n");
    } else {
        printf("Your guess is low. Try again:\n");
    }
}

// Function to print sorry message
void printSorry(int randomNum) {
    printf("Sorry. The number was %d.\n", randomNum);
    printf("You should have gotten it by now. Better luck next time.\n");
}