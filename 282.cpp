#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) { 
        vector<string> res;
        backtrack(num, target, 0, 0, 0, "", res);
        return res;
    }

    void backtrack(string& num, int target, int index, long long currentValue, long long lastOperand, string expression, vector<string>& res) {
        if (index == num.size()) {
            if (currentValue == target) {
                res.push_back(expression);
            }
            return;
        }
        
        for (int i = index; i < num.size(); i++) {
            string part = num.substr(index, i - index + 1);
            if (part[0] == '0' && part.length() > 1) break;
            long long currentNum = stoll(part);

            // nếu đó là số đầu tiên
            if (index == 0) {
                backtrack(num, target, i + 1, currentNum, currentNum, part, res);
            }
            else {
                backtrack(num, target, i + 1, currentValue + currentNum, currentNum, expression + "+" + part, res);
                backtrack(num, target, i + 1, currentValue - currentNum, -currentNum, expression + "-" + part, res);

                // nếu trước đó lastoperand là trừ thì trừ trừ thành cộng, sau đó cộng tích, tương tự với trước đó cộng lastoperand
                backtrack(num, target, i + 1, currentValue - lastOperand + lastOperand * currentNum, lastOperand * currentNum, expression + "*" + part, res);
            }
        }
    }
};

int main() {
    string num;
    int target;
    cin >> num >> target;
    Solution sol;
    vector<string> res = sol.addOperators(num, target);
    for (string s : res) {
        cout << s << endl;
    }
}