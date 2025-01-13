#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;

        for (int& n : nums) {
            if (n > max1) {
                max2 = max1;
                max1 = n;
            } 
            else if (n > max2) {
                max2 = n;
            }
        }
        
        return (max1 - 1) * (max2 - 1);
    }
};

int main() {
    vector<int> v = {3, 4, 5, 2};
    
    Solution sol;
    cout << sol.maxProduct(v);
}