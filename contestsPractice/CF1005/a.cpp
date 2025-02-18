#include <bits/stdc++.h>

using std::cerr;

#define rep(i, a, n) for (int i=a; i<(n); i++)
#define rep(i, a, n) for (int i=a; i<(n); i++)

template<typename T>
void _dbg(T x) {cerr << x << ' ';}
template<typename T>
void _dbgl(T x) {cerr << x << '\n';}
void _dbg(bool x) {cerr << (!x ? "false" : "true") << ' ';}
void _dbgl(bool x) {cerr << (!x ? "false" : "true") << '\n';}

template<typename T>
void _dbg(std::vector<T> u) {for(auto i : u) _dbg(i);}
template<typename T>
void _dbgl(std::vector<T> u) {for(auto i : u) {_dbg(i);}; cerr << '\n';}
template<typename T, typename U>
void _dbg(std::pair<T, U> p) {cerr << "( "; _dbg(p.first); _dbg(p.second); cerr << ")";}

template<typename T> T gcd(T a, T b) {return (!b ? a : gcd(b, a%b));}
template<typename T> T lcm(T a, T b) {return (a / gcd(a, b) * b);}

void solve() {
    int n; std::cin >> n;
    
    std::vector<int> s(n);
    rep(i, 0, n) {
        char c; std::cin >> c;
        s[i] = c - '0';
    }

    std::reverse(s.begin(), s.end());
    int res = 0;
    bool hasZero = false;
    rep(i, 0, n) {
        if (i == 0 && s[i] == 1) {
            res++;
            continue;
        }
        if (s[i] == 0) {
            hasZero = true;
        }
        if (s[i] == 1 && hasZero) {
            res += 2;
            hasZero = false;
        }
    }

    std::cout << res << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; std::cin >> T;

    for (int it = 0; it < T; it++) {
        solve();
    }

    return 0;
}
