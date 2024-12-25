#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int k, m, s, e; cin >> k >> m >> s >> e;
	unordered_map<int, int> hash;
	int idx = 0;
	hash[s] = ++idx; 
	hash[e] = ++idx;
	s = hash[s];
	e = hash[e];

	const int inf = (int)1e9;
	int n = 210;
	vector g(n + 1, vector<int>(n + 1, inf));
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> c >> a >> b;
		if (!hash.count(a)) hash[a] = ++idx;
		if (!hash.count(b)) hash[b] = ++idx;
		a = hash[a], b = hash[b];
		g[a][b] = g[b][a] = min(g[a][b], c);
	}

	auto mul = [&](vector<vector<int>> a, vector<vector<int>> b) -> vector<vector<int>> {
		vector<vector<int>> res(n + 1, vector<int>(n + 1, inf));
		for (int i = 1; i <= idx; i++) res[i][i] = 0;
		for (int k = 1; k <= idx; k++) {
			for (int i = 1; i <= idx; i++) {
				for (int j = 1; j <= idx; j++) {
					res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
				}
			}
		}
		return res;
	};

	vector res(n + 1, vector<int>(n + 1, inf));
    for (int i = 1; i <= idx; i++) res[i][i] = 0;
	for (int i = 1; i <= n; i++) res[i][i] = 0;
	while (k) {
		if (k & 1) {
			res.assign(mul(res, g).begin(), mul(res, g).end());
		}
		g.assign(mul(g, g).begin(), mul(g, g).end());
		k >>= 1;
	}
	cout << res[s][e] << '\n';
	
	return 0;
}
