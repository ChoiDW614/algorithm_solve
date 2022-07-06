#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
#define INF 2000000000
using namespace std;

vector<pair<int, int>> graph[1001];
vector<pair<int, int>> graph2[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
int ccost[1001];
int ccost2[1001];
bool visited[1001];
bool visited2[1001];

void Dijkstra(int startNode) {
	ccost[startNode] = 0;
	que.push({ 0, startNode });
	while (!que.empty()) {
		int curNode = que.top().second;
		int curCost = que.top().first;
		que.pop();
		if (visited[curNode])
			continue;
		visited[curNode] = true;
		for (pair<int, int> p : graph[curNode]) {
			int nextNode = p.first;
			int nextCost = p.second;
			if (visited[nextNode])
				continue;
			else if (nextCost + ccost[curNode] < ccost[nextNode]) {
				ccost[nextNode] = nextCost + ccost[curNode];
				que.push({ ccost[nextNode], nextNode });
			}
		}
	}
}

void Dijkstra2(int startNode) {
	ccost2[startNode] = 0;
	que.push({ 0, startNode });
	while (!que.empty()) {
		int curNode = que.top().second;
		int curCost = que.top().first;
		que.pop();
		if (visited2[curNode])
			continue;
		visited2[curNode] = true;
		for (pair<int, int> p : graph2[curNode]) {
			int nextNode = p.first;
			int nextCost = p.second;
			if (visited2[nextNode])
				continue;
			else if (nextCost + ccost2[curNode] < ccost2[nextNode]) {
				ccost2[nextNode] = nextCost + ccost2[curNode];
				que.push({ ccost2[nextNode], nextNode });
			}
		}
	}
}

void Solve()
{
	int N, M, X;
	cin >> N >> M >> X;

	for (int i = 1; i <= N; i++) {
		ccost[i] = INF;
		ccost2[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int start, end, time;
		cin >> start >> end >> time;
		graph[end].push_back(make_pair(start, time));
		graph2[start].push_back(make_pair(end, time));
	}

	Dijkstra(X);
	while (!que.empty())
		que.pop();
	Dijkstra2(X);

	int shortCost = 0;
	for (int i = 1; i <= N; i++)
		shortCost = max(shortCost, ccost[i]+ccost2[i]);

	cout << shortCost;
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}