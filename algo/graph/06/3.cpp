#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 100010;
int debug;

struct SCC {
    int n, idx, cnt;
    std::vector<int> p[N];
    std::vector<int> low, bel, dfn, ins;
    std::vector<int> scc[N];
    std::stack<int> stk;

    SCC(int n) {
        this -> n = n;
        low.resize(n + 1, 0);
        bel.resize(n + 1, 0);
        dfn.resize(n + 1, 0);
        ins.resize(n + 1, 0);
        idx = cnt = 0;
    }

    void dfs(int x) {
        low[x] = dfn[x] = ++idx;
        ins[x] = true;
        stk.push(x);

        for (auto v : p[x]) {
            if (!dfn[v]) dfs(v);
            if (ins[v]) low[x] = std::min(low[x], low[v]);
        }
		
        if (dfn[x] == low[x]) {
            ++cnt;
            while (true) {
                int v = stk.top();
                stk.pop();
                scc[cnt].push_back(v);
                bel[v] = cnt;
                ins[v] = false;
                if (v == x) {
                    break;
                }
            }
        }
        
    }

    void solve() {
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) dfs(i);
        }
        std::cerr << 2 << '\n';
    }

    int get_bel(int x) {
        return bel[x];
    }

    void add_edge(int x, int y) {
        p[x].push_back(y);
    }
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, mod;
	std::cin >> n >> m >> mod;

	SCC tr(N);

	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		tr.add_edge(a, b);
	}

	tr.solve();

	int dp[N] {}, vis[N] {}, way[N] {};
	int ans = 0, w = 0;
	for (int i = 1; i <= tr.cnt; i++) {
		way[i] = 1;
		dp[i] = 0;

		for (auto u : tr.scc[i]) {
			for (auto v : tr.p[u]) {
				if (tr.get_bel(v) != i && !vis[tr.get_bel(v)]) {
					vis[tr.get_bel(v)] = true;
					if (dp[tr.get_bel(v)] > dp[i]) {
						dp[i] = dp[tr.get_bel(v)];
						way[i] = 0;
					}
					
					if (dp[tr.get_bel(v)] == dp[i]) {
						way[i] = (way[i] + way[tr.get_bel(v)]) % mod;
					} 
				}
			}
		}
		
		for (auto u : tr.scc[i]) {
			for (auto v : tr.p[u]) {
				vis[tr.get_bel(v)] = false;
			}
		}
		
		dp[i] += (int)tr.scc[i].size();
		if (dp[i] > ans) {
			ans = dp[i];
			w = 0;
		}
		
		if (dp[i] == ans)  {
			w = (w + way[i]) % mod;
		}

	} 

	std::cout << ans << '\n' << w << '\n';

	return 0;
}
