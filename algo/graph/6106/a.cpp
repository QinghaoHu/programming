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
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, p, s;
	cin >> n >> m >> p >> s;
	const int MAXN = 25005;
	vector<array<int, 3>> path[MAXN];
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		path[x].push_back({y, z, 0});
		path[y].push_back({x, z, 0});
  }
	for (int i = 1; i <= p; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		path[x].push_back({y, z, 1});
	}
	int cnt = 0;
	vector<int> c(n + 1, 0), a[MAXN];
	function<void(int)> dfs = [&](int x) {
		c[x] = cnt;
		a[cnt].push_back(x);
		for (auto [i, j, k] : path[x]) {
			if (k == 1) continue;
			if (!c[i]) {
				dfs(i);
			}
		}
	};
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) {
			++cnt;
			dfs(i);
		}
	}
	vector<int> deg(cnt + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (auto [j, p, s] : path[i]) {
			if (s == 0) continue;
			++deg[c[j]];
		}
	}
	queue<int> q;
	for (int i = 1; i <= cnt; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}
	vector<int> d(n + 1, 2e9);
	vector<int> v(n + 1, 0);
	d[s] = 0;
	auto dijkestra = [&](int k) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
		for (auto i : a[k]) {
			heap.push({d[i], i});
		}
		while (!heap.empty()) {
			int x = heap.top().second;
			heap.pop();
			if (v[x]) continue;
			v[x] = 1;
			for (auto [i, j, k] : path[x]) {
				if (k == 0) {
					if (d[i] > d[x] + j) {
						d[i] = d[x] + j;
						heap.push({d[i], i});
					}
				} else {
					d[i] = min(d[i], d[x] + j);
					if (--deg[c[i]] == 0) q.push(c[i]);
				}
			}
		}
	};
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		dijkestra(x);
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] > n * 10000) cout << "NO PATH\n";
		else cout << d[i] << '\n';
	}
	return 0;
}
