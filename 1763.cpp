#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2) return "";

        // đánh dấu từ A vì A < a, dùng long long bởi 26 chữ số thường và 26 chữ in hoa
        long long mask = 0;
        for (char c : s) mask |= (1LL << (c - 'A'));

        for (int i = 0; i < s.length(); i++) {
            
            // nếu s chứa cả c thường và c hoa thì bỏ qua, duyệt cả chuỗi bỏ qua hết thì return c
            if ( (mask & (1LL << (toupper(s[i]) - 'A'))) && (mask & (1LL << (tolower(s[i]) - 'A'))) ) continue;

            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));

            if (left.size() >= right.size()) return left;
            return right;
        }

        return s;
    }
};