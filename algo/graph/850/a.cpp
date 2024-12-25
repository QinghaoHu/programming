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
    this -> n = n;
    this -> m = m;
    _path.resize(n + 1);
    dist.resize(n + 1), isV.resize(n + 1);
  }

  void addEdge(int x, int y, int z) {
    _path[x].push_back(make_pair(y, z));
  }

  void solve(int src) {
    fill(dist.begin(), dist.end(), 0x3f3f3f3f);
    fill(isV.begin(), isV.end(), 0);
    dist[src] = 0;
    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      if (isV[t.second]) continue;
      isV[t.second] = true;
      for (auto i : _path[t.second]) {
	if (!isV[i.first] && dist[i.first] > dist[t.second] + i.second) {
	  dist[i.first] = dist[t.second] + i.second;
	  pq.push(make_pair(dist[i.first], i.first));
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
        a.addEdge(x, y, z);
    }
    a.solve(1);
    int t = a.dis(n);
    cout << (t == INF ? -1 : t) << '\n';
	
    return 0;
}
