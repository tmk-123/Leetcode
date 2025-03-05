#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        for (int i = 0; i < strs[0].length(); i++) {
            char last = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] < last) {
                    cnt++;
                    break;
                }
                last = strs[j][i];
            }
        }
        return cnt;
    }
};