#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 100010;
constexpr int LOG = 20;

int ver[N << 1], head[N], edge[N << 1], nxt[N << 1];
int tot = 1;
int d[N], dist[N], fa[N];
int f[N][LOG], dfn[N];
int sum[N];

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
}

void spfa() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	std::queue<int> q;
	bool isV[N];
	isV[1] = true;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		isV[x] = false;
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			if (dist[y] > dist[x] + edge[i]) {
				dist[y] = dist[x] + edge[i];
				if (!isV[y]) q.push(y), isV[y] = true;
			}
		}
	}
}

void get_circle(int x, int y, int z) {
	sum[y] = z;
}

int num = 0;
void dfs(int x) {
	dfn[++num] = x;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (!dfn[y]) {
			fa[y] = i;
			dfs(y);
		} else if ((i ^ 1) != fa[x] && dfn[y] > dfn[x]) {
			get_circle(x, y, edge[i]);
		}
	}
}

int lca(int x, int y) {
	if (d[x] < d[y]) std::swap(x, y);
	for (int i = LOG - 1; i >= 0; i--) {
		if (d[f[x][i]] >= d[y]) x = f[x][i];
	}
	for (int i = LOG - 1; i >= 0; i--) {
		if (d[f[x][i]] != d[f[y][i]]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
} 

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	return 0;
}
