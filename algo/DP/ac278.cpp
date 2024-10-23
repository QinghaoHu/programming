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

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int f[10010] {};
	f[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 0; j--) {
			if (j >= a[i]) {
				f[j] += f[j - a[i]];
			}
		}
	}
	
	cout << f[m] << " \n";

    return 0;
}
