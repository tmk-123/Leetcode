#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in_degree(n, 0);
        
        // Đếm số lần mỗi đỉnh xuất hiện dưới dạng đỉnh đích (in-degree)
        for (auto& edge : edges) {
            in_degree[edge[1]]++;
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            // vì k chu trình nên = 0 là đc
            if (in_degree[i] == 0) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};