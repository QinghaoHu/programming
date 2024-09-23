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

const int N = 100010;
ll a[N], sum[N], add[N];
int L[N], R[N];
int pos[N];
int n, m;

void change(int l, int r, ll d) {
	int p = pos[l], q = pos[r];
	if (p == q) {
		for (int i = l; i <= r; i++) {
			a[i] += d;
		}
		sum[p] += (r - l + 1) * d;
	} else {
		for (int i = p + 1; i <= q - 1; i++) {
			add[i] += d;
		}
		for (int i = l; i <= R[p]; i++) {
			a[i] += d;
		}
		sum[p] += (R[p] - l + 1) * d;
		for (int i = L[q]; i <= r; i++) {
			a[i] += d;
		}
		sum[q] += (r - L[q] + 1) * d;
	}
}

ll query(int l, int r) {
	ll ans = 0;
	int p = pos[l], q = pos[r];
	if (p == q) {
		rep(i, l, r + 1) {
			ans += a[i];
		}
		ans += add[p] * (r - l + 1);
	} else {
		rep(i, p + 1, q) {
			ans += sum[i] + add[i] * (R[i] - L[i] + 1);
		}
		for (int i = l; i <= R[p]; i++) {
			ans += a[i];
		}
		ans += add[p] * (R[p] - l + 1);
		for (int i = L[q]; i <= r; i++) {
			ans += a[i];
		}
		ans += add[q] * (r - L[q] + 1);
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    rep(i, 1, n + 1) {
    	cin >> a[i];
    } 
    int t = (int)sqrt(n);
    rep(i, 1, t + 1) {
    	L[i] = (i - 1) * t + 1;
    	R[i] = i * t;
    }
    if (R[t] < n) {
    	t++;
    	L[t] = R[t - 1] + 1;
    	R[t] = n;
    }
    rep(i, 1, t + 1) {
    	for (int j = L[i]; j <= R[i]; j++) {
    		pos[j] = i;
    		sum[i] += a[j];
    	}
    }
    while (m--) {
    	char op;
    	cin >> op;
    	int l, r, d;
    	cin >> l >> r;
    	if (op == 'Q') {
    		cin >> d;
    		change(l, r, d);
    	} else {
    		cout << query(l, r) << "\n";
    	}
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