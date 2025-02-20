#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 2) return 0;
        map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        int cnt = 0;
        vector<pair<int, int>> v(freq.begin(), freq.end());
        for (int i = 1; i < v.size() - 1; i++) {
            cnt += v[i].second;
        }
        return cnt;
    }
};

int main() {
    vector<int> v = {11,7,2,15};
    Solution sol;
    cout << sol.countElements(v);    
}