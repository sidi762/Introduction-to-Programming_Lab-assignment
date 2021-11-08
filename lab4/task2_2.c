//
// LAB Loops
// 10/11/20
// Sidi Liang
//
#include <stdio.h>

void drawHorizontalLine(int length); //draw a horizontal +----+ line

void drawLineWithoutPlayer(int length);//draw a line without the player |....|

void drawLineWithPlayer(int length, int playerPosition);//draw the line with the player |..@.| at given position

int main(){
    int length, height, positionX, positionY;
    scanf("%d%d%d%d", &length, &height, &positionX, &positionY);//input the room and player position
    getchar();//Prevents the first print to run twice
    puts("Use w, a, s, d to move around");
    while(1){
        //bounce back if out of bounds
        if(positionX < 0) positionX = 0 - positionX;
        else if(positionX > length - 1) positionX = length - 2;
        if(positionY < 0) positionY = 0 - positionY;
        else if(positionY > height - 1) positionY = height - 2;
        
        drawHorizontalLine(length); //Draw the frame
        for(int i = 0; i < positionY; i++){
            drawLineWithoutPlayer(length);
        }
        drawLineWithPlayer(length, positionX);
        for(int i = positionY + 1; i < height; i++){
            drawLineWithoutPlayer(length);
        }
        drawHorizontalLine(length);//Draw the frame
		getchar();//Wait for user input
        int userControl = getchar();
        if(userControl == 'w') positionY -= 1;
        else if (userControl == 's') positionY += 1;
        else if (userControl == 'a') positionX -= 1;
        else if (userControl == 'd') positionX += 1;
        puts("");//New Line
    }
    return 0;
}

void drawHorizontalLine(int length){
    printf("%c", '+');
    for(int i = 0; i < length; i++){
        printf("%c", '-');
    }
    printf("%c\n", '+');
}

void drawLineWithoutPlayer(int length){
    printf("%c", '|');
    for(int i = 0; i < length; i++){
        printf("%c", '.');
    }
    printf("%c\n", '|');
}

void drawLineWithPlayer(int length, int playerPosition){
    printf("%c", '|');
    for(int i = 0; i < playerPosition; i++){
        printf("%c", '.');
    }
    printf("%c", '@');
    for(int i = playerPosition + 1; i < length; i++){
        printf("%c", '.');
    }
    printf("%c\n", '|');
}

