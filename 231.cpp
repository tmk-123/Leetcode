#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        for (int i = 0; i < 32; i++) {
            if (n == (1 << i)) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    cout << sol.isPowerOfTwo(16);
}