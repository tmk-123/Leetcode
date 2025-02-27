#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        if (n < k) return -1;
        
        int cnt = 0;
        while (n > 0) {
            int a = n & 1;
            int b = k & 1;
            n >>= 1;
            k >>= 1;

            if (b == 1) {
                if (a == 0) return -1;
            }
            else {
                if (a == 1) cnt++;
            }
        }

        return cnt;
    }
};