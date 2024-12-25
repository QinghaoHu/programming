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

template <typename T>
struct SPFA {
    int n, m;
    vector<vector<pair<int, T>>> _path;
    vector<T> dist; vector<int> isV;
    
    SPFA(int nl, int ml) {
        this -> n = nl;
        this -> m = ml;
        dist.resize(n + 1), isV.resize(n + 1);
        _path.resize(n + 1);
    }
    
    void addEdge(int x, int y, int z) {
	_path[x].push_back(make_pair(y, z));
    }
    
    void solve(int src) {
        fill(dist.begin(), dist.end(), 0x3f3f3f3f);
        fill(isV.begin(), isV.end(), 0);
        dist[src] = 0;
        queue<int> q;
        isV[src] = 1;
        q.push(src);
        while (!q.empty()) {
            int t = q.front(); q.pop();
            isV[t] = 0;
            for (auto [i, j] : _path[t]) {
                if (dist[i] > dist[t] + j) {
                    dist[i] = dist[t] + j;
                    if (!isV[i]) {
                    q.push(i);
                    isV[i] = 1;
                    }
                }
            }
        }
    }
    
    T dis(int x) {
        return dist[x];
    }
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    SPFA<int> a(n, m);
    for (int i = 1; i <= m; i++) {
        int x, y, z; cin >> x >> y >> z;
        a.addEdge(x, y, z);
    }
    a.solve(1);
    int t = a.dis(n);
    if (t == INF) {
        cout << "impossible\n";
    } else {
        cout << t << '\n';
    }
    return 0;
}
