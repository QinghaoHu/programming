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
    
    vector<pair<int, int>> g;
    for (int i = 1; i <= n; i++) {
		int v, w, s;
		cin >> v >> w >> s;
		for(; s; s >>= 1) {
			if (s & 1) {
				g.push_back(make_pair(v, w));
			}
			v *= 2;
			w *= 2;
		}
	}
	
	int f[2000] {};
	for (int i = 1; i <= g.size(); i++) {
		for (int j = m; j >= g[i].first; j--) {
			f[j] = max(f[j], f[j - g[i - 1].first] + g[i - 1].second);
		}
	}
	
	cout << f[m] << "\n";
	
    return 0;
}
