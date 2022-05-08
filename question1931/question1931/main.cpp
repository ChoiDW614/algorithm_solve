#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr)
#define par std::pair<int, int>

bool comp(par p1, par p2) {
	if (p1.second == p2.second)
		return p1.first < p2.first;
	else if (p1.second < p2.second)
		return true;
	else
		return false;
}

void Solve()
{
	int N;
	std::cin >> N;
	std::vector<par> v;

	while (N--) {
		int start, end;
		std::cin >> start >> end;
		v.push_back({ start, end });
	}
	int cnt = 0, lasttime = 0;
	std::sort(v.begin(), v.end(), comp);

	for (auto i = v.begin(); i != v.end(); i++) {
		if (lasttime <= i->first) {
			cnt++;
			lasttime = i->second;
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