#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Hàm tính số ngày từ 01/01/1971 đến ngày (year, month, day)
    int daysFrom1971(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Tính số ngày từ 1971 đến năm hiện tại (mỗi năm có 365 ngày, năm nhuận có 366 ngày)
        int totalDays = day;
        for (int y = 1971; y < year; y++) {
            totalDays += isLeapYear(y) ? 366 : 365;
        }

        for (int i = 0; i < month - 1; i++) {
            totalDays += daysInMonth[i];
        }
        
        if (month > 2 && isLeapYear(year)) totalDays++;

        return totalDays;
    }

    int daysBetweenDates(string date1, string date2) {
        return abs(daysFrom1971(date1) - daysFrom1971(date2));
    }
};