#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTimeToType(string word) {
        int total_time = 0;
        char current = 'a';  // Con trỏ bắt đầu từ 'a'

        for (char target : word) {
            int clockwise = (target - current + 26) % 26;
            int counterclockwise = (current - target + 26) % 26;
            total_time += min(clockwise, counterclockwise) + 1; // Thời gian di chuyển + gõ ký tự
            current = target;  // Cập nhật vị trí hiện tại
        }

        return total_time;
    }
};