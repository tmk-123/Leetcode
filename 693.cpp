#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastBit = n & 1;
        int i = 1;
        while ((1 << i) <= n) {
            int bit = 0;
            if ((n & (1 << i++)) > 0) bit = 1;
            if (bit == lastBit) return false;
            lastBit = bit;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.hasAlternatingBits(5);
}