#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)

typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;

const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}
//head

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> w(n * 2 + 1, 0);
    vector<char> c(n * 2 + 1);
    for (int i = 1; i <= n; i++) {
		cin >> c[i] >> w[i];
		c[n + i] = c[i];
		w[n + i] = w[i];
	}
	
	int f[110][110] {}, g[110][110] {};
	for (int len = 1; len <= n; len++) {
		for (int l = 1; l <= 2 * n - len + 1; l++) {
			int r = l + len - 1;
			if (len == 1) {
				g[l][r] = f[l][r] = w[l];
			} else {
				f[l][r] = -INF, g[l][r] = INF;
				for (int k = l; k < r; k++) {
					char op = c[k + 1];
					if (op == 't') {
						f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r]);
						g[l][r] = min(g[l][r], g[l][k] + g[k + 1][r]);
					} else {
						int x1 = f[l][k] * f[k + 1][r], x2 = f[l][k] * g[k + 1][r], x3 = g[l][k] * g[k + 1][r], x4 = g[l][k] * f[k + 1][r];
						f[l][r] = max(max(max(x1, x2), max(x3, x4)), f[l][r]);
						g[l][r] = min(min(min(x1, x2), min(x3, x4)), g[l][r]);
					}
				}
			}
		}
	}
	
	int res = -INF;
	for (int i = 1; i <= n; i++) {
		res = max(res, f[i][i + n - 1]);
	}
	cout << res << "\n";
	
	for (int i = 1; i <= n; i++) {
		if (f[i][i + n - 1] == res) {
			cout << i << ' ';
		}
	}
	cout << '\n';
	
    return 0;
}
/*
 * Author: Qinghao Hu
 * Stay calm and focus on understanding the problem fully.
 * Try to write something down
 * Don't stuck on one approach 
 * Don't rush, read carefully, and test thoroughly.
 */
