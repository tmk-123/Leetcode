#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string curString = "";
        int curNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                curNum = curNum * 10 + c - '0';
            }
            else if (c == '[') {
                numStack.push(curNum);
                strStack.push(curString);
                curNum = 0;
                curString = "";
            }
            else if (c == ']') {
                int num = numStack.top();
                string prevString = strStack.top();
                numStack.pop();
                strStack.pop();

                string temp = "";
                while (num--) {
                    temp += curString;
                }
                curString = prevString + temp;
            }
            else curString += c;
        }

        return curString;
    }
};

int main () {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.decodeString(s);
}