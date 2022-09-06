#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;

void Solve()
{
	int N, K, c, i;
	cin >> N >> K;
	
	priority_queue<pair<int, int>> que;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que2;
	for (i = 1; i <= K; i++) {
		cin >> c;
		que.push({ c, i });
		que2.push({ c, i });
	}
	
	cout << 'd';


}

int main()
{
	FASTIO;
	Solve();
	return 0;
}