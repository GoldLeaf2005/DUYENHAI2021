#include <bits/stdc++.h>
using namespace std;

int n;

int max_square_divisor(int xA) {
	if (xA == 0) {
		return 0;
	}
	if (xA < 0) {
		xA = -xA;
	}
	int limit = ceil((double) sqrt(n));
	int maxans = 1;
	for (int i = limit; i >= 2; --i) {
		if (xA % (i * i) == 0) {
			maxans = i;
		}
	}
	maxans *= maxans;
	return maxans;
}

bool square_check(int x) {
	if (x < 0) {
		return false;
	}
	int x_r1 = sqrt(x);
	return x_r1 * x_r1 == x;
}

signed main(void) {
	cin >> n;
	int limitA = sqrt(n);
	int answer = 0;

	for (int a = 1; a <= limitA; ++a) {
		int xA = max_square_divisor(a);
		int k_AB = a / xA, y = 1;

		int b = k_AB;
		while (b <= n - 1) {
			int xB = max_square_divisor(b);
			int k_BC = b / xB, z = 1;

			int c = k_BC;
			while (c <= n) {
				if (square_check(c * a) && (a < b) && (b < c)) {
					cout << a << " " << b << " " << c << "\n";
					answer++;
				}
				z++;
				c = k_BC * z * z;
			}
			y++;
			b = k_AB * y * y;
		}
	}
	cout << answer << '\n';
}