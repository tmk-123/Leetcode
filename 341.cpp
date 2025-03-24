#include<bits/stdc++.h>

using namespace std;

class NestedInteger {
public:
    // Kiểm tra xem đối tượng này có phải số nguyên không
    bool isInteger() const;

    // Trả về số nguyên nếu đối tượng là số nguyên
    int getInteger() const;

    // Trả về danh sách lồng nhau nếu đối tượng là danh sách
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
private:
    stack<NestedInteger> stack;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            stack.push(nestedList[i]);
        }    
    }
    
    int next() {
        int res = stack.top().getInteger();
        stack.pop();
        return res;
    }
    
    bool hasNext() {
        while (!stack.empty()) {
            NestedInteger cur = stack.top();
            if (cur.isInteger()) return true;
            stack.pop();

            vector<NestedInteger> v = cur.getList();
            for (int i = v.size() - 1; i >= 0; i--) {
                stack.push(v[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */