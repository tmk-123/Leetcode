#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();

        while (n--) {
            string temp = s.substr(1);
            temp += s[0];

            if (temp == goal) return true;
            s = temp;
        }
        return false;
    }
};

int main() {
    string s, goal;
    cin >> s >> goal;

    Solution sol;
    cout << sol.rotateString(s, goal);
}