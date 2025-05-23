#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        while (num > 0) {
            v.push_back(num % 10);
            num /= 10;
        }
        
        sort(v.begin(), v.end());
        return v[0] * 10 + v[2] + v[1] * 10 + v[3]; 
    }
};

int main() {
    Solution sol;
    cout << sol.minimumSum(4009);
}