#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)

typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;

const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}
//head

int n, m;

void solve() {
	cin >> n >> m;
	vector<pair<int, int>> pd(n + 1);
	rep(i, 1, n + 1) {
		cin >> pd[i].first >> pd[i].second;
	}
	
	int f[210][21][810], base = 400, M = 810;
	memset(f, -0x3f, sizeof f);
	f[0][0][base] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k < M; k++) {
				f[i][j][k] = f[i - 1][j][k];
				int t = k - (pd[i].first - pd[i].second);
				if (t < 0 || t >= M) continue;
				if (j < 1) continue;
				f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][t] + pd[i].first + pd[i].second);
			}
		}
	}
	
	int v = 0;
	while (f[n][m][base - v] < 0 && f[n][m][base + v] < 0) v++;
	if (f[n][m][base - v] > f[n][m][base + v]) v = base - v;
	else v = base + v;
	
	cerr << 1 << "\n";
	
	int i = n, j = m, k = v;
	vector<int> ans;
	while (j) {
		if (f[i][j][k] == f[i - 1][j][k]) {
			i--;
		} else {
			ans.push_back(i);
			k -= pd[i].first - pd[i].second;
			i--, j--;
		}
	} 
	int ps = 0, ds = 0;
	for (int g : ans) {
		ps += pd[g].first;
		ds += pd[g].second;
	}
	cout << "Best jury has value " << ps << " for prosecution and value " << ds << " for defence:\n";
	reverse(ans.begin(), ans.end());
	for (int g : ans) {
		cout << " " << g;
	}
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    //~int tt = 1;
    //~while (cin >> n >> m, n || m) {
		//~cout << "Jury #" << tt++ << "\n";
		//~solve();
	//~}
	solve();
	
    return 0;
}
