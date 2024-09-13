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

const int N = 5e5 + 10;
int n, q;
ll A[N], B[N];

void add(int x, ll s) {
	for (; x <= n; x += (x & -x)) {
		B[x] += s;
	}
}

ll ask(int x) {
	ll s = 0;
	for (; x; x -= (x & -x)) {
		s += B[x];
	}
	return s;
}

struct info {
	ll gcdv;

	info() {}
	info(ll t): gcdv(t) {}
};

info operator + (const info &l, const info &r) {
	return {gcd(l.gcdv, r.gcdv)};
}

info operator + (const info &l, const ll &r) {
	return {l.gcdv + r};
}

struct node {
	info val;
} seg[4 * N];

void update(int id) {
	seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
}

void build(int id, int l, int r) {
	if (l == r) {
		seg[id].val = info(A[l]);
	} else {
		int mid = l + r >> 1;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		update(id);
	}
}

void change(int id, int l, int r, int pos, ll val) {
	if (l == r) {
		seg[id].val = seg[id].val + val;
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

info query(int id, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) {
		return seg[id].val;
	}
	int mid = l + r >> 1;
	if (qr <= mid) {
		return query(id * 2, l, mid, ql, qr);
	} else if (ql > mid) {
		return query(id * 2 + 1, mid + 1, r, ql, qr);
	} else {
		return query(id * 2, l, mid, ql, mid) + query(id * 2 + 1, mid + 1, r, mid + 1, qr);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}