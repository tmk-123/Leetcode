#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> p(n + 1, true);
        p[0] = p[1] = false;
        int cnt = 0;

        for (int i = 2; i < n; i++) {
            if (p[i]) {
                cnt++;
                for (long j = (long)i * i; j < n; j += i) {
                    p[j] = false;
                }
            }
        }

        return cnt;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.countPrimes(n);
}