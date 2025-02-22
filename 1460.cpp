#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool canBeEqual(vector<int>& target, vector<int>& arr) {
            unordered_map<int, int> freq;
            for (int num : target) freq[num]++;
            
            for (int num : arr) {
                if (freq[num] == 0) return false; 
                freq[num]--;
            }
            
            return true;
        }
    };
    