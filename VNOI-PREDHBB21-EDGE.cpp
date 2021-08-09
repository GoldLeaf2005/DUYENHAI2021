#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<vector<int>> AdjList;
vector<bool> visited;
vector<int> time_in, low;
vector<int> subtree_size;

int timer;
int bridges;
vector<pair<int, int>> bridge_nodes;

void dfs(int u, int par = -1) {
	visited[u] = true;
	time_in[u] = low[u] = timer;
	timer++;
	subtree_size[u] = 1;
	for (int v : AdjList[u]) {
		if (v == par) {
			continue;
		}
		if (visited[v]) {
			low[u] = min(low[u], time_in[v]);
		}
		else {
			dfs(v, u);
			subtree_size[u] += subtree_size[v];
			low[u] = min(low[u], low[v]);
			if (low[v] > time_in[u]) {
				bridge_nodes.push_back(make_pair(subtree_size[v], n - subtree_size[v]));
				bridges++;
			}
		}
	}
}

void find_bridges(void) {
	timer = 0;
	visited.assign(n, false);
	time_in.assign(n, -1);
	subtree_size.assign(n, 0);
	low.assign(n, -1);
	bridges = 0;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}

void dfs_basic(int u) {
	visited[u] = true;
	for (auto v : AdjList[u]) {
		if (!visited[v]) {
			dfs_basic(v);
		}
	}
}

int L, R;
int num_cc(void) {
	visited.assign(n, false);
	L = -1, R = -1;
	int numCC = 0;
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			numCC++;
			dfs_basic(i);
			if (L < 0 && R < 0) {
				R = count(visited.begin(), visited.end(), false);
				L = n - R;
			}
		}
	}
	if (numCC != 2) {
		L = -1, R = -1;
	}
	return numCC;
}

signed main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	AdjList.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
	}
	int numCC = num_cc();
	find_bridges();
	int ans;
	if (numCC > 2) {
		ans = 0;
		cout << ans << "\n";
		return 0;
	}
	if (numCC == 2) {
		ans = L * R * (m - bridges);
		cout << ans << "\n";
		return 0;
	}
	if (numCC == 1) {
		ans = (((n * (n - 1)) >> 1) - m) * (m - bridges);
		for (auto p : bridge_nodes) {
			ans += (p.first * p.second - 1);
		}
		cout << ans << "\n";
		return 0;
	}
	return 0;
}