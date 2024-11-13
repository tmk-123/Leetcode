#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        int currentGas = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];

            // Nếu xăng âm, không thể bắt đầu từ các trạm trước đó, thử bắt đầu từ trạm tiếp theo
            if (currentGas < 0) {
                start = i + 1;
                currentGas = 0;
            }
        }

        if (totalGas < totalCost) return -1;
        return start;
    }

};

int main() {
    int n;
    cin >> n;
    vector<int> gas(n);
    vector<int> cost(n);

    for (int i = 0; i < n; i++) cin >> gas[i];
    for (int i = 0; i < n; i++) cin >> cost[i];

    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost);
}