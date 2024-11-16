#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-5;
const double PI = acos(-1.0);
const ll INF = 1e16;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}
const int N = 90000;

struct node {
	ll val;
	node(): val(INF) {}
	node(ll a): val(a) {}
} seg[4 * N];

node operator+ (const node a, const node b) {
	node ans = node(min(a.val, b.val));
	return ans;
}

void update(int id) {
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void build(int id, int l, int r) {
	if (l == r) {
		seg[id] = node();
		return;
	}
	int mid = l + r >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	update(id);
}

void modify(int id, int l, int r, int t, ll x) {
	if (l == r) {
		seg[id].val = x;
		return;
	}
	int mid = l + r >> 1;
	if (t <= mid) {
		modify(id * 2, l, mid, t, x);
	} else {
		modify(id * 2 + 1, mid + 1, r, t, x);
	}
	update(id);
}

node query(int id, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) {
		return seg[id];
	}
	int mid = l + r >> 1;
	if (qr <= mid) {
		return query(id * 2, l, mid, ql, qr);
	} else if (ql > mid) {
		return query(id * 2 + 1, mid + 1, r, ql, qr);
	}
	return query(id * 2, l, mid, ql, mid) + query(id * 2 + 1, mid + 1, r, mid + 1, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, m, e;
	cin >> n >> m >> e;
	build(1, m - 1, e);
	modify(1, m - 1, e, m - 1, 0);
	vector<array<int, 3>> cows;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cows.push_back({a, b, c});
	}
	sort(cows.begin(), cows.end(), [](array<int, 3> a, array<int, 3> b) {
		return a[1] < b[1];
	});
	for (auto i : cows) {
		int a = i[0], b = i[1], c = i[2];
		ll val = query(1, m - 1, e, a - 1, b - 1).val;
		if (val == INF) continue;
		val += c;
		ll compare = query(1, m - 1, e, b, b).val;
		if (val < compare) {
			modify(1, m - 1, e, b, val);
		}
	}
	ll res = query(1, m - 1, e, e, e).val;
	cout << (res >= INF ? -1 : res) << '\n';
    return 0;
}
