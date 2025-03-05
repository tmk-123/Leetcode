#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int len = min({s1.length(), s2.length(), s3.length()});
        
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (s1[i] == s2[i] && s2[i] == s3[i]) cnt++;
            else break;
        }
        
        if (cnt) return s1.length() + s2.length() + s3.length() - 3 * cnt;
        return -1;
    }
};