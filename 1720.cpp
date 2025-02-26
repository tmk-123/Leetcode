#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> arr;
        arr.push_back(first);
        
        // a ^ b = c -> a ^ c = b
        for (int i = 0; i < encoded.size(); i++) {
            arr.push_back(arr[i] ^ encoded[i]);
        }
        return arr;
    }
};
