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

const int N = 1e5 + 10;
int n, m;
int a[N];

struct node {
	ll add;
	ll val;
} seg[N * 4];

void update(int id) {
	seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
}

void settag(int id, int l, int r, ll t) {
	seg[id].val += (r - l + 1) * t;
	seg[id].add += t;
}

void pushdown(int id, int l, int r, int mid) {
	if (seg[id].add != 0) {
		seg[id * 2].add += seg[id].add;
		seg[id * 2].val += (mid + 1 - l) * seg[id].add;
		seg[id * 2 + 1].add += seg[id].add;
		seg[id * 2 + 1].val += (r - mid) * seg[id].add;
		seg[id].add = 0;
	}
}

void build(int id ,int l, int r) {
	seg[id].add = 0;
	if (l == r) {
		seg[id].val = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	update(id);
}

void modify(int id, int l, int r, int ql, int qr, ll t) {
	if (l == ql && r == qr) {
		settag(id, ql, qr, t);
		return;
	}
	int mid = l + r >> 1;
	pushdown(id, l, r, mid);
	if (qr <= mid) {
		modify(id * 2, l, mid, ql, qr, t);
	} else if (ql > mid) {
		modify(id * 2 + 1, mid + 1, r, ql, qr, t);
	} else {
		modify(id * 2, l, mid, ql, mid, t);
		modify(id * 2 + 1, mid + 1, r, mid + 1, qr, t);
	}
	update(id);
}

ll query(int id, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) {
		return seg[id].val;
	}
	int mid = l + r >> 1;
	pushdown(id, l, r, mid);
	if (qr <= mid) {
		return query(id * 2, l, mid, ql, qr);
	} else if (ql > mid) {
		return query(id * 2 + 1, mid + 1, r, ql, qr);
	} else {
		return query(id * 2, l, mid, ql, mid) + query(id * 2 + 1, mid + 1, r, mid + 1, qr);
	}
	update(id);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    rep(i, 1, n + 1) {
    	cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
    	int ty;
    	cin >> ty;
    	if (ty == 1) {
    		int x, y;
    		ll k;
    		cin >> x >> y >> k;
    		modify(1, 1, n, x, y, k);
    	} else {
    		int x, y;
    		cin >> x >> y;
    		cout << query(1, 1, n, x, y) << "\n";
    	}
    }

    return 0;
}