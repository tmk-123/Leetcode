#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;

        while (left <= right) {
            long long mid = (left + right) / 2;
            if (mid * mid == x) return mid;
            else if (mid * mid < x) left = mid + 1;
            else right = mid - 1;
        } 

        return right;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.mySqrt(n);
}