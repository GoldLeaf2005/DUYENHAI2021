#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

int nth_lucky_number(int n) {
	vector<int> nth_number(n+1);
	nth_number[1] = 4, nth_number[2] = 7;
	for (int i = 3; i <= n; ++i) {
		if (i & 1) {
			nth_number[i] = (nth_number[i>>1] * 10) + 4;
		}
		else {
			nth_number[i] = (nth_number[(i>>1)-1] * 10) + 7;
		}
	}
	return nth_number[n];
}

signed main(void) {
	cin >> n;
	cout << nth_lucky_number(n) << "\n";
}