#include <iostream>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr);

int N, M, i, j, toV, fromV, initV;
bool visited[1001];

void DFS(int node, int ** edge)
{
	std::cout << node << " ";
	visited[node] = true;
	for (int i = 0; i < N; i++) {
		if (edge[node-1][i] && visited[i + 1] == false) {
				DFS(i+1, edge);
		}
	}
}

void BFS(int node, int** edge)
{

}

void Solve()
{
	std::cin >> N >> M >> initV;
	int** edge = new int* [N];
	for (i = 0; i < N; i++)
		edge[i] = new int[N];

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			edge[i][j] = 0;

	for (i = 0; i < M; i++) {
		std::cin >> toV >> fromV;
		edge[fromV - 1][toV - 1] = 1;
		edge[toV - 1][fromV - 1] = 1;
	}

	DFS(initV, edge);
	std::cout << '\n';
	BFS(initV, edge);
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}