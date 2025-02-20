#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> m;
        for (vector<int> x : items1) {
            m[x[0]] += x[1];
        }
        for (vector<int> x : items2) {
            m[x[0]] += x[1];
        }

        vector<vector<int>> res;
        for (pair<int, int> x : m) {
            res.push_back({x.first, x.second});
        }
        return res;
    }
};

int main() {
    vector<vector<int>> a = {{1, 1}, {4, 5}, {3, 8}};
    vector<vector<int>> b = {{3, 1}, {1, 5}};

    Solution sol;
    vector<vector<int>> res = sol.mergeSimilarItems(a, b);
    for (auto x : res) {
        for (int y : x) {
            cout << y << " ";
        } 
        cout << endl;
    } 
}