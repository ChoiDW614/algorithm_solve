#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
#define ll long long

int table[1025][1025];
ll dp[1025][1025];

void Solve()
{
    int N, M, x1, y1, x2, y2;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> table[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        dp[i][1] = dp[i - 1][1] + table[i][1];
        dp[1][i] = dp[1][i - 1] + table[1][i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = table[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 -1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
    }
}

int main()
{
    FASTIO;
    Solve();
    return 0;
}