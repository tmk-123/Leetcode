#include<bits/stdc++.h>

using namespace std;

struct athlete {
    int value;
    int index;
    string rank;
};

bool compare1(athlete a, athlete b) {
    return a.value > b.value;
}
bool compare2(athlete a ,athlete b) {
    return a.index < b.index;
}
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<athlete> v;
        for (int i = 0; i < score.size(); i++) {
            v.push_back({score[i], i});
        }
        sort(v.begin(), v.end(), compare1);
        for (int i = 0; i < score.size(); i++) {
            if (i == 0) v[i].rank = "Gold Medal";
            else if (i == 1) v[i].rank = "Silver Medal";
            else if (i == 2) v[i].rank = "Bronze Medal";
            else v[i].rank = to_string(i + 1);
        }

        sort(v.begin(), v.end(), compare2);
        vector<string> res;
        for (int i = 0; i < v.size(); i++) {
            res.push_back(v[i].rank);
        }
        return res;
    }
};  
  
int main() {
    vector<int> v = {10, 3, 8, 9, 4};
    Solution sol;
    vector<string> res = sol.findRelativeRanks(v);
    for (string x : res) {
        cout << x << " ";
    }
}