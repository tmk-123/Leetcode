#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool found = false;
        string temp = num;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] <= change[num[i] - '0'] + '0') {
                while (i < num.size() && num[i] <= change[num[i] - '0'] + '0') {
                    cout << num[i] << " " << change[num[i] - '0'] << endl;
                    num[i] = change[num[i] - '0'] + '0';
                    i++;
                }
                if (temp != num) found = true;
                if (found) return num;
            }
        }
        return num;
    }
};