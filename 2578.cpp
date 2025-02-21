#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int splitNum(int num) {
        vector<int> v;
        while (num > 0) {
            v.push_back(num % 10);
            num /= 10;
        }

        sort(v.begin(), v.end());
        int left = 0, right = 0;
        for (int i = 0; i < v.size(); i++) {
            if (i % 2 == 0) left = left * 10 + v[i];
            else right = right * 10 + v[i];
        }
        return left + right;
    }
};

int main() {
    Solution sol;
    cout << sol.splitNum(4325);
}