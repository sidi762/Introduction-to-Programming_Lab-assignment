//
//  lab 3 task 2
//
//  Sidi Liang
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

int rollDie(int sides); // pass in number of sides

int main(){
    srand( time(NULL) ); // init random
    getRand(); // kick-start the random numbers
    int value = 0;
    value = rollDie(6);
    printf("6-sided die: %i\n", value);
    value = rollDie(20);
    printf("20-sided die: %i\n", value);
    getchar();
}

int rollDie(int sides){
    float number = getRand();
    return (int)((float)sides * number);
}
