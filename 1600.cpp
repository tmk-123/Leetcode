#include<bits/stdc++.h>

using namespace std;

class ThroneInheritance {
private:
    string king;
    unordered_map<string, vector<string>> children; // Danh sách con của mỗi người
    unordered_set<string> dead; // Tập hợp những người đã chết

    void dfs(string name, vector<string>& order) {
        if (dead.find(name) == dead.end()) // Nếu chưa chết thì thêm vào danh sách
            order.push_back(name);
        for (string& child : children[name]) // Duyệt qua danh sách con theo thứ tự
            dfs(child, order);
    }

public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }

    void birth(string parentName, string childName) {
        children[parentName].push_back(childName);
    }

    void death(string name) {
        dead.insert(name);
    }

    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(king, order);
        return order;
    }
};