#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector a(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x][y] = a[y][x] = min(a[x][y], z);
	}
	vector<int> expand(1 << n, 0);
	vector road(1 << n, vector<int> (n + 1, INF));
	for (int k = 0; k < 1 << n; k++) {
		expand[k] = k;
		for (int x = 1; x <= n; x++) {
			if (k >> (x - 1) & 1) {
				road[k][x] = 0;
				for (int y = 1; y <= n; y++) {
					if (a[x][y] == INF) continue;
					expand[k] |= 1 << (y - 1);
					road[k][y] = min(road[k][y], a[x][y]);
				}
			}
		}
	}
	vector<int> valid[1 << 12], cost[1 << 12];
	for (int j = 0; j < 1 << n; j++) {
		for (int k = 0; k < j; k++) {
			if ((j & k) == k && (j & expand[k]) == j) {
				valid[j].push_back(k);
				int sum = 0;
				for (int i = 1; i <= n; i++) {
					if ((j ^ k) >> (i - 1) & 1) {
						sum += road[k][i];
					}
				}
				cost[j].push_back(sum);
			}
		}
	}
	vector f(n + 1, vector<int>(1 << n, INF));
	for (int i = 1; i <= n; i++) {
		f[1][1 << (i - 1)] = 0;
	}
	int ans = f[1][(1 << n) - 1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < 1 << n; j++) {
			for (int p = 0; p < valid[j].size(); p++) {
				int k = valid[j][p];
				f[i][j] = min(f[i][j], f[i - 1][k] + (i - 1) * cost[j][p]);
			}
		}
		ans = min(ans, f[i][(1 << n) - 1]);
	}
	cout << ans << '\n';
	srand(time(0));
	cout << rand() % 10  << '\n';
	
    return 0;
}
