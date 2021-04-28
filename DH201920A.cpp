#include <bits/stdc++.h>
using namespace std;

int subtask;
string numstr;

int bars[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int more[] = {1, 5, 1, 2, 2, 3, 1, 2, 0, 0};
int all[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int solve1(string &str) {
	int ans = 0;
	for (auto c : str) {
		ans += bars[(c - '0')];
	}
	return ans;
}

int solve2(string &str) {
	int ans = 0;
	int n = str.length();
	for (int i = 0; i < n; ++i) {
		int plus = more[str[i]-'0'];
		for (int j = i+1; j < n; ++j) {
			plus *= all[str[j]-'0'];
		}
		ans += plus;
	}
	return ans;
}

signed main(void) {
	cin >> subtask >> numstr;
	if (subtask == 1) {
		int ans1 = solve1(numstr);
		cout << ans1 << "\n";
		return 0;
	}
	int ans2 = solve2(numstr);
	cout << ans2 << "\n";
}