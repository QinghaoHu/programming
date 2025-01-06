#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 10010;

struct SCC {
    int n, idx, cnt;
    std::vector<int> p[N];
    std::vector<int> low, bel, dfn, ins;
    std::vector<std::vector<int>> scc;
    std::stack<int> stk;
    std::vector<int> sz;

    SCC(int n) {
        this -> n = n;
        low.resize(n + 1, 0);
        bel.resize(n + 1, 0);
        dfn.resize(n + 1, 0);
        ins.resize(n + 1, 0);
        sz.resize(n + 1, 0);
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
            std::vector<int> c;
            while (true) {
                int v = stk.top();
                stk.pop();
                c.push_back(v);
                bel[v] = cnt;
                sz[cnt]++;
                ins[v] = false;
                if (v == x) {
                    break;
                }
            }
            std::sort(c.begin(), c.end());
            scc.push_back(c);
        }
    }

    void solve() {
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) dfs(i);
        }
        std::sort(scc.begin(), scc.end());
    }

    std::vector<std::vector<int>> get_scc() {
        return scc;
    }

    int get_bel(int x) {
        return bel[x];
    }

    void add_edge(int x, int y) {
        p[x].push_back(y);
    }
};

int outEdge[N];


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	SCC ad(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		ad.add_edge(a, b);
	}

	ad.solve();

	for (int u = 1; u <= n; u++) {
		for (auto v : ad.p[u]) {
			if (ad.get_bel(u) != ad.get_bel(v)) {
				outEdge[ad.get_bel(u)]++;
			}
		}
	}

	int cnts = 0, cntv = 0;
	for (int i = 1; i <= ad.cnt; i++) {
		if (outEdge[i] == 0) {
			cnts++;
			cntv += ad.sz[i];
		}
	}

	if (cnts >= 2) {
		std::cout << 0 << '\n';
	} else {
		std::cout << cntv << '\n';
	}

	return 0;
}
