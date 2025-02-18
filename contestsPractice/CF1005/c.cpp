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
	int n; std::cin >> n;
    std::vector<int> a(n); for (auto &i : a) std::cin >> i;

    std::vector<int64_t> pre(n), suf(n);
    pre[0] = (a[0] > 0 ? a[0] : 0);
    FOR(i, 1, n) {
        pre[i] = pre[i - 1];
        if (a[i] > 0) {
            pre[i] += a[i];
        }
    }
    suf[n - 1] = (a[n - 1] < 0 ? -a[n - 1] : 0);
    ROF(i, n - 2, 0) {
        suf[i] = suf[i + 1];
        if (a[i] < 0) {
            suf[i] += -a[i];
        }
    }

    int64_t res = 0;
    FOR(i, 0, n - 1) {
        res = std::max(res, pre[i] + suf[i + 1]);
    }

    res = std::max(suf[0], res);
    res = std::max(pre[n - 1], res);

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
