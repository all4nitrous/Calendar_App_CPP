#include <iostream>
#include <string>

using namespace std;

int dayNumber(int day, int month, int year) {
    static int A[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + A[month - 1] + day) % 7;
}

string getMonthName(int monthNumber) {
    string M[] = { "January", "February", "March", "April", "May", "June",
                   "July", "August", "September", "October", "November", "December" };
    return M[monthNumber - 1]; 
}

int numberOfDays(int monthNumber, int year) {
    switch (monthNumber) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
        default: return -1;
    }
}

void printCalendar(int year) {
    cout << "\t\t\t Calendar - Year " << year << endl;
    int days;
    int current = dayNumber(1, 1, year);

    for (int i = 0; i < 12; i++) {
        days = numberOfDays(i + 1, year);
        if (days == -1) continue; // Skip invalid months

        cout << endl << "\t\t ----x---- " << getMonthName(i + 1) << " ----x----" << endl;
        cout << " Sun Mon Tue Wed Thu Fri Sat " << endl;

        int k;
        for (k = 0; k < current; k++) 
            cout << "    ";  // Print spaces for alignment

        for (int j = 1; j <= days; j++) {
            printf("%2d  ", j);
            if (++k > 6) {
                k = 0;
                cout << endl;
            }
        }
        if (k)
            cout << endl;

        current = k; // Update start position for next month
    }
}

int main() {
    int year;
    cout << "Enter the year: ";
    cin >> year;
    printCalendar(year);
    return 0;
}
