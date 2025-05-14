#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            if (Try(0, i, s, 0)) res += i * i;
        }
        return res;
    }

    bool Try(int start, int n, string s, int sum) {
        if (start == s.size()) {
            if (sum == n) return true;
            return false;
        }

        for (int end = start + 1; end <= s.size(); end++) {
            string substr = s.substr(start, end - start);
            if (Try(end, n, s, sum + stoi(substr))) return true;
        }
        return false;
    }
};