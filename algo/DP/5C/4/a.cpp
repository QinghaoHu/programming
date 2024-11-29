#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

void solve() {
	int n; ll c; cin >> n >> c;
	ll f[21][21][2] {};
	f[1][1][0] = f[1][1][1] = 1;
	for (int i = 2; i <= 20; i++) {
		for (int j = 1; j <= i; j++) {
			for (int p = j; p <= i - 1; p++) {
				f[i][j][0] += f[i - 1][p][1];
			}
			for (int p = 1; p < j; p++) {
				f[i][j][1] += f[i - 1][p][0];
			}
		}
	}
    vector<bool> used(n + 1, false);
	int now = -1, pos = -1;
	for (int i = 1; i <= n; i++) {
		if (f[n][i][1] >= c) {
			now = i, pos = 1;
			break;
		} else c -= f[n][i][1];
		if (f[n][i][0] >= c) {
			now = i, pos = 0;
			break;
		} else c -= f[n][i][0];
	}
	cout << now << ' ';
	used[now] = 1;
	for (int i = 2; i <= n; i++) {
		pos ^= 1;
		for (int len = 1, j = 0; len <= n; len++) {
			if (used[len]) continue;
			j++;
			if ((pos == 0 && len < now) || (pos == 1 && len > now)) {
				if (f[n - i + 1][j][pos] >= c) {
                    now = len;
                    cout << now << ' ';
                    used[now] = 1;
                    break;
                } else c -= f[n - i + 1][j][pos];
			}
		}
	}
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int _;
    cin >> _;
    while (_--) solve();

    return 0;
}
