#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define arr array
#define SZ(x) ((int)x.size())
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int N = 200010;
int n, q;
int a[N];

struct info {
	ll maxv;
	info():maxv(0) {}
	info(ll t):maxv(t) {}
};

struct tag {
	ll add;
};

info operator + (const info &l, const info &r) {
	return {max(l.maxv, r.maxv)};
}

info operator + (const info &l, const tag &r) {
	return {l.maxv + r.add};
}

tag operator + (const tag &l, const tag &r) {
	return {l.add + r.add};
}

struct node {
	tag add;
	info val;
} seg[4 * N];

void update(int id) {
	seg[id].val = seg[id * 2 + 1].val + seg[id * 2].val;
}

void settag(int id, tag t) {
	seg[id].val = seg[id].val + t;
	seg[id].t = seg[id].t + t;
}

void pushdown(int id) {
	if (seg[id].t.add != 0) {
		settag(id * 2, seg[id].t);
		settag(id * 2 + 1, seg[id].t);
		settag[id].t.add = 0;
	}
}

void build(int id, int l, int r) {
	if (l == r) {
		seg[id].val = info(a[l]);
	} else {
		int mid = l + r >> 1;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		update(id);
	}
}

void change(int id, int l, int r, int pos, ll val) {
	if (l == r) {
		seg[id].val = info(val);
	} else {
		int mid = l + r >> 1;
		if (pos <= mid) {
			change(id * 2, l, mid, pos, val);
		} else {
			change(id * 2 + 1, mid + 1, r, pos, val);
		}
		update(id);
	}
}

void modify(int id, int l, int r, int ql, int qr, tag t) {
	if (l == ql && r == qr) {
		settag(id, t);
	} else {
		int mid = l + r >> 1;
		pushdown(id);
		if (qr <= mid) {
			modify(id * 2, l, mid, ql, qr, t); 
		} else if (ql > mid) {
			modify(id * 2 + 1, mid + 1, r, ql, qr, t);
		} else {
			modify(id * 2, l, mid, ql, mid, t);
			modify(id * 2 + 1, mid + 1, r, mid, qr, t);
			update(id);
		}
	}
}

info query(int id, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) {
		return seg[id].val;
	} 
	int mid = l + r >> 1;
	pushdown(id);
	if (qr <= mid) {
		query(id * 2, l, mid, ql, qr);
	} else if (ql > mid) {
		query(id * 2 + 1, mid + 1, r, ql, qr);
	} else {
		return query(id * 2, l, mid, ql, mid) + query(id * 2 + 1, mid + 1, r, mid + 1, qr);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}