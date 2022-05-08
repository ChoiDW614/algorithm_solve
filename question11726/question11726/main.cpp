#include <iostream>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(NULL);

int arr[1001];

int recur(int k)
{
	if (k == 1) return 1;
	else if (k == 2) return 2;
	else if (arr[k] != 0) return arr[k];
	return arr[k] = (recur(k - 1) + recur(k - 2)) % 10007;
}

void Solve()
{
	int n;
	std::cin >> n;
	std::cout << recur(n);
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}