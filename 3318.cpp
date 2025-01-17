#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;

        for (int i = 0; i <= nums.size() - k; i++) {
            vector<int> v(nums.begin() + i, nums.begin() + i + k);
            res.push_back(solve(v, x));
        }
        
        return res;
    }

    int solve(vector<int>& v, int x) {
        map<int, int> freq;
        for (int num : v) {
            freq[num]++;
        }

        vector<pair<int, int>> freqPair(freq.begin(), freq.end());
        sort(freqPair.begin(), freqPair.end(), compare);

        int sum = 0, count = 0;
        for (auto p : freqPair) {
            if (count >= x) break;
            sum += p.first * p.second;
            count++;
        }
        return sum;
    }
};
  
int main() {
    vector<int> v ={1,1,2,2,3,4,2,3};
    Solution sol;
    vector<int> res = sol.findXSum(v, 6, 2);
    for (int x : res) {
        cout << x << " ";
    }
}