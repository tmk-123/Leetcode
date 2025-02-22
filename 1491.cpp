#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int sum = 0;
        for (int i = 1; i < salary.size() - 1; i++) {
            sum += salary[i];
        }

        return sum * 1.0 / (salary.size() - 2);
    }
};