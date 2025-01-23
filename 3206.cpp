#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int cnt = 0;
        int n = colors.size();
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[(i + 1) % n] && colors[(i + 1 ) % n] != colors[(i + 2) % n]) cnt++;
        }
        return cnt;
    }
};
int main() {
    vector<int> v ={0,1,0,0,1};
    Solution sol;
    cout << sol.numberOfAlternatingGroups(v);
}