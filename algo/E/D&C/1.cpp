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

const int N = 2e5 + 10;
int n, k, ans[N];
array<int, 5> a[N], tmp[N];

template <typename T>
struct BIT {
	int n;
	std::vector<T> a;

	BIT(): n(N), a(N) {}
	BIT(int x): n(x), a(x + 1, 0) {}

	void modify(int x, T s) {
		for (; x <= n; x += (x & -x)) {
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

BIT<int> c(N);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    c = BIT<int>(k);
    rep(i, 0, n) {
    	cin >> a[i][0] >> a[i][1] >> a[i][2];
    	a[i][3] = 1;
    }
    sort(a, a + n);
    int t = 0;
    rep(i, 0, n) {
    	if (t != 0  && (a[i][0] == a[t - 1][0] && a[i][1] == a[t - 1][1] && a[i][2] == a[t - 1][2])) {
    		a[t - 1][3]++;
    	} else {
    		a[t++] = a[i];
    	}
    }

    function<void(int, int)> solve = [&](int l, int r) {
    	if (l == r) return;
		int mid = l + r >> 1;
		solve(l, mid);
		solve(mid + 1, r);
		int p1 = l, p2 = mid + 1;
		int p3 = 0;
		while (p1 <= mid || p2 <= r) {
			if (p2 > r || (p1 <= mid && mp(a[p1][1], a[p1][2]) <= mp(a[p2][1], a[p2][2]))) {
				c.modify(a[p1][2], a[p1][3]);
				tmp[p3++] = a[p1++];
			} else {
				a[p2][4] += c.query(a[p2][2]);
				tmp[p3++] = a[p2++];
			}
		}
		for (int i = l; i <= mid; i++) {
			c.modify(a[i][2], -a[i][3]);
		}
		for (int i = 0; i < p3; i++) {
			a[l + i] = tmp[i];
		}
    };

    solve(0, t - 1);
    for (int i = 0; i < t; i++) {
    	ans[a[i][3] + a[i][4] - 1] += a[i][3];
    }
    rep(i, 0, n) {
    	cout << ans[i] << "\n";
    }

    return 0;
}