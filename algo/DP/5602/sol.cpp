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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector c(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		}
	}
	vector<int> cnt(1 << m, 0), state;
	for (int i = 0; i < 1 << m; i++) {
		vector<int> ones;
		for (int j = 0; j < m; j++) {
			if (i >> j & 1) {
				ones.push_back(j);
			}
		}
		cnt[i] = ones.size();
		bool flag = true;
		for (int j = 1; j < ones.size(); j++) {
			if (ones[j] - ones[j - 1] < 3) {
				flag = false;
				break;
			}
		}
		if (flag) {
			state.push_back(i);
		}
	}
	const int N = 105;
	vector valid(n + 1, vector<int>(N, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < state.size(); j++) {
			bool flag = true;
			for (int k = 0; k < m; k++) {
				if ((state[j] >> k & 1) && c[i][k + 1] == 'H') {
					flag = false;
					break;
				}
			}
			valid[i][j] = flag;
		}
	}
	int f[N][N][N] {};
	memset(f, 0xcf, sizeof f);
	f[0][0][0] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < state.size(); j++) {
			if (!valid[i][j]) continue;
			for (int k = 0; k < state.size(); k++) {
				if ((state[j] & state[k]) || (i > 1 && !valid[i - 1][k])) continue;
				for (int l = 0; l < state.size(); l++) {
					if (state[l] & state[j]) continue;
					f[i][j][k] = max(f[i][j][k], f[i - 1][k][l] + cnt[state[j]]);
				}
				if (i == n) ans = max(ans, f[i][j][k]);
			}
		}
	}
	cout << ans << '\n';
	
    return 0;
}
