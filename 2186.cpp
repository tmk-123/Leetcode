#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int, int> m1, m2;
        for (int i = 0; i < s.length(); i++) m1[s[i] - 'a']++;
        for (int i = 0; i < t.length(); i++) m2[t[i] - 'a']++;

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            cnt += min(m1[i], m2[i]);
        }

        return s.length() + t.length() - cnt;
    }
};