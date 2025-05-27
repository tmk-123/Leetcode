#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double p = myPow(x, N / 2);
        if (N % 2 == 1) return x * p * p;
        return p * p;
    }
};