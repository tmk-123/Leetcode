#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // g is greedy, s is size
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int  cnt = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                cnt++;
                i++;
            }
            j++; // duyệt bánh tiếp theo
        }
        return cnt;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> g(n), s(m);
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++) cin >> s[i];

    Solution sol;
    cout << sol.findContentChildren(g, s);
}