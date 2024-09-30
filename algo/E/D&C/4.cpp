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

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;

const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}

const int N = 1e5 + 10;

struct node {
	int p, x, y, z;
} q[3 * N], lq[3 * N], rq[3 * N];

int n, m, t, p, a[N], ans[N];

template <typename T>
struct BIT {
	int size;
	std::vector<T> a;

	BIT(): size(N), a(N, 0) {}
	BIT(int x): size(x), a(x + 1, 0) {}

	void modify(int x, T s) {
		for (; x <= size; x += (x & -x)) {
			a[x] += s;
		}
	}

	T query(int x) {
		T s{};
		for (; x; x -= (x & -x)) {
			s += a[x];
		}
		return s;
	}

	T rangeSum(int x, int y) {
		return query(y) - query(x);
	}
};

BIT<int> c(N * 3);

void work(int lval, int rval, int st, int ed) {
	if (st > ed) return;
	if (lval == rval) {
		for (int i = st; i <= ed; i++) {
			if (q[i].p > 0) ans[q[i].p] = lval;
		}
		return;
	}
	int mid = lval + rval >> 1, lt = 0, rt = 0;
	for (int i = st; i <= ed; i++) {
		if (q[i].p <= 0) {
			if (q[i].y <= mid) {
				c.modify(q[i].x, q[i].z);
				lq[++lt] = q[i];
			} else {
				rq[++rt] = q[i];
			}
		} else {
			int cnt = c.query(q[i].y) - c.query(q[i].x - 1);
			if (cnt >= q[i].z) {
				lq[++lt] = q[i];
			} else {
				q[i].z -= cnt;
				rq[++rt] = q[i];
			}
		}
	}
	for (int i = ed; i >= st; i--) {
		if (q[i].p <= 0 && q[i].y <= mid) c.modify(q[i].x, -q[i].z);
	}
	for (int i = 1; i <= lt; i++) q[i + st - 1] = lq[i];
	for (int i = 1; i <= rt; i++) q[i + lt + st - 1] = rq[i];
	work(lval, mid, st, st + lt - 1);
	work(mid + 1, rval, st + lt, ed);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    c = BIT<int>(3 * n + 5);
    rep(i, 1, n + 1) {
    	cin >> a[i];
    	q[++t] = {0, i, a[i], 1};
    }
    for (int i = 1; i <= m; i++) {
    	char s;
    	cin >> s;
    	if (s == 'Q') {
    		int x, y, z;
    		cin >> x >> y >> z;
    		q[++t] = {++p, x, y, z};
    	} else {
    		int x, y;
    		cin >> x >> y;
    		q[++t] = {-1, x, a[x], -1};
    		q[++t] = {0, x, y, 1};
    		a[x] = y;
    	}
    }

    work(0, INF, 1, t);

    for (int i = 1; i <= p; i++) {
    	cout << ans[i] << "\n";
    }

    return 0;
}