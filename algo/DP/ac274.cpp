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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 210;
    int n, m;

    cin >> m >> n;
    vector c(m + 1, vector<int>(m + 1, 0));
    vector<int> q(n + 1, 0);
    rep(i, 1, m + 1) {
    	rep(j, 1, m + 1) {
    		cin >> c[i][j];
    	}
    }
    rep(i, 1, n + 1) {
    	cin >> q[i];
    }
    q[0] = 3;

    int f[2][N][N] {};
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) {
    	for (int x = 1; j <= m; j++) {
    		for (int y = 1; k <= m; k++) {
    			if (f[i & 1][x][y] != INF) {
    				int z = p[i - 1];
    				if (y != p[i] && z != p[i]) f[i & 1][y][z] = min(f[i & 1][y][z], f[i - 1 & 1][x][y] + c[x][p[i]]);
                    if (x != p[i] && z != p[i]) f[i & 1][x][z] = min(f[i & 1][x][z], f[i - 1 & 1][x][y] + c[y][p[i]]);

    			}
    		}
    	}
    }

    return 0;
}