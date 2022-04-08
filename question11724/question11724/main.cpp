#include <iostream>
#include <vector>
#define FAST_IO	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

int vertex, edgeNum;
std::vector<int> graph[1001];
bool visited[1001];

void Input()
{
	std::cin >> vertex >> edgeNum;
	int fromV, toV;
	while (edgeNum--) {
		std::cin >> fromV >> toV;
		graph[fromV].push_back(toV);
		graph[toV].push_back(fromV);
	}
	visited[0] = true;
	for (int i = vertex + 1; i <= 1000; i++)	visited[i] = true;
}

void DFS(int node)
{
	int next;
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		next = graph[node][i];
		if (!visited[next]) {
			DFS(next);
		}
	}
}

void Solve()
{
	Input();
	int cnt = 0;
	for (int i = 1; i <= vertex; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}
	std::cout << cnt;
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}