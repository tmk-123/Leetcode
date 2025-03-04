#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> group;
        int count = 1; // Đếm số lượng ký tự liên tiếp
        
        // Bước 1: Tạo mảng group lưu độ dài các đoạn '0' và '1' liên tiếp
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                group.push_back(count);
                count = 1;
            }
        }
        group.push_back(count); // Đẩy phần tử cuối vào mảng
        
        // Bước 2: Tính tổng min(group[i], group[i+1])
        int result = 0;
        for (int i = 1; i < group.size(); i++) {
            result += min(group[i - 1], group[i]);
        }
        
        return result;
    }
};  