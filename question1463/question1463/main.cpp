#include <iostream>
#define FAST_IO	std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr);

int table[1000001];

void Solve()
{
	int N, cnt = 0;
	std::cin >> N;

	table[1] = 0;
	table[2] = 1;
	table[3] = 1;

	for (int i = 4; i <= N; i++) {
		table[i] = table[i - 1] + 1;
		if (i % 6 == 0) {
			if (table[i - 1] > table[i / 2]) {
				if (table[i / 2] > table[i / 3]) {
					table[i] = table[i / 3] + 1;
				}
				else {
					table[i] = table[i / 2] + 1;
				}
			}
			else {
				if (table[i - 1] > table[i / 3]) {
					table[i] = table[i / 3] + 1;
				}
				else {
					table[i] = table[i - 1] + 1;
				}
			}
		}
		else if (i % 3 == 0) {
			table[i] = ((table[i - 1] > table[i / 3]) ? table[i / 3] : table[i - 1]) + 1;
		}
		else if (i % 2 == 0) {
			table[i] = ((table[i - 1] > table[i / 2]) ? table[i / 2] : table[i - 1]) + 1;
		}
	}
	std::cout << table[N];
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}