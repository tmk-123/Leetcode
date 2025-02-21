#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int cnt = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (sorted[i] != heights[i]) cnt++;
        }
        return cnt;
    }
};