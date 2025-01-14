#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> arr;
        sort(nums.begin(), nums.end());

        while (!nums.empty()) {
            int aliceMove = nums[0];
            nums.erase(nums.begin());

            int bobMove = nums[0];
            nums.erase(nums.begin());
            
            arr.push_back(bobMove);
            arr.push_back(aliceMove);
        } 

        return arr;
    }
};
int main() {
    vector<int> v = {5,4,2,3};
    Solution sol;
    vector<int> res = sol.numberGame(v);
    for (int x : res) {
        cout << x << " ";
    }
}