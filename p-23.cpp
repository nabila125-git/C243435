#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int total_cost = 0;
        int connected = 0;
        vector<int> min_dist(n, 2147483647);
        vector<bool> visited(n, false);

        min_dist[0] = 0;

        while (connected < n) {
            int curr = -1;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && (curr == -1 || min_dist[i] < min_dist[curr])) {
                    curr = i;
                }
            }

            visited[curr] = true;
            total_cost += min_dist[curr];
            connected++;

            for (int next = 0; next < n; next++) {
                if (!visited[next]) {
                    int dist = abs(points[curr][0] - points[next][0]) +
                               abs(points[curr][1] - points[next][1]);
                    if (dist < min_dist[next]) {
                        min_dist[next] = dist;
                    }
                }
            }
        }
        return total_cost;
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution sol;
    cout << sol.minCostConnectPoints(points) << endl;

    return 0;
}
