#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int cnt = 0;
        for (int i = 0; i < hours.size(); i++) {
            for (int j = i + 1; j < hours.size(); j++) {
                if ((hours[i] + hours[j]) % 24 == 0) cnt++;
            }
        }
        return cnt;
    }
};