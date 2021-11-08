//
// LAB POINTERS TASK 1
// 4/12/20
// Sidi Liang
//
#include <stdio.h>
#include <time.h>
#define TOTAL_SEC_IN_DAY 86400

void calculateYearAndDay(time_t now, int *year, int *day); //Function to calculate Year and Day
void calculateHourAndMinute(time_t now, long *hour, long *minute);//Function to calculate hour and minute
void printTime(int year, int day, long hour, long minute);//Function to print time

int main() {
    time_t now;
    now = time(NULL); //total seconds
    //printf("%li\n", now);
    int year = 0, day = 0;
    long hour = 0, minute = 0;
    calculateYearAndDay(now, &year, &day);
    calculateHourAndMinute(now, &hour, &minute);
    printTime(year, day, hour, minute);
    return 0;
}

void calculateYearAndDay(time_t now, int *year, int *day){
    long int totalDay = now / TOTAL_SEC_IN_DAY;
    *year = (int)totalDay / 365 + 1970;
    *day = (int)totalDay - (*year - 1970) * 365 + 1;
}

void calculateHourAndMinute(time_t now, long *hour, long *minute){
    long totalDay = now / TOTAL_SEC_IN_DAY;
    long totalMinute = now / 60, totalHour = now / 3600;
    *hour = totalHour - (24 * totalDay);
    *minute = totalMinute - totalHour * 60;
}

void printTime(int year, int day, long hour, long minute){
    printf("%d, %d\n%ld, %ld\n", year, day, hour, minute);
}

