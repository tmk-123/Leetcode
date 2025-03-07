#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0, sumB = 0;
        for (int x : aliceSizes) sumA += x;
        for (int x : bobSizes) sumB += x;

        // sumA - x + y = sumB - y + x nên sumB - sumA = 2(y - x)
        int n = (sumB - sumA) / 2;
        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());

        for (int x : aliceSizes) {
            if (bobSet.count(x + n)) {
                return {x, x + n};
            }
        }

        return {};
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    Solution sol;
    sol.fairCandySwap(a, b);
}