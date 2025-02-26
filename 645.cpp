#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int XorAll = 0;

        // khi Xor tất cả phần tử và từ 1 đến n thì 
        // các phần tử đều xuất hiện 2 lần nên Xor = 0 
        // trừ phần tử lặp lại xuất hiện 3 lần và phần tử
        // bị thiếu 1 lặp 1 lần. nên XorAll = a ^ b với a, b là 2 số trên
        for (int num : nums) XorAll ^= num;
        for (int i = 1; i <= nums.size(); i++) XorAll ^= i;

        // XorAll & -XorAll sẽ tìm ra bit LSB, là bit nhỏ nhất = 1 của a ^ b
        // bằng 1 tức là tại bit đấy a, b khác nhau nên thành 2 nhóm, 
        // 1 nhóm có a, 1 nhóm có b
        int bitmask = XorAll & -XorAll;

        int a = 0, b = 0;
        for (int num : nums) {
            if (num & bitmask) a ^= num;
            else b ^= num;
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (i & bitmask) a ^= i;
            else b ^= i;
        } 

        for (int num : nums) {
            if (num == a) return {a, b};
        }
        return {b, a};
    }
};