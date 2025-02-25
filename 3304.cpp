#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        int n = 0;
        while ((1 << n) < k) n++;
        return Try(n, k);
    }
    char Try(int n, int k) {
        if (n == 0) return 'a';
        int prev = 1 << (n - 1);
        if (k > prev) return Try(n - 1, k - prev) + 1;
        return Try(n - 1, k);
    }
};

int main() {
    Solution sol;
    cout << sol.kthCharacter(5);    
}