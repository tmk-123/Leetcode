#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long modPow(long long x, long long y, int m) {
        if (y == 0) return 1;
        long long p = modPow(x, y / 2, m);
        p = (p * p) % m;
        if (y % 2 == 1) return (p * (x % m)) % m;
        return p; 
    }

    int minNonZeroProduct(int p) {
        long long cnt = (1LL << p) - 1, mod = 1000000007;

        // trừ 111..111(2^p - 1) có tất cả số đề là 1, ta đều tìm được 2 số sao cho XOR = 111..111
        // 2 số đó tách lại thành 111...110 và 000...001 (1) nên có 2^p - 2 cặp như vậy
        return cnt % mod * modPow(cnt - 1, cnt / 2, mod) % mod;    
    }
};