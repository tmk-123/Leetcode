#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        if (x < y) swap(x, y);
        int cnt = 0;

        while (x > 0) {
            int a = x & 1;
            int b = y & 1;
            x >>= 1;
            y >>= 1;

            if (a != b) {
                cnt++;
            }
        }

        return cnt;
    }
};