#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> mp;
        
        // Bước 1: Ánh xạ số đầu tiên của mỗi mảng con đến chính nó
        for (const auto& piece : pieces) {
            mp[piece[0]] = piece;
        }

        // Bước 2: Duyệt arr để kiểm tra có thể ghép từ pieces không
        int i = 0;
        while (i < arr.size()) {
            if (mp.find(arr[i]) == mp.end()) return false; // Không tìm thấy mảng con phù hợp

            vector<int> piece = mp[arr[i]];
            for (int num : piece) {
                if (arr[i] != num) return false; // Nếu không khớp, trả về false
                i++;
            }
        }

        return true;
    }
};