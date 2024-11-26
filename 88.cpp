#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;

        // nếu i = -1 trước thì sẽ lặp hết nums2 đến khi hết
        // nếu j = -1 trước thì dừng bởi số còn lại của nums1 được xếp theo tăng dần sẵn rồi
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m + n);
    vector<int> nums2(n);
    for (int i = 0; i < m + n; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];

    Solution sol;
    sol.merge(nums1, m, nums2, n);
}