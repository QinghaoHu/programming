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
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
		
	int n, k; cin >> n >> k;
	int tot = 1;
	const int N = 100005;
	int d[N] {}, edge[N << 1] {}, pre[N] {}, head[N] {}, nxt[N << 1] {}, ver[N << 1] {};
	auto add = [&](int x, int y) -> void {
		ver[++tot] = y, edge[tot] = 1, nxt[tot] = head[x], head[x] = tot; 
	};
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		add(x, y), add(y, x);
	}
	auto bfs = [&](int x) -> int {
		memset(d, -1, sizeof d);
		d[x] = 0;
		queue<int> q; q.push(x);
		while (!q.empty()) {
			int a = q.front(); q.pop();
			for (int i = head[a]; i; i = nxt[i]) {
				int y = ver[i];
				if (d[y] != -1) continue;
				d[y] = d[a] + 1;
				pre[y] = i;
				q.push(y);
			}
		}
		int bRet = x;
		for (int i = 1; i <= n; i++) {
			if (d[i] > d[bRet]) bRet = i;
		}
		return bRet;
	};
	int p = bfs(1), q = bfs(p);
	int ans = 2 * (n - 1) - d[q] + 1;
	if (k == 1) {
		cout << ans << '\n';
		return 0;
	}
	auto update = [&](int p, int q) -> void {
		while (p != q) {
			edge[pre[p]] = -1;
			edge[pre[p] ^ 1] = -1;
			p = ver[pre[p] ^ 1];
		}
	};
	update(q, p);
	memset(d, 0, sizeof d);
	int l2 = 0;
	function<void(int, int)> dp = [&](int x, int fa) {
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			if (y == fa) continue;
			dp(y, x);
			l2 = max(l2, d[x] + d[y] + edge[i]);
			d[x] = max(d[x], d[y] + edge[i]);
		}
	};
	dp(1, 0);
	cout << ans - l2 + 1 << '\n';

	return 0;
}
