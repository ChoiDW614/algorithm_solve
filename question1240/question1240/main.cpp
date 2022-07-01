#include <bits/stdc++.h>
#define FASTIO 	ios_base::sync_with_stdio(false);	cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<pair<int, int>> graph[1001];
bool visited[1001];

void dfs(int x, int length, int tar)
{
	visited[x] = true;
	if (x == tar) {
		cout << length << '\n';
		return;
	}
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i].first;
		if (!visited[y])
			dfs(y, length + graph[x][i].second, tar);
	}
	return;
}

void Solve()
{
	int N, M, input1, input2, dis;
	cin >> N >> M;

	for (int i = 0; i < N - 1; i++) {
		cin >> input1 >> input2 >> dis;
		graph[input1].push_back({ input2, dis });
		graph[input2].push_back({ input1, dis });
	}

	for (int i = 0; i < M; i++) {
		for (int j = 1; j <= N; j++)
			visited[j] = false;

		cin >> input1 >> input2;
		dfs(input1, 0, input2);
	}
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}