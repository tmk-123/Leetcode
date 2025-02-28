#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int XorAll = 0;
        int n = grid.size();
        for (int i = 1; i <= n * n; i++) XorAll ^= i;
        for (auto v : grid) {
            for (int x : v) {
                XorAll ^= x;
            }
        }

        int LSB = XorAll & (-XorAll);
        int n1 = 0, n2 = 0;
        
        for (int i = 1; i <= n * n; i++) {
            if ((i & LSB) == 0) n1 ^= i;
            else n2 ^= i;
        }
        for (auto v : grid) {
            for (int x : v) {
                if ((x & LSB) == 0) n1 ^= x;
                else n2 ^= x; 
            }
        }

        for (auto v : grid) {
            for (int x : v) {
                if (x == n1) return {n1, n2};
            }
        }
        return {n2, n1};
    }
};