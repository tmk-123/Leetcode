#include<bits/stdc++.h>

using namespace std;

vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> prefixDays(13, 0);

class Solution {
public:
    int convert(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        return prefixDays[month - 1] + day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        for (int i = 1; i <= 12; i++) {
            prefixDays[i] = prefixDays[i - 1] + daysInMonth[i - 1];
        }

        int startAlice = convert(arriveAlice);
        int endAlice = convert(leaveAlice);
        int startBob = convert(arriveBob);
        int endBob = convert(leaveBob);

        int start = max(startAlice, startBob);
        int end = min(endAlice, endBob);

        if (start <= end) return end - start + 1;
        return 0;
    }
};