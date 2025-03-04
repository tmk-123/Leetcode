#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int total_lines = 1, cur_width = 0; 

        for (char c : s) {  
            int w = widths[c - 'a'];  
            
            if (cur_width + w > 100) {  
                total_lines++; 
                cur_width = 0;  
            }

            cur_width += w;  
        }

        return {total_lines, cur_width};  
    }
};