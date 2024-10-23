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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, v;
    cin >> n >> v;
    
    vector<pair<int, int>> s[110];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int v, w;
			cin >> v >> w;
			s[i].push_back(make_pair(v, w));
		}
	}
	
	int f[110] {};
	memset(f, -0x3f, sizeof f);
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= 0; j--) {
			for (int k = 0; k < s[i].size(); k++) {
				if (j >= s[i][k].first) {
					f[j] = max(f[j], f[j - s[i][k].first] + s[i][k].second);
				}
			}
		}
	}
	
	cout << f[v] << "\n";
	
    return 0;
}
