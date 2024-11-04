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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    const int N = 12;
	bool st[1 << N] {};
	ll f[N][1 << N] {};
	while (cin >> n >> m, n && m) {
		vector<int> state[1 << N];
		for (int i = 0; i < 1 << m; i++) {
			for (int j = 0; j < 1 << m; j++) {
				if ((i & j) == 0) {
					int t = i | j;
					bool is_odd = 0, cnt = 0;
					for (int k = 0; k < m; k++) {
						if (t >> k & 1) {
							is_odd |= cnt;
							cnt = 0;
						} else {
							cnt ^= 1;
						}
					}
					if ((is_odd | cnt) == 0) {
						state[i].push_back(j);
					}
				}
			}
		}
		f[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 1 << m; j++) {
			    f[i][j] = 0;
				for (auto s : state[j]) {
					f[i][j] += f[i - 1][s];
				}
			}
		}
		cout << f[n][0] << '\n';
	}
	
    return 0;
}
