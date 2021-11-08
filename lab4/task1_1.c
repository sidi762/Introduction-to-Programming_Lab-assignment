//
// LAB guessinggame.c
// 7/11/20
// Sidi Liang
//
#include <stdio.h>

int main(){
    puts("Guess an int between 1 and 32 (inclusive).");
    int presetAnswer = 16; //The preset anwser 16
    int userInput, resultFlag = 0; //resultFlag: 0 if user loses, 1 if user wins
    for(int i = 0; i < 5; i++){
        scanf("%d", &userInput); //input to userInput
        if(userInput < presetAnswer) puts("too low");
        else if(userInput > presetAnswer) puts("too high");
        else{
            puts("correct");
            resultFlag = 1; //user wins
            break;
        }
    }
    if(resultFlag) puts("you win");
    else puts("you lose");
    
    return 0;
}

