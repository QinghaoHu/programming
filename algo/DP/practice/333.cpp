#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define FOR(i, a, n) for (int i = a; i < n; i++) 
#define ROF(i, a, n) for (int i = n; i >= a; i--)
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back

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

const int N = 1010;
int n, m;
char g[N][N];
int num[N][N] {};

bool isFit(char target, char b) {
    if (target == b) return true;
    if (target == 'a') return b == 'w' || b == 'y' || b == 'z';
    if (target == 'b') return b == 'x' || b == 'z' || b == 'w';
    if (target == 'c') return b == 'x' || b == 'y' || b == 'z';
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    while (cin >> m >> n) {
        memset(num, 0, sizeof num);
        FOR(i, 1, m + 1) {
            FOR(j, 1, n + 1) {
                cin >> g[i][j];
            }
        }

        char chr[3] = {'a', 'b', 'c'};
        int ans = 0;
        FOR(t, 0, 3) {
            FOR(i, 1, m + 1) {
                FOR(j, 1, n + 1) {
                    num[i][j] = isFit(chr[t], g[i][j]);
                }
            }
            
            FOR(i, 1, m + 1) {
                FOR(j, 1, n + 1) {
                    if (num[i][j] == 0) continue;
                    num[i][j] += num[i - 1][j];
                }
            }
            
            for (int i = 1; i <= m; i++) {
                stack<int> q, sz;
                for (int j = 1; j <= n + 1; j++) {
                    int size = 0;
                    while (!q.empty() && q.top() >= num[i][j]) {
                        size += sz.top();
                        ans = max(ans, q.top() * size);
                        q.pop(); sz.pop();
                    }
                    q.push(num[i][j]); sz.push(size + 1);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
