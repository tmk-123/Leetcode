#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        if (s.length() <= k) return s;
        while (s.length() > k) {
            string t = "";
            for (int i = 0; i < s.length(); i += k) {
                int n = 0;
                for (int j = i; j < s.length() && j < i + k; j++)  
                    n += s[j] - '0';
                t += to_string(n);
            }
            s = t;
        }
        return s;
    }
};