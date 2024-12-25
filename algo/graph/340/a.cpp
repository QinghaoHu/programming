#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

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

int n, m, k;
vector<pair<int, int>> path[1010];

bool solve(int mid) {
  vector<int> dist(n + 1, INT_MAX), isV(n + 1, 0);
  queue<int> q;
  dist[1] = 0;
  isV[1] = 1;
  q.push(1);
  while (!q.empty()) {
    int x = q.front();
    isV[x] = 0;
    q.pop();
    for (auto [ver, dis] : path[x]) {
      int cost = dis > mid ? 1 : 0;
      if (dist[ver] > dist[x] + cost) {
      dist[ver] = dist[x] + cost;
        if (!isV[ver]) {
          q.push(ver);
          isV[ver] = 1;
        }
      }
    }
  }
  return dist[n] <= k;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    path[x].push_back({y, z});
    path[y].push_back({x, z});
  }
  int L = 0, R = 1000001;
  while (L < R) {
    int mid = (L + R) >> 1;
    if (solve(mid)) R = mid;
    else L = mid + 1;
  }
  cout << (L == 1000001 ? -1 : L) << '\n';
  return 0;
}
