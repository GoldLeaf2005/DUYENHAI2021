#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef pair<int, int> ii;
typedef pair<int, ii> ipii;
int n;
vector<ii> items;
int capa1, capa2;

struct hash_trio {
	size_t operator() (const pair<int, pair<int, int>> &p) const {
		auto hash1 = hash<int>{}(p.first);
		auto hash2 = hash<int>{}(p.second.first);
		auto hash3 = hash<int>{}(p.second.second);
		return hash1 ^ (hash2 ^ hash3);
	}
};

gp_hash_table<ipii, int, hash_trio> memo;
int dp_double_knapsack(int i, int cap1, int cap2) {
	if (cap1 < 0 || cap2 < 0) {
		return INT_MIN;
	}
	if (i == n) {
		return 0;
	}
	ipii t = make_pair(i, make_pair(cap1, cap2));
	auto it = memo.find(t);
	if (it != memo.end()) {
		return it->second;
	}
	int skip = dp_double_knapsack(i+1, cap1, cap2);
	int take1 = dp_double_knapsack(i+1, cap1 - items[i].first, cap2) + items[i].second;
	int take2 = dp_double_knapsack(i+1, cap1, cap2 - items[i].first) + items[i].second;
	int ans = max(skip, max(take1, take2));
	memo[t] = ans;
	return ans;
}

signed main(void) {
	cin >> n >> capa1 >> capa2;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		items.push_back(make_pair(a, b));
	}
	int ans = dp_double_knapsack(0, capa1, capa2);
	cout << ans << "\n";
	return 0;
}