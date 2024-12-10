#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a; i<n; i++)
#define per(i,a,n) for (int i=n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) (int)((x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1e8;
const ll INF = 1 << 29;
ll powmod(ll a, ll b) {ll res = 1; for (; b; b>>=1){if (b&1) res=res*a; a=a*a;}return res;}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a%b); }

const int N = 12;
int n, m;
int a[N + 1], f[1 << N][N + 2];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    rep(i, 0, m) {
    	rep(j, 0, n) {
    		int x; cin >> x;
    		if (!x) {
    			a[i] ^= (1 << j);
    		}
    	}
    }
    VI valid;
    rep(i, 0, (1 << n)) {
    	int cnt = 0;
    	bool isV = true;
    	rep(j, 0, n) {
    		if (i >> j & 1) {
    			cnt++;
    			if (cnt > 1) {
    				isV = false;
    				break;
    			}
    		} else {
    			cnt = 0;
    		}
    	}
    	if (isV) {
    		valid.pb(i);
    	}
    }
    rep(i, 0, (1 << n)) {
    	if ((a[0] & i) == 0) f[i][0] = 1;
    }
    rep(i, 1, m) {
    	for (auto j : valid) {
    		for (auto k : valid) {
    			if (!(k & a[i]) && !(k & j)) {
    				f[k][i] = ((ll)f[j][i - 1] + f[k][i]) % mod;
    			}
    		}
    	}
    }
    int ans = 0;
    for (auto i : valid) {
    	ans = ((ll)f[i][m - 1] + ans) % mod;
    }
    cout << (ans % mod + mod) % mod << '\n';
    return 0;
}