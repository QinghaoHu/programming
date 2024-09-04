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
const int mod = 1e9 + 9;
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

    VI p(n + 1, 0);
    rep(i, 1, n + 1) {
        cin >> p[i];
    }
    vector<bool> st(n + 1, 0);
    int cnt = 0;
    ll res = 1;
    rep(i, 1, n + 1) {
        if (st[i]) {
            continue;
        }
        // cerr << res << "\n";
        st[i] = 1;
        cnt++;
        int l = 1;
        for (int j = p[i]; j != i; j = p[j]) {
            l++;
            st[j] = true;
        }
        res = res * (l == 1 ? 1 : qmi(l, l - 2)) % mod;
        res = res * qmi(jc[l - 1], mod - 2) % mod;
        // cerr << res << endl;
    }
    res = (ll)res * jc[n - cnt] % mod;
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt;
    cin >> tt;
    jc[0] = 1;
    rep(i, 1, N) {
        jc[i] = jc[i - 1] * i % mod;
    }
    while(tt--) {
        solve();
    }

    return 0;
}