#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T>
void _print(T x) {cerr << x << ' ';}
template<typename T>
void _println(T x) {cerr << x << '\n';}
void _print(bool x) {cerr << (!x ? "false" : "true") << ' ';}
void _println(bool x) {cerr << (!x ? "false" : "true") << '\n';}
template<typename T>
void _print(vector<T> u) {for(auto i : u) _print(i);}
template<typename T>
void _println(vector<T> u) {for(auto i : u)_print(i); cerr << '\n';}

template <typename T>
struct Kruskal {
	struct rec { 
		int x, y; T z;
		bool operator < (const rec B) const {
			return z < B.z;
		} 
	};
	int n;
	T ans;
	vector<int> fa, sz;
	vector<rec> edge;

	Kruskal() {}
	Kruskal(int n) {
		init(n);
	}

	int _find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = _find(fa[x]);
	}

	void init(int n) {
		this -> n = n;
		fa.resize(n + 1, 0);
		sz.resize(n + 1, 1);
		ans = 0;
		iota(fa.begin(), fa.end(), 0);
		edge.clear();
	}

	void addEdge(int a, int b, T z) {
		edge.push_back({a, b, z});
	}

	void solve() {
		sort(edge.begin(), edge.end());
		for (auto i : edge) {
			int a = _find(i.x);
			int b = _find(i.y);
			if (a == b) continue;
			ans += (i.z + 1) * (sz[a] * sz[b] - 1);
			sz[b] += sz[a];
			fa[a] = b;
		}
	}

	T get_ans() {
		return ans;
	}

};

void solve() {
	int n; cin >> n;
	Kruskal<ll> t(n);
	for (int i = 1; i < n; i++) {
		int x, y, z; cin >> x >> y >> z;
		t.addEdge(x, y, z);
	}
	t.solve();
	cout << t.ans << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
  	int _; cin >> _;
  	while (_--) {
  		solve();
  	}
	return 0;
}
