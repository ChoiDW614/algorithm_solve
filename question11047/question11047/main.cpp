#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;
typedef long long ll;

ll value[11];

void Solve()
{
	ll N, K, i, cnt = 0;
	cin >> N >> K;
	for (i = 1; i <= N; i++) {
		cin >> value[i];
	}
	
	i = N;
	while (K != 0 && i != 0) {
		if (value[i] > K) {
			i--;
			continue;
		}
		K = K - value[i];
		cnt++;
	}
	
	cout << cnt;
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}