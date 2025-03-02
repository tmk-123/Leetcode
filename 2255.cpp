#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for (string word : words) {
            if (s.find(word) == 0) cnt++;
        }
        return cnt;
    }
};