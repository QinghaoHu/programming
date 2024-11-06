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
    cin.tie(nullptr);
	vector<int> a(9, 0);
	iota(a.begin(), a.end(), 1);
	do {
		int x = a[0] * 100 + a[1] * 10 + a[2];
		int y = a[3] * 100 + a[4] * 10 + a[5];
		int z = a[6] * 100 + a[7] * 10 + a[8];
		if (2 * x == y && 3 * x == z) {
			cout << x << " " << y << " " << z << '\n';
		}
	} 
	while (next_permutation(a.begin(), a.end()));
	
    return 0;
}
