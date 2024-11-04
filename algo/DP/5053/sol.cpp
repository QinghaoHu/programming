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
	int n, m, x, y;
    cin >> n >> m >> x >> y;
    if (m == 1) {
		cout << 2 * (n - x) << '\n';
		exit(0);
	}
	vector f(n + 1, vector<double>(m + 1, 0)), d(m + 1, vector<double>(m + 2, 0));
	
	auto gauss = [&]() -> void {
		for (int i = 1; i <= m; i++) {
			db w = 1.0 / d[i][i];
			d[i][i] *= w;
			d[i][m + 1] *= w;
			if (i == m) break;
			d[i][i + 1] *= w;
			w = d[i + 1][i] / d[i][i];
			d[i + 1][i] -= w * d[i][i];
			d[i + 1][i + 1] -= w * d[i][i + 1];
			d[i + 1][m + 1] -= w * d[i][m + 1];
		}
		for (int i = m - 1; i >= 1; i--) {
			d[i][m + 1] -= d[i][i + 1] * d[i + 1][m + 1];
		}
	};
	
	for (int i = n - 1; i >= x; i--) {
		d[1][1] = d[m][m] = -2.0 / 3;
		d[1][2] = d[m][m - 1] = 1.0 / 3;
		for (int j = 2; j < m; j++) {
			d[j][j] = -3.0 / 4;
			d[j][j - 1] = d[j][j + 1] = 1.0 / 4;
			d[j][m + 1] = -f[i + 1][j] / 4 - 1;
		}
		d[1][m + 1] = -f[i + 1][1] / 3 - 1;
		d[m][m + 1] = -f[i + 1][m] / 3 - 1;
		gauss();
		for (int j = 1; j <= m; j++) {
			f[i][j] = d[j][m + 1];
		}
	}
	cout << fixed << setprecision(10) << f[x][y] << '\n';
	
    return 0;
}
