#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while (n > 0) {
            if ((n & 1) != 0) cnt++;
            n = n >> 1; 
        }       
        return cnt;
    }
};