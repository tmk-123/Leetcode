#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int cnt = 0;
        for (int i = 0; i < seats.size(); i++) {
            cnt += abs(seats[i] - students[i]);
        }

        return cnt;
    }
};

int main() {
    vector<int> a = {3, 1, 5};
    vector<int> b = {2, 7, 4};
    Solution sol;
    cout << sol.minMovesToSeat(a, b);
}