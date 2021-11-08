//
// LAB ARRAYS TASK 3
// 24/11/20
// Sidi Liang
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(int gameBoard[3][3]);//Draw the game board
int gameIsEnded(int gameBoard[3][3]);//Judge if the game is ended
int minmax(int gameBoard[3][3], int lastTurn);
int computerTurn(int gameBoard[3][3]);
int userTurn(int gameBoard[3][3]);
int* inputMove(int move, int gameBoard[3][3]);
int judgeHorizontal(int gameBoard[3][3]);
int judgeVertical(int gameBoard[3][3]);
int judgeX(int gameBoard[3][3]);
int score(int gameBoard[3][3], int lastTurn);
int choice = 0;

int main(){
    srand((unsigned)time(NULL)*10);
    int lastTurn = 2, gameBoard[3][3] = {0};
    drawBoard(gameBoard);
    while(!gameIsEnded(gameBoard)){
        
        if(lastTurn == 1){
            lastTurn = computerTurn(gameBoard);
        }else if(lastTurn == 2){
            lastTurn = userTurn(gameBoard);
        }
        
        //remove board from the screen
        for(int i = 0; i <= 2; i++){
            puts("");
        }
        drawBoard(gameBoard);
    }
    if(lastTurn == 1){
        puts("Player won");
    }else if(lastTurn == 2){
        puts("Computer won");
    }
    //printf("%d", score(gameBoard));
    return 0;
}


void drawBoard(int gameBoard[3][3]){
    for(int i = 2; i >= 0; i--){
        for(int j = 0; j <= 2; j++){
            if(!gameBoard[i][j]) printf("%s ", ".");//If the value is 0, print .
            else if(gameBoard[i][j] == 1) printf("%s ", "X");//If the value is 1, print X
            else if(gameBoard[i][j] == 2) printf("%s ", "O");//If the value is 2, print O
        }
        puts("");
    }
    puts("");
}

int judgeHorizontal(int gameBoard[3][3]){
    for(int i = 0; i <= 2; i++){
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != 0){
            if(gameBoard[i][0] == 1) return 1; //Three same pieces horizontally, player X wins
            else if(gameBoard[i][0] == 2) return 2;//Three same pieces horizontally, player O wins
        }
    }
    return 0;
}
int judgeVertical(int gameBoard[3][3]){
    for(int i = 0; i <= 2; i++){
        if(gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != 0){
            if(gameBoard[0][i] == 1) return 1; //Three same pieces verticallly, player X wins
            else if(gameBoard[0][i] == 2) return 2;//Three same pieces vertically, player O wins
        }
    }
    return 0;
}
int judgeX(int gameBoard[3][3]){
    if(gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != 0){
        if(gameBoard[0][0] == 1) return 1; //Three same pieces in diagonal line, player X wins
        else if(gameBoard[0][0] == 2) return 2;//Three same pieces in diagonal line, player O wins
    }
    if(gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != 0){
        if(gameBoard[0][2] == 1) return 1; //Three same pieces in diagonal line, player X wins
        else if(gameBoard[0][2] == 2) return 2;//Three same pieces in diagonal line, player O wins
    }
    
    return 0;
}

int gameIsEnded(int gameBoard[3][3]){
    
    //Game ended with a player winning, returns the result
    if(judgeX(gameBoard)) return judgeX(gameBoard);
    if(judgeVertical(gameBoard)) return judgeVertical(gameBoard);
    if(judgeHorizontal(gameBoard)) return judgeHorizontal(gameBoard);
    
   
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            if(!gameBoard[i][j]) return 0; //If there's still dots in the borad, game is not ended
        }
    }
    return 3;//Game ended draw
}

int userTurn(int gameBoard[3][3]){
    int userControl, *gameBoardPt = &gameBoard[0][0];;
    scanf("%d", &userControl);//User input
    gameBoardPt = inputMove(userControl - 1, gameBoard);//Point the pointer to the place to change value
    if(*gameBoardPt != 0){
        puts("ilegal input!");
        return 2;
    }
    *gameBoardPt = 1; //change the value
    return 1;
}
int computerTurn(int gameBoard[3][3]){
    int computerControl, *gameBoardPt = &gameBoard[0][0];
    do{
        computerControl = rand() % 9;
        minmax(gameBoard, 1);
        computerControl = choice;
        gameBoardPt = inputMove(computerControl, gameBoard);//Point the pointer to the place to change value
    }while(*gameBoardPt != 0);//Only put piece in empty slots
    *gameBoardPt = 2; //change the value
    return 2;
}
int* inputMove(int move, int gameBoard[3][3]){
    int *gameBoardPt = &gameBoard[0][0];
    gameBoardPt += move;
    return gameBoardPt;
}
int score(int gameBoard[3][3], int lastTurn){
    if(gameIsEnded(gameBoard) == lastTurn){
        return 10;
    }else if(gameIsEnded(gameBoard) != lastTurn){
        return -10;
    }else if(gameIsEnded(gameBoard) == 3){//draw
        return 0;
    }
    return 0;
}
int recDepth = 0;
int minmax(int gameBoard[3][3], int lastTurn){
    recDepth++;
    puts("CURRENT DEPTH");
    printf("%d\n", recDepth);
    puts(" ");
    if(gameIsEnded(gameBoard) != 0) {
        puts("Score returned! at");
        printf("%d\n", recDepth);
        recDepth--;
        return score(gameBoard, lastTurn);
    }
    int nextPossibleBoard[3][3], turnCount = lastTurn;
    int scores[10000], moves[10000];
    int *nextPossibleBoardPt = &nextPossibleBoard[0][0], *scoresPt = &scores[0], *movesPt = &moves[0];
    for(int i = 0; i < 9; i++){
        if(*inputMove(i, gameBoard) == 0){//is blank
            for(int i = 0; i < 3; i++){//Copy the gameBoard
                for(int j = 0; j < 3; j++){
                    nextPossibleBoard[i][j] = gameBoard[i][j];
                }
            }
            //Next posible move
            nextPossibleBoardPt = inputMove(i, nextPossibleBoard);
            if(turnCount == 1){
                *nextPossibleBoardPt = 2;
                turnCount = 2;
            }
            else if(turnCount == 2){
                *nextPossibleBoardPt = 1;
                turnCount = 1;
            }
            
            scoresPt++;
            //puts("POSSIBLE:");
            //drawBoard(nextPossibleBoard);
            *scoresPt = minmax(nextPossibleBoard, turnCount);
            puts("Score returned at i = ");
            printf("%d\n", i);
            movesPt++;
            *movesPt = i;
        }
    }
    
    
    //puts("I made it here");
    if(turnCount == 2){//active turn is player
        int maxScore = 0;
        long maxScoreIndex;
        for(int *i = &scores[0]; i < scoresPt; i++){//Get the index where the score is max
            if(*i > maxScore){
                maxScore = *i;
                maxScoreIndex = i - &scores[0];
                choice = *(&moves[0] + (i - &scores[0]));
                puts("PLAYER CHOICE at");
                printf("%d\n", recDepth);
            }
            
        }
        recDepth--;
        return maxScore;
    }else if(turnCount == 1){//activeTurn is computer
        int minScore = scores[0];
        long minScoreIndex;
        for(int *i = &scores[0]; i < scoresPt; i++){//Get the index where the score is max
            if(*i < minScore){
                minScore = *i;
                minScoreIndex = i - &scores[0];
                choice = *(&moves[0] + (i - &scores[0]));
                puts("COMPUTER CHOICE at");
                //printf("%d\n", choice);
                printf("%d\n", recDepth);
            }
            
        }
        recDepth--;
        return minScore;
    }
    return 0;
}


