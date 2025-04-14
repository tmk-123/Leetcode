#include<bits/stdc++.h>

using namespace std;

    class Solution {
    public:
        int totalNumbers(vector<int>& digits) {
            unordered_set<int> result;
            int n = digits.size();

            // Duyệt qua mọi bộ ba chữ số khác nhau theo chỉ số
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j == i) continue;
                    for (int k = 0; k < n; ++k) {
                        if (k == i || k == j) continue;

                        int a = digits[i];
                        int b = digits[j];
                        int c = digits[k];

                        // Không cho chữ số đầu tiên là 0
                        if (a == 0) continue;

                        // Số phải là chẵn
                        if (c % 2 != 0) continue;

                        int number = a * 100 + b * 10 + c;
                        result.insert(number);
                    }
                }
            }

            return result.size();
        }
    };