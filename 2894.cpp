#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divisible = 0;
        for (int i = m; i <= n; i += m) {
            divisible += i;
        }

        return n * (n + 1) / 2 - 2 * divisible;
    }
};