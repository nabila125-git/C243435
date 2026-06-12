
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start;
    cin >> start;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n + 1, false);

    pq.push({0, start});
    long long total_weight = 0;

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int w = top.first;
        int u = top.second;

        if (visited[u]) continue;
        visited[u] = true;
        total_weight += w;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    cout << total_weight << endl;

    return 0;
}
