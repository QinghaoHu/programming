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

const int N = 2010;
int n, k;

void solve() {
    vector<int> a(n + 1, 0);
    FOR(i, 1, n + 1) cin >> a[i];
    
    vector cost(n + 1, vector<int>(n + 1, 0));
    FOR(i, 1, n + 1) {
        priority_queue<int, vector<int>, greater<int>> mins;
        priority_queue<int, vector<int>, less<int>> maxs;
        int suml = 0, sumr = 0;
        FOR(j, i, n + 1) {
            maxs.push(a[j]); suml += a[j];
            while (!mins.empty() && mins.top() < maxs.top()) {
                auto a = mins.top(), b = maxs.top();
                mins.pop(), maxs.pop();
                maxs.push(a); mins.push(b);
                suml -= b, suml += a;
                sumr -= a, sumr += b;
            }

            while (maxs.size() > mins.size() + 1) {
                mins.push(maxs.top());
                suml -= maxs.top(), sumr += maxs.top();
                maxs.pop();
            }

            int mid = maxs.top();
            cost[i][j] = (maxs.size() * mid - suml) + (sumr - mins.size() * mid);
        }
    }

    int f[26][N];
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    FOR(i, 1, k + 1) {
        FOR(j, 1, n + 1) {
            FOR(pre, 0, j) {
                f[i][j] = min(f[i][j], f[i - 1][pre] + cost[pre + 1][j]);
            }
        }
    }
    cout << f[k][n] << '\n';
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    while (cin >> n >> k, n != 0 || k != 0) {
        solve();
    }

    return 0;
}
