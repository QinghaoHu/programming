#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i=a; i<n; i++)
#define per(i, a, n) for (int i=a; i>=n; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define arr array
#define SZ(x) ((int)x.size())
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
const int N = 3010;
int n;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	rep(i, 1, n + 1) {
		cin >> a[i];
	}
	rep(i, 1, n + 1) {
		cin >> b[i];
	}

	vector f(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		int s = 0;
		for (int j = 1; j <= n; j++) {
			f[i][j] = max(f[i][j], f[i - 1][j]);
			if (a[i] == b[j]) {
				f[i][j] = max(f[i][j], s + 1);
			}
			if (b[j] < a[i]) {
				s = max(f[i - 1][j], s);
			}
		}
	}

	int ans = 0;
	rep(i, 1, n + 1) {
		ans = max(ans, f[n][i]);
	}
	cout << ans << "\n";

    return 0;
}