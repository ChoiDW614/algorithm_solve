#include <iostream>
#include <queue>
#include <utility>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr);

void Solve()
{
	int testcase, i, input;
	std::cin >> testcase;
	while (testcase--)
	{
		int N, targetIdx, cnt = 0;
		std::cin >> N >> targetIdx;
		std::queue<std::pair<int, bool>> que;
		std::priority_queue<int> priority;

		for (i = 0; i < N; i++) {
			std::cin >> input;
			if (i != targetIdx) {
				que.push({ input, false });
				priority.push(input);
			}
			else {
				que.push({ input, true });
				priority.push(input);
			}
		}

		bool flag = false;
		while (true)
		{
			if (que.front().first == priority.top())
			{
				if (que.front().second == true)
				{
					std::cout << cnt + 1 << '\n';
					break;
				}
				que.pop();
				priority.pop();
				cnt++;
			}
			else
			{
				que.push(que.front());
				que.pop();
			}
		}
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}