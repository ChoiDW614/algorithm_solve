#include <bits/stdc++.h>
#define FAST_IO	std::ios_base::sync_with_stdio(false);	std::cin.tie(NULL);

int white, blue;
int arr[129][129];

void Recur(int x, int y, int N)
{
	int bCnt = 0, wCnt = 0;
	for (int i = x; i < x+N; i++)
	{
		for (int j = y; j < y+N; j++)
		{
			if (arr[i][j] == 1) 
			{
				bCnt++;
			}
			else
			{
				wCnt++;
			}
		}
	}
	if (bCnt == N * N)
	{
		blue++;
		return;
	}
	if (wCnt == N * N) 
	{
		white++;
		return;
	}

	Recur(x, y, N / 2);
	Recur(x + N / 2, y, N / 2);
	Recur(x, y + N / 2, N / 2);
	Recur(x + N / 2, y + N / 2, N / 2);

	return;
}

void Solve()
{
	int N, x, y;
	x = 0; y = 0;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> arr[i][j];
		}
	}

	Recur(x, y, N);
	std::cout << white << '\n' << blue << std::endl;
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}