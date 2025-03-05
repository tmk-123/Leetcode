#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reformatDate(string date) {
        string year = date.substr(date.size() - 4, 4);
        string month = date.substr(date.size() - 8, 3);
        string day = date.substr(0, date.find(" ") - 2);

        string res = year + "-";
        vector<string> m = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for (int i = 0; i < m.size(); i++) {
            if (m[i] == month) {
                int n = i + 1;
                if (n < 10) res += "0";
                res += to_string(n) + "-";
                break;
            }
        }

        if (day.size() < 2) res += "0";
        res += day;
        return res;
    }
};