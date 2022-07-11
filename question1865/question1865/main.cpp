#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
#define INF 2000000000
using namespace std;
typedef long long ll;

bool bellman_ford(int startNode, int N, bool* visited, ll* ccost, vector<pair<int, int>>* graph)
{
	ccost[startNode] = 0;
	visited[startNode] = true;
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < graph[i].size(); j++)
			{
				int curNode = i;
				int nextNode = graph[i][j].first;
				ll cost = graph[i][j].second;

				if (ccost[curNode] != INF && ccost[nextNode] > ccost[curNode] + cost) {
					ccost[nextNode] = ccost[curNode] + cost;
					visited[nextNode] = true;
					if (k == N) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Solve()
{
	int tc;
	cin >> tc;

	while (tc--) {
		int N, M, W;
		cin >> N >> M >> W;
		vector<pair<int, int>> graph[501];
		ll ccost[501];
		bool visited[501];
		for (int i = 1; i <= N; i++) {
			ccost[i] = INF;
			visited[i] = false;
		}

		for (int i = 0; i < M; i++) {
			int start, end, time;
			cin >> start >> end >> time;
			graph[start].push_back({ end, time });
			graph[end].push_back({ start, time });
		}
		for (int i = 0; i < W; i++) {
			int start, end, time;
			cin >> start >> end >> time;
			graph[start].push_back({ end, -time });
		}

		bool negativeEdge = false;

		for (int i = 1; i <= N && !negativeEdge; i++) {
			if (visited[i] == false) {
				negativeEdge = bellman_ford(i, N, visited, ccost, graph);
			}
		}

		if (negativeEdge)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}