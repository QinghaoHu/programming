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
    
    vector<int> h(n + 1, 0);
    rep(i, 1, n + 1) {
		cin >> h[i];
	}
	
	vector<int> g[6010];
	vector<int> v(n + 1, 0);
	rep(i, 1, n) {
		int x, y;
		cin >> x >> y;
		g[y].push_back(x);
		v[x] = 1;
	}
	
	int root;
	rep(i, 1, n + 1) {
		if (v[i] == 0) {
			root = i;
			break;
		}
	}
	
	int f[6010][2];
	
	function<void(int)> dfs = [&](int x) {
		f[x][0] = 0;
		f[x][1] = h[x];
		for (auto s : g[x]) {
			dfs(s);
			f[x][0] += max(f[s][0], f[s][1]);
			f[x][1] += f[s][0];
		}
	};
	
	dfs(root);
	cout << max(f[root][0], f[root][1]) << '\n';
	
    return 0;
}
/*
 * Author: Qinghao Hu
 * Stay calm and focus on understanding the problem fully.
 * Try to write something down
 * Don't stuck on one approach 
 * Don't rush, read carefully, and test thoroughly.
 */
