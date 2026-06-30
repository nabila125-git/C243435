#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    void backtrack(string &s, int i, vector<string> &res) {
        if (i == s.length()) {
            res.push_back(s);
            return;
        }

        if (isdigit(s[i])) {
            backtrack(s, i + 1, res);
        } else {
            s[i] = tolower(s[i]);
            backtrack(s, i + 1, res);

            s[i] = toupper(s[i]);
            backtrack(s, i + 1, res);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        backtrack(s, 0, res);
        return res;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    vector<string> result = sol.letterCasePermutation(s);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
