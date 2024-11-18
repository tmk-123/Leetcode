#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n, 0);
        ugly[0] = 1;
        int k = primes.size();
        vector<int> indices(k, 0); // chỉ số từng số nguyên tố
        vector<long long> nextMultiple(k, 0);

        for (int i = 0; i < k; i++) {
            nextMultiple[i] = primes[i];
        }

        for (int i = 1; i < n; i++) {
            long long nextUgly = *min_element(nextMultiple.begin(), nextMultiple.end());
            ugly[i] = (int)nextUgly;

            for (int j = 0; j < k; j++) {
                if (nextUgly == nextMultiple[j]) {
                    indices[j]++;
                    nextMultiple[j] = (long long)primes[j] * ugly[indices[j]];
                }
            }
        }

        return ugly[n - 1];
    }
};
int main() {
    int n;
    cin >> n;
    int x;
    vector<int> primes;
    while (cin >> x) {
        primes.push_back(x);
    }

    Solution sol;
    cout << sol.nthSuperUglyNumber(n, primes);
}