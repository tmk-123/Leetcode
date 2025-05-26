#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int x : piles) {
            pq.push(x);
        }        
        
        while (k--) {
            int n = pq.top(); pq.pop();
            if (n == 0) return 0;
            if (n > 1) pq.push(ceil(n / 2.0));
        }

        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};