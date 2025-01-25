#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;

        for (string s : arr) {
            freq[s]++;
        }      

        for (string s : arr) {
            if (freq[s] == 1) {
                k--;
                if (k == 0) return s;
            }
        }
        
        return "";
    }
};
int main() {
    vector<string> v = {"d","b","c","b","c","a"};
    Solution sol;
    cout << sol.kthDistinct(v, 2);
}