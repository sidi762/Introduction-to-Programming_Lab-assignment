//
// LAB ARRAYS TASK 1
// 24/11/20
// Sidi Liang
//
#include <stdio.h>

void generateFibonacci(int finbonacci[], int n);//The function to generate finbonacci
void displayFibonacci(int finbonacci[], int n);//Display the array

int main(){
    int finbonacci[100]  = {0, 1};//Declare the array
    
    //n = 10
    generateFibonacci(finbonacci, 10);
    displayFibonacci(finbonacci, 10);
    puts("");
    
    //n = 20
    generateFibonacci(finbonacci, 20);
    displayFibonacci(finbonacci, 20);
    puts("");
    
    //n = 50, the number is too large for int to store
    generateFibonacci(finbonacci, 50);
    displayFibonacci(finbonacci, 50);
    
    return 0;
}

void generateFibonacci(int finbonacci[], int n){
    for(int i = 2; i <= n; i++){
        finbonacci[i] = finbonacci[i - 2] + finbonacci[i - 1]; //Finbonacci
    }
}

void displayFibonacci(int finbonacci[], int n){
    for(int i = 0; i <= n; i++){
        printf("%d ", finbonacci[i]);
    }
    puts("");
}


