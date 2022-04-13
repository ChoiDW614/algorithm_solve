#include <iostream>
#include <queue>
#include <vector>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr)

std::priority_queue<int, std::vector<int>, std::greater<>> que;

void Solve()
{
	int N, input;
	std::cin >> N;
	while (N--) {
		std::cin >> input;
		if (input == 0) {
			if (!que.empty()) {
				std::cout << que.top() << '\n';
				que.pop();
			}
			else {
				std::cout << "0" << '\n';
			}
		}
		else {
			que.push(input);
		}
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}