#include <bits/stdc++.h>
using namespace std;

int find_group(int n) {
	int curGroup = 2;
	int totalNumbers = 0;
	int countn = 0;
	while (n > totalNumbers) {
		countn++;
		totalNumbers += curGroup;
		curGroup <<= 1;
	}
	return countn;
}

void next_xary(vector<int> &vstr) {
	int n = vstr.size();
	for (int i = n-1; i >= 0; --i) {
		if (vstr[i] == 7) {
			vstr[i] = 4;
		}
		else {
			vstr[i] = 7;
			return ;
		}
	}
}

void print_xary(vector<int> &vstr) {
	for (auto i : vstr) {
		cout << i;
	}
}

void nth_lucky(vector<int> &answer, int n) {
	for (int i = 0 ; i < n; ++i) {
		next_xary(answer);
	}
}

int n, base;
signed main(void) {
	cin >> n;
	int k = find_group(n);
	int countn = (1 << k) - 2;
	vector<int> answer(k, 4);
	nth_lucky(answer, n - countn - 1);
	print_xary(answer);
	cout << "\n";
}