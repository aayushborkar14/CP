/*
ID: aayushb14
TASK: friday
LANG: C++                 
*/

#include <fstream>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n{ };
    fin >> n;
    bool isLeapYear = false;
    int dayCount[7] = {0, 0, 0, 0, 0, 0, 0};
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int currentDay = 1;
    for (int i=1900; i <= 1900+n-1; i++) {
        if (i%4 == 0 && i != 1900 && i!= 2100 && i != 2200 && i != 2300) {
            daysInMonth[1] = 29;
        }
        for (int j=0; j < 12; j++) {
            for (int k=1; k <= daysInMonth[j]; k++) {
                currentDay++;
                currentDay = currentDay%7;
                if (k==13) {
                    dayCount[currentDay]++;
                }
            }
        }
        daysInMonth[1] = 28;
    }
    for (int i=0; i < 7; i++) {
        fout << dayCount[i];
        if (i == 6) {
            fout << "\n";
            break;
        }
        fout << " ";
    }
}
