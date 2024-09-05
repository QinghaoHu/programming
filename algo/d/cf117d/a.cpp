#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
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

const int M = 110;
ll n; int m;
int f[M], a[M][M];

void mulself() {
    int c[M][M] = {0};
    rep(i, 0, m) {
        rep(j, 0, m) {
            rep(k, 0, m) {
                c[i][j] = (c[i][j] + (ll)a[k][j] * a[i][k]) % mod;
            }
        }
    }
    memcpy(a, c, sizeof c);
}

void mul() {
    int c[M] = {0};
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < m; k++) {
            c[i] = (c[i] + (ll)f[k] * a[k][i]) % mod;
        }
    }
    memcpy(f, c, sizeof c);
}

void powMatrix(ll k) {
    for (; k; k >>= 1) {
        if (k & 1) {
            mul();
        }
        mulself();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    rep(i, 0, m - 1) {
        a[i + 1][i] = 1;
    }
    a[0][m - 1] = 1;
    a[m - 1][m - 1] = 1;
    f[m - 1] = 1;
    powMatrix(n);
    cout << f[m - 1] << "\n";

    return 0;
}
