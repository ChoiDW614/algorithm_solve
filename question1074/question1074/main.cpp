#include <iostream>
#include <cmath>
#define FAST_IO	std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr)

int cnt, N, R, C;

void Recur(int n, int r, int c)
{
	if (r == R && c == C) {
		std::cout << cnt;
		return;
	}
	
	if (R >= r && R < r+n && C >= c && C < c+n)
	{
		Recur(n / 2, r, c);
		Recur(n / 2, r, c + n / 2);
		Recur(n / 2, r + n / 2, c);
		Recur(n / 2, r + n /2, c + n / 2);
	}
	else
	{
		cnt += n * n;
	}
}

void Solve()
{
	std::cin >> N >> R >> C;
	Recur(pow(2, N), 0, 0);
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}