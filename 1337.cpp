#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j]) {
                    count++;
                }
            }
            v.push_back({count, i});
        }
        sort(v.begin(), v.end(), compare);
        
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(v[i].second);
        }
        return res;
    }
};
  
int main() {
    vector<vector<int>> v = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
    };

    Solution sol;
    vector<int> res = sol.kWeakestRows(v, 2); 
    for (int x : res) {
        cout << x << " ";
    }
}