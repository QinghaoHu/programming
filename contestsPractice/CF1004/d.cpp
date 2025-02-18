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
    std::vector<int> x(n);
    rep(i, 0, n) {
        std::cin >> x[i];
        x[i]--;
    }

    std::vector<int> ix(n, -1);
    rep(i, 0, n) {
        ix[x[i]] = i;
    }

    int c = std::find(ix.begin(), ix.end(), -1) - ix.begin();
    if (c != n) {
        std::cout << "? " << c + 1 << ' ' << (c + 1) % n + 1 << '\n';
        std::cout.flush();
        int res;
        std::cin >> res;
        if (res == 0) {
            std::cout << "! A\n";
        } else {
            std::cout << "! B\n";
        }
        return;
    }

    int a = 0, b = n - 1;
    std::cout << "? " << a + 1 << ' ' << b + 1 << '\n';
    std::cout.flush();
    int res; std::cin >> res;

    if (res > n - 1) {
        std::cout << "! B\n";
        return;
    }

    if (res < n - 1) {
        std::cout << "!A\n";
        return;
    }

    std::cout << "? " << b + 1 << ' ' << a + 1 << '\n';
    std::cout.flush();
    std::cin >> res;

    if (res == n - 1) {
        std::cout << "! B\n";
    } else {
        std::cout << "! A\n";
    }
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; std::cin >> T;

    for (int it = 0; it < T; it++) {
        solve();
    }

    return 0;
}
