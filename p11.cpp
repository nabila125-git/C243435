
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter rod length: ";
    cin >> n;

    int price[n];

    cout << "Enter prices: ";
    for(int i = 0; i < n; i++)
        cin >> price[i];

    int dp[n+1];
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        int max_val = -1;

        for(int j = 0; j < i; j++) {
            max_val = max(max_val, price[j] + dp[i-j-1]);
        }

        dp[i] = max_val;
    }

    cout << "Maximum profit = " << dp[n];

    return 0;
}
