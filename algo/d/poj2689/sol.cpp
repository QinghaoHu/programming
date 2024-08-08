#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back

int main() {
    vector<int> v(1000001, 0); // assuming we need primes up to 1,000,000
    vector<int> p;

    auto primes = [&](int n) -> void {
        fill(all(v), 0);
        for (int i = 2; i <= n; i++) {
            if (!v[i]) {
                v[i] = i;
                p.pb(i);
            }
            for (auto j : p) {
                if (j > v[i] || j > n / i) {
                    break;
                }
                v[i * j] = j;
            }
        }
    };

    primes(100); // Example usage, finding primes up to 100

	for (int i : p) {
		cerr << i << "\n";
	}

    return 0;
}
