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

const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 1061109567;
 
int main() {
    int N; 
    while (cin >> N, N != EOF) {
        vector<int> p[1510];
        bool st[1510] {};
        FOR(i, 0, N) {
            int a, b;
            scanf("%d:(%d)", &a, &b);
            while (b--) {
                int ver; cin >> ver;
                st[ver] = true;
                p[a].push_back(ver);
            }
        }

        int root = 0;
        while (st[root]) root++;

        int f[1510][2] {};
        function<void(int)> dfs = [&](int s) {
            f[s][0] = 0;
            f[s][1] = 1;
            for (auto i : p[s]) {
                dfs(i);
                f[s][0] += f[i][1];
                f[s][1] += min(f[i][0], f[i][1]);
            }
        };
        dfs(root);
        cout << min(f[root][0], f[root][1]) << '\n';
    }

    return 0;
}
