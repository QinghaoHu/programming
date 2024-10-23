#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
    
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	
	vector<pair<int, int>> g(n + 1, {0, 0});
	for (int i = 1; i <= n; i++) {
		cin >> g[i].first;
		g[i].second = i;
	}
	sort(g.begin() + 1, g.end(), [&](pair<int, int> a, pair<int, int> b) {
		return a.first > b.first;
	});
	
	vector<int> s(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + g[i].first;
	}
	
	vector f(n + 1, vector<int>(m + 1, INF));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j < i) continue;
			f[i][j] = f[i][j - i];
			for (int k = 1; k <= i; k++) {
				f[i][j] = min(f[i][j], f[i - k][j - k] + (s[i] - s[i - k]) * (i - k));
			}
		}
	}
	
	cout << f[n][m] << "\n";
	
	vector<int> ans(n + 1, 0);
	int i = n, j = m, h = 0;
	while (i) {
		if (f[i][j] == f[i][j - i]) {
			j -= i;
			h++;
		} else {
			for (int k = 1; k <= i; k++) {
				if (f[i][j] == f[i - k][j - k] + (s[i] - s[i - k]) * (i - k)) {
					for (int u = i - k + 1; u <= i; u++) {
						ans[g[u].second] = 1 + h;
					}
					i -= k, j -= k;
					break;
				}
			}
		}
	}
	
	for (i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";

    return 0;
}
