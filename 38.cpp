#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string s = "1";

    string countAndSay(int n) {
        recursion(1, n);
        return s;
    }
    
    void recursion(int index, int n) {
        if (index == n) {
            return;
        }

        int cnt = 1;
        string t;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == s[i + 1]) cnt++;
            else {
                t += to_string(cnt) + s[i];
                cnt = 1;
            }
        }

        s = t;
        recursion(index + 1, n);
    }
};

int main () {
    int n;
    cin >> n;

    Solution sol;
    cout << sol.countAndSay(n);
}