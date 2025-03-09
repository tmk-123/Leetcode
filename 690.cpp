#include<bits/stdc++.h>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int dfs(int id, unordered_map<int, Employee*> m) {
        Employee* emp = m[id];
        int total = emp->importance;

        for (int idSub : emp->subordinates) {
            total += dfs(idSub, m);
        }

        return total;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;

        for (Employee* emp : employees) {
            m[emp->id] = emp;
        }
        return dfs(id, m);
    }
};