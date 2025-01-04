#include <bits/stdc++.h>
using namespace std;

const int N = 50010;
int f[N][20], d[N], dist[N];
int ver[N << 1], nxt[N << 1], edge[N << 1], head[N];
int T, n, m, tot, t;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
}

void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i]; 
			if (d[y]) continue;
			d[y] = d[x] + 1;
			dist[y] = dist[x] + edge[i];
			f[y][0] = x;
			for (int j = 1; j <= 20; j++) {
				f[y][j] = f[f[y][j - 1]][j - 1];
			}
			q.push(y);
		}
	}
}

int lca(int x, int y) {
	if (d[x] < d[y]) swap(x, y);
	for (int i = t; i >= 0; i--) {
		if (d[f[x][i]] >= d[y]) x = f[x][i];
	}
	if (x == y) return x;
	for (int i = 19; i >= 0; i--) {
		if (d[f[x][i]] != d[f[y][i]]) x = f[x][i], y = f[y][i];
	}
	return f[x][0];
}

int dis(int x, int y, int lcat) {
	return d[x] + d[y] - 2 * d[lcat];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	return 0;
}
