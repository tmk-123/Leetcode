#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        bitset<100005> bits;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i]) bits.set(i);
        }      

        long long totalSum = 0;
        for (int& n : nums2) totalSum += n;

        vector<long long> res;
        for (auto& q : queries) {
            int type = q[0], a = q[1], b = q[2];

            if (type == 1) {
                for (int i = a; i <= b; i++) {
                    bits.flip(i);
                }
            }
            else if (type == 2) {
                long long cnt = bits.count();
                totalSum += 1LL * cnt * a;
            }
            else {
                res.push_back(totalSum);
            }
        }

        return res;
    }
};