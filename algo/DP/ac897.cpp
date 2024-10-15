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
const int N = 1010;
int n, m;
char a[N], b[N];
int f[N][N] {};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    rep(i, 1, n + 1) {
    	cin >> a[i];
    }
    rep(i, 1, m + 1) {
    	cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
    	f[i][0] = 0;
    }
    for (int i = 1; i <= m; i++) {
    	f[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    		if (a[i] == b[j]) {
    			f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
    		}
    	}
    }
    cout << f[n][m] << "\n";

    return 0;
}