#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
   bool stoneGameIX(vector<int>& stones) {
        int count[3] = {0};  // Đếm số lượng đá có phần dư 0, 1, 2 khi chia cho 3

        for (int val : stones) {
            count[val % 3]++;
        }

        // Nếu không có đá dư 1 hoặc dư 2 thì Alice không thể tránh được thua
        if (count[1] == 0 && count[2] == 0) return false;

        if (count[0] % 2 == 0) {
            return count[1] > 0 && count[2] > 0;
        } else {
            return abs(count[1] - count[2]) > 2;
        }
    }
};