//
// LAB 8 TASK 1
// 5/12/20
// Sidi Liang
//
#include <stdio.h>
#include <string.h>

float calculateCLI(char string[]);

int main(){
    char text[100] = "I like cats. Cats like me. Miao miao miao. Dogs are bad. Bad dogs bad.";
    char text2[500] = "Tomorrow, and tomorrow, and tomorrow, Creeps in this petty pace from day to day, To the last syllable of recorded time; And all our yesterdays have lighted fools The way to dusty death. Out, out, brief candle. Life's but a walking shadow, a poor player That struts and frets his hour upon the stage And then is heard no more. It is a tale Told by an idiot, full of sound and fury Signifying nothing.";
    char text3[1000] = "Existing computer programs that measure readability are based largely upon subroutines which estimate number of syllables, usually by counting vowels. The shortcoming in estimating syllables is that it necessitates keypunching the prose into the computer. There is no need to estimate syllables since word length in letters is a better predictor of readability than word length in syllables. Therefore, a new readability formula was computed that has for its predictors letters per hundred words and sentences per hundred words. Both predictors can be counted by an optical scanning device, and thus the formula makes it economically feasible for an organization such as the US Office of Education to calibrate the readability of all textbooks for the public school system.";
    
    printf("CLI is Grade %f\n", calculateCLI(text));
    printf("CLI is Grade %f\n", calculateCLI(text2));
    printf("CLI is Grade %f\n", calculateCLI(text3));
}

float calculateCLI(char string[]){
    int characters = 0, words = 1, sentences = 0;//Because each sentance begin with words and ends with peroid, words count starts from 1
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] != ' ' && string[i] != '.'){
            characters++; //Calculate characters
        }
        if(string[i] == ' '){
            words++; //Calculate words
        }
        if(string[i] == '.'){
            sentences++; //Calculate sentences
        }
    }

    float cli =  5.89 * ((float)characters / (float)words) - 29.5 * ((float)sentences / (float)words) - 15.8;
    
    
    if(cli < 1) cli = 1; //If the calculated grade is less than 1, set it to 1 instead of returning a lower number.
    
    return cli;
}

