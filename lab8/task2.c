//
// LAB 8 TASK 2
// 5/12/20
// Sidi Liang
//
#include <stdio.h>

struct Change {
    int paid, itemCost, changeIn200Pence, changeIn100Pence, changeIn50Pence, changeIn20Pence, changeIn10Pence, changeIn5Pence, changeIn2Pence, changeIn1Pence;
};

struct Change getChange(int itemCost, int paid);
void printChange(struct Change change);

int main() {
    struct Change coins;
    coins = getChange(7, 10);
    printChange(coins);
    coins = getChange(56, 70);
    printChange(coins);
    coins = getChange(124, 200);
    printChange(coins);
    coins = getChange(1232, 2000);
    printChange(coins);
    getchar();
    return 0;
    
}

struct Change getChange(int itemCost, int paid){
    struct Change changeCoins;
    
    int *changePt = &changeCoins;
    for(int i = 0; i<sizeof(struct Change)/sizeof(int); i++)
    {
        (*changePt++) = 0;//Initialize every member in struct change
    }

    changeCoins.paid = paid;
    changeCoins.itemCost = itemCost;
    int totalChangeInPence = paid - itemCost;
    //Calculate the coins from the largest coin to the smallest
    while(totalChangeInPence >= 200){
        changeCoins.changeIn200Pence += 1;
        totalChangeInPence -= 200;
    }
    while(totalChangeInPence >= 100){
        changeCoins.changeIn100Pence += 1;
        totalChangeInPence -= 100;
    }
    while(totalChangeInPence >= 50){
        changeCoins.changeIn50Pence += 1;
        totalChangeInPence -= 50;
    }
    while(totalChangeInPence >= 20){
        changeCoins.changeIn20Pence += 1;
        totalChangeInPence -= 20;
    }
    while(totalChangeInPence >= 10){
        changeCoins.changeIn10Pence += 1;
        totalChangeInPence -= 10;
    }
    while(totalChangeInPence >= 5){
        changeCoins.changeIn5Pence += 1;
        totalChangeInPence -= 5;
    }
    while (totalChangeInPence >= 2) {
        changeCoins.changeIn2Pence += 1;
        totalChangeInPence -= 2;
    }
    while (totalChangeInPence >= 1) {
        changeCoins.changeIn1Pence += 1;
        totalChangeInPence -= 1;
    }
    return changeCoins;
}

void printChange(struct Change change){
    printf("Customer gave %d pence, item(s) cost %d pence.\nGive customer:\n", change.paid, change.itemCost);
    printf("£2 £1 50 20 10 5  2  1\n%d  %d  %d  %d  %d  %d  %d  %d\n", change.changeIn200Pence, change.changeIn100Pence, change.changeIn50Pence, change.changeIn20Pence, change.changeIn10Pence, change.changeIn5Pence, change.changeIn2Pence, change.changeIn1Pence);
    puts("");//Change line
}

