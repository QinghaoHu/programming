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
struct Dijkestra {
    int n, m;
    vector<vector<pair<int, T>>> _path;
    vector<T> dist;
    vector<int> isV;

    Dijkestra(int n, int m) {
        this->n = n;
        this->m = m;
        _path.resize(n + 1);
        dist.resize(n + 1), isV.resize(n + 1);
    }

    void addEdge(int x, int y, int z) {
        _path[x].push_back(make_pair(y, z));
    }

    int _find() {
        int res = INF;
        int bRet = -1;
        for (int i = 1; i <= n; i++) {
            if (!isV[i] && dist[i] <= res) {
                res = dist[i];
                bRet = i;
            }
        }
        return bRet;
    }

    void solve(int src) {
        fill(dist.begin(), dist.end(), INF);
        fill(isV.begin(), isV.end(), 0);
        dist[src] = 0;
        for (int i = 1; i <= n; i++) {
            int t = _find();
            isV[t] = 1;
            for (auto j : _path[t]) {
                if (!isV[j.first] && dist[j.first] > dist[t] + j.second) {
                    dist[j.first] = j.second + dist[t];
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
    Dijkestra<int> a(n, m);
    FOR(i, 1, m + 1) {
        int x, y, z; cin >> x >> y >> z;
        if (x == y) continue;
        a.addEdge(x, y, z);
    }
    a.solve(1);
    int s = a.dis(n);
    cout << (s == INF ? -1 : s) << '\n';
	
    return 0;
}
