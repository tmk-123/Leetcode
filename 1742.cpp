#include<bits/stdc++.h>

using namespace std;

class Solution {
public: 
    int sumDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        int maxBalls = INT_MIN;
        unordered_map<int, int> m;
        for (int i = lowLimit; i <= highLimit; i++) {
            int n = sumDigits(i);
            m[n]++;
            maxBalls = max(maxBalls, m[n]);
        }

        return maxBalls;
    }
};