#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        string res;
        int count = 0;
        if (backtrack(res, n, k, '\0', count)) return res;
        return "";
    }

    bool backtrack(string& res, int n, int k, char last_char, int &count) {
        if (res.length() == n) {
            count++;
            if (count == k) return true;
            return false;
        }
        
        for (char c = 'a'; c <= 'c'; c++) {
            if (c != last_char) {
                res.push_back(c);
                if (backtrack(res, n, k, c, count)) return true;
                res.pop_back();
            }
        }

        return false;
    }
}; 

int main() {
    int n, k;
    cin >> n >> k;
    Solution sol;
    cout << sol.getHappyString(n, k);
}