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
    
    const int N = 310;
    int f[N][N] {};
    vector<int> s(n + 1, 0);
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] += s[i - 1];
	}
	
	rep(i, 1, n + 1) {
		f[i][i] = 0;
	}
	
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l <= n - len + 1; l++) {
			int r = l + len - 1;
			for (int k = l; k < r; k++) {
				f[l][r] = min(f[l][k] + f[k + 1][r], f[l][r]);
			}
			f[l][r] += s[r] - s[l - 1];
		}
	}
	
	cout << f[1][n] << "\n";
	
    return 0;
}
