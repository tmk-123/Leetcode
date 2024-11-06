#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> v;
        backtrack(s.length(), 0, s, v);
        return res;
    }

    void backtrack(int n, int sum, string s, vector<string> &v) {
        if (sum == n) {
            res.push_back(v);
            return;
        }

        for (int i = 1; i + sum <= n; i++) {
            string t = s.substr(sum, i);

            if (isPalindrome(t)){
                v.push_back(t);
                backtrack(n, sum + i, s, v);
                v.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    vector<vector<string>> v = sol.partition(s);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}