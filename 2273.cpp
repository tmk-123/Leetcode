#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isAnagram(string a, string b) {
            if (a.size() != b.size()) return false;
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            return a == b;
        }
    
        vector<string> removeAnagrams(vector<string>& words) {
            stack<string> st; 
            
            for (string word : words) {
                if (!st.empty() && isAnagram(st.top(), word)) {
                    continue; 
                }
                st.push(word);
            }
    
            vector<string> result;
            while (!st.empty()) {
                result.push_back(st.top());
                st.pop();
            }
            reverse(result.begin(), result.end()); 
            return result;
        }
    };
    
