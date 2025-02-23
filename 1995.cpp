#include<bits/stdc++.h>

using namespace std;

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int a = 0; a < n - 3; ++a) {
            for (int b = a + 1; b < n - 2; ++b) {
                for (int c = b + 1; c < n - 1; ++c) {
                    int sum = nums[a] + nums[b] + nums[c];
                    for (int d = c + 1; d < n; ++d) {
                        if (nums[d] == sum) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};
