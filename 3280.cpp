#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToBinary(int n) {
        string res;
        while (n > 0) {
            if (n & 1) res = "1" + res;
            else res = "0" + res;
            n >>= 1;
        }
        return res;
    }
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        return convertToBinary(year) + "-" + convertToBinary(month) + "-" + convertToBinary(day);
    }
};