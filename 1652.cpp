#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> v(n, 0);
        if (k == 0) return v;

        for (int i = 0; i < n; i++) {
            if (k > 0) {
                for (int j = 1; j <= k; j++) {
                    v[i] += code[(i + j) % n];
                }
            }
            else {
                for (int j = 1; j <= -k; j++) {
                    v[i] += code[(i - j + n) % n];
                }
            }
        }

        return v;
    }
};
int main() {
    vector<int> v = {2,4,9,3};
    Solution sol;
    vector<int> res = sol.decrypt(v, -2);
    for (int x : res) {
        cout << x << " ";
    }
}