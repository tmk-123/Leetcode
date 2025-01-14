#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();

            if (stone1 != stone2) {
                pq.push(stone1 - stone2);
            }
        }

        if (pq.empty()) return 0;
        return pq.top();
    }
};

int main() {
    vector<int> v = {2, 7, 4, 1, 8, 1};
    Solution sol;
    cout << sol.lastStoneWeight(v);
}