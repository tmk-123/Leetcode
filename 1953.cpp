#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long maxVal = LLONG_MIN, sum = 0;
        for (int x : milestones) {
            if (maxVal < x) maxVal = x;
            sum += x;
        }
        
        sum -= maxVal;
        if (maxVal <= sum) {
            return maxVal + sum;
        }
        else {
            return 2 * sum + 1;
        }
    }
};