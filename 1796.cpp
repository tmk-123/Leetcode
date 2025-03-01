#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        set<int> digits;

        // Lọc và lưu các chữ số duy nhất
        for (char c : s) {
            if (isdigit(c)) {
                digits.insert(c - '0'); // Chuyển ký tự số thành số nguyên
            }
        }

        // Nếu có ít hơn 2 chữ số, trả về -1
        if (digits.size() < 2) return -1;

        // Lấy chữ số lớn nhất và xóa nó để tìm chữ số lớn thứ hai
        auto it = digits.rbegin();
        ++it; // Lấy phần tử lớn thứ hai

        return *it;
    }
};