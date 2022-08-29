#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
using namespace std;

int R[1001], G[1001], B[1001];
int sum1[1001], sum2[1001], sum3[1001];

void Solve()
{
    int i, N;
    cin >> N;
    for (i = 1; i <= N; i++)
        cin >> R[i] >> G[i] >> B[i];
    sum1[1] = R[1];
    sum2[1] = G[1];
    sum3[1] = B[1];
    for (i = 2; i <= N; i++) {
        sum1[i] = min(sum2[i - 1], sum3[i - 1]) + R[i];
        sum2[i] = min(sum1[i - 1], sum3[i - 1]) + G[i];
        sum3[i] = min(sum1[i - 1], sum2[i - 1]) + B[i];
    }
    cout << min({ sum1[N], sum2[N], sum3[N] }) << '\n';
}

int main()
{
    FASTIO;
    Solve();
    return 0;
}