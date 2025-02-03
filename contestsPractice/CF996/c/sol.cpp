#include <bits/stdc++.h>

using std::cerr;
using i64 = int64_t;

template<typename T>
void dbg(T x) {cerr << x << ' ';}
template<typename T>
void dbgl(T x) {cerr << x << '\n';}
void dbg(bool x) {cerr << (!x ? "false" : "true") << ' ';}
void dbgl(bool x) {cerr << (!x ? "false" : "true") << '\n';}
template<typename T>
void dbg(std::vector<T> u) {for(auto i : u) dbg(i);}
template<typename T>
void dbgl(std::vector<T> u) {for(auto i : u) dbgl(i); cerr << '\n';}

void solve() {
	int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector a(n, std::vector<i64>(m));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		std::cin >> a[i][j];
    	}
    }

    int i = 0, j = 0;
    while (i + j < n + m - 1) {
    	if (i + j == n + m - 2 || s[i + j] == 'D') {
    		int64_t res = 0;
    		for (int x = 0; x < m; x++) {
    			res -= a[i][x];
    		}
    		a[i][j] = res;
    		i++;
    	} else {
    		int64_t res = 0;
    		for (int x = 0; x < n; x++) {
    			res -= a[x][j];
    		}
    		a[i][j] = res;
    		j++;
    	}
    }

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		std::cout << a[i][j] << " \n"[j == m - 1];
    	}
    }
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; 
	std::cin >> T;

	while (T--) {
		solve();
	}

    return 0;
}
