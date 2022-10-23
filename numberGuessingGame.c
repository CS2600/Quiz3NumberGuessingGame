#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

const int MAX_VALUE = 100;

void playGame(int maxNumber) {
    //Pick random number from 0 to maxNumber
    time_t t;
    srand((unsigned)time(&t));
    int number = rand() % (maxNumber + 1);
    char input[3];

    //Loop until user finds number or inputs q
    for(;;) {

        //Read user input
        printf("Enter a number!\n");
        scanf("%s", input);
        fflush(stdin);

        int inputNumber = -1;

        //Convert char array to int
        sscanf(input, "%d", &inputNumber);
        fflush(stdin);

        if(inputNumber != -1) { //If input is a number
            if(inputNumber == number) {
                printf("You win!\n\n");
                return;
            }
            else if(inputNumber < number) {
                printf("Too Low!\n\n");
                continue;
            }
            else {
                printf("Too High!\n\n");
                continue;
            }

        }
        else if(input[0] == 'q') { //If input is q
            return;
        }
        else {
            printf("Invalid input!\n");
        }
    }
} //End playGame

void changeMaxNumber(int* maxNumber) {
    printf("The max value that you can set the number to is %d\n", MAX_VALUE);

    //Loop until user provides valid input
    for(;;) {
        int input;
        scanf("%d", &input);
        fflush(stdin);

        //Check if input is valid
        if(input < 0 || input > MAX_VALUE) {
            printf("Please provide a value between 0 and %d\n", MAX_VALUE);
            continue;
        }

        *maxNumber = input;
        printf("\n");
        return;
    }
} //End changeMaxNumber


int main() {

    int temp = MAX_VALUE;
    int* maxNumber = &temp;

    //Loop until quit
    for(;;) {
        printf("Press 1 to play a game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n\n");

        //Read user input
        int option;
        for(;;) {
            scanf("%d", &option);
            fflush(stdin);
            if(option != 1 && option != 2 && option != 3) { //Check if input is not 1, 2, or 3
                printf("Please provide a valid input\n");
                continue;
            }
            printf("\n");
            break;
        }

        //Execute option selected
        switch(option) {
            case 1: //Play game
                playGame(*maxNumber);
                break;
            case 2: //Change max number
                changeMaxNumber(maxNumber);
                break;
            default: //Quit
                return 1;
        }
    }
} //End main