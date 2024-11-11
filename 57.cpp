#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int start = newInterval[0], end = newInterval[1];

        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] <= start && intervals[i][1] >= start) {
                start = min(start, intervals[i][0]);
            }
            if (intervals[i][0] <= end && intervals[i][1] >= end) {
                end = max(end, intervals[i][1]);
            }
            if (intervals[i][1] < start || intervals[i][0] > end) {
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        }

        res.push_back({start, end});
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<vector<int>> intervals;
    vector<int> newInterval;
    int n, m;
    cin >> n >> m;
    newInterval.push_back(n);
    newInterval.push_back(m);

    while (cin >> n >> m) {
        intervals.push_back({n, m});
    }

    Solution sol;
    vector<vector<int>> res = sol.insert(intervals, newInterval);
    for (auto x : res) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}