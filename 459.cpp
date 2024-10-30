#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string sub;

        for (int i = 1; i <= s.length() / 2; i++) {
            int ok = 1;
            sub = s.substr(0, i);
            int x = i;
            
            while (x + i <= s.length()) {
                if (s.length() % i != 0 || s.find(sub, x) == string::npos || s.find(sub, x) != x){
                    ok = 0;
                    break;
                }
                x += i;
            }
            
            if (ok == 1) return true;
        }
        return false;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.repeatedSubstringPattern(s);
}
