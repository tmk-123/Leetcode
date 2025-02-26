#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = n - 1; j >= 0; j--) {
                v.push_back(image[i][j] ^ 1);
            }
            res.push_back(v);
        }
        return res;
    }
};