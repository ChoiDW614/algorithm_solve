#include <iostream>
#include <map>
#include <ctype.h>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr);
#define MAX_SIZE	100001

void Solve()
{
	int N, M, i, input;
	int arrM[MAX_SIZE];
	std::map<int, int> mp;
	std::cin >> N;
	for (i = 0; i < N; i++) {
		std::cin >> input;
		mp.insert({ input, input });
	}
	std::cin >> M;
	for (i = 0; i < M; i++)	std::cin >> arrM[i];

	for (i = 0; i < M; i++) {
		if (mp.find(arrM[i]) != mp.end())
			std::cout << "1\n";
		else
			std::cout << "0\n";
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}