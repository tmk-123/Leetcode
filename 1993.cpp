#include<bits/stdc++.h>

using namespace std;

class LockingTree {
private:
    vector<int> parent;
    vector<int> locked; 
    vector<vector<int>> children; 

public:
    LockingTree(vector<int>& parent) : parent(parent), locked(parent.size(), -1), children(parent.size()) {
        for (int i = 1; i < parent.size(); i++) {
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (locked[num] == -1) {
            locked[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if (locked[num] == user) {
            locked[num] = -1;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if (locked[num] != -1) return false;
        if (hasLockedAncentor(num)) return false;
        if (!hasLockedDescendant(num)) return false;

        unlockDescendants(num);
        locked[num] = user;
        return true;
    }

    bool hasLockedAncentor(int num) {
        while (parent[num] != -1) {
            if (locked[parent[num]] != -1) return true;
            num = parent[num];
        }
        return false;
    }

    bool hasLockedDescendant(int num) {
        for (int& child : children[num]) {
            if (locked[child] != -1 || hasLockedDescendant(child)) return true;
        }
        return false;
    }

    void unlockDescendants(int num) {
        for (int child : children[num]) {
            unlockDescendants(child);
            locked[child] = -1;
        }
    }
};