#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unorderset có thứ tự ngẫu nhiên nên mỗi lần chèn hay xóa sẽ xử lý nhanh hơn set khi phải sắp xếp lại thứ tự
        unordered_set<char> chars;
        // dùng hai con trỏ để duyệt
        int left = 0, right = 0, maxLength = 0;

        while (right < s.length()) {
            // nếu s[right] chưa tồn tại trong set thì trả về chars.end()
            if (chars.find(s[right]) == chars.end()){
                chars.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            }
            else {
                // nếu trùng thì loại bỏ ký tự bên trái, tăng left. nếu không trùng thì thêm
                // vào set và tăng right
                // chú ý xóa bên trái chứ không phải xóa trùng
                chars.erase(s[left]); 
                left++;
            }
        }
        return maxLength;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.lengthOfLongestSubstring(s);
}