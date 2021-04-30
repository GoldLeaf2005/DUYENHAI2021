#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
int maxIslands = 1, numIslands = 1;
int n;

signed main(void) {
	cin >> n;
	vector<ii> planks;
	vector<bool> under(n, false);
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		planks.push_back(make_pair(x, i));
	}
	sort(planks.begin(), planks.end());
	for (auto pi : planks) {
		under[pi.second] = true;
		int k = pi.second;
		if ((k == 0 && under[k+1]) || (k == n-1 && under[k-1])) {
			numIslands--;
		}
		else if (1 <= k && k <= n-2) {
			if (!under[k-1] && !under[k+1]) {
				numIslands++;
			}
			else if (under[k-1] && under[k+1]) {
				numIslands--;
			}
		}

		if (maxIslands < numIslands) {
			maxIslands = numIslands;
		}
	}
	cout << maxIslands << "\n";
}