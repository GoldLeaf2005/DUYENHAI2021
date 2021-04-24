#include <bits/stdc++.h>
using namespace std;

void show_vector(vector<int> &v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << "\n";
}


vector<string> solve(vector<int> &disks) {
	string pole[] = {"A", "B", "C"};
	vector<string> ans;

	int n = disks.size();
	int target = 2;
	vector<int> targets(n, 0);
	for (int i = n-1; i >= 0; --i) {
		targets[i] = target;
		if (disks[i] != target) {
			target = 3 - target - disks[i];
		}
	}
	// show_vector(targets);
	int i = 0;
	while (i < n) { // i is the number stages
		for (i = 0; i < n; ++i) {
			if (targets[i] != disks[i]) {
				target = targets[i];
				// cout << "move disk " << (i+1) << " from pole " << (disks[i]+1) << " to pole " << (target+1) << "\n";
				string step = pole[disks[i]] + pole[target]; ans.push_back(step);

				disks[i] = target;
				for (int j = i - 1; j >= 0; --j) {
					targets[j] = target;
					target = 3 - target - disks[j];
				}
				break;
			}
		}
	}
	return ans;
}

vector<int> hanoitower;
int disks;
signed main(void) {
	cin >> disks;
	for (int i = 0; i < disks; ++i) {
		char x; cin >> x;
		hanoitower.push_back((int) x - 'A');
	}
	vector<string> htans = solve(hanoitower);
	cout << htans.size() << "\n";
	for (auto str : htans) {
		cout << str << "\n";
	}	
}