#include <bits/stdc++.h>

using std::cerr;

#define FOR(i, a, n) for (int i=a; i<(n); i++)
#define ROF(i, a, n) for (int i=a; i>=(n); i--)

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
    int n, q; std::cin >> n >> q;
    std::vector<int> w(n); for (auto &i : w) std::cin >> i;

    std::vector<int> pre(n + 1);
    pre[0] = w[0];
    FOR(i, 1, n) {
        pre[i] = pre[i - 1] ^ w[i];
    }

    std::vector<std::array<int, 30>> last(n);
    for (int i = 0; i < n; i++) {
        std::fill(last[i].begin(), last[i].end(), 0);
        if (i > 0) last[i] = last[i - 1];
        last[i][std::__lg(w[i])] = i;

        for (int j = 28; j >= 0; j--) {
            last[i][j] = std::max(last[i][j], last[i][j + 1]);
        }
    }

    while (q--) {
        int x; std::cin >> x;

        int idx = n - 1;
        while (idx >= 0 && x > 0) {
            int msb = std::__lg(x);

            int nxt = last[idx][msb];
            x ^= pre[idx] ^ pre[nxt];
            idx = nxt;
            if (nxt == -1 || w[nxt] > x) break;

            x ^= w[nxt];
            idx--;
        }

        std::cout << n - idx - 1 << ' ';
    }
    std::cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; std::cin >> T;

    for (int it = 0; it < T; it++) {
        solve();
    }

    return 0;
}
