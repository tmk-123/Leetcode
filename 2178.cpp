#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 == 1) return {};
        
        vector<long long> res;
        long long i = 2;
        long long curSum = 0;

        // greedy
        while (i + curSum <= finalSum) {
            res.push_back(i);
            curSum += i;
            i += 2;
        }

        // cộng phần dư cho số cuối
        res.back() += (finalSum - curSum);
        return res;
    }
};  