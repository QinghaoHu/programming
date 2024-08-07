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

const int N = 30;
int n;
arr<arr<char, N>, 3> e{};
arr<int, N> q{}, path{};
arr<bool, N> st{};

bool check() {
    int t = 0;
    per(i, n - 1, 0) {
        int a = path[e[0][i] - 'A'], b = path[e[1][i] - 'A'], c = path[e[2][i] - 'A'];
        if (a != -1 && b != -1 && c != -1) {
            if (t == -1) {
                if ((a + b) % n != c && (a + b + 1) % n != c) {
                    return false;
                }
                if (!i && a + b >= n) {
                    return false;
                }
            } else {
                if ((a + b + t) % n != c) {
                    return false;
                }
                if (!i && a + b + t >= n) {
                    return false;
                }
                t = (a + b + t) / n;
            }
        } else {
            t = -1;
        }
    }
    return true;
}

bool dfs(int u) {
    if (u == n) {
        return true;
    } 
    per(i, n - 1, 0) {
        if (!st[i]) {
            st[i] = true;
            path[q[u]] = i;
            if (check() && dfs(u + 1)) {
                return true;
            }
            st[i] = false;
            path[q[u]] = -1;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    rep(i, 0, 3) {
        rep(j, 0, n) {
            cin >> e[i][j];
        }
    }
    int k = 0;
    fill(all(st), false);
    per(i, n - 1, 0) {
        rep(j, 0, 3) {
            int t = e[j][i] - 'A';
            if (!st[t]) {
                q[k++] = t;
                st[t] = true;
            }
        }
    }
    fill(all(path), -1);
    fill(all(st), false);
    dfs(0);
    rep(i, 0, n) {
        cout << path[i] << " ";
    }
    cout << "\n";

    return 0;
}
