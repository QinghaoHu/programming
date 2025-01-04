#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int n, m;

int tot = 0;
const int LOG = 19;
int head[N], ver[N << 1], edge[N << 1], nxt[N << 1];
void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
}

int d[N];
int f[N][20];
void bfs() {
    int root = 1;
    queue<int> q;
    d[root] = 1;
    q.push(root);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i]; 
            if (d[y]) continue;
            f[y][0] = x;
			d[y] = d[x] + 1;
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

long long dist[N], dfn[N];
int num = 0;
void dfs(int x) {
    dfn[x] = ++n;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (dfn[y] == 0) {
            dist[y] = dist[x] + edge[i];
            dfs(y);
        }
    }
}

long long dist_point(int x, int y) {
    return (long long)dist[x] + dist[y] - 2 * dist[lca(x, y)];
}

set<pair<int, int>> s;
int get_pre(int x) {
    auto it = s.lower_bound(make_pair(dfn[x], x));
    if (it == s.begin()) return -1;
    return (--it) -> second;
}

int get_next(int x) {
    auto it = s.upper_bound(make_pair(dfn[x], x));
    if (it == s.end()) return -1;
    return it -> second;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y, z; cin >> x >> y >> z;
		add(x, y, z); add(y, x, z);
	}
    dfs(1);
    bfs();
	cin >> m;
    long long ans = 0;
	const int inf = (int)2e9;
	s.insert({-inf, 0});
	s.insert({inf, 0});
    for (int i = 1; i <= m; i++) {
        char op; int x;
        cin >> op;
        if (op == '+') {
            cin >> x;
            if (s.size() == 2) ans = 0;
            else if (s.size() == 3) {
				auto it = s.begin();
				it++;
				ans = 2 * dist_point(it -> second, x);
			} else {
                int l = get_pre(x), r = get_next(x);
				if (l == -1) {
					ans += 2 * dist_point(r, x);
				} else if (r == -1) {
					ans += 2 * dist_point(l, x);
				} else {
					ans += dist_point(l, x) + dist_point(x, r) - dist_point(l, r);
				}
            }
			s.insert(make_pair(dfn[x], x));
        } else if (op == '-') {
            cin >> x;
            s.erase(make_pair(dfn[x], x));
            if (s.size() <= 3) ans = 0;
            else {
                int l = get_pre(x), r = get_next(x);
				if (l == -1) {
					ans -= 2 * dist_point(r, x);
				} else if (r == -1) {
					ans -= 2 * dist_point(l, x);
				} else {
					ans -= dist_point(l, x) + dist_point(x, r) - dist_point(l, r);
				}
            }
        } else {
            cout << ans / 2 << '\n';
        }
    }
    return 0;
}
