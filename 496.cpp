#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> st;
        for (int n : nums2) {
            while (!st.empty() && st.top() < n) {
                m[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }

        while (!st.empty()) {
            m[st.top()] = -1;
            st.pop();
        }

        vector<int> res;
        for (int n : nums1) {
            res.push_back(m[n]);
        }
        return res;
    }
};