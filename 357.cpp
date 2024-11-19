#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int total = 1; // cả số 0
        int uniqueNumber = 9; // số số unique ở mỗi chữ số, bắt đầu từ 1;
        int availableDigits = 9; // số chữ số còn lại có thể chọn

        for (int i = 1; i <= n; i++) {
            total += uniqueNumber;
            uniqueNumber *= availableDigits; // quy tắc nhân
            availableDigits--;
        }

        return total;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.countNumbersWithUniqueDigits(n);
}