#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isFascinating(int n) {
        int temp = n;
        unordered_map<int, int> m;
        while (temp > 0) {
            m[temp % 10]++;
            if (temp % 10 == 0 || m[temp % 10] == 2) return false;
            temp /= 10;
        }

        temp = n * 2;
        while (temp > 0) {
            m[temp % 10]++;
            if (temp % 10 == 0 || m[temp % 10] == 2) return false;
            temp /= 10;
        }

        temp = n * 3;
        while (temp > 0) {
            m[temp % 10]++;
            if (temp % 10 == 0 || m[temp % 10] == 2) return false;
            temp /= 10;
        }

        return true;
    }
};