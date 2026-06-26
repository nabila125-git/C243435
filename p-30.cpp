#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> tmp = dist;
            for (auto& f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] != 1e9 && dist[u] + w < tmp[v]) {
                    tmp[v] = dist[u] + w;
                }
            }
            dist = tmp;
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

int main() {
    int n, edge_count, src, dst, k;

    cout << "Enter number of cities (n): ";
    cin >> n;
    cout << "Enter number of flights: ";
    cin >> edge_count;

    vector<vector<int>> flights;
    cout << "Enter flights (from to price):" << endl;
    for (int i = 0; i < edge_count; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        flights.push_back({u, v, w});
    }

    cout << "Enter source, destination and at most stops (k): ";
    cin >> src >> dst >> k;

    Solution sol;
    int result = sol.findCheapestPrice(n, flights, src, dst, k);

    cout << "Cheapest Price: " << result << endl;

    return 0;
}
