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
const int N = 31;
int f[N][N][N][N][N];
int a[6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n) {
    	for (int i = 1; i <= n; i++) {
    		cin >> a[i];
    	}
    	while (n < 5) a[++n] = 0;
    	memset(f, 0, sizeof f);
    	f[0][0][0][0][0] = 1;
    	for (int a1 = 0; a1 <= a[1]; a1++) {
    		for (int a2 = 0; a2 <= min(a[2], a1); a2++) {
    			for (int a3 = 0; a3 <= min(a2, a[3]); a3++) {
    				for (int a4 = 0; a4 <= min(a3, a[4]); a4++) {
    					for (int a5 = 0; a5 <= min(a4, a[5]); a5++) {
    						int &v = f[a1][a2][a3][a4][a5];
    						if (v == 0) continue;
    						if (a1 < a[1]) f[a1 + 1][a2][a3][a4][a5] += v;
    						if (a2 < a[2] && a2 < a1) f[a1][a2 + 1][a3][a4][a5] += v;
    						if (a3 < a[3] && a3 < a2) f[a1][a2][a3 + 1][a4][a5] += v;
    						if (a4 < a[4] && a4 < a3) f[a1][a2][a3][a4 + 1][a5] += v;
    						if (a5 < a[5] && a5 < a4) f[a1][a2][a3][a4][a5 + 1] += v;
    					}
    				}
    			}
    		}
    	}
    	cout << f[a[1]][a[2]][a[3]][a[4]][a[5]] << "\n";
    }

    return 0;
}