#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int F = 0;
        for (int i = 0; i < n; i++) {
            F += i * nums[i];
        }

        int maxF = F;
        for (int i = 1; i < n; i++) {
            // khi quay vòng thì mỗi số coi như cộng thêm 1 đơn vị, tức cộng thêm sum, sau đó trừ đi số cuối nhân n(sau khi dịch 1)
            F = F + sum - n * nums[n - i];
            maxF = max(maxF, F);
        }

        return maxF;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }
    Solution sol;
    cout << sol.maxRotateFunction(nums);
}