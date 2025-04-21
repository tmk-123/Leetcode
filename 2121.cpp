#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> m;
        
        for (int i = 0; i < n; i++) m[arr[i]].push_back(i);

        vector<long long> res(n, 0);

        for (auto& [x, v] : m) {
            if (v.size() == 1) continue;

            vector<long long> prefixSum(v.size(), 0);
            prefixSum[0] = v[0];
            for (int i = 1; i < v.size(); i++) prefixSum[i] = prefixSum[i - 1] + v[i];

            for (int i = 0; i < v.size(); i++) {
                long long left;
                if (i == 0) left = (long long) i * v[i];
                else left = (long long) i * v[i] - prefixSum[i - 1];

                long long right = prefixSum[v.size() - 1] - prefixSum[i] - (long long)(v.size() - i - 1) * v[i];

                res[v[i]] = left + right;
            }
        }

        return res;
    }
};