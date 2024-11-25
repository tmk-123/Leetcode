#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;
        // dùng queue vì sử lý các trạng thái cùng cấp trước, stack phù hợp với đi sâu hơn
        queue<string> q;
        vector<string> res;
        bool found = false;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (isValid(current)) {
                res.push_back(current);
                found = true;
            }
            // nếu đã tìm thấy chuỗi hợp lệ thì không xét level sau, quay về lặp các phần tử cùng level xem thỏa mãn không
            if (found) continue;

            for (int i = 0; i < current.length(); i++) {
                if (current[i] != '(' && current[i] != ')') continue;
                string next = current.substr(0, i) + current.substr(i + 1);

                if (visited.find(next) == visited.end()) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }

        return res;
    }

    bool isValid(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') cnt++;
            else if (s[i] == ')') cnt--;

            if (cnt < 0) return false;
        }
        if (cnt == 0) return true;
        return false;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    vector<string> res = sol.removeInvalidParentheses(s);
    for (string str : res) {
        cout << str << endl;
    }
}