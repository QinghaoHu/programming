#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> price(n + 1, 0), path[100010];
	for (int i = 1; i <= n; i++) {
		cin >> price[i];
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		path[x].emplace_back(y);
		if (z == 2) {
			path[y].emplace_back(x);
		}
	}

	vector<int> d(n + 1, 0x3f3f3f3f);
	queue<int> q;
	vector<int> isV(n + 1, 0);
	int ans = INT_MIN;
	auto spfa = [&]() -> void {
		isV[1] = 1;
		q.push(1);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			isV[x] = 0;
			d[x] = min(d[x], price[x]);
			ans = max(ans, price[x] - d[x]);
			for (auto i : path[x]) {
				if (d[i] > d[x]) {
					d[i] = d[x];
					if (!isV[i]) {
						isV[i] = 1;
						q.push(i);
					}
				}
			}
		}
	};
	spfa();
	cout << ans << '\n';

	return 0;
}
