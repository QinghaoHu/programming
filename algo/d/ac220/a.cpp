#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
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
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll powmod(ll a, ll b, ll p) { ll res=1; for(;b;b>>=1){ if(b&1){ res=res*a%p;} a=a*a%p;} return res;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int N = 1e7 + 10;
ll st[N], phi[N], sum[N];
VI prime;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        if (st[i] == 0) {
            st[i] = i;
            prime.pb(i);
            phi[i] = i - 1;
        }
        for (auto j : prime) {
            if (j > st[i] || j > n / i) {
                break;
            }
            st[i * j] = j;
            phi[i * j] = (i % j == 0 ? j * phi[i] : (j - 1) * phi[i]);
        }
    }

    for (int i = 2; i <= n; i++) {
        sum[i] = sum[i - 1] + phi[i];
    }

    ll res = 0;
    for (auto j : prime) {
        res += sum[n / j] * 2 + 1;
    }

    cout << res << "\n";
    
    return 0;
}