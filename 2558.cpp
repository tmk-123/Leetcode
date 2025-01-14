#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());

        while (k--) {
            int maxGift = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(sqrt(maxGift));
        }

        long long res = 0;
        while (!maxHeap.empty()) {
            res += maxHeap.top();
            maxHeap.pop();
        }

        return res;
    }
};
int main() {
    vector<int> v = {25,64,9,4,100};
    Solution sol;
    cout << sol.pickGifts(v, 4);
}