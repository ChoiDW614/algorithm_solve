#include <iostream>
#include <vector>
#include <algorithm>

void solution() {
	std::vector<int> v1;

	int numOfCard, Max, i, N;
	std::cin >> numOfCard >> Max;
	for (i = 0; i < numOfCard; i++) {
		std::cin >> N;
		v1.push_back(N);
	}
	std::sort(v1.begin(), v1.end());

	int M, nowMax = 0;
	for (auto iter1 = v1.begin(); iter1 < v1.end(); iter1++) {
		M = 0;
		M += *iter1;
		for (auto iter2 = iter1 + 1; iter2 < v1.end(); iter2++) {
			M += *iter2;
			for (auto iter3 = iter2 + 1; iter3 < v1.end(); iter3++) {
				M += *iter3;
				if (M > nowMax && M <= Max)
					nowMax = M;
				if (M == Max) {
					std::cout << M;
					return;
				}
				M -= *iter3;
			}
			M -= *iter2;
		}
	}
	std::cout << nowMax;
	return;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	solution();

	return 0;
}