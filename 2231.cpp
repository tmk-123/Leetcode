#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        vector<int> digits;
        int temp = num;
        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        reverse(digits.begin(), digits.end());

        priority_queue<int> odd;
        priority_queue<int> even;

        for (int d : digits) {
            if (d % 2 == 0) even.push(d);
            else odd.push(d);
        }

        vector<int> res;
        for (int d : digits) {
            if (d % 2 == 0) {
                res.push_back(even.top());
                even.pop();
            }
            else {
                res.push_back(odd.top());
                odd.pop();
            }
        }

        int largestSum = 0;
        for (int d : res) {
            largestSum = largestSum * 10 + d;
        }
        return largestSum;
    }
};
  
int main() {
    Solution sol;
    cout << sol.largestInteger(1234);
}