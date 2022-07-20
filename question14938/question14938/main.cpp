#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;
#define INF 2000000000;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
vector<pair<int, int>> graph[101];
pair<int, int> node[101];
int ccost[101];
int item[101];
bool visited[101];

void Dijkstra(int startnode, int m)
{
	que.push({ 0, startnode });
	ccost[startnode] = 0;
	item[startnode] += node[startnode].second;
	while (!que.empty()) {
		int curNode = que.top().second;
		int curCost = que.top().first;
		que.pop();
		if (visited[curNode] || ccost[curNode] > m)
			continue;
		visited[curNode] = true;
		for (pair<int, int> p : graph[curNode]) {
			int nextNode = p.first;
			int nextCost = p.second;
			if (visited[nextNode])
				continue;
			else if (nextCost + ccost[curNode] < ccost[nextNode]) {
				ccost[nextNode] = nextCost + ccost[curNode];
				if (!visited[nextNode] && ccost[nextNode] <= m)
					item[startnode] += node[nextNode].second;
				que.push({ ccost[nextNode], nextNode });
			}
		}
	}
}

void clear(int n)
{
	while (!que.empty())
		que.pop();
	for (int i = 1; i <= n; i++) {
		ccost[i] = INF;
		visited[i] = false;
	}
}

void Solve()
{
	int n, m, r, t, a, b, l;
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> t;
		node[i] = make_pair(i, t);
		ccost[i] = INF;
	}

	for (int i = 1; i <= r; i++) {
		cin >> a >> b >> l;
		graph[a].push_back({ b, l });
		graph[b].push_back({ a, l });
	}
	
	int maxitem = 0;
	for (int i = 1; i <= n; i++) {
		Dijkstra(i, m);
		clear(n);
		maxitem = max(maxitem, item[i]);
	}
	cout << maxitem;
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}