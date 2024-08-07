#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define all(x) (x).begin(), (x).end()

const int N = 30;
int n;
// Change: Modified array initialization to match the 2D array structure
array<array<char, N>, 3> e{};  
array<int, N> q{}, path{};
array<bool, N> st{};

bool check() {
    int t = 0;
    per(i, n - 1, 0) {
        int a = path[e[0][i] - 'A'], b = path[e[1][i] - 'A'], c = path[e[2][i] - 'A'];
        if (a != -1 && b != -1 && c != -1) {
            if (t == -1) {
                if ((a + b) % n != c && (a + b + 1) % n != c) {
                    return false;
                }
                if (!i && a + b >= n) {
                    return false;
                }
            } else {
                if ((a + b + t) % n != c) {
                    return false;
                }
                if (!i && a + b + t >= n) {
                    return false;
                }
                t = (a + b + t) / n;
            }
        } else {
            t = -1;
        }
    }
    return true;
}

bool dfs(int u) {
    if (u == n) {
        return true;
    }
    per(i, n - 1, 0) {
        if (!st[i]) {
            st[i] = true;
            path[q[u]] = i;
            if (check() && dfs(u + 1)) {
                return true;
            }
            st[i] = false;
            path[q[u]] = -1;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    // Change: Adjusted input loop to correctly read the 2D array
    rep(i, 0, 3) {
        rep(j, 0, n) {
            cin >> e[i][j];
        }
    }
    fill(all(st), false);
    fill(all(path), -1);
    
    int k = 0;
    per(i, n - 1, 0) {
        rep(j, 0, 3) {
            int t = e[j][i] - 'A';
            if (!st[t]) {
                q[k++] = t;
                st[t] = true;
            }
        }
    }
    fill(all(st), false);
    if (dfs(0)) {
        rep(i, 0, n) {
            cout << path[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "No solution\n";
    }

    return 0;
}
