#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.length() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1); // Lấy từ đầu đến chữ số lẻ đầu tiên
            }
        }
        return ""; 
    }
};