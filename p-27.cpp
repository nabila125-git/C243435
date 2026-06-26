#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();
        vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == R - 1 && c == C - 1) return d;
            if (d > dist[r][c]) continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                    int effort = max(d, abs(heights[r][c] - heights[nr][nc]));
                    if (effort < dist[nr][nc]) {
                        dist[nr][nc] = effort;
                        pq.push({effort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> heights(rows, vector<int>(cols));
    cout << "Enter the grid values:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> heights[i][j];
        }
    }

    Solution sol;
    cout << "Minimum Effort: " << sol.minimumEffortPath(heights) << endl;

    return 0;
}
