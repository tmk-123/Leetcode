#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int cnt = 0;
        int prev = 0;

        for (int rung : rungs) {
            if (rung - prev > dist) {
                // Số bậc cần thêm vào giữa prev và rung
                cnt += (rung - prev - 1) / dist;
            }
            prev = rung;
        }

        return cnt;
    }
};
