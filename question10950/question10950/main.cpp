#include <iostream>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(NULL);

int testcase;
void Solve()
{
	std::cin >> testcase;
	int A, B;
	while (testcase--) {
		std::cin >> A >> B;
		std::cout << A + B << '\n';
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}