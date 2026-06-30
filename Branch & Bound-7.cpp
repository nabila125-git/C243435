#include <iostream>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    int total_solve = 0;
    for (int i = 0; i < n; i++) {
        int p, v, t;
        cin >> p >> v >> t;
        if (p + v + t >= 2) {
            total_solve++;
        }
    }

    cout << total_solve << endl;

    return 0;
}
