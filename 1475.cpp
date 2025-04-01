#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        stack<int> st;
        vector<int> res(n);
        int i = n - 1;

        while (i >= 0) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            
            if (st.empty()) res[i] = prices[i];
            else res[i] = prices[i] - st.top();

            st.push(prices[i]);
            i--;
        }

        return res;
    }
};

int main() {
    vector<int> v = {10, 1, 1, 6};
    Solution sol;
    vector<int> res = sol.finalPrices(v);
    for (int x : res) {
        cout << x << " ";
    }
}