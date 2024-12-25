#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define FOR(i, a, n) for (int i = a; i < n; i++) 
#define ROF(i, a, n) for (int i = n; i >= a; i--)

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

const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 1061109567;

int a[50];
int f[50][65];
int vis[50][65];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    function<int(bool, bool, int, int)> dfs = [&](bool limit, bool lead, int pos, int cha) {
		int res = 0;
		if (pos == 0) return cha >= 30;
		if (!limit && !lead && vis[pos][cha]) return f[pos][cha];
		int up = limit ? a[pos] : 1;
		for (int i = 0; i <= up; i++) {
			res += dfs(limit & (i == a[pos]), lead & (i == 0), pos - 1, cha + (i == 0 ? (lead ? 0 : 1) : -1));
		}
		if (!limit && !lead) vis[pos][cha] = 1, f[pos][cha] = res;
		return res;
	};
	auto solve = [&](int x) -> int {
		int len = 0;
		while (x) {
			a[++len] = x & 1;
			x >>= 1;
		}
		return dfs(1, 1, len, 30);
	};
    memset(f, -1, sizeof f);
    int l, r; cin >> l >> r;
    if (l > r) swap(l, r);
    cout << solve(r) - solve(l - 1) << '\n';
    return 0;
}
