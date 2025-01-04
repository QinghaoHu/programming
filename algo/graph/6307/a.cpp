#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = (int)3e5 + 10;
int n, m;
int ver[N << 1], head[N], nxt[N << 1], tot;
int d[N];
vector<int> w(N);

void add(int x, int y) {
	ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}

const int LOG = 20;
int f[N][21] {};

void bfs() {
    queue<int> q;
    d[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i]; 
            if (d[y]) continue;
            d[y] = d[x] + 1; 
            f[y][0] = x;
            for (int j = 1; j < LOG; j++) {
                f[y][j] = f[f[y][j - 1]][j - 1];
            }
            q.push(y);
        }
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    for (int i = LOG - 1; i >= 0; i--) {
        if (d[f[x][i]] >= d[y]) x = f[x][i];
    }
    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

struct opr {
	int idx, delta, kind;
	opr() {}
	opr(int idx, int delta, int kind): idx(idx), delta(delta), kind(kind) {}
};
vector<opr> a[N];
int c[2][N << 1];
int ans[N] {};

void dfs(int x) {
	int val0 = c[0][w[x] + d[x]];
	int val1 = c[1][w[x] - d[x] + n];
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (d[y] <= d[x]) continue;
		dfs(y);
	}
	for (int i = 0; i < (int)a[x].size(); i++) {
		c[a[x][i].kind][a[x][i].idx] += a[x][i].delta;
	}
	ans[x] = c[0][w[x] + d[x]] - val0 + c[1][w[x] - d[x] + n] - val1;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		add(x, y); add(y, x);
	}
	bfs();
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= m; i++) {
		int s, t; cin >> s >> t;
		int u = lca(s, t);
		a[s].push_back(opr(d[s], 1, 0));
		if (f[u][0]) a[f[u][0]].push_back(opr(d[s], -1, 0));

		a[t].push_back(opr(d[s] - 2 * d[u] + n, 1, 1));
		a[u].push_back(opr(d[s] - 2 * d[u] + n, -1, 1));
	}
	dfs(1);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}
