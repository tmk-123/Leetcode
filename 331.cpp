#include<bits/stdc++.h>

using namespace std;

// preorder traversal : duyệt các node theo thứ tự trước

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slot = 1; // node gốc chiếm 1 slot, node # không sinh ra slot mới, còn lại sinh ra 2
        stringstream ss(preorder);
        string node;

        while (getline(ss, node, ',')) {
            slot--;
            if (slot < 0) return false;
            if (node != "#") slot += 2; 
        }
        return slot == 0;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.isValidSerialization(s);
}