#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (string& s : operations) {
            if (s == "D") {
                st.push(st.top() * 2);
            }
            else if (s == "C") {
                if (!st.empty()) st.pop();
            }
            else if (s == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
            }
            else {
                st.push(stoi(s));
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};