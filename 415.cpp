#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.length() < num2.length()) swap(num1, num2);
        while (num1.length() > num2.length()) num2 = "0" + num2;
        
        string res = "";
        int memory = 0;
        for (int i = num1.length() - 1; i >= 0; i--) {
            int x = num1[i] - '0' + num2[i] - '0' + memory;
            res = to_string(x % 10) + res;
            memory = x / 10;
        }
        if (memory > 0) res = to_string(memory) + res;
        return res;
    }
};