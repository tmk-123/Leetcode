#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for (int i = 0; i < arr1.size(); i++) {
            int check = true;
            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    check = false;
                    break;
                }
            }
            if (check) cnt++;
        }

        return cnt;
    }
};