#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total_sum = 0;
        for (int num : arr) {
            total_sum += num;
        }

        if (total_sum % 3 != 0) return false;

        int target = total_sum / 3;
        int current_sum = 0, count = 0;

        for (int i = 0; i < arr.size(); i++) {
            current_sum += arr[i];
            if (current_sum == target) {
                count++;
                current_sum = 0;
            }
            // Nếu tìm được 2 phần và còn phần cuối, trả về true
            if (count == 2 && i < arr.size() - 1) return true;
        }

        return false;
    }
};

int main() {
    int n;
    vector<int> arr;
    while (cin >> n) {
        arr.push_back(n);
    }
    Solution sol;
    cout << sol.canThreePartsEqualSum(arr);
}