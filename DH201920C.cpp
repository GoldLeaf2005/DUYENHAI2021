#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define mp make_pair
#define fi first
#define se second
#define pb push_back

vector<vector<int>> AdjMatrix;
int cities, query_num;
int pos[3] = {0, 1, 2};
int ans = 0;
vector<int> queries;

typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;

struct hash_quad {
	size_t operator() (const iiii &p) const {
		auto hash1 = hash<int>{}(p.first.first);
		auto hash2 = hash<int>{}(p.first.second);
		auto hash3 = hash<int>{}(p.second.first);
		auto hash4 = hash<int>{}(p.second.second);
		return hash1 ^ hash2 ^ hash3 ^ hash4;
	}
};

gp_hash_table<iiii, int, hash_quad> memo;

int dp_solve(int i, int pos1, int pos2, int pos3) {
	if (pos1 == pos2 || pos2 == pos3 || pos3 == pos1) {
		return 99999999;
	}
	if (i == query_num) {
		return 0;
	}
	iiii p = mp(mp(i, pos1), mp(pos2, pos3));
	auto it = memo.find(p);
	if (it != memo.end()) {
		return it->second;
	}
	int move1 = dp_solve(i+1, queries[i]-1, pos2, pos3) + AdjMatrix[pos1][queries[i]-1];
	int move2 = dp_solve(i+1, pos1, queries[i]-1, pos3) + AdjMatrix[pos2][queries[i]-1];
	int move3 = dp_solve(i+1, pos1, pos2, queries[i]-1) + AdjMatrix[pos3][queries[i]-1];
	int ans = min(move1, min(move2, move3));
	memo[p] = ans;
	return ans;
}

signed main(void) {
	cin >> cities >> query_num;
	AdjMatrix.assign(cities, vector<int>(cities, 0));
	for (int i = 0; i < cities; ++i) {
		for (int j = 0; j < cities; ++j) {
			cin >> AdjMatrix[i][j];
		}
	}
	queries.assign(query_num, 0);
	for (int q = 0; q < query_num; ++q) {
		cin >> queries[q];
	}
	int ans = dp_solve(0, 0, 1, 2);
	cout << ans << "\n";
}