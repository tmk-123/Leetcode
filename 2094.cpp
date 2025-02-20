#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
vector<int> findEvenNumbers(vector<int>& digits) {
    set<int> uniqueNumbers;
    int n = digits.size();

    // Duyệt qua mọi bộ ba chữ số
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (i == j || j == k || i == k) continue; // Đảm bảo mỗi số chỉ dùng một lần
                if (digits[i] == 0) continue; // Không được có số 0 ở đầu
                if (digits[k] % 2 != 0) continue; // Chữ số cuối phải là số chẵn
                
                // Tạo số từ ba chữ số
                int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                uniqueNumbers.insert(num);
            }
        }
    }

    return vector<int>(uniqueNumbers.begin(), uniqueNumbers.end());
}
};