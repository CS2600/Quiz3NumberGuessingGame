#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

const int MAX_VALUE = 100;

void playGame(int maxNumber) {
    //Pick random number from 1 to maxNumber
    time_t t;
    srand((unsigned)time(&t));
    int number = (rand() % maxNumber) + 1;
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
                printf("You win!\n");
                return;
            }
            else if(inputNumber < number) {
                printf("Too Low!\n");
                continue;
            }
            else {
                printf("Too High!\n");
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

}


int main() {

    int temp = MAX_VALUE;
    int* maxNumber = &temp;

    for(;;) {
        printf("Press 1 to play a game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n");

        int option;
        for(;;) {
            scanf("%d", &option);
            fflush(stdin);
            if(option != 1 && option != 2 && option != 3) {
                printf("Please provide a valid input\n");
                continue;
            }
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