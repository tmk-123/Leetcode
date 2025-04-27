#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26, 0); 
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // Đếm số lượng từng chữ số 0..9
        vector<int> digit(10, 0);
        
        // Các chữ cái đặc biệt
        digit[0] = count['z' - 'a']; // 'z' -> "zero"
        digit[2] = count['w' - 'a']; // 'w' -> "two"
        digit[4] = count['u' - 'a']; // 'u' -> "four"
        digit[6] = count['x' - 'a']; // 'x' -> "six"
        digit[8] = count['g' - 'a']; // 'g' -> "eight"
        
        digit[1] = count['o' - 'a'] - digit[0] - digit[2] - digit[4]; // 'o' -> "one"
        digit[3] = count['h' - 'a'] - digit[8]; // 'h' -> "three"
        digit[5] = count['f' - 'a'] - digit[4]; // 'f' -> "five"
        digit[7] = count['s' - 'a'] - digit[6]; // 's' -> "seven"
        digit[9] = count['i' - 'a'] - digit[5] - digit[6] - digit[8]; // 'i' -> "nine"
        
        string result;
        for (int i = 0; i <= 9; i++) {
            result.append(digit[i], '0' + i); // neu khong có thì digit[i] = 0 hay không append;
        }
        
        return result;
    }
};