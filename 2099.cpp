#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < nums.size(); i++) {
            minHeap.push({nums[i], i});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<pair<int, int>> v;
        while (!minHeap.empty()) {
            v.push_back(minHeap.top());
            minHeap.pop();
        }

        sort(v.begin(), v.end(), compare);

        vector<int> res;
        for (auto x : v) {
            res.push_back(x.first);
        }

        return res;
    }
};
int main() {
    vector<int> v = {5,4,2,3};
    Solution sol;
    vector<int> res = sol.maxSubsequence(v, 2);
    for (int x : res) {
        cout << x << " ";
    }
}