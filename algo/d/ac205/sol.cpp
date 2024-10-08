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
const int mod = 10000;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

int n;

void mul(int a[2], int b[2][2]) {
    int c[2] = {0, 0};
    rep(i, 0, 2) {
        rep(k, 0, 2) {
            c[i] = (c[i] + (ll)(a[k] * b[k][i])) % mod;
        }
    }
    memcpy(a, c, sizeof a);
}

void mulself(int a[2][2]) {
    int c[2][2] = {0, 0, 0, 0};
    rep(i, 0, 2) {
        rep(j, 0, 2) {
            rep(k, 0, 2) {
                c[i][j] = (c[i][j] + (ll)(a[i][k] * a[k][j])) % mod;
            }
        }
    }
    memcpy(a, c, sizeof c);
}

int powMat(int a[2], int b[2][2], int c) {
    for (; c; c >>= 1) {
        if (c & 1) {
            mul(a, b);
        }
        mulself(b);
    }
    return a[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> n, n != -1) {
        int a[2] = {0, 1};
        int b[2][2] = {
            {0, 1},
            {1, 1},
        };
        cout << powMat(a, b, n) << "\n";
    }

    return 0;
}