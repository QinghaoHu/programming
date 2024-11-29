#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 0x3f3f3f3f;
#define rep(x, y, z) for(int x = y; x < z; x++)
#define per(x, y, z) for(int x = z; x >= y; x--)

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int f[21][4] {};
    f[0][0] = 1;
    for (int i = 1; i <= 20; i++) {
    	f[i][0] = 9 * (f[i - 1][0] + f[i - 1][1] + f[i - 1][2]);
    	f[i][1] = f[i - 1][0];
    	f[i][2] = f[i - 1][1];
    	f[i][3] = f[i - 1][2] + 10 * f[i - 1][3];
    }

    int tt; cin >> tt;
    while (tt--) {
    	int x; cin >> x;
    	int n;
    	for (n = 1; f[n][3] < x; n++);

    	int cnt = 0;
    	for (int i = 1; i <= n; i++) {
    		for (int j = 0; j <= 9; j++) {
    			int six = 3;
    			if (cnt == 3) {
    				six = 0;
    			} else if (j == 6) {
    				six = 3 - cnt - 1;
    			}

    			int sum = 0;
    			for (int k = six; k <= 3; k++) sum += f[n - i][k];

    			if (sum >= x) {
    				cout << j;
    				if (cnt < 3) {
    					if (j == 6) cnt++;
    					else cnt = 0;
    				}
    				break;
    			} else x -= sum;
    		}
    	}
    	cout << '\n';
    }

    return 0;
}
