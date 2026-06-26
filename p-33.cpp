#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 1) return 1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int steps = 1;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                if (r == n - 1 && c == n - 1) return steps;

                for (int i = 0; i < 8; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter grid size (n): ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter grid values (0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int result = sol.shortestPathBinaryMatrix(grid);
    cout << "Shortest Path Length: " << result << endl;

    return 0;
}
