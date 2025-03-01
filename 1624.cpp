#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> firstPos;
        int maxLen = -1;

        // Duyệt qua chuỗi để lưu vị trí xuất hiện đầu tiên của mỗi ký tự
        for (int i = 0; i < s.length(); i++) {
            if (firstPos.find(s[i]) == firstPos.end()) {
                firstPos[s[i]] = i;  // Lưu vị trí đầu tiên
            } else {
                maxLen = max(maxLen, i - firstPos[s[i]] - 1); // Khoảng cách giữa hai vị trí
            }
        }

        return maxLen;
    }
};