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
#define SZ(x) ((int)x.size()) 
#define reopen(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;
typedef pair<double, double> PDD;
typedef pair<string, int> PSI;
typedef pair<char, int> PCI;
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 1e5 + 10;

char str[N];
int a[N];

void solve() {
    cin >> str;
    int n = strlen(str);
    stack<PCI> S;
    S.push(mp(str[0], 0));
    rep(i, 1, n) {
        if (str[i] == '}' && S.top().fi == '{') {
            a[i] = a[S.top().se] = 1;
            S.pop();
        } else if (str[i] == ')' && S.top().fi == '(') {
            a[i] = a[S.top().se] = 1;
            S.pop();
        } else if (str[i] == ']' && S.top().fi == '[') {
            a[i] = a[S.top().se] = 1;
            S.pop();
        } else {
            S.push(mp(str[i], i));
        }
    }
    int res = 0, sres = 0;
    rep(i, 0, n - 1) {
        if (a[i] == 1 && a[i + 1] == 1) {
            sres++;
            res = max(sres, res);
        } else {
            sres = 0;
        }
    }
    cout << (!res ? 0 : res + 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    
    rep(t, 0, T) {
        solve();
    }

    return 0;
}
