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

        printf("Enter a number!\n");
        scanf("%s", input);
        fflush(stdin);

        int inputNumber = -1;

        sscanf(input, "%d", &inputNumber);
        fflush(stdin);

        if(inputNumber != -1) {
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
        else if(input[0] == 'q') {
            return;
        }
        else {
            printf("Invalid input!\n");
        }
    }
}

void changeMaxNumber(int* maxNumber) {
    printf("The max value that you can set the number to is %d\n", MAX_VALUE);

    for(;;) {
        int input;
        scanf("%d", &input);
        fflush(stdin);
        if(input < 0 || input > MAX_VALUE) {
            printf("Please provide a value between 0 and %d\n", MAX_VALUE);
            continue;
        }
        *maxNumber = input;
        printf("\n");
        return;
    }
    
}


int main() {

    int temp = MAX_VALUE;
    int* maxNumber = &temp;

    for(;;) {
        printf("Press 1 to play a game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n\n");

        int option;
        for(;;) {
            scanf("%d", &option);
            fflush(stdin);
            if(option != 1 && option != 2 && option != 3) {
                printf("Please provide a valid input\n");
                continue;
            }
            printf("\n");
            break;
        }

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

    return 1;
}