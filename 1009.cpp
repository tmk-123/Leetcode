#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int t = 0;
        while ((1 << t) <= n) {
            cout << (1 << t) << " ";
            n ^= (1 << t);
            t++;
        }
        return n;
    }
};

int main() {
    Solution sol;
    cout << sol.bitwiseComplement(5);
}