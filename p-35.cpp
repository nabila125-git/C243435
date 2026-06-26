#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 0;
vector<int> cats;
vector<vector<int>> adj;

void dfs(int u, int p, int consecutive_cats) {
    if (cats[u]) {
        consecutive_cats++;
    } else {
        consecutive_cats = 0;
    }

    if (consecutive_cats > m) return;

    bool is_leaf = true;
    for (int v : adj[u]) {
        if (v != p) {
            is_leaf = false;
            dfs(v, u, consecutive_cats);
        }
    }

    if (is_leaf && u != 1) {
        ans++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    cats.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> cats[i];

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);

    cout << ans << endl;

    return 0;
}
