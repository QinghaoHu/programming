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
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}

const int N = 1e5 + 10;

struct rec {
	int op, x, y, z;
} q[2 * N], lq[2 * N], rq[2 * N];

int n, m, t, c[N], ans[N];

int ask(int x) {
	int y = 0;
	for (; x; x -= x & -x) {
		y += c[x];
	}
	return y;
}

void modify(int x, int y) {
	for (; x <= n; x += x & -x) {
		c[x] += y;
	}
}

void solve(int lval, int rval, int st, int ed) {
	if (st > ed) return;
	if (lval == rval) {
		rep(i, st, ed + 1) {
			if (q[i].op > 0) {
				ans[q[i].op] = lval;
			}
		}
		return;
	}
	int mid = lval + rval >> 1;
	int lt = 0, rt = 0;
	for (int i = st; i <= ed; i++) {
		if (q[i].op == 0) {
			if (q[i].y <= mid) modify(q[i].x, 1), lq[++lt] = q[i];
			else rq[++rt] = q[i];
		} else {
			int cnt = ask(q[i].y) - ask(q[i].x - 1);
			if (cnt >= q[i].z) lq[++lt] = q[i];
			else q[i].z -= cnt, rq[++rt] = q[i];
		}
	}
	for (int i = ed; i >= st; i--) {
		if (q[i].op == 0 && q[i].y <= mid) {
			modify(q[i].x, -1);
		}
	}
	for (int i = 1; i <= lt; i++) q[st + i - 1] = lq[i];
	for (int i = 1; i <= rt; i++) q[st + lt + i - 1] = rq[i];
	solve(lval, mid, st, st + lt - 1);
	solve(mid + 1, rval, st + lt, ed);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
    	int val;
    	cin >> val;
    	q[++t] = {0, i, val};
    }
    for (int i = 1; i <= m; i++) {
    	int l, r, k;
    	cin >> l >> r >> k;
    	q[++t] = {i, l, r, k};
    }
    solve(-INF, INF, 1, t);
    rep(i, 1, m + 1) {
    	cout << ans[i] << "\n";
    }

    return 0;
}