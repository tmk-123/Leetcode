#include<bits/stdc++.h>

using namespace std;

// cách 1 quy hoạch động
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.length();
        
//         vector<vector<bool>> dp(n, vector<bool>(n, true));

//         int start = 0, end = 0, max_len = 1;
//         for (int len = 2; len <= n; len++) {
//             for (int i = 0; i <= n - len; i++) {
//                 int j = i + len - 1;

//                 if (len == 2 && s[i] == s[j]) {
//                     dp[i][j] = true;
//                 }
//                 else {
//                     dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
//                 }

//                 if (dp[i][j]) {
//                     if (len > max_len) {
//                         start = i;
//                         end = j;
//                     }
//                 }
//             }
//         }

//         return s.substr(start, end - start + 1);
//     }
// };

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;

        // lấy 1 ký tự trung tâm sau đó mở rộng 2 bên theo chẵn hoặc lẻ
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);     // Mở rộng quanh một ký tự (chuỗi đối xứng lẻ)
            int len2 = expandAroundCenter(s, i, i + 1); // Mở rộng quanh hai ký tự liền nhau (chuỗi đối xứng chẵn)
            int len = max(len1, len2);

            if (len > (end - start)) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }

private:
    int expandAroundCenter(string& s, int left, int right) {

        // nếu left và right vẫn thỏa mãn nằm trong s và s[l] = s[r] thì có thể thêm vào hai bên xâu trung tâm
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.longestPalindrome(s);
}