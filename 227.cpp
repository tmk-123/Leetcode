#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int current_num = 0;
        char last_operator = '+'; // bắt đầu với phép cộng
        s += "+"; // để xử lý phép toán cuối cùng

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                current_num = current_num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
                if (last_operator == '+') {
                    stk.push(current_num);
                }
                else if (last_operator == '-') {
                    stk.push(-current_num);
                }
                else if (last_operator == '*') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top * current_num);
                }
                else if (last_operator == '/') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top / current_num);
                }

                current_num = 0;
                last_operator = c;
            }
        }

        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }

        return res;
    }
};

int main() {
    string s;
    getline(cin, s);

    Solution sol;
    cout << sol.calculate(s);
}