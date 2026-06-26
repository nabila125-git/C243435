#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<int> adj[26];
    vector<int> inDegree(26, 0);

    for (int i = 0; i < n - 1; i++) {
        string s1 = s[i], s2 = s[i + 1];
        int len = min(s1.length(), s2.length());
        bool found = false;
        for (int j = 0; j < len; j++) {
            if (s1[j] != s2[j]) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                inDegree[s2[j] - 'a']++;
                found = true;
                break;
            }
        }
        if (!found && s1.length() > s2.length()) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    string result = "";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result += (char)(u + 'a');

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) q.push(v);
        }
    }

    if (result.length() < 26) {
        cout << "Impossible" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
