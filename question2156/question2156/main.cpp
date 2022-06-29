#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL); cout.tie(NULL);
using namespace std;

int dp[10001];
int wine[10001];

void Solve()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> wine[i];

	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];
	for (int i = 3; i <= N; i++)
		dp[i] = max({ dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i], dp[i - 1] });
	cout << dp[N];
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}