#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 0) return false;
        unsigned int t = 0;
        while (t < 16 && (1 << t) <= n) {
            if ((1 << t) * (1 << t) == n) return true; 
            t++;
        }
        return false;
    }
};