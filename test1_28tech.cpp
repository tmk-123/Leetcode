#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define MAX 1000000

vector<int> v(MAX + 1);

void sang() {
	for (int i = 2; i <= MAX; i++) {
		if (v[i] == 0) {
			for (int j = i; j <= MAX; j += i) {
				if (v[j] == 0) {
					v[j] = i;
				}
			}
		}
	}
}
int main() {
	sang();
	int n;
	cin >> n;
	int number;
	unordered_map<int, int> freq;
	long long ans = 1;

	while (n--) {
		cin >> number;
		
		while (number > 1) {
			int x = v[number];
			int cnt = 0;
			while (number % x == 0 && number > 1) {
				number /= x;
				cnt++;
			}
			freq[x] += cnt;
		}
	}
	
	for (auto it : freq) {
		ans *= (it.second + 1);
		ans %= mod;
	}

	cout << ans;
}