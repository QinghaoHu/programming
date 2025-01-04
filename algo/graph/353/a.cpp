#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, m, cnt, num;
int ver[N << 2], head[N], nxt[N << 2], tot;
int d[N], f[N][20], vals[N];
int root[N];
struct {int lc, rc, dat, pos;} tr[N * 4 * 18];
struct {int x, y, z;} a[N];

void bfs() {
	d[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			if (d[y]) continue;
			q.push(y);
			d[y] = d[x] + 1;
			f[y][0] = x;
			for (int i = 1; i <= 19; i++) {
				f[y][i] = f[f[y][i - 1]][i - 1];
			}
		}
	}
}

int lca(int x, int y) {
	if (d[y] > d[x]) swap(x, y);
	for (int i = 19; i >= 0; i--) {
		if (d[f[x][i]] >= d[y]) x = f[x][i];
	}
	if (x == y) return x;
	for (int i = 19; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i], y = f[y][i];
		}
	}
	return f[x][0];
}

void add(int x, int y) {
	ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}

void insert(int p, int l, int r, int idx, int delta) {
	if (l == r) {
		tr[p].dat += delta;
		tr[p].pos = tr[p].dat ? idx : 0;
		return;
	}
	int mid = l + r >> 1;
	if (idx <= mid) {
		if (tr[p].lc == 0) tr[p].lc = ++num;
		insert(tr[p].lc, l, mid, idx, delta);
	} else {
		if (tr[p].rc == 0) tr[p].rc = ++num;
		insert(tr[p].rc, mid + 1, r, idx, delta);
	}
	tr[p].dat = max(tr[tr[p].lc].dat, tr[tr[p].rc].dat);
	tr[p].pos = tr[tr[p].lc].dat >= tr[tr[p].rc].dat ? tr[tr[p].lc].pos : tr[tr[p].rc].pos;
}

int merge(int p, int q, int l, int r) {
	if (!p) return q;
	if (!q) return p;
	if (l == r) {
		tr[p].dat += tr[q].dat;
		tr[p].pos = tr[p].dat ? l : 0;
		return p;
	}
	int mid = l + r >> 1;
	tr[p].lc = merge(tr[p].lc, tr[q].lc, l, mid);
	tr[p].rc = merge(tr[p].rc, tr[q].rc, mid + 1, r);
	tr[p].dat = max(tr[tr[p].lc].dat, tr[tr[p].rc].dat);
	tr[p].pos = tr[tr[p].lc].dat >= tr[tr[p].rc].dat ? tr[tr[p].lc].pos : tr[tr[p].rc].pos;
	return p;
}

void dfs(int x) {
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (d[y] <= d[x]) continue;
		dfs(y);
		root[x] = merge(root[x], root[y], 1, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		add(x, y); add(y, x);
	}
	bfs();
	for (int i = 1; i <= n; i++) root[i] = ++num;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		vals[i] = a[i].z;
	}
	sort(vals + 1, vals + m + 1);
	cnt = unique(vals + 1, vals + m + 1) - vals - 1;
	for (int i = 1; i <= m; i++) {
		int x = a[i].x, y = a[i].y;
		int z = lower_bound(vals + 1, vals + cnt + 1, a[i].z) - vals;
		int u = lca(x, y);
		insert(root[x], 1, cnt, z, 1);
		insert(root[y], 1, cnt, z, 1);
		insert(root[u], 1, cnt, z, -1);
		if (u != 1) insert(root[f[u][0]], 1, cnt, z, -1);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) cout << vals[tr[root[i]].pos] << '\n';
	return 0;
}
