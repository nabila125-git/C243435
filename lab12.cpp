#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x, y;

    cout << "Enter First String: ";
    cin >> x;

    cout << "Enter Second String: ";
    cin >> y;

    int m = x.length();
    int n = y.length();

    int **dp = new int*[m + 1];

    for(int i = 0; i <= m; i++)
        dp[i] = new int[n + 1];

    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = 0;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << "LCS Length = " << dp[m][n] << endl;

    return 0;
}
