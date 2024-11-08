#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> last_occurrence; // vị trí xuất hiện cuối cùng của từng chữ cái; 
        unordered_set<char> in_stack; // để xem các ký tự trong stack xuất hiện chưa vì stack không find được
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            last_occurrence[s[i]] = i; 
        }

        for (int i = 0; i < s.length(); i++) {
            char current = s[i];

            if (in_stack.find(current) != in_stack.end()) {
                continue;
            }
            // Loại bỏ ký tự lớn hơn hiện tại trong stack nếu chúng sẽ xuất hiện lại sau này (chưa phải last_occurrence)
            while (!st.empty() && st.top() > current && last_occurrence[st.top()] > i) {
                in_stack.erase(st.top());
                st.pop();
            }

            st.push(current);
            in_stack.insert(current);
        }

        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.removeDuplicateLetters(s);
}