#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for (int n : nums) {
            if ( (n & 1) == 0) cnt++;
            if (cnt >= 2) return true;
        }
        return false;
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4 ,5};
    Solution sol;
    cout << sol.hasTrailingZeros(v);
}