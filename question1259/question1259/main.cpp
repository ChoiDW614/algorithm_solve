#include <iostream>
#include <string>
#define FAST_IO std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

bool check(std::string num)
{
	int MaxIdx = num.size() - 1;
	for (int i = 0; i < num.size() / 2; i++)
	{
		if (num[i] != num[MaxIdx - i]) {
			return false;
		}
	}
	return true;
}

void Solve()
{
	std::string input = "-1";
	while (true) {
		std::cin >> input;
		if (input == "0")
			return;
		if (check(input))
			std::cout << "yes\n";
		else
			std::cout << "no\n";
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}