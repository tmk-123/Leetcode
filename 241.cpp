#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // expression : biểu thức
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;

        for (int i = 0; i < expression.length(); i++) {
            int ch = expression[i];

            if (ch == '+' || ch == '-' || ch == '*') {
                string leftPart = expression.substr(0, i);
                string rightPart = expression.substr(i + 1);
                vector<int> left = diffWaysToCompute(leftPart);
                vector<int> right = diffWaysToCompute(rightPart);

                for (int l : left) {
                    for (int r : right) {
                        if (ch == '+') res.push_back(l + r);
                        else if (ch == '-') res.push_back(l - r);
                        else res.push_back(l * r);
                    }
                }
            }
        }

        if (res.empty()) res.push_back(stoi(expression));
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    vector<int> v = sol.diffWaysToCompute(s);

    for (int x : v) {
        cout << x << " ";
    }
}