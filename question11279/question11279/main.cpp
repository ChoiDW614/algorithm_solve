#include <iostream>
#include <queue>
#define FAST_IO	std::ios_base::sync_with_stdio(false);	std::cin.tie(NULL)

void Solve()
{
	int N, x;
	std::cin >> N;
	std::priority_queue<int> que;

	while (N--)
	{
		std::cin >> x;
		if (!que.empty() && x == 0) {
			std::cout << que.top() << '\n';
			que.pop();
		}
		else if (x == 0) {
			std::cout << 0 << '\n';
		}
		else {
			que.push(x);
		}
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}