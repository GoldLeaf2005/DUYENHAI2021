#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

int n, mweight;
vector<pair<int, int>> items;

// int knapsack1(int i, int capacity) {
// 	if (capacity < 0) {
// 		return INT_MIN;
// 	}
// 	if (i == n) {
// 		return 0;
// 	}
// 	return 	max(knapsack1(i+1, capacity),
// 				knapsack1(i+1, capacity - items[i].first) + items[i].second); // <weight, gain>
// }

// vector<vector<int>> memo;
// int dp_knapsack(int i, int cap) {
// 	if (cap < 0) {
// 		return INT_MIN;
// 	}
// 	if (i == n) {
// 		return 0;
// 	}
// 	if (memo[i][cap] > -1) {
// 		return memo[i][cap];
// 	}
// 	int skip = dp_knapsack(i+1, cap);
// 	int take = items[i].second + dp_knapsack(i+1, cap - items[i].first);
// 	memo[i][cap] = max(skip, take);
// 	return memo[i][cap];
// }

// vector<int> sample;

struct hash_pair {
	template <class T1, class T2>
	size_t operator() (const pair<T1, T2> &p) const {
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		return hash1 ^ hash2;
	}
};

gp_hash_table<pair<int, int>, int, hash_pair> memo;
int dp_knapsack2(int i, int cap) {
	if (cap < 0) {
		return INT_MIN;
	}
	if (i == n) {
		return 0;
	}
	pair<int, int> p = make_pair(i, cap);
	auto it = memo.find(p);
	if (it != memo.end()) {
		return it->second;
	}
	int skip = dp_knapsack2(i+1, cap);
	int take = dp_knapsack2(i+1, cap - items[i].first) + items[i].second;
	int res = max(skip, take);
	memo[p] = res;
	return res;
}

signed main(void) {
	cin >> n >> mweight;
	// sample.assign(mweight+1, -1);
	// memo.assign(n, sample);
	for (int i = 0; i < n; ++i) {
		int w, g; cin >> w >> g;
		items.push_back(make_pair(w, g));
	}
	int ans = dp_knapsack2(0, mweight);
	cout << ans << "\n";
}