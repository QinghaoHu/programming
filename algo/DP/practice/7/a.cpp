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
void _println(vector<T> u) {for(auto i : u){_print(i);} cerr<<'\n';}

const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int INF = 1061109567;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    while (true) {
        vector<int> a(7, 0);
        FOR(i, 1, 7) {
            cin >> a[i];
            a[0] += a[i] * i;
        }
        if (a[0] == 0) break;
        if (a[0] & 1) {cout << "Can't\n"; continue;}
        
        int f[120000] {}, used[120005] {};
        f[0] = 1; a[0] = a[0] / 2;
        for (int i = 1; i <= 7; i++) {
            memset(used, 0, sizeof used);
            for (int j = i; j <= a[0]; j++) {
                if (!f[j] && f[j - i] && used[j - i] < a[i]) {
                    f[j] = 1; used[j] = used[j - i] + 1;
                }
            }
        }
        if (f[a[0]]) cout << "Can\n";
        else cout << "Can't\n";
    }

    return 0;
}
// Traditional model to count can we form a number by the package. 
