#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;

        while (left < right) {
            int mid = (left + right) / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }

        return left;
    }

    // The API isBadVersion is defined for you.
    bool isBadVersion(int version);
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.firstBadVersion(n);
}