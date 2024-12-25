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

int get_num(vector<int> num, int l, int r) {
    int res = 0;
    for (int i = l; i >= r; i--) {
        res *= 10;
        res += num[i];
    }
    return res;
}

int power10(int x) {
    int res = 1;
    while (x--) res *= 10;
    return res;
}

int count(int n, int x) {
    if (!n) return 0;
    vector<int> num;
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();
    int res = 0;
    for (int i = n - 1 - !x; i >= 0; i--) {
        if (i < n - 1) {
            res += (get_num(num, n - 1, i + 1) - !x) * power10(i);
        }
        if (num[i] == x) {
            res += get_num(num, i - 1, 0) + 1;
        } else if (num[i] > x) {
            res += power10(i);
        }
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int a, b; 
    while (cin >> a >> b, a || b) {
        if (a > b) swap(a, b);
        for (int i = 0; i < 9; i++) {
            cout << count(b, i) - count(a - 1, i) << ' ';
        }
        cout << count(b, 9) - count(a - 1, 9) << '\n';
    }

    return 0;
}
