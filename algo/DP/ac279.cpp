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
const ll mod = (ll)INT_MAX + 1;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    
    vector<ll> f(n + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			f[j] = (f[j] + f[j - i]) % mod;
		}
	}
	
	cout << f[n] - 1 << "\n";

    return 0;
}
