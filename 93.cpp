#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;

        for (int a = 1; a <= 3; a++) {
            for (int b = 1; b <= 3; b++) {
                for (int c = 1; c <= 3; c++) {
                    for (int d = 1; d <= 3; d++) {
                        if (a + b + c + d == s.length()) {
                            int s1 = stoi(s.substr(0, a));
                            int s2 = stoi(s.substr(a, b));
                            int s3 = stoi(s.substr(a + b, c));
                            int s4 = stoi(s.substr(a + b + c, d));

                            if (s1 <= 255 && s2 <= 255 && s3 <= 255 && s4 <= 255) {
                                // check xem có số 0 ở trước không
                                string t = to_string(s1) + "." + to_string(s2) + "." + to_string(s3) + "." + to_string(s4);
                                if (t.length() == s.length() + 3) {
                                    ans.push_back(t);
                                }
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};

int main () {
    string s;
    cin >> s;
    
    Solution sol;
    vector<string> v = sol.restoreIpAddresses(s);
    
    for (string x : v) {
        cout << x << " ";
    }
}