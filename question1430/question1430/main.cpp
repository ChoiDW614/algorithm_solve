#include <iostream>
#include <queue>
#define FAST_IO	std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr)

int vertex[1001];
std::priority_queue<int, std::vector<int>, std::greater<>> que;

class node {
public:
	int fromV;
	int toV;
	int weight;
};

int getParent(int node) {
	if (vertex[node] == node) return node;
	else return getParent(vertex[node]);
}

bool sameParent(int node1, int node2) {
	int x = getParent(node1);
	int y = getParent(node2);
	if (x == y)	return true;
	else return false;
}

void unionParent(int node1, int node2) {
	int x = getParent(node1);
	int y = getParent(node2);
	if (x != y)	vertex[y] = x;
}

void Input()
{
	for (int i = 0; i < 1001; i++)	vertex[i] = i + 1;
	int N;
	std::cin >> N;
	while (N--) {
		int input;
		std::cin >> input;
		que.push(input);
	}
}

void Solve()
{
	Input();





}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}

/*while (!que.empty()) {
	std::cout << que.top() << " ";
	que.pop();
}*/