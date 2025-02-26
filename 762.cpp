#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        vector<int> v = {2, 3, 5, 7, 11, 13, 17, 19};
        return find(v.begin(), v.end(), n) != v.end();
    }
    int countSetBit(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n & 1);
            n = n >> 1;
        }
        return cnt;
    }

    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            if (isPrime(countSetBit(i))) cnt++;
        }
        return cnt;
    }
};