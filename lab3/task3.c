//
// PRE LAB POINTERS
// 17/11/20
// Sidi Liang
//
#include <stdio.h>
#include <stdlib.h> // extra includes!
#include <time.h>

/* Get a random number from 0 to 0.9999999
    (you don't need to understand this function)
    ***** DON'T MODIFY THIS FUNCTION *****
 */
float getRand() {
    return rand() / (RAND_MAX+1.0);
}

int gameSession(int correct_answer);//our function for the game

int main(){
    srand( time(NULL) ); // init random
    getRand(); // kick-start the random numbers
    int resultFlag = 0;//1 if the user wins, 0 if the user loses
    int presetAnswer = (int)(getRand() * 32 + 0.5);//Generate a ramdom number between 1 and 32
    for(int i = 0; i < 5; i++){
        if(gameSession(presetAnswer)){//break if returns 1
            resultFlag = 1;
            break;
        }
    }
    if(resultFlag) puts("you win"); //if result flag is 1, the user wins
    else puts("you lose");
    return 0;
}

int gameSession(int correct_answer){
    puts("Guess an int between 1 and 32 (inclusive).");//prompt instruction
    int userInput;
    scanf("%d", &userInput); //input to userInput
    if(userInput < correct_answer){//Compare input with correct_answer
        puts("too low");
        return 0;
    }
    else if(userInput > correct_answer){
        puts("too high");
        return 0;
    }
    else{
        puts("correct");
        return 1;
    }
}

