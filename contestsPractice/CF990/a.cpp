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
void dbgl(std::vector<T> u) {for(auto i : u) {dbg(i);} cerr << '\n';}

void solve() {
	int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> cnt(26, 0), pos(26, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
        pos[s[i] - 'a'] = i;
    }

    int bMax = -1;
    for (int i = 0; i < 26; i++) {
        if (bMax == -1 && cnt[i]) bMax = i;
        if (cnt[i] > cnt[bMax]) {
            bMax = i;
        }
    }

    int bMin = bMax;
    for (int i = 0; i < 26; i++) {
        if (i == bMax) continue;
        if (cnt[i] > 0 && cnt[i] <= cnt[bMin]) {
            bMin = i;
        }
    }

    s[pos[bMin]] = s[pos[bMax]];
    std::cout << s << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);

	int T;
    std::cin >> T;

    for (int it = 0; it < T; it++) {
        solve();
    }

    return 0;
}
