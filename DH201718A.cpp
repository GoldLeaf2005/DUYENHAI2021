#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define watch(x) cout << (#x) << " = " << (x) << "; "

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

set<int> results;
vector<int> v1, v2, q;

void show_arr(vector<int> v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << "\n";
}

int rmin, rmax;

signed main(void) {
	freopen("DH1718A_tg.out", "r", stdin);
	// freopen("SEQGAME.out", "w", stdout);
	int n1, n2, queries;
	cin >> n1 >> n2 >> queries;
	for (int i = 0; i < n1; ++i) {
		int x; cin >> x;
		v1.push_back(x);
	}
	for (int j = 0; j < n2; ++j) {
		int x; cin >> x;
		v2.push_back(x);
	}
	for (int a = 0; a < queries; ++a) {
		int x; cin >> x;
		q.push_back(x);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	// show_arr(v1);
	// show_arr(v2);

	rmin = v1[0] + v2[0], rmax = (*v1.rbegin()) + (*v2.rbegin());

	int ans;
	if (n1 > n2) {
		v1.swap(v2);
		swap(n1, n2);
	}
	for (auto x : q) {
		if (x <= rmin) {
			ans = rmin - x;
			cout << ans << "\n";
		}
		else if (x >= rmax) {
			ans = x - rmax;
			cout << ans << "\n";
		}
		else {
			int cans = INT_MAX;
			for (auto i : v1) {
				int k = x - i;
				// watch(x - i);
				auto it = lower_bound(v2.begin(), v2.end(), k);
				ans = *it - k;
				if (*it > k) {
					int pos = it - v2.begin();
					if (pos > 0) {
						ans = min(abs(v2[pos-1] - k), v2[pos] - k);
					}
					else {
						ans = v2[pos] - k;
					}
				}
				if (cans > ans) {
					cans = ans;
				}
			}
			cout << cans << "\n";
		}
	}
}