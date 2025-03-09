#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> path;

        int level = 0;
        int temp = label;
        while (temp > 1) {
            temp /= 2;
            level++;
        }

        while (label > 0) {
            path.push_back(label);
            int levelStart = pow(2, level);
            int levelEnd = pow(2, level + 1) - 1;

            // nếu k đảo ngược là label / 2
            label = (levelStart + levelEnd - label) / 2;
            level--;
        }

        reverse(path.begin(), path.end());
        return path;
    }
};