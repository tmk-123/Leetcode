#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> m1, m2;
        for (string s : words1) {
            m1[s]++;
        }
        for (string s : words2) {
            m2[s]++;
        }

        int cnt = 0;
        for (auto x : m1) {
            if (x.second == 1 && m2[x.first] == 1) cnt++;
        }
        return cnt;
    }
};