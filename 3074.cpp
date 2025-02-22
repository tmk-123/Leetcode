#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(apple.rbegin(), apple.rend());
        sort(capacity.rbegin(), capacity.rend());

        int j = 0;
        for (int i = 0; i < apple.size(); i++) {
            if (j < capacity.size()) {
                while (j < capacity.size() && apple[i] > capacity[j]) {
                    apple[i] -= capacity[j++];
                }

                if (apple[i] > 0 && j < capacity.size()) capacity[j] -= apple[i];
            }
        }

        return j + 1;
    }
};

int main() {
    vector<int> a = {5, 5, 5};
    vector<int> b = {2, 4, 7, 2};
    Solution sol;
    cout << sol.minimumBoxes(a, b);
}