#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        string s;
        backtrack(0, 0, s, n);
        return res;
    }

    void backtrack(int open, int close, string s, int n) {
        if (open > n || close > n) return;
        if (open == n && close == n) {
            res.push_back(s);
            return;
        }

        if (open <= n) backtrack(open + 1, close, s + "(", n);
        if (close < open) backtrack(open, close + 1, s + ")", n);
    }
};

int main () {
    int n;
    cin >> n;

    Solution sol;
    vector<string> res = sol.generateParenthesis(n);
    
    for (string s : res){
        cout << s << endl;
    }
}