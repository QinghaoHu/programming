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
    int n; std::cin >> n;

    std::vector<int> a(n); for (auto &i : a) std::cin >> i;

    if (n == 1) {
        std::cout << a[0] << '\n';
        return;
    }
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    for (int i = 0; i < n; i++) {
        q.push(std::make_pair(a[i], i));
    }

    std::vector<int> ans, wait;
    int l = q.top().second, r = q.top().second;
    ans.push_back(q.top().first);
    q.pop();
    
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        
        if (t.second < l) {
            wait.push_back(t.first + 1);
        } else if (t.second < r) {
            wait.push_back(t.first + 1);
        } else {
            ans.push_back(t.first);
            r = t.second;
        }
    }

    if (wait.size() == 0) {
        for (int i : ans) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
        return;
    }

    int mark = std::upper_bound(ans.begin(), ans.end(), wait[0]) - ans.begin();
    std::vector<int> tmp;
    for (int i = mark; i < (int)ans.size(); i++) {
        tmp.push_back(ans[i] + 1);
    }
    if (mark < ans.size()) ans.erase(ans.begin() + mark, ans.end());
    l = 0, r = 0;
    while (l < tmp.size() && r < wait.size()) {
        if (tmp[l] <= wait[r]) {
            ans.push_back(tmp[l]);
            l++;
        } else {
            ans.push_back(wait[r]);
            r++;
        }
    }

    while (l < tmp.size()) {
        ans.push_back(tmp[l++]);
    }

    while (r < wait.size()) {
        ans.push_back(wait[r++]);
    }

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << ' ';
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
