#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int i = 1, j = 0;
        while (i <= n && j < target.size()) {
            if (i != target[j]) {
                res.push_back("Push");
                res.push_back("Pop");
                
            }
            else {
                res.push_back("Push");
                j++;
            }
            
            i++;
        }      

        return res;
    }
};