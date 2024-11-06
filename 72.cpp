#include<bits/stdc++.h>

using namespace std;

//Levenshtein distance

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        int dp[n + 1][m + 1]; // lưu trữ bước nhỏ nhất chuyển đổi i ký tự đầu của word1 thành j ký tự đầu của word2

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0) {
                    dp[i][j] = j; // chèn j ký tự nếu word1 rỗng
                }
                else if (j == 0) {
                    dp[i][j] = i; // xóa i ký tự nếu word2 rỗng
                }
                else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // không thay đổi nếu ký tự giống nhau
                }
                else {
                    // dp[i - 1][j] : xóa 1 phần tử (tức là đang ở dp[i][j] muốn trở thành dp[i - 1][j] thì phải xóa 1 phần tử)
                    // dp[i][j - 1] : chèn 1 phần tử
                    // dp[i - 1][j - 1] : thay thế một phần tử
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    Solution sol;
    cout << sol.minDistance(s1, s2);
}