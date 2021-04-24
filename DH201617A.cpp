#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define watch(x) cout << (#x) << " = " << (x) << "; "

int n;
vector<int> line, line_clone, pos;
vector<bool> visited;
int ranking = 0;
gp_hash_table<int, int> sortrank;

vector<int> dfs(int v) {
	vector<int> ans;
	while (!visited[v]) {
		// watch(v);
		ans.push_back(v);
		visited[v] = true;
		v = line[v];
	}
	return ans;
}

void solve(void) {
	visited.assign(n, false);
	for (int i = 0; i < n; ++i) {
		if (!visited[i] && line_clone[i] != line[i]) {
			vector<int> vc = dfs(i);
			int k = vc.size();
			for (int i = 0; i < k-1; ++i) {
				cout << pos[vc[i]]+1 << " " << pos[vc[i+1]]+1 << "\n";
				swap(pos[vc[i]], pos[vc[i+1]]);
			}
		}
	}
}

signed main(void) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; line.push_back(x);
	}
	line_clone = line; // O(n)
	sort(line_clone.begin(), line_clone.end()); // O(nlogn)
	for (auto i : line_clone) { // O(n)
		if (sortrank.find(i) == sortrank.end()) {
			sortrank[i] = ranking;
			ranking++;
		}
	}
	for (int i = 0; i < n; ++i) {
		line[i] = sortrank[line[i]]; // O(n)
	}
	for (int i = 0; i < n; ++i) {
		line_clone[i] = sortrank[line_clone[i]];
	}
	// total time up until now: O(n(3 + logn))
	// // so proportional to O(n)?
	for (auto i : line_clone) {
		cout << i << " ";
	}
	cout << "\n";
	for (auto i : line) {
		cout << i << " ";
	}
	cout << "\n";
	pos.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		pos[line[i]] = i;
	}
	solve();
}