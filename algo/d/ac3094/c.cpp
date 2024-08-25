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
const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

const int N = 100005;
int T, n, m, s;
ll p[N];

void gauss() {
    s = 0;
    for (int i = 63; i >= 0; i--) {
        for (int j = s; j < n; j++) {
            if (p[j] >> i & 1) {
                swap(p[j], p[s]);
                break;
            }
        }
        if ((p[s] >> i & 1) == 0) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (j != s && (p[j] >> i & 1)) {
                p[j] ^= p[s];
            }
        }
        s++;
        if (s == n) break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    rep(G, 1, T + 1) {
        cin >> n;
        cout << "Case " << G << ":\n";
        rep(i, 0, n) {
            cin >> p[i];
        }
        gauss();
        cin >> m;
        while (m--) {
            int k;
            cin >> k;
            if (s < n) {
                k--;
            }
            if (k >= (1ll << s)) {
                cout << -1 << "\n";
            } else {
                ll ans = 0;
                for (int i = 0; i < s; i++) {
                    if (k >> i & 1) {
                        ans ^= p[s - i - 1];
                    }
                }
                cout << ans << "\n";
            }
        }
    }

    return 0;
}