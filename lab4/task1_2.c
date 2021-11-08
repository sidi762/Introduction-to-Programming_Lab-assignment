//
// LAB guessinggame_2.c
// 7/11/20
// Sidi Liang
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gameSession(int presetAnswer);

int main(){
    int score = 0, bestScore = 0;
    int presetAnswer = 16;
    srand((unsigned)time(NULL)*10);
    score = gameSession(presetAnswer);
    bestScore = score;
    while(1){
		presetAnswer = rand() % 32 + 1;
        score = gameSession(presetAnswer);
        if(score < bestScore) bestScore = score;
        printf("your best score (fewest number of guesses) is %d \n", bestScore);
        if(score <= 4) break;
    }
    return 0;
}

int gameSession(int presetAnswer){
    puts("Guess an int between 1 and 32 (inclusive).");
    int userInput, attempts = 0; //resultFlag: 0 if user loses, 1 if user wins
    while(1){
        attempts += 1;
        scanf("%d", &userInput); //input to userInput
        if(userInput < presetAnswer) puts("too low");
        else if(userInput > presetAnswer) puts("too high");
        else{
            puts("correct");
            break;
        }
    }
    puts("you win");
    printf("you took %d guesses to win\n", attempts);
    
    return attempts;
}

