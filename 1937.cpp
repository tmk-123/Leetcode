#include<bits/stdc++.h>

using namespace std;

/*
dp[r][c] = max(dp[r - 1][c'] - |c - c'|) + points[r][c]
nếu c' < c thì dp[r][c] = max(dp[r - 1][c'] + c') - c + points[r][c]
                        = leftMax - c + points
nếu c' > c -> dp[r][c] = max(dp[r - 1][c'] - c') + c + points[r][c]
                        = rightMax + c + points
Hay dp[r][c] = max(leftMax - c, rightMax + c) + points   (duyệt c' trước, c sau, c hay c' có thể có giá trị tùy ý)
*/
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size();
        int col = points[0].size();
        vector<long long> dp(col, 0);

        for (int i = 0; i < col; i++) dp[i] = points[0][i];

        for (int r = 1; r < row; r++) {
            vector<long long> leftMax(col, 0), rightMax(col, 0);
            vector<long long> newDp(col, 0);

            leftMax[0] = dp[0] + 0;
            for (int i = 1; i < col; i++) {
                leftMax[i] = max(leftMax[i-1], dp[i] + i);
            }

            rightMax[col - 1] = dp[col-1] - (col-1);
            for (int i = col - 2; i >= 0; i--) {
                rightMax[i] = max(rightMax[i+1], dp[i] - i);
            }
            
            // i chia ra leftMax, rightMax rồi nên i khi tính rightMax là c' khác i bên dưới
            // nghĩa là max ở i phải dựa vào dp hàng trước và i, nên ta cộng cả 2 xem (dp[i'] + i') của từng cái
            // là nếu dp bằng nhau hết thì ở tại i' = i lớn nhất, không thì dp sẽ bù 
            for (int i = 0; i < col; i++) {
                newDp[i] = max(leftMax[i] - i, rightMax[i] + i) + points[r][i];
            }
            dp = newDp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};