#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> degree;
        queue<string> q;
        vector<string> res;

        for (int i = 0; i < recipes.size(); i++) {
            for (string& s : ingredients[i]) {
                graph[s].push_back(recipes[i]);
                degree[recipes[i]]++;
            }
        }

        for (string& s : supplies) q.push(s);

        while (!q.empty()) {
            string u = q.front(); q.pop();

            for (string& recipe : graph[u]) {
                if (--degree[recipe] == 0) {
                    res.push_back(recipe);
                    q.push(recipe);
                }
            }
        }

        return res;
    }
};