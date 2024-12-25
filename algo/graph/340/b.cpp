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

vector<pair<int, int>> path[1010];
int d[1010][1010] {};
bool isV[1010][1010] {};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y, z; cin >> x >> y >> z;
        path[x].push_back(make_pair(y, z));
        path[y].push_back(make_pair(x, z));
    }

    memset(d, 0x3f, sizeof(d));
    isV[1][0] = 1;
    d[1][0] = 1;
    
    queue<pair<int, int>> q;
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        isV[x.first][x.second] = false;
        for (auto [ver, dis] : path[x.first]) {
            if (d[ver][x.second] > max(d[x.first][x.second], dis)) {
                d[ver][x.second] = max(d[x.first][x.second], dis);
                if (!isV[ver][x.second]) q.push(make_pair(ver, x.second)); isV[ver][x.second] = true;
            }
            if (x.second < k && d[ver][x.second + 1] > d[x.first][x.second]) {
                d[ver][x.second + 1] = d[x.first][x.second];
                if (!d[ver][x.second + 1]) q.push(make_pair(ver, x.second + 1)); isV[ver][x.second + 1] = true;
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, d[n][i]);
    }
    cout << ans << '\n';
    
    return 0;
}
