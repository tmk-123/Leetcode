#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<pair<int, int>> arrivals;
        for (int i = 0; i < n; i++) {
            arrivals.push_back({times[i][0], i});
        }
        sort(arrivals.begin(), arrivals.end(), compare);

        // {leavingTime, charNumber}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingHeap;

        // chair available
        priority_queue<int, vector<int>, greater<int>> chairs;
        for (int i = 0; i < n; i++) chairs.push(i);

        for (auto& [arrival, freindInx] : arrivals) {
            // giải phóng ghế người đã rời đi, nếu lúc họ rời trước thời gian đến
            while (!leavingHeap.empty() && leavingHeap.top().first <= arrival) {
                chairs.push(leavingHeap.top().second);
                leavingHeap.pop();
            }

            int i = chairs.top();
            chairs.pop();

            if (freindInx == targetFriend) {
                return i;
            }

            leavingHeap.push({times[freindInx][1], i});
        }

        return -1;
    }
};