#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
	const int N = 500005;
	// linklist
	int d[N] {}, ver[N << 1] {}, head[N] {}, nxt[N << 1] {}, edge[N << 1] {}, pre[N << 1] {};
	int a[N] {}, b[N] {};
	int n, s, t = 0; cin >> n >> s;
	int tot = 1;
	auto add = [&](int x, int y, int z) -> void {
		ver[++tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
	};
	for (int i = 1; i < n; i++) {
		int x, y, z; cin >> x >> y >> z;
		add(x, y, z), add(y, x, z);
	}
	auto bfs = [&](int x) -> int {
		memset(d, -1, sizeof d);
		d[x] = 0;
		queue<int> q; q.push(x);
		while (!q.empty()) {
			int t = q.front(); q.pop();
			for (int i = head[t]; i; i = nxt[i]) {
				int y = ver[i];
				if (d[y] != -1) continue;
				d[y] = d[t] + edge[i];
				pre[y] = i;
				q.push(y);
			}
		}
		int j = x;
		for (int i = 1; i <= n; i++) {
			if (d[i] > d[j]) j = i;
		}
		return j;
	};
	int p = bfs(1), q = bfs(p);
	while (q != p) {
		a[++t] = q;
		b[t + 1] = edge[pre[q]];
		q = ver[pre[q] ^ 1];
	}
	a[++t] = p;
	bool v[N] {};
	int f[N] {}; int sum[N] {};
	for (int i = 1; i <= t; i++) v[a[i]] = true;
	function<void(int)> dfs = [&](int x) {
		v[x] = true;
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			if (v[y]) continue;
			dfs(y);
			f[x] = max(f[x], f[y] + edge[i]);
		}
	};
	int maxf = 0;
	for (int i = 1; i <= t; i++) {
		dfs(a[i]);
		maxf = max(maxf, f[a[i]]);
		sum[i] = sum[i - 1] + b[i];
	}
	int ans = 2e9;
	for (int i = 1, j = 1; i <= t; i++) {
		while (j < t && sum[j + 1] - sum[i] <= s) j++;
		ans = min(ans, max(maxf, max(sum[i], sum[t] - sum[j])));
	}
	
	cout << ans << '\n';
    return 0;
}
