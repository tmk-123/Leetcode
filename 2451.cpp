#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string oddString(vector<string>& words) {
            map<vector<int>,vector<string>> mp;
            for(auto c:words){
                vector<int> temp;
                for(int i=1;i<c.size();++i){
                    temp.push_back(c[i]-c[i-1]);
                }
                mp[temp].push_back(c);
            }
            
            for(auto [f,s]:mp){
                if(s.size()==1)return s[0];
            }

            return "";
        }
    };