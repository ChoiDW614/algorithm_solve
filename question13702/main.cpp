#include <iostream>
#include <cmath>
typedef long long ll;

ll friends;
ll maxPot;
ll potMak[10000];

void inputData()
{
	std::cin >> maxPot >> friends;
	for (int i = 0; i < maxPot; i++) {
		std::cin >> potMak[i];
	}
}

void Bsearch(int target)
{
	ll first = 0;
	ll last = static_cast<ll>(pow(2, 31)) - 1;
	ll mid, cnt;

	while (first <= last) {
		cnt = 0;
		mid = (first + last) / 2;
		for (int i = 0; i < maxPot; i++) {
			cnt += potMak[i] / mid;
		}

		if (cnt >= target) {
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}
	std::cout << static_cast<int>(last) << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	inputData();
	Bsearch(friends);
	return 0;
}