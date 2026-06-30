#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    Solution sol;
    vector<string> result = sol.generateParenthesis(n);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
