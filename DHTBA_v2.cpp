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

string next_binary(string str) {
	string one = "1";
	int n = str.length();
	string answer = str;
	for (int i = n-1; i >= 0; --i) {
		if (answer[i] == '1') {
			answer[i] = '0';
		}
		else {
			answer[i] = '1';
			return answer;
		}
	}
	one += answer;
	return one;
}

char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void next_xary(vector<int> &vstr, int base) {
	if (base > strlen(digits)) {
		return ;
	}
	vector<int> one = {1};
	int n = vstr.size();
	for (int i = n-1; i >= 0; --i) {
		char c = vstr[i];
		if (c == base-1) {
			vstr[i] = 0;
		}
		else {
			vstr[i]++;
			return ;
		}
	}
	one.insert(one.end(), vstr.begin(), vstr.end());
	vstr = one;
	return ;
}

void print_xary(vector<int> &vstr) {
	for (auto i : vstr) {
		cout << digits[i];
	}
}

string nth_binary(int n, int digits) {
	string answer(digits, '0');
	for (int i = 0; i < n; ++i) {
		answer = next_binary(answer);
	}
	return answer;
}

int n, base;
signed main(void) {
	cin >> n;
	int k = find_group(n);
	int countn = 0;
	for (int i = 1; i < k; ++i) {
		countn += (1 << i);
	}
	string answer = nth_binary(n - countn - 1, k);
	for (int i = 0; i < k; ++i) {
		if (answer[i] == '0') {
			answer[i] = '4';
		}
		else {
			answer[i] = '7';
		}
	}
	cout << answer << "\n";
}