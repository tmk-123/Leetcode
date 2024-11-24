#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> res;
        int minNumber = 0, maxNumber = n;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                res.push_back(minNumber++);
            }
            else res.push_back(maxNumber--);
        }

        if (s[n - 1] == 'I') res.push_back(minNumber);
        else res.push_back(maxNumber);
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    vector<int> res = sol.diStringMatch(s);
    for (int x : res) {
        cout << x << " ";
    }
}