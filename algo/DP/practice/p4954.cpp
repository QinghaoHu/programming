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

const int N = 100005;
int n;
int a[N], s[N], g[N];
int f[N];
int q[N];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    ROF(i, 1, n) cin >> a[i];
    FOR(i, 1, n + 1) s[i] = s[i - 1] + a[i];

    int l = 0, r = 0;
    FOR(i, 1, n + 1) {
        while (l < r && s[q[l + 1]] + g[q[l + 1]] <= s[i]) l++;
        f[i] = f[q[l]] + 1;
        g[i] = s[i] - s[q[l]];
        while (l < r && s[q[r]] + g[q[r]] >= s[i] + g[i]) r--;
        q[++r] = i;
    }
    cout << f[n] << '\n';

    return 0;
}
