#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
#define INF 2000000000
using namespace std;
typedef long long ll;

vector<pair<int, int>> graph[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
bool visited[801];
ll ccost[801];
bool notConnect;

ll Dijkstra(int startnode, int endnode)
{
	ccost[startnode] = 0;
	que.push({ 0, startnode });
	while (!que.empty()) {
		int curNode = que.top().second;
		ll curCost = que.top().first;
		que.pop();
		if (curNode == endnode) {
			return curCost;
		}
		if (visited[curNode])
			continue;
		visited[curNode] = true;
		for (pair<int, int> p : graph[curNode]) {
			int nextNode = p.first;
			ll nextCost = p.second;
			if (visited[nextNode])
				continue;
			else if (nextCost + ccost[curNode] < ccost[nextNode]) {
				ccost[nextNode] = nextCost + ccost[curNode];
				que.push({ ccost[nextNode], nextNode });
			}
		}
	}
	notConnect = true;
	cout << -1;
	return -1;
}

void clear(int N)
{
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
		ccost[i] = INF;
	}
	while (!que.empty())
		que.pop();
}

void Solve()
{
	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	int v1, v2;
	cin >> v1 >> v2;
	ll shortCost1 = 0, shortCost2 = 0;

	for (int i = 1; i <= N; i++)
		ccost[i] = INF;

	shortCost1 += Dijkstra(1, v1);
	if (notConnect) return;
	clear(N);

	shortCost1 += Dijkstra(v1, v2);
	if (notConnect) return;
	clear(N);

	shortCost1 += Dijkstra(v2, N);
	if (notConnect) return;
	clear(N);

	shortCost2 += Dijkstra(1, v2);
	if (notConnect) return;
	clear(N);

	shortCost2 += Dijkstra(v2, v1);
	if (notConnect) return;
	clear(N);

	shortCost2 += Dijkstra(v1, N);
	if (notConnect) return;

	cout << min(shortCost1, shortCost2);
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}