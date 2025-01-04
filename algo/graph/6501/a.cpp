#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5050;
int n, m;
int ver[N], head[N], nxt[N];
double edge[N];
double dist[N];
bool visit[N];
std::vector<int> fun;
struct rec { int x, y, times; } a[N];
int tot = 0;

void add(int x, int y, double z) {
	ver[++tot] = y, edge[tot] = z;
	nxt[tot] = head[x], head[x] = tot;
}

bool spfa() {
	memset(dist, 0, sizeof dist);
	std::queue<int> q;
	std::array<int, N> cnt;

	for (int i = 1; i <= n; i++) {
		visit[i] = true;
		cnt[i] = 0;
		q.push(i);

	}

	while (!q.empty()) {
		int x = q.front(); q.pop();
		visit[x] = false;

		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			double z = edge[i];
			if (dist[y] > dist[x] + z) {
				dist[y] = dist[x] + z;
				cnt[y] = cnt[x] + 1;
				if (cnt[y] >= n) return true;
				if (!visit[y]) {
					q.push(y);
					visit[y] = true;
				}
			}
		}
	}
	return false;
}

const double eps = 1e-4;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	
	fun.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> fun[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i].x >> a[i].y >> a[i].times;
	}
	
	double l = 0, r = 1e6;
	while (r - l > eps) {
		double mid = (l + r) / 2;
		memset(head, 0, sizeof head);
		tot = 0;
		for (int i = 1; i <= m; i++) add(a[i].x, a[i].y, mid * a[i].times - fun[a[i].x]);
		if (spfa()) l = mid; else r = mid;
	}
	
	std::cout << std::fixed << std::setprecision(2) << r << '\n';

	return 0;
}
