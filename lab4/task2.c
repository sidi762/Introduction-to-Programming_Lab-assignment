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
	if(positionX > length || positionX < 0 || positionY > height || positionY < 0){
		puts("invalid");
		return 0;
	}
    drawHorizontalLine(length); //Draw the frame
    for(int i = 0; i < positionY; i++){
        drawLineWithoutPlayer(length); 
    }
    drawLineWithPlayer(length, positionX);
    for(int i = positionY + 1; i < height; i++){
        drawLineWithoutPlayer(length);
    }
    drawHorizontalLine(length);//Draw the frame
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

