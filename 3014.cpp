#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int cnt = 0;
        for (int i = 0; i < word.size(); i++) {
            cnt += i/8 + 1;
        }
        return cnt;
    }
};