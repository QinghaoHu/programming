#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define FOR(i, a, n) for (int i = a; i < n; i++) 
#define ROF(i, a, n) for (int i = n; i >= a; i--)

template<typename T>
void _print(T x) {cerr << x << ' ';}
template<typename T>
void _println(T x) {cerr << x << '\n';}
void _print(bool x) {cerr << (!x ? "false" : "true") << ' ';}
void _println(bool x) {cerr << (!x ? "false" : "true") << '\n';}
template<typename T>
void _print(vector<T> u) {for(auto i : u) _print(i);}
template<typename T>
void _println(vector<T> u) {for(auto i : u)_print(i); cerr << '\n';}

const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 1061109567;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    while (cin >> N) {
        vector<pair<int, int>> path[10010];
        FOR(i, 2, N + 1) {
            int a, b; cin >> a >> b;
            path[i].push_back({a, b});
            path[a].push_back({i, b});
        }

        vector d(N + 2, vector<int>(3, 0));
        function<void(int, int)> dfs1 = [&](int u, int fa) {
            int dist1 = 0, dist2 = 0;
            for (auto [v, w] : path[u]) {
                if (v == fa) continue;
                dfs1(v, u);
                int dist = d[v][0] + w;
                if (dist >= dist1) {
                    dist2 = dist1;
                    dist1 = dist;
                } else if (dist > dist2) dist2 = dist;
            }
            d[u][0] = dist1;
            d[u][1] = dist2;
        };
        function<void(int, int)> dfs2 = [&](int u, int fa) {
            for (auto [v, w] : path[u]) {
                if (v == fa) continue;
                int dist = d[u][0] != d[v][0] + w ? d[u][0] : d[u][1];
                d[v][2] = max(d[u][2], dist) + w;
                dfs2(v, u);
            }
        };
        dfs1(1, -1);
        dfs2(1, -1);
        FOR(i, 1, N + 1) {
            cout << max(d[i][0], d[i][2]) << '\n';
        }

    }

    return 0;
}
