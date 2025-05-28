#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int> v, int n, int maxPerStore) {
        int total = 0;
        for (int q : v) {
            total += ceil(q * 1.0 / maxPerStore);
        }
        return total <= n; // tổng số cửa hàng cần để đúng maxPerStore, nếu cần nhiều cửa hàng hơn thì loại
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        int ans = right;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(quantities, n, mid)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};