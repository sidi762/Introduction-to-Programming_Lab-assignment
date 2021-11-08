//
// Lab3
// 3/11/20
// Sidi Liang
//
#include <stdio.h>

float calculateTax(float grossIncome, float tax); //The function for calculating total tax, takes grossIncome and current tax (must be 0 in the first call) as input, returns the total tax(float)

int main(){
    float grossIncome;
    printf("%s", "Enter Gross Income in GBP: ");
    scanf("%f", &grossIncome);
    printf("Your Take-home salary is:  %.2f\n", grossIncome - calculateTax(grossIncome, 0));
    printf("The total tax paid is: %.2f\n", calculateTax(grossIncome, 0));
    return 0;
}

float calculateTax(float grossIncome, float tax){
    if(grossIncome <= 12500) return tax; //Exits the recurtion
    else if(grossIncome <= 14585){ //Calculates Starter rate
        tax += 0.19 * (grossIncome - 12500);
        return calculateTax(12500, tax);
    }else if(grossIncome <= 25158){ //Calculates Basic rate
        tax += 0.2 * (grossIncome - 14585);
        return calculateTax(14585, tax);
    }else if(grossIncome <= 43430){ //Calculates Intermediate rate
        tax += 0.21 * (grossIncome - 25158);
        return calculateTax(25158, tax);
    }else if(grossIncome <= 150000){ //Calculates Higher rate
        tax += 0.41 * (grossIncome - 43430);
        return calculateTax(43430, tax);
    }else{ //Calculates Top rate
        tax += 0.46 * (grossIncome - 150000);
        return calculateTax(150000, tax);
    }
}

