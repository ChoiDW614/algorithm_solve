#include <iostream>
#include <string>
#include <map>
#include <queue>
#define FAST_IO	std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr)

void Solve()
{
	std::map<std::string, int> mp;
	std::queue<std::string> que;
	std::string st;
	int iterN, iterM, i;
	std::cin >> iterN >> iterM;
	for (i = 0; i < iterN; i++) {
		std::cin >> st;
		mp[st] = 1;
	}
	for (i = 0; i < iterM; i++) {
		std::cin >> st;
		mp[st] += 1;
	}
	for (auto j = mp.begin(); j != mp.end(); j++) {
		if (j->second == 2)
			que.push(j->first);
	}
	std::cout << que.size() << '\n';
	while (!que.empty()) {
		std::cout << que.front() << '\n';
		que.pop();
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}