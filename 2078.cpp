#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), i = 0, j = n - 1;
        
        // so voi nha dau tien
        while (colors[0] == colors[j]) j--;
        
        // so nha cuoi cung
        while (colors[n - 1] == colors[i]) i++;

        return max(j, n - i - 1);
    }
};