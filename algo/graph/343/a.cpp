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

const int N = 30;
int n, m;
int d[N][N], e[N][N];

int floyd() {
	memcpy(e, d, sizeof e);
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				e[i][j] |= e[i][k] & e[k][j];
				if (e[i][j] == e[j][i] && e[i][j] && i != j) return -1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (e[i][j] == e[j][i] && !e[i][j] && i != j) return 0;
		}
	}
	return 1;
}

void solve() {
	memset(d, 0, sizeof d);
	bool flag = 1;
	for (int i = 1; i <= m; i++) {
		char s[6];
		cin >> s;
		d[s[0] - 'A'][s[2] - 'A'] = 1;
		if (flag) {
			int now = floyd();
			if (now == -1) {
				printf("Inconsistency found after %d relations.\n", i);
                flag = 0;
			} else if (now == 1) {
				printf("Sorted sequence determined after %d relations: ", i);
				pair<int, char> ans[N];
				for (int j = 0; j < n; j++) {
					ans[j].first = 0;
					ans[j].second = (char) (j + 'A');
				}
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						if (e[j][k]) ++ans[j].first;
					}
				}
				sort(ans, ans + n);
				for (int j = n - 1; j >= 0; j--) cout << ans[j].second;
				printf(".\n");
				flag = 0;
			}
		}
	}
	if (flag) puts("Sorted sequence cannot be determined.");
}

int main() {
	while (cin >> n >> m, n) solve();
	return 0;
}
