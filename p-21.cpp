
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

bool compareEdges(Edge a, Edge b) {
    if (a.w != b.w) {
        return a.w < b.w;
    }
    return (a.u + a.v + a.w) < (b.u + b.v + b.w);
}

int parent[3001];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int total_weight = 0;
    int edges_count = 0;

    for (int i = 0; i < m && edges_count < n - 1; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            unite(edges[i].u, edges[i].v);
            total_weight += edges[i].w;
            edges_count++;
        }
    }

    cout << total_weight << endl;

    return 0;
}
