#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if (m == 1) {
		cout << 2 * (n - x) << '\n';
		return 0;
	}
	double f[N][N] {}, d[N][N] {};
	
	auto gauss = [&]() -> void {
		for (int i = 1; i <= m; i++) {
			double w = 1.0 / d[i][i];
			d[i][i] *= w;
			d[i][m + 1] *= w;
			if (i == m) break;
			d[i][i + 1] *= w;
			w = d[i + 1][i] / d[i][i];
			d[i + 1][i] -= w * d[i][i];
			d[i + 1][i + 1] -= w * d[i][i + 1];
			d[i + 1][m + 1] -= w * d[i][m + 1];
		}
		for (int i = m - 1; i >= 1; i--) {
			d[i][m + 1] -= d[i][i + 1] * d[i + 1][m + 1];
		}
	};
	
	for (int i = n - 1; i >= x; i--) {
		d[1][1] = d[m][m] = -2.0 / 3;
		d[1][2] = d[m][m - 1] = 1.0 / 3;
		for (int j = 2; j < m; j++) {
			d[j][j] = -3.0 / 4;
			d[j][j - 1] = d[j][j + 1] = 1.0 / 4;
			d[j][m + 1] = -f[i + 1][j] / 4 - 1;
		}
		d[1][m + 1] = -f[i + 1][1] / 3 - 1;
		d[m][m + 1] = -f[i + 1][m] / 3 - 1;
		gauss();
		for (int j = 1; j <= m; j++) {
			f[i][j] = d[j][m + 1];
		}
	}
	cout << fixed << setprecision(10) << f[x][y] << '\n';
	
    return 0;
}
