//
//  lab 3 task 1
//
//  Sidi Liang
//

#include <stdio.h>
#include <math.h>

float Ohm_law(float voltage, float resistent); //Returns current using the Ohm law
float series(float r1, float r2); //Returns the total resistant of two resistors in a series
float parallel(float r1, float r2); //Returns the total resistant of two resistors in parallel
float parallel_three(float, float, float); //Returns the total resistant of three resistors in parallel

int main(){
    //int r1=100, r2=200, r3=300, r4=400, r5=500, r6=600, r7=700;
    int r1=123, r2=234, r3=345, r4=456, r5=567, r6=678, r7=789;
    printf("%f\n", Ohm_law(12, parallel_three(series(r1, r2), parallel(r3, r4), series(parallel(r6, r7), r5))));
    return 0;
}

float Ohm_law(float voltage, float resistent){ 
    return voltage / resistent;
}
float series(float r1, float r2){ 
    return r1 + r2;
}
float parallel(float r1, float r2){ 
    return 1 / ((1 / r1) + (1 / r2));
}
float parallel_three(float r1, float r2, float r3){ 
    return 1 / ((1 / r1) + (1 / r2) + (1 / r3));
}
