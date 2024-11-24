#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd_sum = 0, even_sum = 0;
        for (int i = 0; i < position.size(); i++) {
            if (position[i] % 2 == 0) even_sum ++;
            else odd_sum++;
        }

        return min(odd_sum, even_sum);
    }
};

int main() {
    int n;
    vector<int> position;
    while (cin >> n) {
        position.push_back(n);
    }
    Solution sol;
    cout << sol.minCostToMoveChips(position);
}