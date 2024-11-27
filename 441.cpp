#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 1, right = n;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long currentSum = mid * (mid + 1) / 2;
            
            if (currentSum == n) return mid;  
            else if (currentSum < n) left = mid + 1; 
            else right = mid - 1; 
        }
        return right;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.arrangeCoins(n);
}