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
const ll mod = 1e9;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a%b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a /gcd(a,b)*b;}
//head

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;
    
    int n = (int)str.size();
	
	if (n % 2 == 0) {
		cout << 0 << "\n";
		exit(0);
	}
	
	ll f[310][310] {};
	for (int len = 1; len <= n; len++) {
		for (int l = 0; l < n - len + 1; l++) {
			int r = l + len - 1;
			if (len == 1) f[l][r] = 1;
			else if (str[l] ==  str[r]) {
				for (int k = l; k < r; k += 2) {
					if (str[k] == str[r]) {
						f[l][r] = (f[l][r] + (ll)f[l][k] * f[k + 1][r - 1]) % mod;
					}
				}
			}
		}
	}
	cout << f[0][n - 1] << '\n';
	
    return 0;
}
/*
 * Author: Qinghao Hu
 * Stay calm and focus on understanding the problem fully.
 * Try to write something down
 * Don't stuck on one approach 
 * Don't rush, read carefully, and test thoroughly.
 */
