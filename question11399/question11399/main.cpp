#include <iostream>
#include <queue>
#define FAST_IO	std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr)

void Solve() {
	std::priority_queue<int, std::vector<int>, std::greater<>> que;
	long long N, cnt = 0, ans = 0;
	std::cin >> N;
	while (N--) {
		int input;
		std::cin >> input;
		que.push(input);
	}
	while (!que.empty()) {
		cnt += que.top();
		que.pop();
		ans += cnt;
	}
	std::cout << ans;
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}