#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for (int x : nums) {
            if (x > 0) pos++;
            if (x < 0) neg++;
        }

        return max(pos, neg);
    }
};

int main() {
    vector<int> v = {-1, -1, 0, 0, 1};
    Solution sol;
    cout << sol.maximumCount(v);
}