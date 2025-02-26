#include<bits/stdc++.h>

using namespace std;

// cách này có 1 số xuất hiện chẵn lần thì chắc chắn đúng
// nhưng có nhiều số lẻ lần thì ch chắc VD: 1 ^ 2 = 3, nên 1 ^ 2 ^ 3 = 0;

// class Solution {
// public:
//     bool divideArray(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int XorAll = 0;
//         for (int n : nums) {
//             XorAll ^= n;

//             cout << XorAll << " " << n << endl;
//         }
//         if (XorAll == 0) return true;
//         return false;
//     }
// };

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;
        for (auto &[num, count] : freq) {
            if (count % 2 != 0) return false;
        }
        return true;
    }
};

int main() {
    vector<int> v = {9,9,19,10,9,12,2,12,3,3,11,5,8,4,13,6,2,11,9,19,11,15,9,17,15,12,5,14,12,16,18,16,10,3,8,9,16,20,2,4,16,12,11,14,20,16,2,18,17,20,3,13,16,17,1,1,11,20,20,4};
    Solution sol;
    cout << sol.divideArray(v);
}