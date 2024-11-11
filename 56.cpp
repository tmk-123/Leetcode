#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;

        int i = 0;
        while (i < n) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
            else {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            i++;
        }

        res.push_back({start, end});
        return res;
    }
};

int main() {
    vector<vector<int>> v;
    int n, m;
    while (cin >> n >> m) {
        v.push_back({n, m});
    }

    Solution sol;
    vector<vector<int>> res = sol.merge(v);

    for (auto x : res) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}