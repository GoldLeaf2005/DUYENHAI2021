#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

static random_device rd;
static mt19937 rng{rd()};

int dice(int low, int high) {
	static uniform_int_distribution<int> uid(low, high);
	return uid(rng);
}

signed main(void) {
	freopen("DH1718A_tg.out", "w", stdout);
	int m = 1e5, n = 1e5, k = 500;
	cout << m << " " << n << " " << k << "\n";
	for (int i = 1; i <= m; ++i) {
		cout << i << " ";
	}
	cout << "\n";
	for (int i = 1; i <= n; ++i) {
		cout << i << " ";
	}
	cout << "\n";
	for (int i = 0; i < k; ++i) {
		cout << dice(-10500, 20500) << " ";
	}
	cout << "\n";
}