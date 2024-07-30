#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
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

void solve() {
    const int N = 1010;
    arr<int, N> f{};
    vector<PII> e[N], p[N];
    int n, m, s, t, k;
    cin >> n >> m;
    rep(i, 0, m) {
        int a, b, l;
        cin >> a >> b >> l;
        e[a].pb({b, l});
        p[b].pb({a, l});
    }
    cin >> s >> t >> k;
    fill(all(f), INF);
    auto dijkestra = [&](int src) -> void {
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        heap.push({0, src});
        f[src] = 0;
        arr<bool, N> st{};
        fill(all(st), false);
        while (!heap.empty()) {
            auto [dis, ver] = heap.top();
            heap.pop();
            if (st[ver]) {
                continue;
            }
            st[ver] = true;
            for (auto [i, j] : p[ver]) {
                if (f[i] > f[ver] + j && !st[i]) {
                    f[i] = f[ver] + j;
                    heap.push({f[i], i});
                } 
            }
        }
    };
    dijkestra(t);
    if (s == t) {
        k++;
    }
    auto astar = [&](int s, int t) -> int {
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        heap.push({f[s], s});
        arr<int, N> cnt{};
        while (!heap.empty()) {
            auto [dis, ver] = heap.top();
            heap.pop();
            cnt[ver]++;
            if (cnt[t] == k) {
                return dis;
            }
            for (auto [i, j] : e[ver]) {
                if (cnt[i] < k) {
                    heap.push({dis - f[ver] + f[i] + j, i});
                }
            }
        }
        return -1;
    };
    cout << astar(s, t) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    
    while (T--) {
        solve();
    }

    return 0;
}
