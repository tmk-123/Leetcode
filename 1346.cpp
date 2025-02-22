#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0 && binary_search(arr.begin(), arr.end(), arr[i] * 2)) return true;
            if (i < arr.size() - 1 && arr[i] == 0 && arr[i + 1] == 0) return true;
        }
        return false;
    }
};

int main() {
    vector<int> v = {-2,0,10,-19,4,6,-8};
    Solution sol;
    cout << sol.checkIfExist(v);
}