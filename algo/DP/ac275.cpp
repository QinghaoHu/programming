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

    int m, n;
    cin >> n >> m;

    vector v(n + 1, vector<int>(m + 1, 0));
    rep(i, 1, n + 1) {
    	rep(j, 1, m + 1) {
    		cin >> v[i][j];
    	}
    }

  	int f[110][55][55] {};
  	for (int k = 2; k <= n + m; k++) {
  		for (int x1 = max(1, k - m); x1 <= min(k - 1, n); x1++) {
  			for (int x2 = max(1, k - m); x2 <= min(k - 1, n); x2++) {
  				int t = v[x1][k - x1];
  				if (x1 != x2) {
  					t += v[x2][k - x2];
  				}
  				for (int a = 0; a <= 1; a++)
  					for (int b = 0; b <= 1; b++)
  						f[k][x1][x2] = max(f[k][x1][x2], f[k - 1][x1 - a][x2 - b] + t);
  			}
  		}
  	}

    cout << f[n + m][n][n] << "\n";

    return 0;
}