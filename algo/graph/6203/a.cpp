#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, n) for (int i = a; i < n; i++) 
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) (int)(x).size()
#define all(x) (x).begin, (x).end()
#define pb push_back
#define mp make_pair

template<typename T>
void _print(T x) {cerr << x << ' ';}
template<typename T>
void _println(T x) {cerr << x << '\n';}
void _print(bool x) {cerr << (!x ? "false" : "true") << ' ';}
void _println(bool x) {cerr << (!x ? "false" : "true") << '\n';}
template<typename T>
void _print(vector<T> u) {for(auto i : u) _print(i);}
template<typename T>
void _println(vector<T> u) {for(auto i : u)_print(i); cerr << '\n';}

const double PI = acos(-1);
const ll mod = (1ll << 31) - 1;
const double eps = 1e-9;
const int INF = 1061109567;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int n, m; cin >> n >> m;
	const int inf = 1e9;
	vector a(n + 1, vector<int>(n + 1, inf));
	rep(i, 1, n + 1) a[i][i] = 0;
	rep(i, 1, m + 1) {
		int x, y, z; cin >> x >> y >> z;
		a[x][y] = a[y][x] = min(a[x][y], z);
	}

	vector<int> d(n + 1, inf);
	const int N = 1010;
	bool v[N] {};
	d[1] = 0;
	rep(i, 1, n) {
		int x = 0;
		for (int j = 1; j <= n; j++) {
			if (!v[j] && (x == 0 || d[x] > d[j])) x = j;
		}
		v[x] = true;
		rep(j, 1, n + 1) {
			d[j] = min(d[j], d[x] + a[x][j]);
		}
	}

	memset(v, 0, sizeof v);
	v[1] = 1;
	ll ans = 1;
	rep(i, 1, n) {
		int t = 0, k = 0;
		for (int j = 2; j <= n; j++) {
			if (!v[j] && (!t || d[j] < d[t])) t = j;
		}
		for (int j = 1; j <= n; j++) {
			if (v[j] && d[j] + a[j][t] == d[t]) k++;
		}
		v[t] = 1;
		ans = ans * k % mod;
	}
	cout << ans << '\n';

    return 0;
}
