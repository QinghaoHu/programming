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

const int N = 50005;
int n, m; int head[N], ver[N << 1], edge[N << 1], nxt[N << 1];
int tot = 0;
pair<long long, int> a[N];
bool cover[N], has[N];

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z;
	nxt[tot] = head[x], head[x] = tot;
}

int d[N];
ll dist[N];
int f[N][20];
void bfs() {
	d[1] = 1;
	queue<int> q; q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			if (d[y] != 0) continue;
			d[y] = d[x] + 1;
			dist[y] = dist[x] + edge[i];
			q.push(y);
			f[y][0] = x;
			for (int k = 1; k < 20; k++) {
				f[y][k] = f[f[y][k - 1]][k - 1];
			}
		}
	}
}

pair<ll, int> go(int x, ll mid) {
	for (int i = 17; i >= 0; i--) {
		if (f[x][i] > 1 && dist[x] - dist[f[x][i]] <= mid) {
			mid -= dist[x] - dist[f[x][i]];
			x = f[x][i];
		}
	}
	return make_pair(mid, x);
}

int son[N], p;
void dfs(int x) {
	bool all_child_covered = true;
	bool is_leaf = true;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (d[y] <= d[x]) continue;
		dfs(y);
		all_child_covered &= cover[y];
		is_leaf = false;
		if (x == 1 && !cover[y]) son[++p] = y;
	}
	cover[x] = has[x] || (!is_leaf && all_child_covered);
}

bool cmp(int x, int y) {
	return dist[x] < dist[y];
}

bool used[N]; int cnt = 0;
int army[N];
bool solve(ll mid) {
	memset(has, 0, sizeof has);
	memset(cover, 0, sizeof cover);
	memset(used, 0, sizeof used);
	cnt = p = 0;
	for (int i = 1; i <= m; i++) {
		pair<ll, int> pr = go(army[i], mid);
		ll rest = pr.first;
		int pos = pr.second;
		if (rest <= dist[pos]) has[pos] = true;
		else a[++cnt] = make_pair(rest - dist[pos], pos);
	}
	dfs(1);
	sort(a + 1, a + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		ll rest = a[i].first;
		int s = a[i].second;
		if (!cover[s] && rest < dist[s]) {
			cover[s] = used[i] = true;
		}
	}
	sort(son + 1, son + p + 1, cmp);
	for (int i = 1, j = 1; i <= p; i++) {
		int s = son[i];
		if (cover[s]) continue;
		while (j <= cnt && (used[j] || a[j].first < dist[s])) j++;
		if (j > cnt) return false;
		j++;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	ll l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		int x, y, z; cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
		r += z;
	}
	bfs();
	cin >> m;
	int s = r;
	for (int i = 1; i <= m; i++) cin >> army[i];
	while (l < r) {
		ll mid = l + r >> 1;
		if (solve(mid)) r = mid;
		else l = mid + 1;
	}
	if (l == s) cout << -1 << '\n';
	else cout << l << '\n';
	return 0;
}

