#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> received(n + 1, false);
        set<int> losers;
        for (int i = 1; i <= n; i++) losers.insert(i);

        int current = 1;
        int step = 1;
        while (!received[current]) {
            received[current] = true;
            losers.erase(current);

            // trừ 1 để chuyển về hệ 0 sau đó +1 để lên hệ 1
            current = (current + step * k - 1) % n + 1;
            step++;
        }

        vector<int> res(losers.begin(), losers.end());
        return res;
    }
};