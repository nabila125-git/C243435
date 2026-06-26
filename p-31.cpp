#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        int res = 0;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            res = max(res, d);
            if (r == n - 1 && c == n - 1) return res;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    pq.push({grid[nr][nc], {nr, nc}});
                }
            }
        }
        return res;
    }
};

int main() {
    int n;
    cout << "Enter grid size (n): ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter the grid values:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << "Minimum time: " << sol.swimInWater(grid) << endl;

    return 0;
}
