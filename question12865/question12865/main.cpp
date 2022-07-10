#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;
typedef long long ll;

vector<pair<int, int>> chap;
ll dp[101][100001];

void knapsack(int n, int W)
{
	int i, w;
	for (i = 1; i <= n; i++) {
		for (w = 1; w <= W; w++) {
			if (w < chap[i].first)
				dp[i][w] = dp[i - 1][w];
			else {
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - chap[i].first] + chap[i].second);
			}
		}
	}
}

void Solve()
{
	int N, K, w, v;
	cin >> N >> K;
	chap.push_back({ 0, 0 });
	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		chap.push_back({ w, v });
	}
	knapsack(N, K);
	cout << dp[N][K];
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}