#include <iostream>
using namespace std;

int main() {
    string text, pattern;

    cout << "Enter Text: ";
    cin >> text;

    cout << "Enter Pattern: ";
    cin >> pattern;

    int n = text.length();
    int m = pattern.length();

    int hash_p = 0, hash_t = 0;

    for(int i = 0; i < m; i++) {
        hash_p += pattern[i];
        hash_t += text[i];
    }

    for(int i = 0; i <= n - m; i++) {

        if(hash_p == hash_t) {
            bool match = true;

            for(int j = 0; j < m; j++) {
                if(text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if(match)
                cout << "Pattern found at index: " << i << endl;
        }

        if(i < n - m)
            hash_t = hash_t - text[i] + text[i + m];
    }

    return 0;
}
