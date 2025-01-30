#include <iostream>
#include <string.h>

using namespace std;

int dayNumber(int day, int month, int year) {
    static int A[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4 - year/100 + year/400 + A[month-1] + day) % 7;
}

string getMonthName(int monthNumber) {
    
    string M[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return (M[monthNumber - 1]);
}

int numberOfDays (int monthNumber, int year) {

    switch(monthNumber) {
        case 0: 
        case 2:
        case 4:
        case 6:
        case 7:
        case 9:
        case 11: return(31);
            if (year % 400 == 0 || (year % 4 == 0 && year %100 != 0))
                return (29);
            else
                return (28);
            break;
            case 3:
            case 5:
            case 8:
            case 10: return(30);
            break;




    }

}
