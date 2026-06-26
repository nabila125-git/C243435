#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<int> adj[100005];

long double dfs(int u, int p) {
    long double sum = 0;
    int children = 0;

    for (int v : adj[u]) {
        if (v != p) {
            children++;
            sum += dfs(v, u);
        }
    }

    if (children == 0) return 0;
    return (sum / children) + 1;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    if (n == 1) {
        cout << fixed << setprecision(15) << 0.0 << endl;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << fixed << setprecision(15) << (double)dfs(1, 0) << endl;

    return 0;
}
