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
    
    // v, w, s
    vector<array<int, 3>> subj(n + 1, {0, 0, 0});
    for (int i = 1; i <= n; i++) {
		cin >> subj[i][0] >> subj[i][1] >> subj[i][2];
	}
	
	ll f[110][110] {};
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= v; j++) {
			for (int k = 0; k <= subj[i][2] && k * subj[i][0] <= j; k++) {
				f[i][j] = max(f[i][j], f[i - 1][j - k * subj[i][0]] + k * subj[i][1]);
				//~cerr << f[i][j] << "\n";
			}
		}
	}
	
	cout << f[n][v] << "\n";
		
    return 0;
}
