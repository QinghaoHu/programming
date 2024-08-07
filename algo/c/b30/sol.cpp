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

const int N = 24;
int dep;
arr<int, N> q;
int op[8][7] = {
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10}
};
arr<int, 8> cent{6, 7, 8, 11, 12, 15, 16, 17};
arr<int, 8> iot{5, 4, 7, 6, 1, 0, 3, 2};
arr<int, 100> path{};

void operate(int x) {
    int t = q[op[x][0]];
    rep(i, 0, 6) {
        q[op[x][i]] = q[op[x][i + 1]];
    }
    q[op[x][6]] = t;
}

int f() {
    static int sum[4];
    memset(sum, 0, sizeof sum);
    rep(i, 0, 8) {
        sum[q[cent[i]]]++;
    }
    int k = 0;
    rep(i, 0, 4) {
        k = max(k, sum[i]);
    }
    return 8 - k;
}

bool dfs(int u, int last) {
    if (u + f() > dep) {
        return false;
    }
    if (!f()) {
        return true;
    }
    rep(i, 0, 8) {
        if (iot[i] == last) {
            continue;
        }
        operate(i);
        path[u] = i;
        if (dfs(u + 1, i)) {
            return true;
        }
        operate(iot[i]);
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> q[0], q[0]) {
        rep(i, 1, 24) {
            cin >> q[i];
        }
        for (dep = 0; !dfs(0, -1); dep++);
        if (!dep) {
            cout << "No moves needed\n";
        } else {
            rep(i, 0, dep) {
                cout << (char)('A' + path[i]);
            }
            cout << '\n';
        }
        cout << q[6] << "\n";
    }

    return 0;
}
