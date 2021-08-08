#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> ii;
vector<ii> stage(3);

void merge(void) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == j) {
				continue ;
			}
			if ((stage[i].first <= stage[j].first) && (stage[i].second <= stage[j].second)) {
				stage[i] = ii(0, 0);
			}
		}
	}
}

bool comp(ii &a, ii &b) {
	if (a.first == b.first) {
		return a.second <= b.second;
	}
	return a.first <= b.first;
}

signed main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (true) {
		for (int i = 0; i < 3; ++i) {
			cin >> stage[i].first >> stage[i].second;
			if (stage[i].first > stage[i].second) {
				swap(stage[i].first, stage[i].second);
			}
		}
		if ((!stage[0].first) && (!stage[0].second)) {
			return 0;
		}

		merge();
		sort(stage.begin(), stage.end(), comp);

		/*for (int i = 0; i < 3; ++i) {
			cout << "(" << stage[i].first << ", " << stage[i].second << ") ";
		}
		cout << "\n";*/

		int countn = 0;
		for (int i = 0; i < 3; ++i) {
			if (stage[i].first && stage[i].second) countn++;
		}

		int ans;
		if (countn == 1) {
			ans = stage[2].first * stage[2].second;
			cout << ans << "\n";
			continue;
		}
		if (countn == 2) {
			ans = stage[1].first * stage[2].second + (stage[2].first - stage[1].first) * stage[2].second + (stage[1].second - stage[2].second) * stage[1].first;
			cout << ans << "\n";
			continue;
		}
		if (countn == 3) {
			ans = stage[1].first * stage[1].second + (stage[2].first - stage[1].first) * stage[2].second + (stage[0].second - stage[1].second) * stage[0].first;
			cout << ans << "\n";
			continue;
		}
	}
}