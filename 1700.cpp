#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int count0 = 0, count1 = 0;

        for (int& s : students) {
            q.push(s);
            if (s == 0) count0++;
            else count1++;
        }

        for (int& s : sandwiches) {
            if (s == 0 && count0 == 0) return count1;
            if (s == 1 && count1 == 0) return count0;

            while (q.front() != s) {
                q.push(q.front());
                q.pop();
            }
            q.pop();

            if (s == 0) count0--;
            else count1--;
        }

        return 0;
    }
};