#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long ans = 0;

        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        while (i < s.length()) {
            if (isdigit(s[i])) {
                ans = ans * 10 + s[i] - '0';
                i++;

                if (ans > INT_MAX && sign == -1){
                    return INT_MIN;
                }
                else if (ans > INT_MAX && sign == 1){
                    return INT_MAX;
                }
            }
            else return ans * sign;
        }

        return ans * sign;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.myAtoi(s);
}