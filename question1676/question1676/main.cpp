#include <iostream>
#include <algorithm>
#define FAST_IO	std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr);
typedef long long ll;

void Solve()
{
	ll cnt2 = 0, cnt5 = 0, N, div;
	std::cin >> N;
	while (N) {
		div = N;
		while (div % 2 == 0) {
			cnt2++;
			div /= 2;
		}
		while (div % 5 == 0) {
			cnt5++;
			div /= 5;
		}
		N--;
	}
	std::cout << std::min(cnt2, cnt5);
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}