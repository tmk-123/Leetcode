#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen; // Tập hợp lưu các giá trị đã gặp

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNextNumber(n); // Tính tổng bình phương các chữ số
        }

        return n == 1; // Trả về true nếu n là số hạnh phúc
    }
    int getNextNumber(int n) {
        int output = 0;
        
        while (n > 0) {
            int digit = n % 10;
            output += digit * digit;
            n = n / 10;
        }
        
        return output;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.isHappy(n);
}