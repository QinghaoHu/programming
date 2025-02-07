#include <bits/stdc++.h>

using std::cerr;

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
	int n, k, l;
    std::cin >> n >> k >> l;
    k *= 2;
    l *= 2; 

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    	a[i] *= 2;
    }

    int ans = a[0];
    int x = k;
    for (int i = 1; i < n; i++) {
    	if (a[i] > x) {
    		a[i] = std::max(x, a[i] - ans);
    		ans += (a[i] - x) / 2;
    		x = (x + a[i]) / 2 + k;
    	} else {
    		a[i] = std::min(x, a[i] + ans);
    		x = a[i] + k;
    	}
    }

    if (x < l) {
    	ans += l - x;
    }
    std::cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T; std::cin >> T;

	while (T--) {
		solve();
	}

    return 0;
}
