#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int mid = n / 2;
        int countA = 0, countB = 0;

        string vowel = "ueoaiUEOAI";
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (vowel.find(s[i++]) != string::npos) countA++;
            if (vowel.find(s[j--]) != string::npos) countB++;
        }

        return countA == countB;
    }
};