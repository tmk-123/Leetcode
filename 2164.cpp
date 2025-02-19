#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 1) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }

        sort(odd.rbegin(), odd.rend());
        sort(even.begin(), even.end());

        vector<int> res(nums.size());
        int i = 0, j = 0, k = 0;
        while (j < odd.size() && k < even.size()) {
            if (i % 2 == 1) res[i++] = odd[j++];
            else res[i++] = even[k++];
        }

        while (j < odd.size()) res[i++] = odd[j++];
        while (k < even.size()) res[i++] = even[k++];
        return res;
    }
};

int main() {
    vector<int> v = {4, 1, 2, 3};
    Solution sol;
    vector<int> res = sol.sortEvenOdd(v);
    for (int x : res) {
        cout << x << " ";
    }
}