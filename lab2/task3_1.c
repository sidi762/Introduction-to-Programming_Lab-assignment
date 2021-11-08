//
//  task3_1.c
//  Sidi Liang
//

#include <stdio.h>
#include <math.h>

int main(){
    const short height = 4, length = 5, width = 6;
    const int volume = height * length * width;
    const float weight = volume / 1.5;
    printf("The height of the box: %hd \nThe length of the box: %hd \nThe width of the box: %hd \n \nThe total volume: %d \nTotal Weight: %0.1f \n", height, length, width, volume, weight);
    return 0;
}

