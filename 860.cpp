#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> money;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) money[5]++;
            else if (bills[i] == 10) {
                if (money[5] <= 0) return false;
                money[5]--;
                money[10]++;
            }
            else {
                // vì mọi tờ tiền đều đổi được ra 5 nên ưu tiên đổi đồng 10$ trước
                if (money[10] >= 1 && money[5] >= 1) {
                    money[10]--;
                    money[5]--;
                }
                else if (money[5] >= 3) {
                    money[5] -= 3;
                } 
                else return false;
            }
        }

        return true;
    }
};

int main() {
    int n;
    vector<int> bills;
    while (cin >> n) {
        bills.push_back(n);
    }

    Solution sol;
    cout << sol.lemonadeChange(bills);
}