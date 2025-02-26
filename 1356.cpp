#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
class Solution {
public:
    int countBit(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> v;
        for (int i = 0; i < arr.size(); i++) {
            v.push_back({arr[i], countBit(arr[i])});
        }

        sort(v.begin(), v.end(), compare);
        vector<int> res;
        for (int i = 0; i < arr.size(); i++) {
            res.push_back(v[i].first);
        }
        return res;
    }
};  

int main() {
    vector<int> v = {1024,512,256,128,64,32,16,8,4,2,1};
    Solution sol;
    vector<int> res = sol.sortByBits(v);
    for (int x : res) {
        cout << x << " ";
    }
}