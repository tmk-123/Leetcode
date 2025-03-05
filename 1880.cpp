#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stringToNumber(string s) {
        int num = 0;
        for (char c : s) {
            num = num * 10 + (c - 'a');
        }
        return num;
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return stringToNumber(firstWord) + stringToNumber(secondWord) == stringToNumber(targetWord);
    }
};