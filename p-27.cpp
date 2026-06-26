#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        dist[k] = 0;
        pq.push({0, {0, k}});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second.second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], {0, v}});
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};

int main() {
    int n, edges_count, k;
    cout << "Enter number of nodes (n) and starting node (k): ";
    cin >> n >> k;

    cout << "Enter number of edges: ";
    cin >> edges_count;

    vector<vector<int>> times;
    cout << "Enter edges (source target weight):" << endl;
    for (int i = 0; i < edges_count; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        times.push_back({u, v, w});
    }

    Solution sol;
    int result = sol.networkDelayTime(times, n, k);

    cout << "Minimum time: " << result << endl;

    return 0;
}
