#include <iostream>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr)

int sumMemo[12];

int topDown(int n)
{
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 4;
	else if (!sumMemo[n]) {
		sumMemo[n] = topDown(n - 1) + topDown(n - 2) + topDown(n - 3);
	}
	return sumMemo[n];
}

void Solve()
{
	int testcase;
	std::cin >> testcase;
	while (testcase--) {
		int n;
		std::cin >> n;
		std::cout << topDown(n) << '\n';
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}