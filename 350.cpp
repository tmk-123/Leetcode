#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> res;

        for (int n : nums1) {
            freq[n]++;
        }

        for (int n : nums2) {
            if (freq[n] >= 1) {
                res.push_back(n);
                freq[n]--;        
            }
        }

        return res;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < m; i++) cin >> nums2[i];

    Solution sol;
    vector<int> res = sol.intersect(nums1, nums2);
    for (int x : res) {
        cout << x << " ";
    }
}