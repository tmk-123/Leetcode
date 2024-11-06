#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] đúng nếu từ 0 đến i có thể phân tách thành các từ trong wordDict
        // bằng cách dp[start] đúng và có từ khớp trong đoạn start -> i thì dp[i] cũng đúng
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (string w : wordDict) {
                // start là chỗ ta quy hoạch động, hay dp[i - start] đúng thì dp[i] đúng
                int start = i - w.length();

                if (start >= 0 && dp[start] && w == s.substr(start, w.length())) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }
};

int main() {
    string s, t;
    cin >> s;
    vector<string> v;
    while (cin >> t) {
        v.push_back(t);
    }

    Solution sol;
    cout << sol.wordBreak(s, v);

    return 0;
}
