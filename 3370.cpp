#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int t = 0;
        int num = 1;
        while ((1 << t) <= n) {
            num |= (1 << t);
            t++;
        }
        return num;
    }
};