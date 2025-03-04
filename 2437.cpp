#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTime(string time) {
        int hour = 1;
        if (time[1] == '?') {
            if (time[0] == '?') hour = 24;
            else if (time[0] == '2') hour = 4;
            else hour = 10;
        }
        else if (time[0] == '?') {
            if (time[1] >= '4') hour = 2;
            else hour = 3;
        }

        int minute = 1;
        if (time[4] == '?') {
            if (time[3] == '?') minute = 60;
            else minute = 10;
        }
        else if (time[3] == '?') minute = 6;

        return minute * hour;
    }
};