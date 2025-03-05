#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count1 = 0, count0 = 0;
        
        for (char c : s) {
            if (c == '1') count1++;
            else count0++;
        }
        
        // Đặt các '1' lên đầu (trừ 1 cái để ở cuối)
        string result(count1 - 1, '1');
        // Đặt tất cả '0' vào giữa
        result += string(count0, '0');
        // Đặt '1' cuối cùng để đảm bảo số lẻ
        result += '1';
        
        return result;
    }
};