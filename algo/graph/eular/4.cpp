#include <bits/stdc++.h>

void solve() {
	constexpr int N = 27;
	int n; std::cin >> n;

	std::vector<int> fa(N), din(N, 0), dout(N, 0);
	std::vector<bool> st(N, false);
	std::iota(fa.begin(), fa.end(), 0);

	std::function<int(int)> find = [&](int x) {
		return (x != fa[x]) ? fa[x] = find(fa[x]) : fa[x];
	};

	for (int i = 0; i < n; i++) {
		std::string s; std::cin >> s;
		int f = s[0] - 'a', b = s[(int)s.length() - 1] - 'a';
		st[f] = st[b] = true;
		din[b]++, dout[f]++;
		fa[find(f)] = find(b);
	}

	bool isValid = true;
	int start = 0, end = 0;
	for (int i = 0; i < 26; i++) {
		if (din[i] != dout[i]) {
			if (din[i] == dout[i] + 1) {
				end++;
			} else if (din[i] + 1 == dout[i]) {
				start++;
			} else {
				isValid = false;
				break;
			}
		}
	}

	if (isValid && !((!start && !end) || (start == 1 && end == 1))) isValid = false;

	int fp = -1;
	for (int i = 0; i < 26; i++) if (st[i]) {
		if (fp == -1) fp = find(i);
		else if (fp != find(i)) {
			isValid = false;
			break;
		}
	}

	std::cout << (isValid ? "Ordering is possible.\n" : "The door cannot be opened.\n");
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
	int T; std::cin >> T;

	while (T--) 
		solve();
}