#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> Set;
        for (int n : nums) {
            if (n > 0) Set.insert(n);
        }
        return Set.size();
    }
};
  
int main() {
    vector<int> v ={0};
    Solution sol;
    cout << sol.minimumOperations(v);
}