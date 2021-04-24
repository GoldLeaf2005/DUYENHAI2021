#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef pair<int, int> ii;
typedef pair<int, ii> ipii;
typedef pair<int, vector<int>> pivi;

int n;
int capa1, capa2;
vector<ii> items;

struct hash_trio {
	size_t operator() (const pair<int, pair<int, int>> &p) const {
		auto hash1 = hash<int>{}(p.first);
		auto hash2 = hash<int>{}(p.second.first);
		auto hash3 = hash<int>{}(p.second.second);
		return hash1 ^ (hash2 ^ hash3);
	}
};

gp_hash_table<ipii, pivi, hash_trio> memo;
vector<int> blank;
pivi dp_double_knapsack(int i, int cap1, int cap2) {
	if (cap1 < 0 || cap2 < 0) {
		return pivi(INT_MIN, blank);
	}
	if (i == n) {
		return pivi(0, blank);
	}
	ipii t = make_pair(i, make_pair(cap1, cap2));
	auto it = memo.find(t);
	if (it != memo.end()) {
		return it->second;
	}
	pivi skip = dp_double_knapsack(i+1, cap1, cap2);
	pivi take1 = dp_double_knapsack(i+1, cap1 - items[i].first, cap2);
	pivi take2 = dp_double_knapsack(i+1, cap1, cap2 - items[i].first);
	take1.first += items[i].second;
	take2.first += items[i].second;
	int ans_fi = max(skip.first, max(take1.first, take2.first));
	pivi ans;
	ans.first = ans_fi;
	if (ans_fi == skip.first) {
		ans.second = skip.second;
		(ans.second).push_back(0);
	}
	else if (ans_fi == take1.first) {
		ans.second = take1.second;
		(ans.second).push_back(1);
	}
	else {
		ans.second = take2.second;
		(ans.second).push_back(2);
	}
	memo[t] = ans;
	return ans;
}

void show_vi(vector<int> &v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << "\n";
}

void show_vi_r(vector<int> &v) {
	int n = v.size();
	for (int i = n-1; i >= 0; --i) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

signed main(void) {
	// freopen("KNAPSACK.INP", "r", stdin);
	// freopen("KNAPSACK.OUT", "w", stdout);
	cin >> n >> capa1 >> capa2;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		items.push_back(make_pair(a, b));
	}
	pivi ans = dp_double_knapsack(0, capa1, capa2);
	show_vi_r(ans.second);
	return 0;
}