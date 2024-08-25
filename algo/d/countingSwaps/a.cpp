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
const int mod = 1e9 + 7;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 1e5 + 10;
ll jc[N];
bool st[N];
int p[N];

ll qmi(ll a, int b) {
    ll c = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            c = a * c % mod;
        }
        a = a * a % mod;
    }
    return c;
}

void solve() {
    int n;
    cin >> n;
    memset(p, 0, sizeof p);
    memset(st, 0, sizeof st);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int cnt = 0;
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        if (st[i]) {
            continue;
        }
        cnt++;
        int l = 1;
        st[i] = 1;
        for (int j = p[i]; j != i; j = p[j]) {
            l++;
            st[j] = 1;
        }
        if (l > 1) {
            res = res * qmi(l, l - 2) % mod;
        }
        res = res * qmi(jc[l - 1], mod - 2) % mod;
    }
    res = res * jc[n - cnt] % mod;
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    jc[0] = 1;
    for (int i = 1; i < N; i++) {
        jc[i] = jc[i - 1] * i % mod;
    }
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }

    return 0;
}