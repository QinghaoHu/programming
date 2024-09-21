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

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b) *b;}

const int N = 10010;
int n, w, h;
vector<ll> vx;
vector<array<ll, 4>> event;

struct info {
	ll maxv;
};

info operator + (const info &l, const info &r) {
	info a;
	a.maxv = max(l.maxv, r.maxv);
	return a;
}

struct node {
	ll t;
	info val;
} seg[8 * N];

void update(int id) {
	seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
}

void settag(int id, ll t) {
	seg[id].val.maxv += t;
	seg[id].t += t;
}

void pushdown(int id) {
	if (seg[id].t != 0) {
		settag(id * 2, seg[id].t);
		settag(id * 2 + 1, seg[id].t);
		seg[id].t = 0;
	}
}

void build(int id, int l, int r) {
	seg[id].t = 0;
	if (l == r) {
		seg[id].val = {0};
		return;
	}
	int mid = l + r >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	update(id);
}

void modify(int id, int l, int r, int ql, int qr, int t) {
	if (l == ql && r == qr) {
		settag(id, t);
		return;
	}
	int mid = l + r >> 1;
	pushdown(id);
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _;
    cin >> _;
    rep(T, 0, _) {
    	cin >> n >> w >> h;
    	vx.clear(); event.clear();
    	rep(i, 0, n) {
    		ll x, y, c;
    		cin >> x >> y >> c;
    		vx.pb(y); vx.pb(y + h - 1);
    		event.pb({x, c, y, y + h - 1});
    		event.pb({x + w, -c, y, y + h - 1});
    	}
    	sort(all(vx));
    	sort(all(event));
    	vx.erase(unique(all(vx)), vx.end());
    	int m = SZ(vx);
    	build(1, 1, m);
    	ll ans = 0;
    	for (auto evt : event) {
    		ans = max(ans, seg[1].val.maxv);
    		int x = lower_bound(all(vx), evt[2]) - vx.begin() + 1;
    		int y = lower_bound(all(vx), evt[3]) - vx.begin() + 1;
    		modify(1, 1, m, x, y, evt[1]);
    	}
    	cout << ans << "\n";
    }

    return 0;
}
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */