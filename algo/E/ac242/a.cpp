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
ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll powmod(ll a, ll b, ll p) {ll res=1;for(;b;b>>=1){if(b&1){res=res*a%p;}a=a*a%p;}return res;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0), c(n + 1, 0);
    rep(i, 1, n + 1) {
        cin >> a[i];
    }

    auto lowbit = [](int x) -> int {
        return x & (-x);
    };

    auto query = [&](int x) -> int {
        int s = 0;
        for (; x; x -= lowbit(x)) {
            s += c[x];
        }
        return s;
    };

    auto modify = [&](int x, int s) -> void {
        for (int i = x; i <= n; i += lowbit(i)) {
            c[i] += s;
        }
    };

    rep(i, 1, n + 1) {
        modify(i, a[i] - a[i - 1]);
    }
    while (m--) {
        int cd;
        int l, r, d;
        cin >> cd >> l;
        if (cd == 2) {
            cout << query(l) << "\n";
        } else {
            cin >> r >> d;
            modify(l, d);
            modify(r + 1, -1 * d);
        }
    }

    return 0;
}