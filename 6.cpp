#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;

        int index = 0;
        int d = 1; // hướng di chuyển: 1 là lên; -1 là xuống
        vector<vector<char>> rows(numRows); // mảng 2 chiều lưu ký tự theo hàng

        for (char c : s){
            rows[index].push_back(c);

            if (index == 0){
                d = 1;
            }
            else if (index == numRows - 1){
                d = -1;
            }

            index += d;
        }

        string res;
        for (auto row : rows){
            for (auto c : row){
                res.push_back(c);
            }
        }

        return res;
    }
};

int main() {
    string s;
    int n;
    cin >> s >> n;
    
    Solution sol;
    cout << sol.convert(s, n);
}