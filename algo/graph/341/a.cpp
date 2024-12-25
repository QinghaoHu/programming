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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	const int MAXN = 100010;
	vector<int> mp1[MAXN], mp2[MAXN];
	vector<int> w(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		mp1[x].emplace_back(y);
		mp2[y].emplace_back(x);
		if (z == 2) {
			mp1[y].emplace_back(x);
			mp2[x].push_back(y);
		}
	}
	const int inf = (int)1e9;
	vector<int> d(n + 1, inf);
	queue<int> q;
	q.push(1); 
	while (!q.empty()) {
		int u = q.front(); q.pop();
		d[u] = min(d[u], w[u]);
		for (auto v : mp1[u]) {
			if (w[u] < d[v]) {
				d[v] = w[u];
				q.push(v);
			}
		}
	}
	_println(d);
	vector<int> f(n + 1, 0);
	q.push(n);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		f[u] = max(w[u], f[u]);
		for (auto v : mp2[u]) {
			if (w[u] > f[v]) {
				f[v] = w[u];
				q.push(v);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, f[i] - d[i]);
	}
	cout << ans << '\n';
	return 0;
}
