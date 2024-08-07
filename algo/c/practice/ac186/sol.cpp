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
#define VI vector<int>
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

const int mod = 999971;
const db eps = 1e-9;
const db PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << '\n';
#endif

struct route {
    int am;
    int a, d;
    bool operator<(const route &t) const {
        return am > t.am;
    }
};

const int M = 60;

int n;
arr<int, M> bus{};
vector<route> routes;

bool check(int a, int d) {
    for (int i = a; i < 60; i += d) {
        if (!bus[i]) {
            return false;
        }
    }
    return true;
}

bool dfs(int u, int sum, int start) {
    if (u == 0) {
        return sum == n;
    }
    for (int i = start; i < SZ(routes); i++) {
        if (u * routes[i].am + sum < n) {
            continue;
        }
        if (!check(routes[i].a, routes[i].d)) {
            continue;
        }
        for (int j = routes[i].a; j < 60; j += routes[i].d) {
            bus[j]--;
        }
        if (dfs(u - 1, sum + routes[i].am, i)) {
            return true;
        }
        for (int j = routes[i].a; j < 60; j += routes[i].d) {
            bus[j]++;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    rep(i, 0, n) {
        int t;
        cin >> t;
        bus[t]++;
    }
    rep(i, 0, 60) {
        for (int j = i + 1; i + j < 60; j++) {
            if (check(i, j)) {
                routes.pb({(59 - i) / j + 1, i, j});
            }
        }
    }
    sort(all(routes));
    int depth = 0;
    while (!dfs(depth, 0, 0)) {
        depth++;
    }
    cout << depth << " \n";

    return 0;
}