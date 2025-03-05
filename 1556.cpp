#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        if (n < 10) return to_string(n);
        string res;
        int cnt = 1;
        while (n > 0) {
            res = string(1, n % 10 + '0') + res;
            if (cnt % 3 == 0) res = "." + res;
            cnt++;
            n /= 10;
        }

        if (cnt % 3 == 1) res.erase(0, 1);
        return res;
    }
};