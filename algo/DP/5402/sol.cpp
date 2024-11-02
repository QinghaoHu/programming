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
	
	int n, m;
	cin >> n >> m;
	
	vector<int> son[310];
	vector<int> score(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x >> score[i];
		son[x].push_back(i);
	}
	
	int f[310][310] {};
	
	auto dp = [&](auto&& self, int x) -> void {
		f[x][0] = 0;
		for (auto y : son[x]) {
			self(self, y);
			for (int t = m; t >= 0; t--) {
				for (int j = 0; j <= t; j++) {
					f[x][t] = max(f[x][t], f[x][t - j] + f[y][j]);
				}
			}
		}
		if (x != 0) {
			for (int t = m; t > 0; t--) {
				f[x][t] = f[x][t - 1] + score[x];
			}
		}
	};
	
	memset(f, -0x3f, sizeof f);
	dp(dp, 0);
	cout << f[0][m] << '\n';
	
    return 0;
}
/*
 * Author: Qinghao Hu
 * Stay calm and focus on understanding the problem fully.
 * Try to write something down
 * Don't stuck on one approach 
 * Don't rush, read carefully, and test thoroughly.
 */
