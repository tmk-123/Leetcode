#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cnt = 0;
        int minVal = INT_MAX;
        long long sum = 0;
        for (auto m : matrix) {
            for (int x : m) {
                if (x < 0) cnt++;
                minVal = min(minVal, abs(x));
                sum += abs(x);
            }
        }

        if (cnt % 2 == 0) {
            return sum;
        }
        else {
            return sum - 2 * minVal;
        }
    }
};