#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int _ = 0; _ < T; _++) {
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		if ((a - b) % 2) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
}
