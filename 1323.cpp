#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '6') {
                s[i] = '9';
                return stoi(s);
            }
        }
        return stoi(s);
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.maximum69Number(n);
}