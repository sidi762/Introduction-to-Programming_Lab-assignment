//
// LAB 8 TASK 2
// 5/12/20
// Sidi Liang
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TwoLetters{
    char firstLetter;
    char secondLetter;
};

struct TwoLetters split(int decrypted){
    struct TwoLetters a;
    a.firstLetter = decrypted >> 8;
    a.secondLetter = decrypted & 0xFF;
    return a;
}

int main() {
    //char encrypted[] = "15643 6913 6916 23040 2377 6985 6408 3657 5638 3084 2119";
    //char encrypted[] = "15910 23079 13629 23101 10300 10557 23073 13092 23369";
	char encrypted[1000];
	scanf("%[^\n]", encrypted);
    int wordCount = 1;
    for(int i = 0; encrypted[i] != '\0'; i++){
        if(encrypted[i] == ' '){
            wordCount++;
        }
    }
    //Seperate the char and convert them to int
    char *token, *tmpPtr;
    token = strtok(encrypted, " ");
    long allInts[wordCount];
    allInts[0] = strtoul(token, &tmpPtr, 10);
    int i = 1;
    while(token != NULL) {
        //printf( "%s\n", token );
        token = strtok(NULL, " ");
        if(token != NULL){
            allInts[i] = strtoul(token, &tmpPtr, 10);
            i++;
        }
    }
    
    for(int i = 0; i < wordCount; i++){
        allInts[i] ^= 31337;
        //printf("%ld \n", allInts[i]);
        struct TwoLetters result = split((int)allInts[i]);
        printf("%c%c", result.firstLetter, result.secondLetter);
    }
    
    return 0;
}

