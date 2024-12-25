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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  const int inf = (int)1e9;
  vector<vector<int>> a(n + 1, vector<int>(n + 1, inf));
  vector<vector<int>> d(n + 1, vector<int>(n + 1, inf));
  for (int i = 1; i <= n; i++) a[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x][y] = a[y][x] = min(a[x][y], z);
	}
	d.assign(a.begin(), a.end());
	vector<int> path;
	vector<vector<int>> pos(n + 1, vector<int>(n + 1, 0));
	function<void(int, int)> get_path = [&](int x, int y) {
		if (pos[x][y] == 0) return;
		get_path(x, pos[x][y]);
		path.push_back(pos[x][y]);
		get_path(pos[x][y], y);
	};
	int ans = inf;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if ((ll)d[i][j] + a[j][k] + a[k][i] < ans) {
					ans = d[i][j] + a[j][k] + a[k][i];
					path.clear();
					path.push_back(i);
					get_path(i, j);
					path.push_back(j);
					path.push_back(k);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					pos[i][j] = k;
				}
			}
		}
	}
	if (ans == inf) {
		cout << "No solution.\n";
		return 0;
	}
	for (int i = 0; i < (int)path.size() - 1; i++) {
		cout << path[i] << ' ';
	}
	cout << path[(int)path.size() - 1] << '\n';
	return 0;
}
