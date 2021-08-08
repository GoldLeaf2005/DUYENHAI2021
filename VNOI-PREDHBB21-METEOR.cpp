#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const int MAXN2 = 1e7+5;
#define left_child ((v << 1) | 1)
#define right_child ((v + 1) << 1)

int tree[MAXN2<<2], lazy[MAXN2<<2];
int n2 = 1e7+2;

void build(int v, int tl, int tr, vector<int> &a) {
	if (tl == tr) {
		tree[v] = a[tl];
		return ;
	}
	int tm = (tl + tr) >> 1;
	build(left_child, tl, tm, a);
	build(right_child, tm+1, tr, a);
	tree[v] = tree[left_child] + tree[right_child];
	return ;
}

void build(vector<int> &a) {
	build(0, 0, n2-1, a);
}

void update(int v, int tl, int tr, int l, int r, int delta) {
	if (lazy[v] != 0) {
		tree[v] += lazy[v] * (tr - tl + 1);
		if (tl != tr) {
			lazy[left_child] += lazy[v];
			lazy[right_child] += lazy[v];
		}
		lazy[v] = 0;
	}
	if (tl > tr || l > tr || tl > r) {
		return ;
	}
	if (l <= tl && tr <= r) {
		tree[v] += delta * (tr - tl + 1);
		if (tl != tr) {
			lazy[left_child] += delta;
			lazy[right_child] += delta;
		}
		return ;
	}
	int tm = (tl + tr) >> 1;
	update(left_child, tl, tm, l, r, delta);
	update(right_child, tm+1, tr, l, r, delta);
	tree[v] = tree[left_child] + tree[right_child];
	return ;
}

void update(int l, int r, int delta) {
	update(0, 0, n2-1, l, r, delta);
}

int get(int v, int tl, int tr, int l, int r) {
	if (lazy[v] != 0) {
		tree[v] += lazy[v] * (tr - tl + 1);
		if (tl != tr) {
			lazy[left_child] += lazy[v];
			lazy[right_child] += lazy[v];
		}
		lazy[v] = 0;
	}
	if (tl > tr || l > tr || tl > r) {
		return 0;
	}
	if (l <= tl && tr <= r) {
		return tree[v];
	}
	int tm = (tl + tr) >> 1;
	return get(left_child, tl, tm, l, r) + get(right_child, tm+1, tr, l, r);
}

int get(int l, int r) {
	return get(0, 0, n2-1, l, r);
}

//------------------------------------------------------------------------------------

int n, R;
const int MAXN = 1e5+5;
const int INF = 1e7+5;

int x[MAXN], y[MAXN], z[MAXN], vx[MAXN], vy[MAXN], vz[MAXN];
double l[MAXN], r[MAXN];

signed main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> R;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> z[i] >> vx[i] >> vy[i] >> vz[i];
	}

	fill(tree, tree+(MAXN2<<2), 0);

	for (int i = 0; i < n; ++i) {
		int a = vx[i] * vx[i] + vy[i] * vy[i] + vz[i] * vz[i];
		int b = (x[i] * vx[i] + y[i] * vy[i] + z[i] * vz[i]) << 1;
		int c = x[i] * x[i] + y[i] * y[i] + z[i] * z[i] - R * R;
		// cout << a << " " << b << " " << c << "\n";

		if (a == 0) {
			if (b == 0) {
				if (c == 0) {
					l[i] = -INF, r[i] - INF;
				}
				else {
					l[i] = 0.0, r[i] = -1.0;
				}
			}
			else {
				l[i] = r[i] = ((double) c) / ((double) b);
			}
		}
		else {
			double delta = b * b - ((a * c) << 2);
			if (delta < 0) {
				l[i] = 0.0, r[i] = -1.0;
			}
			else {
				double sqrt_delta = sqrt(delta);
				double n1 = (-b + sqrt_delta) / (2.0 * a), n2 = (-b - sqrt_delta) / (2.0 * a);
				l[i] = min(n1, n2), r[i] = max(n1, n2);
			}
		}


		if (l[i] <= r[i]) {
			update(ceil(l[i]), floor(r[i]), 1);
		}
	}

	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		double t; cin >> t;
		int ans = get(t, t);
		cout << ans << "\n";
	}
}