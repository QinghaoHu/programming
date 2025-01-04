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

const int MAXN = 100005, MAXM = 300005;
int ver[2*MAXN], edge[2*MAXN], nxt[2*MAXN], head[MAXN], tot;
int d[MAXN], f[MAXN][18], g[MAXN][18][2], fa[MAXN];
int n, m;
queue<int> q;
struct rec{int x, y, z;} a[MAXM];
bool chose[MAXM];

bool operator <(const rec& a, const rec& b) {
    return a.z < b.z;
}

// Linklist
const int LOG = 20;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, nxt[tot] = head[x], head[x] = tot;
}


void merge(int c[2], int a[2], int b[2]) {
	if (a[0] == b[0]) c[1] = max(a[1], b[1]);
	else if (a[0] > b[0]) c[1] = max(a[1], b[0]);
	else c[1] = max(a[0], b[1]);
	c[0] = max(a[0], b[0]);
}

void bfs(int n, int root) {
    d[root] = 1;
    q.push(root);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i]; 
            if (d[y]) continue;
            d[y] = d[x] + 1;
            f[y][0] = x;
			g[y][0][0] = edge[i];
            for (int j = 1; j < LOG; j++) {
                f[y][j] = f[f[y][j - 1]][j - 1];
				merge(g[y][j], g[y][j - 1], g[f[y][j - 1]][j - 1]);
            }
            q.push(y);
        }
    }
}

int lca(int ans[2], int x, int y) {
	ans[0] = ans[1] = 0;
    if (d[x] < d[y]) swap(x, y);
    for (int i = LOG - 1; i >= 0; i--) {
        if (d[f[x][i]] >= d[y]) {
			merge(ans, ans, g[x][i]);
			x = f[x][i];
		}
    }
    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
			merge(ans, ans, g[x][i]);
			merge(ans, ans, g[y][i]);
            x = f[x][i];
            y = f[y][i];
        }
    }
	merge(ans, ans, g[x][0]);
	merge(ans, ans, g[y][0]);
    return f[x][0];
}

int get(int x) {
	return (x == fa[x]) ? x : (fa[x] = get(fa[x]));
}


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i].x >> a[i].y >> a[i].z;
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	ll mst = 0;
	for (int i = 1; i <= m; i++) {
		int x = get(a[i].x), y = get(a[i].y);
		if (x != y) {
			chose[i] = true;
			mst += a[i].z;
			fa[y] = x;
			add(a[i].x, a[i].y, a[i].z);
			add(a[i].y, a[i].x, a[i].z);
		}
	}
	bfs(n, 1);
	int delta = 1 << 30;
	for (int i = 1; i <= m; i++) {
		if (chose[i]) continue;
		if (a[i].x == a[i].y) continue;
		int temp[2];
		lca(temp, a[i].x, a[i].y);
		if (temp[0] < a[i].z) delta = min(delta, a[i].z - temp[0]);
		else if (temp[1]) delta = min(delta, a[i].z - temp[1]);
	}
	cout << mst + delta << '\n';
	return 0;
}
