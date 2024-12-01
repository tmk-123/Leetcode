#include<bits/stdc++.h>

using namespace std;

class NumArray {
private:
    vector<int> prefixSum; // Mảng lưu tổng trước

public:
    // Constructor
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n + 1, 0); // Khởi tạo mảng prefixSum với kích thước n+1
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i]; // Tính tổng trước
        }
    }
    
    // Hàm sumRange: Tính tổng từ left đến right
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* numArray = new NumArray(nums);

    cout << numArray->sumRange(0, 2) << endl; 
    cout << numArray->sumRange(2, 5) << endl; 
    cout << numArray->sumRange(0, 5) << endl; 

    delete numArray; 
    return 0;
}