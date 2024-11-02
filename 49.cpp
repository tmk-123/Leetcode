#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs){
            string word = s;
            sort(word.begin(), word.end());
            mp[word].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto x : mp) {
            // push cả mảng string một chiều
            ans.push_back(x.second);
        }
        return ans;
    }
};

int main () {
    vector<string> v;
    string s;
    while (cin >> s){
        v.push_back(s);
    }

    Solution sol;
    vector<vector<string>> res = sol.groupAnagrams(v);

    for (auto x : res) {
        for (auto string : x) {
            cout << string << " ";
        }
        cout << endl;
    }
}