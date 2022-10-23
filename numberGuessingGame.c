#include <stdio.h>
#include <time.h>

const int MAX_NUMBER = 100;

void playGame() {

}

void changeMaxNumber() {

}


int main() {

    printf("Press 1 to play a game\n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n");

    int option;
    for(;;) {
        scanf("%d", &option);
        if(option != 1 && option != 2 && option != 3) {
            printf("Please provide a valid input\n");
            fflush(stdin);
            continue;
        }
        break;
    }

    for(;;) {
        switch(option) {
            case 1: //Play game
                playGame();
                break;
            case 2: //Change max number
                changeMaxNumber();
                break;
            default: //Quit
                return 1;
        }
    }
    

    return 1;
}