#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int res = 0;
        
        for (int j = 0; j < n; j++) {
            int leftSmaller = 0, leftGreater = 0;
            int rightSmaller = 0, rightGreater = 0;

            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) leftSmaller++;
                if (rating[i] > rating[j]) leftGreater++;
            }
            for (int k = j + 1; k < n; k++) {
                if (rating[k] < rating[j]) rightSmaller++;
                if (rating[k] > rating[j]) rightGreater++; 
            }

            res += leftSmaller * rightGreater + leftGreater * rightSmaller;
        }
        return res;
    }
};