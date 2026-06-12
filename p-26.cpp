#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

struct Edge {
    int u, v, w;
};

bool compareEdges(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[MAXN];
vector<pair<int, int>> adj[MAXN];
long long ans_bits[MAXM + 100];
int n, m;

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
        return true;
    }
    return false;
}

int subtree_size[MAXN];

void dfs(int u, int p) {
    subtree_size[u] = 1;
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p) {
            dfs(v, u);
            subtree_size[u] += subtree_size[v];
            ans_bits[w] = (long long)subtree_size[v] * (n - subtree_size[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    for (int i = 1; i <= n; i++) parent[i] = i;

    int count = 0;
    for (int i = 0; i < m && count < n - 1; i++) {
        if (union_sets(edges[i].u, edges[i].v)) {
            adj[edges[i].u].push_back({edges[i].v, edges[i].w});
            adj[edges[i].v].push_back({edges[i].u, edges[i].w});
            count++;
        }
    }

    dfs(1, 0);

    string result = "";
    for (int i = 0; i < MAXM + 80; i++) {
        if (ans_bits[i] >= 2) {
            ans_bits[i + 1] += ans_bits[i] / 2;
            ans_bits[i] %= 2;
        }
        result += to_string(ans_bits[i]);
    }

    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());
    cout << result << endl;

    return 0;
}

