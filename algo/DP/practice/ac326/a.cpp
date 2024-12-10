#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a; i<n; i++)
#define per(i,a,n) for (int i=n; i>=a; i--)
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
const ll mod = 1000000007;
const ll INF = 1 << 29;
const double eps = 1e-8;
ll powmod(ll a, ll b) {ll res = 1; for (; b; b>>=1){if (b&1) res=res*a; a=a*a;}return res;}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a%b); }
//head

const int N = 105;
int n, m, deg[N];
vector<PII> p[105];
db a[N][N], ans;

void guass() {
	for (int c = 1, r = 1; c <= n; c++, r++) {
		int pos = r;
		for (int i = r + 1; i <= n; i++) {
			if (fabs(a[i][c]) - fabs(a[pos][c]) > eps) pos = i;
		}
		if (pos != r) swap(a[pos], a[r]);
		for (int i = n + 1; i >= c; i--) a[r][i] /= a[r][c];
		for (int i = 1; i <= n; i++) {
			if (i != r && fabs(a[i][c]) > eps) {
				for (int j = n + 1; j >= c; j--) {
					a[i][j] -= a[i][c] * a[r][j];
				}
			}
		}
	}
}

void calc(int bit) {
	memset(a, 0, sizeof a);
	for (int x = 1; x < n; x++) {
		a[x][x] = deg[x];
		for (auto [v, edge] : p[x]) {
			int w = (edge >> bit) & 1;
			a[x][v] += w ? 1 : -1; a[x][n + 1] += w;
		}
	}
	a[n][n] = 1;
	guass();
	ans += a[1][n + 1] * (1 << bit);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    rep(i, 1, m + 1) {
    	int x, v, w; cin >> x >> v >> w;
    	p[x].pb({v, w}); deg[x]++;
    	if (x != v) {
    		p[v].pb({x, w});
    		deg[v]++;
    	}
    }
    rep(i, 0, 31) calc(i);
    cout << fixed << setprecision(3) << ans << '\n';
    return 0;
}