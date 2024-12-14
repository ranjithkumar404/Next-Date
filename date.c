#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0; 
    }
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return -1; 
    }
}

void nextDate(int day, int month, int year) {
    int maxDays = daysInMonth(month, year);

    if (day < 1 || day > maxDays || month < 1 || month > 12 || year < 1) {
        printf("Invalid date input\n");
        return;
    }

    day++; 
    if (day > maxDays) { 
        day = 1;  
        month++;  
        if (month > 12) { 
            month = 1; 
            year++;    
        }
    }

    printf("Next Date: %02d/%02d/%04d\n", day, month, year);
}

int main() {
    int day, month, year;

    printf("Enter the date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    nextDate(day, month, year);

    return 0;
}
