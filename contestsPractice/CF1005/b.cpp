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
    
    const int N = (int)2e5 + 10;
    int st[N] {};
    std::vector<int> a(n); for (auto &i : a) std::cin >> i;
    
    rep(i, 0, n) {
        st[a[i]]++;
    }

    std::vector<int> ix(n, 1);
    rep(i, 0, n) {
        if (st[a[i]] > 1) {
            ix[i] = 0;
        }
    }

    int cnt = ix[0];
    int res = 0;
    int l = -1, r = -1;
    for (int i = 1; i < n; i++) {
        if (ix[i] == 1) {
            cnt++;
        } else {
            if (ix[i] == 0 && cnt > res) {
                l = i - cnt;
                r = i - 1;
                res = cnt;
                cnt = 0;
            }
            if (ix[i] == 0) cnt = 0;
        }
    }

    if (cnt > res) {
        l = n - cnt;
        r = n - 1;
    }

    if (l == -1) {
        std::cout << 0 << '\n';
        return;
    } 
    std::cout << l + 1 << ' ' << r + 1 << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; std::cin >> T;

    for (int it = 0; it < T; it++) {
        solve();
    }

    return 0;
}
