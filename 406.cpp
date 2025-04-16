#include<bits/stdc++.h>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    if (a[0] != b[0]) return a[0] > b[0];
    return a[1] < b[1];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> res;
        for(auto& person : people) {
            res.insert(res.begin() + person[1], person);
        }
        return res;
    }
};