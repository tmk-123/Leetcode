#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        for (char c : s) {
            string t = to_string(c - 'a' + 1);
            for (char ch : t) {
                num += ch - '0';
            }
        }

        k--;
        while (k--) {
            int temp = 0;
            while (num > 0) {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
        }

        return num;
    }
};

int main() {
    Solution sol;
    cout << sol.getLucky("leetcode", 2);
}