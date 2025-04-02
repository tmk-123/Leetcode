#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        st.push(n);
        int op = 0; // op: 0(*), 1(/), 2(+), 3(-)
        
        while (--n) {
            if (op == 0) {
                int top = st.top();
                st.pop();
                st.push(n * top);
            }
            else if (op == 1) {
                int top = st.top();
                st.pop();
                st.push(top / n);
            }
            else if (op == 2) {
                st.push(n);
            }
            else st.push(-n);

            op = (op + 1) % 4;
        }
        
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};