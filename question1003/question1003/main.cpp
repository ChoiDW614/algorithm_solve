#include <iostream>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr);
typedef long long ll;

ll fib_table[41][3];
ll cnt0, cnt1;

void fibo(int n)
{
	for (int i = 1; i <= n; i++) {
		 if (i == 1) {
			fib_table[1][0] = 1;
			fib_table[1][1] = 0;
			fib_table[1][2] = 1;
		}
		else {
			fib_table[i][0] = fib_table[i - 1][0] + fib_table[i - 2][0];
			fib_table[i][1] = fib_table[i - 1][1] + fib_table[i - 2][1];
			fib_table[i][2] = fib_table[i - 1][2] + fib_table[i - 2][2];
		}
	}
}

void Solve()
{
	int testcase;
	std::cin >> testcase;
	while (testcase--) {
		int N;
		std::cin >> N;

		fib_table[0][0] = 0;
		fib_table[0][1] = 1;
		fib_table[0][2] = 0;

		fibo(N);
		std::cout << fib_table[N][1] << " " << fib_table[N][2] << '\n';
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}