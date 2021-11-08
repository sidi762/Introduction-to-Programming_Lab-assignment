//
//  task3_2.c
//
//  Sidi Liang
//

#include <stdio.h>
#include <math.h>

int main(){
    int x = 1;
    //scanf("%d", &x);
    float exp_x = 1 + x + (float)x * x / 2 + (float)x * x * x / 6 + (float)x * x * x * x / 24;
    printf("%.3f\n", exp_x);
    return 0;
}

