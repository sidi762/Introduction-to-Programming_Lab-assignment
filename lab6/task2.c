//
// LAB ARRAYS TASK 2
// 24/11/20
// Sidi Liang
//
#include <stdio.h>

void drawBoard(int gameBoard[3][3]);//Draw the game board
int gameIsEnded(int gameBoard[3][3]);//Judge if the game is ended

int main(){
    int gameBoard[3][3] = {0};
    drawBoard(gameBoard);
    while(!gameIsEnded(gameBoard)){
        int userControl, *gameBoardPt = &gameBoard[0][0];
        scanf("%d", &userControl);//User input
        gameBoardPt += userControl - 1;//Point the pointer to the place to change value
        *gameBoardPt = 1; //change the value
        
        //remove board from the screen
        for(int i = 0; i <= 2; i++){
            puts("");
        }
        drawBoard(gameBoard);
    }
    return 0;
}

void drawBoard(int gameBoard[3][3]){
    for(int i = 2; i >= 0; i--){
        for(int j = 0; j <= 2; j++){
            if(!gameBoard[i][j]) printf("%s ", ".");//If the value is 0, print .
            else printf("%s ", "X");//If the value is 1, print X
        }
        puts("");
    }
    puts("");
}

int gameIsEnded(int gameBoard[3][3]){
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            if(!gameBoard[i][j]) return 0; //If there's still dots in the borad, game is not ended
        }
    }
    return 1;
}

