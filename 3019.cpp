#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countKeyChanges(string s) {
        int cnt = 0;
        for (int i = 1; i < s.length(); i++) {
            if (tolower(s[i]) != tolower(s[i - 1])) cnt++;
        }
        return cnt;
    }
};