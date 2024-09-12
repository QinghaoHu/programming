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
int a[N];

struct info {
	ll mss, mpre, msuf, s;
	info() {}
	info(int a):mss(a), mpre(a), msuf(a), s(a) {}
};

info operator + (const info &l, const info &r) {
	info a;
	a.mss = max(max(l.mss, r.mss), l.msuf + r.mpre);
	a.mpre = max(l.mpre, l.s + r.mpre);
	a.msuf = max(r.msuf, l.msuf + r.s);
	a.s = l.s + r.s;
	return a;
}

struct node {
	info val;
} seg[4 * N];

void update(int id) {
	seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
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

void change(int id, int l, int r, int pos, int val) {
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

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    build(1, 1, n);
    rep(i, 0, q) {
    	int ty;
    	cin >> ty;
    	if (ty == 2) {
    		int x, d;
    		cin >> x >> d;
    		change(1, 1, n, x, d);
    	} else {
    		int l, r;
    		cin >> l >> r;
    		if (l > r) {
    			swap(r, l);
    		}
    		auto res = query(1, 1, n, l, r);
    		cout << res.mss << "\n";
    	}
    }

    return 0;
}