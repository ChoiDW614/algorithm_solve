#include <bits/stdc++.h>
#define FASTIO  ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
using namespace std;

int road[100001][3];
int cost[2][3];

void Solve()
{
    int a, i, j;
    cin >> a;
    for (i = 1; i <= a; i++) {
        for (j = 0; j < 3; j++) {
            cin >> road[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        cost[0][i] = road[1][i];
    }
    for (i = 2; i <= a; i++) {
        cost[1][0] = max(cost[0][0], cost[0][1]) + road[i][0];
        cost[1][1] = max({ cost[0][0], cost[0][1], cost[0][2] }) + road[i][1];
        cost[1][2] = max(cost[0][1], cost[0][2]) + road[i][2];
        cost[0][0] = cost[1][0];
        cost[0][1] = cost[1][1];
        cost[0][2] = cost[1][2];
    }
    cout << max({ cost[0][0], cost[0][1], cost[0][2] }) << ' ';

    for (i = 0; i < 3; i++) {
        cost[0][i] = road[1][i];
    }
    for (i = 2; i <= a; i++) {
        cost[1][0] = min(cost[0][0], cost[0][1]) + road[i][0];
        cost[1][1] = min({ cost[0][0], cost[0][1], cost[0][2] }) + road[i][1];
        cost[1][2] = min(cost[0][1], cost[0][2]) + road[i][2];
        cost[0][0] = cost[1][0];
        cost[0][1] = cost[1][1];
        cost[0][2] = cost[1][2];
    }
    cout << min({ cost[0][0], cost[0][1], cost[0][2] }) << '\n';
}

int main()
{
    FASTIO;
    Solve();
    return 0;
}