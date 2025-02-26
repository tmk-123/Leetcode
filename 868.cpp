#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int last = -1, maxDistance = 0, pos = 0;

        while (n > 0) {
            if (n & 1) {
                if (last != -1) maxDistance = max(maxDistance, pos - last);
                last = pos;
            }
            n >>= 1;
            pos++;
        }

        return maxDistance;
    }
};  