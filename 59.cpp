#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cnt = 1;
        vector<vector<int>> res(n, vector<int>(n));
        int h1 = 0, c1 = 0, h2 = n - 1, c2 = n - 1;
        
        while (h1 <= h2 && c1 <= c2) {
            for (int i = c1; i <= c2; i++) {
                res[h1][i] = cnt++;
            }
            h1++;

            for (int i = h1; i <= h2; i++) {
                res[i][c2] = cnt++;
            }
            c2--;

            if (h1 <= h2) {
                for (int i = c2; i >= c1; i--) {
                    res[h2][i] = cnt++;
                }
            }
            h2--;

            if (c1 <= c2) {
                for (int i = h2; i >= h1; i--) {
                    res[i][c1] = cnt++;
                }
            }
            c1++;
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    vector<vector<int>> res = sol.generateMatrix(n);
    for (auto x : res) {
        for (int y : x) {
            cout << y << " ";
        } 
        cout << endl;
    }
}