#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        string vowel = "aouie";
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            string s = words[i];
            if (vowel.find(s[0]) != string::npos && 
                vowel.find(s[s.length() - 1]) != string::npos) cnt++;
        }
        return cnt;
    }
};