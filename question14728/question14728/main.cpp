#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);   cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<pair<int, int>> chap;
int dp[101][10001];

void bt(int n, int W)
{
	int i, w;
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0) {
				dp[i][w] = 0;
			}
			else if (w < chap[i].first) {
				dp[i][w] = dp[i - 1][w];
			}
			else {
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - chap[i].first] + chap[i].second);
			}
		}
	}
}

void Solve()
{
	int N, T, K, S;
	cin >> N >> T;
	chap.push_back({ 0, 0 });
	for (int i = 0; i < N; i++) {
		cin >> K >> S;
		chap.push_back({ K, S });
	}
	bt(N, T);
	cout << dp[N][T];
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}